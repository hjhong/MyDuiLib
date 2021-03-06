#ifndef _Lua_CComboBoxUI_h
#define _Lua_CComboBoxUI_h
#pragma once
#include "LuaDefine.h"

namespace DuiLib
{
	LUA_CLASS(CComboBoxUI, ComboBoxUI, CComboBoxUI, ComboUI, CComboUI)
	{
	public:
		
		LUA_METHOD_DECL(New)
		LUA_METHOD_DECL(GetClassName)
		LUA_METHOD_DECL(SetArrowImage)
		LUA_METHOD_DECL(GetArrowImage)

		LUA_CLASS_REG_DECL()
	};
}


#endif//_Lua_CComboBoxUI_h