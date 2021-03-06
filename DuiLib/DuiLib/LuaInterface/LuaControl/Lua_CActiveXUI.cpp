#include "LuaEntry.h"

#include REQUIRE_H(CActiveXUI)

namespace DuiLib
{
	LUA_METHOD_IMPL(CActiveXUI, New)
	{
		CActiveXUI  *ctrl = new CActiveXUI();
		LuaStatic::AddObject2Lua(l, ctrl, METATABLE_NAME(ctrl));
		return 1;
	}

	LUA_METHOD_IMPL(CActiveXUI, GetClassName)
	{
		CDuiString pstrText = CActiveXUI::GetClassName();
		lua_op_t<CDuiString>::push_stack(l, pstrText);
		return 1;
	}


	LUA_METHOD_IMPL(CActiveXUI,GetHostWindow)
	{
		try
		{
			CActiveXUI* self;
			self = static_cast<CActiveXUI*>(LuaStatic::CheckUserData(l, 1));
			HWND hHostWnd = self->GetHostWindow();
			LuaStatic::AddObject2Lua(l, hHostWnd, "HWND");
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCActiveXUI::GetHostWindow"));
			return 0;
		}
	}

	LUA_METHOD_IMPL(CActiveXUI,IsDelayCreate)
	{
		try
		{
			CActiveXUI* self;
			self = static_cast<CActiveXUI*>(LuaStatic::CheckUserData(l, 1));
			lua_op_t<bool>::push_stack(l, self->IsDelayCreate());
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCActiveXUI::IsDelayCreate"));
			return 0;
		}
	}

	LUA_METHOD_IMPL(CActiveXUI,SetDelayCreate)
	{
		try
		{
			CActiveXUI* self;
			self = static_cast<CActiveXUI*>(LuaStatic::CheckUserData(l, 1));
			bool bDelayCreate = true;
			if (!lua_isnone(l, 2))
				bDelayCreate = lua_toboolean(l,2) != 0;
			self->SetDelayCreate(bDelayCreate);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCActiveXUI::SetDelayCreate"));
			return 0;
		}
	}

	LUA_METHOD_IMPL(CActiveXUI,CreateControl)
	{
		try
		{
			CActiveXUI* self;
			self = static_cast<CActiveXUI*>(LuaStatic::CheckUserData(l, 1));
			
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCActiveXUI::CreateControl"));
			return 0;
		}
	}

	LUA_METHOD_IMPL(CActiveXUI,CreateControl2)
	{
		try
		{
			CActiveXUI* self;
			self = static_cast<CActiveXUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrCLSID;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrCLSID);
			self->CreateControl(pstrCLSID);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCActiveXUI::CreateControl2"));
			return 0;
		}
	}

	LUA_METHOD_IMPL(CActiveXUI,SetModuleName)
	{
		try
		{
			CActiveXUI* self;
			self = static_cast<CActiveXUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);
			self->SetModuleName(pstrText);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCActiveXUI::SetModuleName"));
			return 0;
		}
	}

	LUA_METHOD_IMPL(CActiveXUI,GetModuleName)
	{
		try
		{
			CActiveXUI* self;
			self = static_cast<CActiveXUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText = self->GetModuleName();

			lua_op_t<CDuiString>::push_stack(l, pstrText);

			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCActiveXUI::GetModuleName"));
			return 0;
		}
	}

	LUA_CLASS_REG_IMPL(CActiveXUI)
	{
		lua_newtable(l);
		static LuaReg StaticFuncs[] =
		{
			{ "New", New },
			{ "GetClassName", GetClassName },
		};
		LuaStatic::LuaSetFuncsInTable(l, StaticFuncs, sizeof(StaticFuncs) / sizeof(StaticFuncs[0]));
		lua_setfield(l, -2, "ActiveXUI");

		luaL_newmetatable(l, "CActiveXUI");
		luaL_getmetatable(l, "CControlUI");
		lua_setmetatable(l, -2);
		
		lua_pushvalue(l, -1);
		lua_setfield(l, -2, "__index");
		static LuaReg MethodFuncs[] =
		{
			{ "GetHostWindow", GetHostWindow },
			{ "IsDelayCreate", IsDelayCreate },
			{ "SetDelayCreate", SetDelayCreate },
			{ "CreateControl", CreateControl },
			{ "CreateControl2", CreateControl },
			{ "SetModuleName", SetModuleName },
			{ "GetModuleName", GetModuleName },
		};
		LuaStatic::LuaSetFuncsInTable(l, MethodFuncs, sizeof(MethodFuncs) / sizeof(MethodFuncs[0]));
		
		lua_pop(l, 1);
	}
}