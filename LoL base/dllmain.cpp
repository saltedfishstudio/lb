// dllmain.cpp : Define o ponto de entrada para da aplicação DLL.
#include <time.h>
#include "stdafx.h"
#include "guicon.h"
#include "Engine.h"
#include "Hooks.h"
#include "detours.h"
#include <string>
#include <iostream>
//#include "OrbWalker.h"
#pragma comment(lib, "detours.lib")

CObjectManager* ObjManager;
CConsole Console;
CFunctions Functions;

clock_t lastmove = NULL;
bool bInit = false;
bool drawCircle = false;
typedef HRESULT(WINAPI *Prototype_Present)(DWORD, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*);
Prototype_Present Original_Present;

//OrbWalker* orbwalker;

int r = 255, g = 255, b = 255;
int selectedColor = 0;

void ChangeColorIndex(bool up)
{
	if(up)
	{
		selectedColor++;
	} else
	{
		selectedColor--;
	}

	selectedColor %= 3;
}

void ChangeColor(bool up)
{
	if (selectedColor == 0)
	{
		r = up ? r + 10 : r - 10;
		r %= 256;
	}
	else if (selectedColor == 1)
	{
		g = up ? g + 10 : g - 10;
		g %= 256;
	}
	else if (selectedColor == 2)
	{
		b = up ? b + 10 : b - 10;
		b %= 256;
	}
}

HRESULT WINAPI Hooked_Present(DWORD Device, CONST RECT *pSrcRect, CONST RECT *pDestRect, HWND hDestWindow, CONST RGNDATA *pDirtyRegion) {

	if (me) {

		if (me->IsAlive()) {

			if(GetAsyncKeyState(VK_HOME))
			{
				drawCircle = !drawCircle;
			}
			
			if(drawCircle)
			{
				auto color = CONVERT_RGB(r,g,b);
				Functions.DrawCircle(&me->GetPos(), me->GetAttackRange() + me->GetBoundingRadius(), &color, 0, 0.0f, 0, 0.5f);
			}

			if(VK_UP)
			{
				ChangeColor(true);
			}

			if(VK_DOWN)
			{
				ChangeColor(false);
			}

			if(VK_RIGHT)
			{
				ChangeColorIndex(true);
			}

			if (VK_LEFT)
			{
				ChangeColorIndex(false);
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

		//if(me->IsHero())
		//{
		//	
		//}

		for (int i = 0; i < 10000; i++) {
			CObject* obj = Engine::GetObjectByID(i);
			if (obj) {

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

	while (Engine::GetGameTime() < 1.0f || !me)
		Sleep(1);

	ObjManager = (CObjectManager*)(baseAddr + oObjManager);

	Functions.PrintChat = (Typedefs::fnPrintChat)(baseAddr + oPrintChat);
	Functions.IsTargetable = (Typedefs::fnIsTargetable)(baseAddr + oIsTargetable);
	Functions.IsAlive = (Typedefs::fnIsAlive)(baseAddr + oIsAlive);

	Functions.IsMinion = (Typedefs::fnIsMinion)(baseAddr + oIsMinion);
	Functions.IsTurret = (Typedefs::fnIsTurret)(baseAddr + oIsTurret);
	Functions.IsHero = (Typedefs::fnIsHero)(baseAddr + oIsHero);
	Functions.IsMissile = (Typedefs::fnIsMissile)(baseAddr + oIsMissile); 
	Functions.IsNexus = (Typedefs::fnIsNexus)(baseAddr + oIsNexus);
	Functions.IsInhibitor = (Typedefs::fnIsInhibitor)(baseAddr + oIsInhib);
	Functions.IsTroyEnt = (Typedefs::fnIsTroyEnt)(baseAddr + oIsTroy);

	//Functions.CastSpell = (Typedefs::fnCastSpell)((DWORD)GetModuleHandle(NULL) + oCastSpell);
	Functions.IssueOrder = (Typedefs::fnIssueOrder)((DWORD)GetModuleHandle(NULL) + oIssueOrder);
	Functions.DrawCircle = (Typedefs::fnDrawCircle)((DWORD)GetModuleHandle(NULL) + oDrawCircle);

	Functions.GetAttackCastDelay = (Typedefs::fnGetAttackCastDelay)((DWORD)GetModuleHandle(NULL) + oGetAttackCastDelay);
	Functions.GetAttackDelay = (Typedefs::fnGetAttackDelay)((DWORD)GetModuleHandle(NULL) + oGetAttackDelay);

	//orbwalker = new OrbWalker();

	Original_Present = (Prototype_Present)DetourFunction((PBYTE)GetDeviceAddress(17), (PBYTE)Hooked_Present);
}

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
