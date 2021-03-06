local Lplus = require "Lplus"
local IBaseWindow = require "IBaseWindow"

local MainFrame = Lplus.Extend(IBaseWindow,"MainFrame")
local def = MainFrame.define
def.field("number").mTimerId = 0

def.static(IBaseWindow,"=>",MainFrame).new = function(parent)
	print("new")
	local obj = MainFrame()
	obj.m_parent = parent
	return obj
end

def.override("=>","string").WindowClass = function(self)
	return "MainFrame"
end
def.override("=>","string").WindowName = function(self)
	return "TestDemo"
end

def.override("=>","table").WindowInitPos = function(self)
	return nil
end
def.override("=>","string").SkinFile = function(self)
	return "xml/main_frame.xml"
end
def.method("=>","string").GetSkinPath = function(self)
	return DuiLib.PaintManagerUI.GetInstancePath()
end
def.method("=>","string").GetSkinFolder = function(self)
	return "assets"
end
def.method("=>","string").GetZIPFileName = function(self)
	return ""
end
def.method("=>","string").GetResourceID = function(self)
	return ""
end
def.method("=>","number").GetResourceType = function(self)
	return DuiLib.UILIB_RESOURCETYPE.UILIB_FILE
end

def.override().MsgTableExtend = function(self)
	local msgt = self.m_msgTable
	msgt.GetItemText = self:tryget("GetItemText")
end
def.method("dynamic","dynamic").OnSysCommand = function(self,wParam,lParam)
end
def.method("number","dynamic","dynamic").ProcessWindowMessage = function(self,uMsgId,wParam,lParam)
	local MsgArgs = DuiLib.MsgArgs
	if uMsgId == MsgArgs.WM_USER + 2500 then
		self:OnAddListItem(wParam,lParam)
	elseif uMsgId == MsgArgs.WM_TIMER then
		self:OnTimer(wParam,lParam);
	elseif uMsgId == MsgArgs.WM_QUIT then
		print("WM_QUIT")
	elseif uMsgId == MsgArgs.WM_KEYDOWN then
		if wParam == 27 then
			self.m_hWin:Close()
		end
	end
end

def.method("userdata","number","number").GetItemText = function(self,pControl,iIndex,iSubItem)
	local szBuf = ""
    if iSubItem == 0 then
    	szBuf = "" .. iIndex
    elseif iSubItem ==  1 then
    	szBuf = "" .. "www.baidu.com"
    else
    	szBuf = "" .. "中国&China"
    end
    pControl:SetUserData(szBuf);
end
local index = 0
local pList = nil
def.method("dynamic","dynamic").OnAddListItem = function(self,wParam,lParam)
	local win = self.m_hWin
	local pListElement = win:ControlFromPtr(lParam)
	if not pList then
		pList = win:FindControl("domainlist")
	end
	print(index,pListElement,pList,lParam,win)
	pList:Add(pListElement)
	pList:EndDown()
end

def.method("dynamic","dynamic").OnTimer = function(self,wParam,lParam)
	local win = self.m_hWin
	if wParam == 100 then
		if index <100 then
			local ListTextElementUI = DuiLib.ListTextElementUI
			local pControl = ListTextElementUI.New()
			pControl:SetTag(index)
			win:ListenUIDestroy(pControl)
			win:SendMessage(DuiLib.MsgArgs.WM_USER + 2500,0,pControl)
		else
			win:KillTimer(self.mTimerId)
			self.mTimerId = 0
			index = 0
			return
		end
		index = index + 1
	end
end

def.override("userdata").OnNotify = function(self,msg)
	local win = self.m_hWin
	local msgType = msg:getType()
	local sender = msg:getSender()
	if sender:isnil() then return end
	print("OnNotify",win,sender:GetName(),sender:GetClass(),msg:getType())
	if msg:isType("click") then
		if msg:isControl("closebtn") then
			win:MsgBox("确定退出吗？","警告",0x00000030,function(ret)
				if ret == 1 then
					win:Close()
				end
			end)
		elseif msg:isControl("maxbtn") then
			win:SendMessage(DuiLib.MsgArgs.WM_SYSCOMMAND, DuiLib.SC_MAXIMIZE, 0)
			return;
		elseif msg:isControl("minbtn") then
			win:SendMessage(DuiLib.MsgArgs.WM_SYSCOMMAND, DuiLib.SC_MINIMIZE, 0)
			return;
		elseif msg:isControl("btn") then
			self:OnSearch()
		end
	elseif msg:isType("windowinit") then
		print("windowinit")
		--local btn = win:FindControl("btn")
		--win:ListenUIEvent(btn)
	elseif msg:isType("itemactivate") then
		local iIndex = sender:GetTag()
		local sMessage = "Click: "
		DuiLib.MsgBox(win,sMessage .. iIndex,"提示(by ldf)",0)
	end
end

def.method().OnSearch = function(self)
	local win = self.m_hWin
	local pList = win:FindControl("domainlist")
	pList:RemoveAll()
	if self.mTimerId ~= 0 then
		win:KillTimer(self.mTimerId)
		self.mTimerId = 0
		return
	end

	win:SetListCallback(pList)
	-- for i=1,100 do
	-- 	local pControl = ListTextElementUI.New()
	-- 	pControl:SetTag(i)
	-- 	win:PostMessage(1724,0,pControl)
	-- end
	index = 0
	self.mTimerId = win:SetTimer(100,1)
end


MainFrame.Commit()

return MainFrame
