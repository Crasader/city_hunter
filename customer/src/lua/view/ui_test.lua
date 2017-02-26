--[[
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  ui_test.lua
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-01-17
  @ description:  ui for testing entry.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
--]]

local function init_ui(cur_scene)

    cclog("[ui_test::init_ui] begin")
    
    
    cclog("[ui_test::init_ui] end")

end

local function on_ui_test_enter(cur_scene)
    
    cclog("[ui_test::on_ui_test_enter] begin")

    if nil == cur_scene then
        cclog_err("[ui_test::on_ui_test_enter] nil == cur_scene")
        return
    end

    init_ui(cur_scene)

    cclog("[ui_test::on_ui_test_enter] end")

end

local function on_ui_test_update(cur_scene)

    cclog("[ui_test::on_ui_test_enter] begin")
    cclog("[ui_test::on_ui_test_enter] end")

end

local function on_ui_test_exit(cur_scene)

    cclog("[ui_test::on_ui_test_enter] begin")
    cclog("[ui_test::on_ui_test_enter] end")

end

local function init()

    cclog("[ui_test::init] begin")

    g_view_api_.add_ui_callback(g_ui_table_[1].name, 
                                on_ui_test_enter, 
                                on_ui_test_update, 
                                on_ui_test_exit)

    cclog("[ui_test::init] end")

end

init()