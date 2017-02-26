require "ui_define"

local module_table_ = 
{
    { name = "logic_api_provider" },
    { name = "view_api_provider" }    
}

-- init all lua modules here.
function init_modules()
    
    cclog("[module_manager::init_modules] begin")
    
    -- require all module files except ui module
    for i, v in pairs(module_table_) do
        require(v.name)
        cclog("[module_manager::init_modules] require lua file of module : " .. v.name)
    end

    -- require all ui files
    for i, v in pairs(g_ui_table_) do
        require(v.name)
        cclog("[module_manager::init_modules] require lua file of ui : " .. v.name)
    end

    --g_view_api.add_ui_by_name(g_ui_table_[1].name)

    cclog("[module_manager::init_modules] end")

end