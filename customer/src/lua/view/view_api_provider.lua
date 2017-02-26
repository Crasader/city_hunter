--[[
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  view_api_provider.lua
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-03-22
  @ description:  offer global api to deal with ui.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
]]--

-- declare all view api(s) here.
g_view_api_ = 
{
    add_ui_by_name     = nil,
    remove_ui_by_name  = nil,
    add_ui_callback    = nil,
}

-- store all ui modules and their callback functions.
local ui_table_ =
{
    --[[
    { 
      name      = "",  -- name is id
      on_enter  = nil, 
      on_update = nil, 
      on_exit   = nil 
    }
    ]]
}

local function add_ui_by_name(ui_name)

    cclog("[view_api_provider::add_ui_by_name] begin")
    
    if nil == ui_name then
        cclog_err("[view_api_provider::add_ui_by_name] nil == ui_name")
        return
    end

    for i, v in pairs(ui_table_) do
        if ui_name == v.name then
            if nil ~= v.on_enter then    
                local scene = gamer.SceneManager:getInstance():getRunningScene()  
                if nil == scene then
                    cclog_err("[view_api_provider::add_ui_by_name] nil == scene")
                    return
                end  
                --scene = tolua.cast(scene, "cc.Node")     
                v.on_enter(scene)
            end
            break
        end
    end

    cclog("[view_api_provider::add_ui_by_name] end")

end

local function remove_ui_by_name(ui_name)

    cclog("[view_api_provider::remove_ui_by_name] begin")

    if nil == ui_name then
        cclog_err("[view_api_provider::remove_ui_by_name] nil == ui_name")
        return
    end

    for i, v in pairs(ui_table_) do
        if ui_name == v.name then
            if nil ~= v.on_exit then
                local scene = gamer.SceneManager:getInstance():getRunningScene()  
                if nil == scene then
                    cclog_err("[view_api_provider::remove_ui_by_name] nil == scene")
                    return
                end 
                v.on_exit(scene)
            end
            break
        end
    end

    cclog("[view_api_provider::remove_ui_by_name] end")

end

local function add_ui_callback(ui_name, on_enter, on_update, on_exit)

    cclog("[view_api_provider::add_ui_callback] begin")

    if nil == ui_name or 
       nil == on_enter or 
       nil == on_update or 
       nil == on_exit then
        cclog_err("[view_api_provider::add_ui_callback] one or more arg is invalid!")
        return
    end

    table.insert(ui_table_, 
                 { 
                    name      = ui_name, 
                    on_enter  = on_enter, 
                    on_update = on_update, 
                    on_exit   = on_exit 
                 })

    cclog("[view_api_provider::add_ui_callback] end")

end

local function init()

    cclog("[view_api_provider::init] begin")
    
    g_view_api_.add_ui_by_name       = add_ui_by_name
    g_view_api_.remove_ui_by_name    = remove_ui_by_name
    g_view_api_.add_ui_callback      = add_ui_callback

    cclog("[view_api_provider::init] end")

end

init()