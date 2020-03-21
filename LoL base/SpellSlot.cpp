#include "Windows.h"
#include "SpellSlot.h"
#include "Engine.h"

int SpellSlot::GetLevel()
{
	return *reinterpret_cast<int*>(reinterpret_cast<DWORD>(this) + 0x20);
}

float SpellSlot::GetTime()
{
	return *reinterpret_cast<float*>(reinterpret_cast<DWORD>(this) + 0x28);
}

float SpellSlot::GetTimeUsed()
{
	return *reinterpret_cast<float*>(reinterpret_cast<DWORD>(this) + O_SS_TIME_USED);
}

float SpellSlot::GetCooldown()
{
	auto cd = this->GetTimeUsed() - Engine::GetGameTime();
	
	if(cd <= 0.0f)
	{
		cd = 0.0f;
	}

	return cd;
}
