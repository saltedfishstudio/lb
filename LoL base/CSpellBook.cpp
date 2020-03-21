#include "Windows.h"
#include "CSpellBook.h"

CSpellEntry* CSpellBook::GetActiveSpellEntry()
{
	return *reinterpret_cast<CSpellEntry**>(reinterpret_cast<DWORD>(this) + 0x20);
}

SpellSlot* CSpellBook::GetSpellSlotById(int id)
{
	return *reinterpret_cast<SpellSlot**>(reinterpret_cast<DWORD>(this) + 0x530 + (0x4 * id));
}


