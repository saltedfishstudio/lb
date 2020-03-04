// dllmain.cpp : Define o ponto de entrada para da aplica豫o DLL.
#include <time.h>
#include "stdafx.h"
#include "guicon.h"
#include "Engine.h"
#include "Hooks.h"
#include "detours.h"
#include <string>
#include <iostream>
#pragma comment(lib, "detours.lib")

CObjectManager* ObjManager;
CConsole Console;
CFunctions Functions;

clock_t lastmove = NULL;
bool bInit = false;
typedef HRESULT(WINAPI *Prototype_Present)(DWORD, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*);
Prototype_Present Original_Present;

HRESULT WINAPI Hooked_Present(DWORD Device, CONST RECT *pSrcRect, CONST RECT *pDestRect, HWND hDestWindow, CONST RGNDATA *pDirtyRegion) {
	if (me) {
		if (!bInit) {
			Console.print("Local player's name: %s | Champion: %s | HP: %f\n", me->GetName(), me->GetChampionName(), me->GetHealth());
			bInit = true;
		}

		if (me->IsAlive()) {
			auto color = createRGB(0, 255, 0);
			Functions.DrawCircle(&me->GetPos(), me->GetAttackRange() + me->GetBoundingRadius(), &color, 0, 0.0f, 0, 0.5f);

			if (lastmove == NULL || clock() - lastmove > 30.0f) {
				lastmove = clock();
				Engine::MoveTo(&Engine::GetMouseWorldPosition());
			}
		}
	}

	if (ObjManager) {
		for (int i = 0; i < 10000; i++) {
			CObject* obj = Engine::GetObjectByID(i);
			if (obj) {
				if (obj->IsHero()) {
					if (obj->IsAlive() && obj->IsVisible() && obj->GetTeam() != me->GetTeam()) {
						auto color = createRGB(255, 0, 0);
						Functions.DrawCircle(&obj->GetPos(), obj->GetAttackRange() + obj->GetBoundingRadius(), &color, 0, 0.0f, 0, 0.5f); //Draw range
					}
				}
			}
		}
	}
	return Original_Present(Device, pSrcRect, pDestRect, hDestWindow, pDirtyRegion);
}

DWORD FindDevice(DWORD Len)
{
	DWORD dwObjBase = 0;

	dwObjBase = (DWORD)LoadLibrary("d3d9.dll");
	while (dwObjBase++ < dwObjBase + Len)
	{
		if ((*(WORD*)(dwObjBase + 0x00)) == 0x06C7
			&& (*(WORD*)(dwObjBase + 0x06)) == 0x8689
			&& (*(WORD*)(dwObjBase + 0x0C)) == 0x8689
			) {
			dwObjBase += 2; break;
		}
	}
	return(dwObjBase);
}

DWORD GetDeviceAddress(int VTableIndex)
{
	PDWORD VTable;
	*(DWORD*)&VTable = *(DWORD*)FindDevice(0x128000);
	return VTable[VTableIndex];
}

void __stdcall Start() {
	//Console.startConsoleWin(80, 25, NULL);

	while (Engine::GetGameTime() < 1.0f || !me)
		Sleep(1);

	//ObjManager = (CObjectManager*)(baseAddr + oObjManager);

	//Functions.PrintChat = (Typedefs::fnPrintChat)(baseAddr + oPrintChat);
	//Functions.IsTargetable = (Typedefs::fnIsTargetable)(baseAddr + oIsTargetable);
	//Functions.IsAlive = (Typedefs::fnIsAlive)(baseAddr + oIsAlive);

	//Functions.IsMinion = (Typedefs::fnIsMinion)(baseAddr + oIsMinion);
	//Functions.IsTurret = (Typedefs::fnIsTurret)(baseAddr + oIsTurret);
	//Functions.IsHero = (Typedefs::fnIsHero)(baseAddr + oIsHero);
	//Functions.IsMissile = (Typedefs::fnIsMissile)(baseAddr + oIsMissile); 
	//Functions.IsNexus = (Typedefs::fnIsNexus)(baseAddr + oIsNexus);
	//Functions.IsInhibitor = (Typedefs::fnIsInhibitor)(baseAddr + oIsInhib);
	//Functions.IsTroyEnt = (Typedefs::fnIsTroyEnt)(baseAddr + oIsTroy);

	////Functions.CastSpell = (Typedefs::fnCastSpell)((DWORD)GetModuleHandle(NULL) + oCastSpell);
	//Functions.IssueOrder = (Typedefs::fnIssueOrder)((DWORD)GetModuleHandle(NULL) + oIssueOrder);
	//Functions.DrawCircle = (Typedefs::fnDrawCircle)((DWORD)GetModuleHandle(NULL) + oDrawCircle);

	//Functions.GetAttackCastDelay = (Typedefs::fnGetAttackCastDelay)((DWORD)GetModuleHandle(NULL) + oGetAttackCastDelay);
	//Functions.GetAttackDelay = (Typedefs::fnGetAttackDelay)((DWORD)GetModuleHandle(NULL) + oGetAttackDelay);

	Original_Present = (Prototype_Present)DetourFunction((PBYTE)GetDeviceAddress(17), (PBYTE)Hooked_Present);
}

const std::string currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); // YYYY-MM-DD.HH:mm:ss 형태의 스트링

	return buf;
}

std::string startTime;
std::string endTime;

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	UNREFERENCED_PARAMETER(lpReserved);
	DWORD tid = 0;
	
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		startTime = currentDateTime();
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Start, 0, 0, &tid);
		return TRUE;
	}

	else if (ul_reason_for_call == DLL_PROCESS_DETACH) {
		endTime = currentDateTime();
		std::string result = "Start : " + startTime + "\nEndTime : " + endTime;
		LPCTSTR pS2 = result.c_str();
		MessageBoxA(nullptr, "Dettached!", pS2, 0);
		return TRUE;
	}
	return FALSE;
}
