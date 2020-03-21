#pragma once
#include <Windows.h>

#define baseAddr (DWORD)GetModuleHandle(NULL)

#define STR_MERGE_IMPL(x, y)				x##y
#define STR_MERGE(x,y)						STR_MERGE_IMPL(x,y)
#define MAKE_PAD(size)						BYTE STR_MERGE(pad_, __COUNTER__) [ size ]

#define DEFINE_MEMBER_0(x, y)				x
#define DEFINE_MEMBER_N(x,offset)			struct { MAKE_PAD(offset); x; }

#define OBJ_MINION  1
#define OBJ_HERO    2
#define OBJ_MISSILE 3

template< typename Function > Function CallVirtual(PVOID Base, DWORD Index)
{
	PDWORD* VTablePointer = (PDWORD*)Base;
	PDWORD VTableFunctionBase = *VTablePointer;
	DWORD dwAddress = VTableFunctionBase[Index];

	return (Function)(dwAddress);
}

inline char* GetStr(DWORD offset) {
	if (*reinterpret_cast<int*>(offset + 0x10) > 15)
	{
		return reinterpret_cast<char*>(*reinterpret_cast<DWORD*>(offset));
	}
	else
	{
		return reinterpret_cast<char*>(offset);
	}
}

inline float GetEffectiveHP(const float armor, const float hp) {
	return hp * (100.0f + armor) / 100.0f;
}

inline int GetColor(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}