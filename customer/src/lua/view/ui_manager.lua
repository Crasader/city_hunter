--[[
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  ui_manager.lua
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-04-05
  @ description:  manager the enter, update and exit of ui. etc.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
]]--

local ui_table_ =
{
    { id        = "login", 
      path      = "res/ui/ui_login/ui_login.ExportJson", 
      on_enter  = on_ui_login_enter, 
      on_update = on_ui_login_update, 
      on_exit   = on_ui_login_exit 
    }
}