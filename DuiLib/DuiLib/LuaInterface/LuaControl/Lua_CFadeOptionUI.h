#ifndef _Lua_CFadeOptionUI_h
#define _Lua_CFadeOptionUI_h
#pragma once
#include "LuaDefine.h"

namespace DuiLib
{
	LUA_CLASS(CFadeOptionUI, FadeOptionUI, CFadeOptionUI, OptionUI, COptionUI)
	{
	public:
		
		LUA_METHOD_DECL(New)
		LUA_METHOD_DECL(GetClassName)

		LUA_CLASS_REG_DECL()
	};
}


#endif//_Lua_CFadeOptionUI_h