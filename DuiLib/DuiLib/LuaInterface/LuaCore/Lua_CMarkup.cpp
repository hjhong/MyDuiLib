#include "LuaEntry.h"

#include REQUIRE_H(CMarkup)

namespace DuiLib
{
	LUA_METHOD_IMPL(CMarkup, isnil)
	{
		CMarkup* self;
		self = static_cast<CMarkup*>(LuaStatic::CheckUserData(l, 1));

		lua_pushboolean(l, self == NULL ? 1 : 0);
		return 1;
	}
	LUA_METHOD_IMPL(CMarkup, _gc)
	{	
		CMarkup* self;
		self = static_cast<CMarkup*>(LuaStatic::CheckUserData(l, 1));
		LuaStatic::RemoveObjectInLua(l);
		SafeDelete(self);
		return 0;
	}
	LUA_METHOD_IMPL(CMarkup, _eq)
	{
		try
		{
			CMarkup* left;
			left = static_cast<CMarkup*>(LuaStatic::CheckUserData(l, 1));

			CMarkup* right;
			right = static_cast<CMarkup*>(LuaStatic::CheckUserData(l, 2));

			lua_pushboolean(l, left == right ? 1 : 0);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkup::_eq"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkup, _tostring)
	{
		try
		{
			CMarkup* self;
			self = static_cast<CMarkup*>(LuaStatic::CheckUserData(l, 1));
			if (self)
			{
				CDuiString str = CDuiString::FormatString(_T("%s(addr:%p)"), self->GetClass(), (void*)self);
				lua_pushstring(l, str.GetAString().c_str());
			}
			else
			{
				CDuiString str = CDuiString::FormatString(_T("%s(addr:%s)"), "Markup", "nil");
				lua_pushstring(l, str.GetAString().c_str());
			}
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkup::_tostring"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkup, Delete)
	{
		CMarkup* self;
		self = static_cast<CMarkup*>(LuaStatic::CheckUserData(l, 1));
		LuaStatic::RemoveObjectInLua(l);
		SafeDelete(self);
		return 0;
	}
	LUA_METHOD_IMPL(CMarkup, New)
	{
		LPCTSTR pstrXML = NULL;
		if (lua_isstring(l, 1))
		{
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);

			pstrXML = pstrText.GetData();
		}
		CMarkup  *self = new CMarkup(pstrXML);
		LuaStatic::AddObject2Lua(l, self, METATABLE_NAME(self));
		return 1;
	}
	LUA_METHOD_IMPL(CMarkup, GetClassName)
	{
		CDuiString pstrText = CMarkup::GetClassName();
		lua_op_t<CDuiString>::push_stack(l, pstrText);
		return 1;
	}

	LUA_METHOD_IMPL(CMarkup, GetClass)
	{
		try
		{
			CMarkup* self;
			self = static_cast<CMarkup*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText = self->GetClass();
			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkup::GetClass"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkup, Load)
	{
		try
		{
			CMarkup* self;
			self = static_cast<CMarkup*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);

			lua_pushboolean(l, self->Load(pstrText) ? 1 : 0);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkup::Load"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkup, LoadFromMem)
	{
		try
		{
			CMarkup* self;
			self = static_cast<CMarkup*>(LuaStatic::CheckUserData(l, 1));
			size_t len = 0;
			const char* pbuf = lua_tolstring(l, 2, &len);
			
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkup::LoadFromMem"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkup, LoadFromFile)
	{
		try
		{
			CMarkup* self;
			self = static_cast<CMarkup*>(LuaStatic::CheckUserData(l, 1));
			size_t len = 0;
			const char* pbuf = lua_tolstring(l, 2, &len);

			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkup::LoadFromFile"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkup, Release)
	{
		try
		{
			CMarkup* self;
			self = static_cast<CMarkup*>(LuaStatic::CheckUserData(l, 1));
			self->Release();
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkup::Release"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkup, IsValid)
	{
		try
		{
			CMarkup* self;
			self = static_cast<CMarkup*>(LuaStatic::CheckUserData(l, 1));
			lua_pushboolean(l, self->IsValid() ? 1 : 0);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkup::IsValid"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkup, SetPreserveWhitespace)
	{
		try
		{
			CMarkup* self;
			self = static_cast<CMarkup*>(LuaStatic::CheckUserData(l, 1));
			self->SetPreserveWhitespace(lua_toboolean(l, 2) != 0);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkup::SetPreserveWhitespace"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkup, GetLastErrorMessage)
	{
		try
		{
			CMarkup* self;
			self = static_cast<CMarkup*>(LuaStatic::CheckUserData(l, 1));

			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkup::GetLastErrorMessage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkup, GetLastErrorLocation)
	{
		try
		{
			CMarkup* self;
			self = static_cast<CMarkup*>(LuaStatic::CheckUserData(l, 1));

			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkup::GetLastErrorLocation"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkup, GetRoot)
	{
		try
		{
			CMarkup* self;
			self = static_cast<CMarkup*>(LuaStatic::CheckUserData(l, 1));
			CMarkupNode node = self->GetRoot();
			LuaStatic::AddObject2Lua(l, &node, METATABLE_NAME(&node));
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkup::GetRoot"));
			return 0;
		}
	}

	LUA_CLASS_REG_IMPL(CMarkup)
	{
		lua_newtable(l);
		static LuaReg StaticFuncs[] =
		{
			{ "New", New },
			{ "GetClassName", GetClassName },
		};
		LuaStatic::LuaSetFuncsInTable(l, StaticFuncs, sizeof(StaticFuncs) / sizeof(StaticFuncs[0]));
		lua_setfield(l, -2, "Markup");

		luaL_newmetatable(l, "CMarkup");
		
		lua_pushvalue(l, -1);
		lua_setfield(l, -2, "__index");
		static LuaReg MethodFuncs[] =
		{
			{ "isnil",isnil },
			{ "__eq",_eq },
			{ "__gc",_gc },
			{ "__tostring", _tostring },
			{ "Delete",Delete},
			{ "GetClass", GetClass },
			{ "Load", Load },
			{ "LoadFromMem", LoadFromMem },
			{ "LoadFromFile", LoadFromFile },
			{ "Release", Release },
			{ "IsValid", IsValid },
			{ "SetPreserveWhitespace", SetPreserveWhitespace },
			{ "GetLastErrorMessage", GetLastErrorMessage },
			{ "GetLastErrorLocation", GetLastErrorLocation },
			{ "GetRoot", GetRoot },
		};

		LuaStatic::LuaSetFuncsInTable(l, MethodFuncs, sizeof(MethodFuncs) / sizeof(MethodFuncs[0]));
		
		lua_pop(l, 1);
	}
};

namespace DuiLib
{
	LUA_METHOD_IMPL(CMarkupNode, isnil)
	{
		CMarkupNode* self;
		self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));

		lua_pushboolean(l, self == NULL ? 1 : 0);
		return 1;
	}
	LUA_METHOD_IMPL(CMarkupNode, _gc)
	{	
		CMarkupNode* self;
		self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
		LuaStatic::RemoveObjectInLua(l);
		SafeDelete(self);
		return 0;
	}
	LUA_METHOD_IMPL(CMarkupNode, _eq)
	{
		try
		{
			CMarkupNode* left;
			left = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));

			CMarkupNode* right;
			right = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 2));

			lua_pushboolean(l, left == right ? 1 : 0);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::_eq"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, _tostring)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			if (self)
			{
				CDuiString str = CDuiString::FormatString(_T("%s(addr:%p)"), self->GetClass(), (void*)self);
				lua_pushstring(l, str.GetAString().c_str());
			}
			else
			{
				CDuiString str = CDuiString::FormatString(_T("%s(addr:%s)"), "MarkupNode", "nil");
				lua_pushstring(l, str.GetAString().c_str());
			}
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::_tostring"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, Delete)
	{
		CMarkupNode* self;
		self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
		LuaStatic::RemoveObjectInLua(l);
		SafeDelete(self);
		return 0;
	}
	LUA_METHOD_IMPL(CMarkupNode, GetClassName)
	{
		CDuiString pstrText = CMarkupNode::GetClassName();
		lua_op_t<CDuiString>::push_stack(l, pstrText);
		return 1;
	}

	LUA_METHOD_IMPL(CMarkupNode, GetClass)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText = self->GetClass();
			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::GetClass"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, GetParent)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			CMarkupNode parent = self->GetParent();
			LuaStatic::AddObject2Lua(l, &parent, METATABLE_NAME(&parent));
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::GetParent"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, GetSibling)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			CMarkupNode sibling = self->GetSibling();
			LuaStatic::AddObject2Lua(l, &sibling, METATABLE_NAME(&sibling));
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::GetSibling"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, GetChild)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			if(lua_isstring(l,2))
			{
				CDuiString pstrText;
				lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);

				CMarkupNode child = self->GetChild(pstrText);
				LuaStatic::AddObject2Lua(l, &child, METATABLE_NAME(&child));
			}
			else
			{
				CMarkupNode child = self->GetChild();
				LuaStatic::AddObject2Lua(l, &child, METATABLE_NAME(&child));
			}
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::GetChild"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, HasSiblings)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			lua_pushboolean(l,self->HasSiblings() ? 1 :0);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::HasSiblings"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, HasChildren)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			lua_pushboolean(l,self->HasChildren() ? 1 :0);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::HasChildren"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, GetName)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText = self->GetName();
			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::GetName"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, GetValue)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText = self->GetValue();
			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::GetValue"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, HasAttributes)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			lua_pushboolean(l,self->HasAttributes() ? 1 :0);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::HasAttributes"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, HasAttribute)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);
			lua_pushboolean(l, self->HasAttribute(pstrText) ? 1 : 0);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::HasAttribute"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, GetAttributeCount)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			lua_pushinteger(l,self->GetAttributeCount());
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::GetAttributeCount"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, GetAttributeName)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			int iIndex = lua_tointeger(l,2);
			CDuiString pstrText = self->GetAttributeName(iIndex);
			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::GetAttributeName"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, GetAttributeValue1)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			int iIndex = lua_tointeger(l,2);
			LPCTSTR pValStr = self->GetAttributeValue(iIndex);
			if(!pValStr)
			{ lua_pushnil(l); return 1; }
			CDuiString pstrText(pValStr);
			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::GetAttributeValue1"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, GetAttributeValue2)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);
			LPCTSTR pValStr = self->GetAttributeValue(pstrText);
			if(!pValStr)
			{ lua_pushnil(l); return 1; }
			CDuiString pstrText2(pValStr);
			lua_op_t<CDuiString>::push_stack(l, pstrText2);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::GetAttributeValue2"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, GetAttributeValue3)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			int iIndex = lua_tointeger(l,2);
			LPCTSTR pValStr = self->GetAttributeValue(iIndex);
			if(!pValStr)
			{ 
				lua_pushboolean(l,0);
				lua_pushnil(l); 
				return 2; 
			}
			else
			{
				CDuiString pstrText(pValStr);
				lua_pushboolean(l,1);
				lua_op_t<CDuiString>::push_stack(l, pstrText);
				return 2;
			}
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::GetAttributeValue3"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CMarkupNode, GetAttributeValue4)
	{
		try
		{
			CMarkupNode* self;
			self = static_cast<CMarkupNode*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);
			LPCTSTR pValStr = self->GetAttributeValue(pstrText);
			if(!pValStr)
			{
				lua_pushboolean(l,0);
				lua_pushnil(l); 
				return 2; 
			}
			else
			{
				CDuiString pstrText(pValStr);
				lua_pushboolean(l,1);
				lua_op_t<CDuiString>::push_stack(l, pstrText);
				return 2;
			}
		}
		catch (...)
		{
			DuiException(_T("LuaCMarkupNode::GetAttributeValue4"));
			return 0;
		}
	}

	LUA_CLASS_REG_IMPL(CMarkupNode)
	{
		lua_newtable(l);
		static LuaReg StaticFuncs[] =
		{
			{ "GetClassName", GetClassName },
		};
		LuaStatic::LuaSetFuncsInTable(l, StaticFuncs, sizeof(StaticFuncs) / sizeof(StaticFuncs[0]));
		lua_setfield(l, -2, "MarkupNode");

		luaL_newmetatable(l, "CMarkupNode");
		
		lua_pushvalue(l, -1);
		lua_setfield(l, -2, "__index");
		static LuaReg MethodFuncs[] =
		{
			{ "isnil",isnil },
			{ "__eq",_eq },
			{ "__gc",_gc },
			{ "__tostring", _tostring },
			{ "Delete",Delete},
			{ "GetClass", GetClass },
			{ "GetParent", GetParent },
			{ "GetSibling", GetSibling },
			{ "GetChild", GetChild },
			{ "HasSiblings", HasSiblings },
			{ "HasChildren", HasChildren },
			{ "GetName", GetName },
			{ "GetValue", GetValue },
			{ "HasAttributes", HasAttributes },
			{ "HasAttribute", HasAttribute },
			{ "GetAttributeCount", GetAttributeCount },
			{ "GetAttributeName", GetAttributeName },
			{ "GetAttributeValue1", GetAttributeValue1 },
			{ "GetAttributeValue2", GetAttributeValue2 },
			{ "GetAttributeValue3", GetAttributeValue3 },
			{ "GetAttributeValue4", GetAttributeValue4 },
		};

		LuaStatic::LuaSetFuncsInTable(l, MethodFuncs, sizeof(MethodFuncs) / sizeof(MethodFuncs[0]));
		
		lua_pop(l, 1);
	}
}