#ifndef _Lua_CFadeCheckBoxUI_h
#define _Lua_CFadeCheckBoxUI_h
#pragma once
#include "LuaDefine.h"

namespace DuiLib
{
	LUA_CLASS(CFadeCheckBoxUI, FadeCheckBoxUI, CFadeCheckBoxUI, FadeOptionUI, CFadeOptionUI)
	{
	public:
		
		LUA_METHOD_DECL(New)
		LUA_METHOD_DECL(GetClassName)
		LUA_METHOD_DECL(SetCheck)
		LUA_METHOD_DECL(GetCheck)

		LUA_CLASS_REG_DECL()
	};
}


#endif//_Lua_CFadeCheckBoxUI_h