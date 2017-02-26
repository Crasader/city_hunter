--[[
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  ui_login.lua
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-04-05
  @ description:  ui for user login.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
--]]

local function on_btn_close_touch(sender, event_type)
    if event_type == ccui.TouchEventType.ended then
        --self:unscheduleUpdate()
        cclog("[ui_login::on_btn_close_touch] touch ended");
    end
end

local function init_ui(cur_scene)

    cclog("[ui_login::init_ui] begin")
    
    local guireader = ccs.GUIReader:getInstance()
    local widget_main = guireader:widgetFromJsonFile(g_ui_table[1].path)

    if nil == widget_main then
        cclog_err("[ui_login::init_ui] nil == widget_main")
        return
    end

    local layer = cc.Layer:create()
    layer:addChild(widget_main)
    
    cur_scene = tolua.cast(cur_scene, "cc.Node")
    cur_scene:addChild(layer)

    local visible_size   = cc.Director:getInstance():getVisibleSize()
    local visible_origin = cc.Director:getInstance():getVisibleOrigin()   
    cclog("[ui_login::init_ui] visible_origin.x : %d, visible_origin.y : %d", visible_origin.x, visible_origin.y)
    cclog("[ui_login::init_ui] visible_size.width : %d, visible_size.height : %d", visible_size.width, visible_size.height)

    widget_main:setContentSize(visible_size)
    widget_main:setAnchorPoint(cc.p(0.5, 0.5))
    widget_main:setPosition(cc.p(visible_origin.x + visible_size.width / 2, 
                                 visible_origin.y + visible_size.height / 2))
                  
   local panel_root = widget_main:getChildByName("Panel")
   local panel_bg = widget_main:getChildByName("Panel_bg")

    panel_bg = tolua.cast(panel_bg, "cc.Node")
    panel_bg:setContentSize(visible_size)
    panel_bg:setAnchorPoint(cc.p(0.5, 0.5))
    panel_bg:setPosition(cc.p(visible_origin.x + visible_size.width / 2  + widget_main:getPositionX(), 
                              visible_origin.y + visible_size.height / 2 + widget_main:getPositionY()))

    local btn_close = panel_bg:getChildByName("Button_close")
    btn_close:setTouchEnabled(true)
    btn_close:addTouchEventListener(on_btn_close_touch)
    
    cclog("[ui_login::init_ui] end")

end

local function on_ui_login_enter(cur_scene)
    
    cclog("[ui_login::on_ui_login_enter] begin")

    if nil == cur_scene then
        cclog_err("[ui_login::on_ui_login_enter] nil == cur_scene")
        return
    end

    init_ui(cur_scene)

    cclog("[ui_login::on_ui_login_enter] end")

end

local function on_ui_login_update(cur_scene)

    cclog("[ui_login::on_ui_login_enter] begin")
    cclog("[ui_login::on_ui_login_enter] end")

end

local function on_ui_login_exit(cur_scene)

    cclog("[ui_login::on_ui_login_enter] begin")
    cclog("[ui_login::on_ui_login_enter] end")

end

local function init()

    cclog("[ui_login::init] begin")

    g_view_api_.add_ui_callback(g_ui_table_[1].name, 
                                on_ui_login_enter, 
                                on_ui_login_update, 
                                on_ui_login_exit)

    cclog("[ui_login::init] end")

end

init()