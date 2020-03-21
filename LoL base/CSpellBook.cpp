#include "Windows.h"
#include "CSpellBook.h"
#include "Engine.h"

CSpellEntry* CSpellBook::GetActiveSpellEntry()
{
	return *reinterpret_cast<CSpellEntry**>(reinterpret_cast<DWORD>(this) + 0x20);
}

SpellSlot* CSpellBook::GetSpellSlotById(int id)
{
	return *reinterpret_cast<SpellSlot**>(reinterpret_cast<DWORD>(this) + 0x508 + (0x4 * id));
}

bool CSpellBook::IsSpellReady(int ID)
{
	static byte zero = 0;
	int result = Functions.GetSpellState(reinterpret_cast<DWORD>(me->GetSpellBook()), ID, &zero);

	Engine::Chat("Test", GetColor(255, 0, 0));
	
	if (result == 0) return true;

	return false;
}

enum class ESpellState
{
	Ready = 0,
	NotAvailable = 4,
	Surpressed = 8,
	NotLearned = 12,
	Processing = 24,
	Cooldown = 32,
	NoMana = 64,
};
