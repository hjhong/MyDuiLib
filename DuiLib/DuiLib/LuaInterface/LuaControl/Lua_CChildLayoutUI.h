#ifndef _Lua_CChildLayoutUI_h
#define _Lua_CChildLayoutUI_h
#pragma once
#include "LuaDefine.h"

namespace DuiLib
{
	LUA_CLASS(CChildLayoutUI, ChildLayoutUI, CChildLayoutUI, ContainerUI, CContainerUI)
	{
	public:
		
		LUA_METHOD_DECL(New)
		LUA_METHOD_DECL(GetClassName)
		LUA_METHOD_DECL(Init)
		LUA_METHOD_DECL(SetChildLayoutXML)
		LUA_METHOD_DECL(GetChildLayoutXML)

		LUA_CLASS_REG_DECL()
	};
}


#endif//_Lua_CChildLayoutUI_h