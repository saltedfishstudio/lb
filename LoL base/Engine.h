#pragma once
#include "Offsets.h"
#include "Utils.h"
#include "Vector.h"
#include "Hooks.h"
#include "CObjectManager.h"
#include <string>

#define me Engine::GetLocalObject()

class Engine {
public:

	// CastSpellSelf : Soraka ult, Kalista E..
	// CastSpellTargetted : Veigar ult, Kayle Q, Soraka W...
	// CastSpellPos : Veigar's E, Soraka Q & E, Katarina E...
	
	static void CastSpellSelf(int slotID);
	static void CastSpellPos(int slotID, Vector pos);
	static void CastSpellTargetted(int slotID, CObject* obj);
	
	static Vector GetMouseWorldPosition() {
		
		DWORD MousePtr = reinterpret_cast<DWORD>(GetModuleHandle(nullptr)) + oHudInstance;

		auto aux1 = *reinterpret_cast<DWORD*>(MousePtr);
		aux1 += 0x14;
		auto aux2 = *reinterpret_cast<DWORD*>(aux1);
		aux2 += 0x1C;

		float X = *reinterpret_cast<float*>(aux2 + 0x0);
		float Y = *reinterpret_cast<float*>(aux2 + 0x4);
		float Z = *reinterpret_cast<float*>(aux2 + 0x8);

		return Vector{ X, Y, Z };
	}

	static char* GetGameVersion() {
		return reinterpret_cast<char*>((baseAddr + oGameVersion));
	}

	static float GetGameTime() {
		return *reinterpret_cast<float*>((baseAddr + oGameTime));
	}

	static CObject* GetLocalObject() {
		auto localPlayerAddr = *reinterpret_cast<DWORD*>((baseAddr + oLocalPlayer));
		if (localPlayerAddr == NULL)
			return nullptr;

		return reinterpret_cast<CObject*>(localPlayerAddr);
	}

	// 문제 있는 함수
	static CObject* GetObjectByID(int ID)
	{
		if (ObjManager != NULL && ID >= 0 && ID <= 10000) {
			return ObjManager->objectArray[ID];
		}
		return nullptr;
	}

	static void MoveTo(Vector* position) {
		Functions.IssueOrder(GetLocalObject(), 2, position, NULL, false, false, false);
	}
};