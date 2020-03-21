#include "Windows.h"
#include "CSpellEntry.h"
#include <minwindef.h>

char* CSpellEntry::GetSpellName()
{
	auto aux3 = *reinterpret_cast<DWORD*>(reinterpret_cast<DWORD>(this) + 0x4);
	if(aux3)
	{
		auto aux4 = *reinterpret_cast<DWORD*>(aux3 + 0xC);
		if(aux4)
		{
			if(*reinterpret_cast<DWORD*>(aux4 + 0x8))
			{
				return reinterpret_cast<char*>(aux4 + 0x8);
			}
		}
	}

	return nullptr;
}
