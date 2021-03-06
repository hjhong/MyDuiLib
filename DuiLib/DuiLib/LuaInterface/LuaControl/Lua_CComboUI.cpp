#include "LuaEntry.h"

#include REQUIRE_H(CComboUI)

namespace DuiLib
{
	LUA_METHOD_IMPL(CComboUI, New)
	{
		CComboUI  *ctrl = new CComboUI();
		LuaStatic::AddObject2Lua(l, ctrl, METATABLE_NAME(ctrl));
		return 1;
	}

	LUA_METHOD_IMPL(CComboUI, GetClassName)
	{
		CDuiString pstrText = CComboUI::GetClassName();
		
		lua_op_t<CDuiString>::push_stack(l, pstrText);
		return 1;
	}

	LUA_METHOD_IMPL(CComboUI, GetDropBoxAttributeList)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText = self->GetDropBoxAttributeList();

			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetDropBoxAttributeList"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetDropBoxAttributeList)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);
			self->SetDropBoxAttributeList(pstrText);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetDropBoxAttributeList"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetDropBoxSize)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			SIZE sz = self->GetDropBoxSize();

			LuaStatic::WriteSize2Lua(l, sz);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetDropBoxSize"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetDropBoxSize)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			SIZE sz = LuaStatic::ReadSizeFromLua(l,2);
			self->SetDropBoxSize(sz);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetDropBoxSize"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetCurSel)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			lua_pushinteger(l, (int)self->GetCurSel());
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetCurSel"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SelectItem)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			int iIndex = lua_tointeger(l,2);
			bool bTakeFocus = false;
			bool bSelected = true;
			if(!lua_isnone(l,3))
				bTakeFocus = lua_toboolean(l,3) != 0;
			if(!lua_isnone(l,4))
				bSelected = lua_toboolean(l,4) != 0;

			self->SelectItem(iIndex,bTakeFocus,bSelected);

			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SelectItem"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetMultiSelect)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			bool bMulti = lua_toboolean(l,2) != 0;

			self->SetMultiSelect(bMulti);

			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetMultiSelect"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, IsMultiSelected)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			lua_op_t<bool>::push_stack(l,self->IsMultiSelected());
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::IsMultiSelected"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetTextPadding)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));

			RECT rt = self->GetTextPadding();

			LuaStatic::WriteRect2Lua(l, rt);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetTextPadding"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetTextPadding)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));

