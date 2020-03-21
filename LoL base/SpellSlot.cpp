#include "Windows.h"
#include "SpellSlot.h"

bool SpellSlot::IsReady()
{
	return GetTime() < 0.1f;
}

int SpellSlot::GetLevel()
{
	return *reinterpret_cast<int*>(reinterpret_cast<DWORD>(this) + 0x20);
}

float SpellSlot::GetTime()
{
	return *reinterpret_cast<float*>(reinterpret_cast<DWORD>(this) + 0x28);
}
