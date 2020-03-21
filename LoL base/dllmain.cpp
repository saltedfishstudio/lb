#include "stdafx.h"
#include "guicon.h"
#include "Engine.h"
#include "Hooks.h"
#include "detours.h"
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <atlconv.h>

using namespace std;

#pragma comment(lib, "detours.lib")

// DEFINE FUNCTION
DWORD FindDevice(DWORD Len);
DWORD GetDeviceAddress(int VTableIndex);

// TYPE DEFINES
typedef HRESULT(WINAPI* Prototype_Present)(DWORD, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*);

// LOCAL HANDLES
CObjectManager* ObjManager;
CConsole Console;
CFunctions Functions;
Prototype_Present Original_Present;
clock_t lastmove = NULL;

// SWITCHES
bool bDrawAttackRange = false;

int spellIndex = 1;

HRESULT WINAPI Hooked_Present(DWORD Device, CONST RECT *pSrcRect, CONST RECT *pDestRect, HWND hDestWindow, CONST RGNDATA *pDirtyRegion) {

	if (me) {

		if (me->IsAlive()) {

			if(GetAsyncKeyState(VK_HOME))
			{
				bDrawAttackRange = !bDrawAttackRange;
			}
			
			if(bDrawAttackRange)
			{
				auto color = GetColor(255,255,0);

				//auto pos = &me->GetPos();
				auto range = me->GetAttackRange() + me->GetBoundingRadius();
				
				Functions.DrawCircle(&me->GetPos(), range, &color, 0, 0.0f, 0, 0.5f);

				auto mouseWorldPos = Engine::GetMouseWorldPosition();

				//Vector screenPos;
				//Functions.WorldToScreen(&mouseWorldPos, &screenPos);

				//Functions.DrawCircle(&screenPos, 500, &color, 0, 0.0f, 0, 0.5f);
			}

			if(GetAsyncKeyState(VK_INSERT))
			{
				Engine::CastSpellPos(spellIndex, me->GetPos());
				spellIndex = (spellIndex + 1) % 4;

				Sleep(100);
				//auto minions = ObjManager->GetMinions(me->GetTeam());
			}

			if (GetAsyncKeyState(VK_CAPITAL))
			{
				if (lastmove == NULL || clock() - lastmove > 30.0f) {
					lastmove = clock();
					Engine::MoveTo(&Engine::GetMouseWorldPosition());
				}
			}
		}
	}

	

	if (ObjManager) {
		for (int i = 0; i < 10000; i++) {
			CObject* obj = Engine::GetObjectByID(i);
			if (obj) {

				//AllocConsole();
				
				//cout << obj->GetName() << endl;
				
				//if (obj->IsHero()) // <- Crashed here
				{
					//if(!obj -> IsAlive())
					//{
					//	continue;
					//}
					//if(!obj -> IsVisible())
					//{
					//	continue;
					//}
					//if(obj->GetTeam() == me->GetTeam())
					//{
					//	continue;
					//}
					//if (obj->IsAlive() && obj->IsVisible() && obj->GetTeam() != me->GetTeam()) 
					//{
					//	auto color = CONVERT_RGB(255, 0, 0);
					//	Functions.DrawCircle(&obj->GetPos(), obj->GetAttackRange() + obj->GetBoundingRadius(), &color, 0, 0.0f, 0, 0.5f); //Draw range
					//}
				}
			}
		}
	}
	
	return Original_Present(Device, pSrcRect, pDestRect, hDestWindow, pDirtyRegion);
}

void __stdcall Start() {

	while (Engine::GetGameTime() < 1.0f || !me)
	{
		Sleep(1);
	}
	
	ObjManager = (CObjectManager*)(baseAddr + oObjManager);
	Functions.IsAlive = (Typedefs::fnIsAlive)(baseAddr + oIsAlive);
	//Functions.PrintChat = (Typedefs::fnPrintChat)(baseAddr + oPrintChat);
	
	Functions.IsTargetable = (Typedefs::fnIsTargetable)(baseAddr + oIsTargetable);

	Functions.IsMinion = (Typedefs::fnIsMinion)(baseAddr + oIsMinion);
	Functions.IsTurret = (Typedefs::fnIsTurret)(baseAddr + oIsTurret);
	Functions.IsHero = (Typedefs::fnIsHero)(baseAddr + oIsHero);
	Functions.IsMissile = (Typedefs::fnIsMissile)(baseAddr + oIsMissile); 
	Functions.IsNexus = (Typedefs::fnIsNexus)(baseAddr + oIsNexus);
	Functions.IsInhibitor = (Typedefs::fnIsInhibitor)(baseAddr + oIsInhib);
	
	//Functions.IsTroyEnt = (Typedefs::fnIsTroyEnt)(baseAddr + oIsTroy);
	Functions.CastSpell = (Typedefs::fnCastSpell)((DWORD)GetModuleHandle(NULL) + oCastSpell);
	//
	Functions.IssueOrder = (Typedefs::fnIssueOrder)((DWORD)GetModuleHandle(NULL) + oIssueOrder);
	Functions.DrawCircle = (Typedefs::fnDrawCircle)((DWORD)GetModuleHandle(NULL) + oDrawCircle);

	Functions.GetAttackCastDelay = (Typedefs::fnGetAttackCastDelay)((DWORD)GetModuleHandle(NULL) + oGetAttackCastDelay);
	Functions.GetAttackDelay = (Typedefs::fnGetAttackDelay)((DWORD)GetModuleHandle(NULL) + oGetAttackDelay);

	Functions.WorldToScreen = (Typedefs::WorldToScreen)(baseAddr + oW2S);

	Original_Present = (Prototype_Present)DetourFunction((PBYTE)GetDeviceAddress(17), (PBYTE)Hooked_Present);
}

#ifndef DLL_MAIN
#define DLL_MAIN
#endif
#ifdef DLL_MAIN
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	UNREFERENCED_PARAMETER(lpReserved);
	
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Start, nullptr, 0, nullptr);
		return TRUE;
	}

	else if (ul_reason_for_call == DLL_PROCESS_DETACH) {
		return TRUE;
	}
	return FALSE;
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

	//Log(L"FindDevice");
	cout << "FindDevice " << dwObjBase << endl;

	return(dwObjBase);
}

DWORD GetDeviceAddress(int VTableIndex)
{
	PDWORD VTable;
	*(DWORD*)&VTable = *(DWORD*)FindDevice(0x128000);

	cout << "GetDeviceAddress " << VTableIndex << endl;

	return VTable[VTableIndex];
}

#endif