			RECT rt = LuaStatic::ReadRectFromLua(l, 2);
			self->SetTextPadding(rt);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetTextPadding"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetNormalImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText = self->GetNormalImage();

			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetNormalImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetNormalImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);
			self->SetNormalImage(pstrText);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetNormalImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetHotImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText = self->GetHotImage();

			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetHotImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetHotImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);
			self->SetHotImage(pstrText);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetHotImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetPushedImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText = self->GetPushedImage();

			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetPushedImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetPushedImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);
			self->SetPushedImage(pstrText);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetPushedImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetFocusedImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText = self->GetFocusedImage();

			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetFocusedImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetFocusedImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);
			self->SetFocusedImage(pstrText);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetFocusedImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetDisabledImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText = self->GetDisabledImage();

			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetDisabledImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetDisabledImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);
			self->SetDisabledImage(pstrText);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetDisabledImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetListInfo)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			//TListInfoUI* pInfo = self->GetListInfo();
			//LuaStatic::AddObject2Lua(l,pInfo,METATABLE_NAME(pInfo));
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetListInfo"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetItemFont)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			int iFont = lua_tointeger(l,2);
			self->SetItemFont(iFont);

			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetItemFont"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetItemTextStyle)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			int iFont = lua_tointeger(l,2);
			self->SetItemTextStyle(iFont);

			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetItemTextStyle"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetItemTextPadding)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));

			RECT rt = self->GetItemTextPadding();

			LuaStatic::WriteRect2Lua(l, rt);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetItemTextPadding"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetItemTextPadding)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));

			RECT rt = LuaStatic::ReadRectFromLua(l, 2);
			self->SetItemTextPadding(rt);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetItemTextPadding"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetItemTextColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			
			DWORD dwBkCor = self->GetItemTextColor();
			
			LuaStatic::WriteRGBA2Lua(l, dwBkCor);

			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetItemTextColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetItemTextColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));

			DWORD dwBkCor = LuaStatic::ReadRGBAFromLua(l, 2);

			self->SetItemTextColor(dwBkCor);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetItemTextColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetItemBkColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			
			DWORD dwBkCor = self->GetItemBkColor();
			
			LuaStatic::WriteRGBA2Lua(l, dwBkCor);

			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetItemBkColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetItemBkColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));

			DWORD dwBkCor = LuaStatic::ReadRGBAFromLua(l, 2);

			self->SetItemBkColor(dwBkCor);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetItemBkColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetItemBkImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText = self->GetItemBkImage();

			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetItemBkImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetItemBkImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);
			self->SetItemBkImage(pstrText);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetItemBkImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, IsAlternateBk)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			lua_op_t<bool>::push_stack(l,self->IsAlternateBk());
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::IsAlternateBk"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetAlternateBk)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			bool bMulti = lua_toboolean(l, 2) != 0;

			self->SetAlternateBk(bMulti);

			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetAlternateBk"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetSelectedItemTextColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			
			DWORD dwBkCor = self->GetSelectedItemTextColor();
			
			LuaStatic::WriteRGBA2Lua(l, dwBkCor);

			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetSelectedItemTextColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetSelectedItemTextColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));

			DWORD dwBkCor = LuaStatic::ReadRGBAFromLua(l, 2);

			self->SetSelectedItemTextColor(dwBkCor);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetSelectedItemTextColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetSelectedItemBkColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			
			DWORD dwBkCor = self->GetSelectedItemBkColor();
			
			LuaStatic::WriteRGBA2Lua(l, dwBkCor);

			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetSelectedItemBkColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetSelectedItemBkColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));

			DWORD dwBkCor = LuaStatic::ReadRGBAFromLua(l, 2);

			self->SetSelectedItemBkColor(dwBkCor);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetSelectedItemBkColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetSelectedItemImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText = self->GetSelectedItemImage();

			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetSelectedItemImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetSelectedItemImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);
			self->SetSelectedItemImage(pstrText);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetSelectedItemImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetHotItemTextColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			
			DWORD dwBkCor = self->GetHotItemTextColor();
			
			LuaStatic::WriteRGBA2Lua(l, dwBkCor);

			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetHotItemTextColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetHotItemTextColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));

			DWORD dwBkCor = LuaStatic::ReadRGBAFromLua(l, 2);

			self->SetHotItemTextColor(dwBkCor);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetHotItemTextColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetHotItemBkColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			
			DWORD dwBkCor = self->GetHotItemBkColor();
			
			LuaStatic::WriteRGBA2Lua(l, dwBkCor);

			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetHotItemBkColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetHotItemBkColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));

			DWORD dwBkCor = LuaStatic::ReadRGBAFromLua(l, 2);

			self->SetHotItemBkColor(dwBkCor);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetHotItemBkColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetHotItemImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText = self->GetHotItemImage();

			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetHotItemImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetHotItemImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);
			self->SetHotItemImage(pstrText);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetHotItemImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetDisabledItemTextColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			
			DWORD dwBkCor = self->GetDisabledItemTextColor();
			
			LuaStatic::WriteRGBA2Lua(l, dwBkCor);

			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetDisabledItemTextColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetDisabledItemTextColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));

			DWORD dwBkCor = LuaStatic::ReadRGBAFromLua(l, 2);

			self->SetDisabledItemTextColor(dwBkCor);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetDisabledItemTextColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetDisabledItemBkColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			
			DWORD dwBkCor = self->GetDisabledItemBkColor();
			
			LuaStatic::WriteRGBA2Lua(l, dwBkCor);

			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetDisabledItemBkColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetDisabledItemBkColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));

			DWORD dwBkCor = LuaStatic::ReadRGBAFromLua(l, 2);

			self->SetDisabledItemBkColor(dwBkCor);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetDisabledItemBkColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetDisabledItemImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText = self->GetDisabledItemImage();

			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetDisabledItemImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetDisabledItemImage)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);
			self->SetDisabledItemImage(pstrText);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetDisabledItemImage"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, GetItemLineColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			
			DWORD dwBkCor = self->GetItemLineColor();
			
			LuaStatic::WriteRGBA2Lua(l, dwBkCor);

			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::GetItemLineColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetItemLineColor)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));

			DWORD dwBkCor = LuaStatic::ReadRGBAFromLua(l, 2);

			self->SetItemLineColor(dwBkCor);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetItemLineColor"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, IsItemShowHtml)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			lua_op_t<bool>::push_stack(l,self->IsItemShowHtml());
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::IsItemShowHtml"));
			return 0;
		}
	}
	LUA_METHOD_IMPL(CComboUI, SetItemShowHtml)
	{
		try
		{
			CComboUI* self;
			self = static_cast<CComboUI*>(LuaStatic::CheckUserData(l, 1));
			bool bMulti = lua_toboolean(l, 2) != 0;

			self->SetItemShowHtml(bMulti);

			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCComboUI::SetItemShowHtml"));
			return 0;
		}
	}

	LUA_CLASS_REG_IMPL(CComboUI)
	{
		lua_newtable(l);
		static LuaReg StaticFuncs[] =
		{
			{ "New", New },
			{ "GetClassName", GetClassName },
		};
		LuaStatic::LuaSetFuncsInTable(l, StaticFuncs, sizeof(StaticFuncs) / sizeof(StaticFuncs[0]));
		lua_setfield(l, -2, "ComboUI");

		luaL_newmetatable(l, "CComboUI");
		luaL_getmetatable(l, "CContainerUI");
		lua_setmetatable(l, -2);
		
		lua_pushvalue(l, -1);
		lua_setfield(l, -2, "__index");
		static LuaReg MethodFuncs[] =
		{
			{"GetDropBoxAttributeList", GetDropBoxAttributeList },
			{"SetDropBoxAttributeList", SetDropBoxAttributeList},
			{"GetDropBoxSize", GetDropBoxSize},
			{"SetDropBoxSize", SetDropBoxSize},
			{"GetCurSel", GetCurSel},
			{"SelectItem", SelectItem },
			{"SetMultiSelect", SetMultiSelect},
			{"IsMultiSelected", IsMultiSelected},
			{"GetTextPadding", GetTextPadding},
			{"SetTextPadding", SetTextPadding},
			{"GetNormalImage", GetNormalImage},
			{"SetNormalImage", SetNormalImage},
			{"GetHotImage", GetHotImage},
			{"SetHotImage", SetHotImage},
			{"GetPushedImage", GetPushedImage},
			{"SetPushedImage", SetPushedImage},
			{"GetFocusedImage", GetFocusedImage},
			{"SetFocusedImage", SetFocusedImage},
			{"GetDisabledImage", GetDisabledImage},
			{"SetDisabledImage", SetDisabledImage},
			{"GetListInfo", GetListInfo},
			{"SetItemFont", SetItemFont},
			{"SetItemTextStyle", SetItemTextStyle },
			{"GetItemTextPadding", GetItemTextPadding},
			{"SetItemTextPadding", SetItemTextPadding},
			{"GetItemTextColor", GetItemTextColor},
			{"SetItemTextColor", SetItemTextColor},
			{"GetItemBkColor", GetItemBkColor},
			{"SetItemBkColor", SetItemBkColor},
			{"SetItemBkImage", GetItemBkImage},
			{"IsAlternateBk", IsAlternateBk},
			{"SetAlternateBk", SetAlternateBk},
			{"GetSelectedItemTextColor", GetSelectedItemTextColor},
			{"SetSelectedItemTextColor", SetSelectedItemTextColor},
			{"GetSelectedItemBkColor", GetSelectedItemBkColor},
			{"SetSelectedItemBkColor", SetSelectedItemBkColor},
			{"GetSelectedItemImage", GetSelectedItemImage},
			{"SetSelectedItemImage", SetSelectedItemImage},
			{"GetHotItemTextColor", GetHotItemTextColor},
			{"SetHotItemTextColor", SetHotItemTextColor},
			{"GetHotItemBkColor", GetHotItemBkColor},
			{"SetHotItemBkColor", SetHotItemBkColor},
			{"GetHotItemImage", GetHotItemImage},
			{"SetHotItemImage", SetHotItemImage},
			{"GetDisabledItemTextColor", GetDisabledItemTextColor},
			{"SetDisabledItemTextColor", SetDisabledItemTextColor},
			{"GetDisabledItemBkColor", GetDisabledItemBkColor},
			{"SetDisabledItemBkColor", SetDisabledItemBkColor},
			{"GetDisabledItemImage", GetDisabledItemImage},
			{"SetDisabledItemImage", SetDisabledItemImage},
			{"GetItemLineColor", GetItemLineColor},
			{"SetItemLineColor", SetItemLineColor},
			{"IsItemShowHtml", IsItemShowHtml},
			{"SetItemShowHtml", SetItemShowHtml},
		};
		LuaStatic::LuaSetFuncsInTable(l, MethodFuncs, sizeof(MethodFuncs) / sizeof(MethodFuncs[0]));
		
		lua_pop(l, 1);
	}
}