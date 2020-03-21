#pragma once
#include <Windows.h>
#include "Offsets.h"
#include "Vector.h"
#include "Utils.h"
#include "CSpellBook.h"

class CObject {
public:
	bool IsTurret();
	bool IsMinion();
	bool IsAlive();
	bool IsHero();
	bool IsMissile();
	bool IsNexus();

	bool IsInhibitor();
	bool IsTroyEnt();
	bool CanBeTarget();

	static CSpellBook* GetSpellBook();

	short GetIndex() {
		return *reinterpret_cast<short*>(reinterpret_cast<DWORD>(this) + oObjIndex);
	}

	DWORD GetNetworkID() {
		return *reinterpret_cast<DWORD*>(reinterpret_cast<DWORD>(this) + oObjNetworkID);
	}

	Vector GetPos() {
		return *reinterpret_cast<Vector*>(reinterpret_cast<DWORD>(this) + oObjPos);
	}

	int GetLevel() {
		return *reinterpret_cast<int*>(reinterpret_cast<DWORD>(this) + oObjLevel);
	}

	float GetHealth() {
		return *reinterpret_cast<float*>(reinterpret_cast<DWORD>(this) + oObjHealth);
	}

	float GetBaseAttackDamage() {
		return *reinterpret_cast<float*>(reinterpret_cast<DWORD>(this) + oObjBaseAtk);
	}

	float GetBonusAttackDamage() {
		return *reinterpret_cast<float*>(reinterpret_cast<DWORD>(this) + oObjBonusAtk);
	}

	float GetTotalAttackDamage() {
		return this->GetBonusAttackDamage() + this->GetBaseAttackDamage();
	}

	float GetArmor() {
		return *reinterpret_cast<float*>(reinterpret_cast<DWORD>(this) + oObjArmor);
	}

	float GetMaxHealth() {
		return *reinterpret_cast<float*>(reinterpret_cast<DWORD>(this) + oObjHealth + 0x10);
	}

	float GetAttackRange() {
		return *reinterpret_cast<float*>(reinterpret_cast<DWORD>(this) + oObjAtkRange);
	}

	bool IsVisible() {
		return *reinterpret_cast<bool*>(reinterpret_cast<DWORD>(this) + oObjVisibility);
	}

	float GetBoundingRadius() {
		typedef float(__thiscall* OriginalFn)(PVOID);
		return CallVirtual<OriginalFn>(this, 36)(this);
	}

	bool IsEnemyTo(CObject* Obj) {
		if (Obj->GetTeam() == 100 && this->GetTeam() == 200)
			return true;

		else if (Obj->GetTeam() == 200 && this->GetTeam() == 100)
			return true;

		return false;
	}

	char* GetName() {
		return GetStr(reinterpret_cast<DWORD>(this) + oObjName);
	}

	char* GetChampionName() {
		return GetStr(reinterpret_cast<DWORD>(this) + oObjChampionName);
	}

	int GetTeam() {
		return *reinterpret_cast<int*>(reinterpret_cast<DWORD>(this) + oObjTeam);
	}

	
};
