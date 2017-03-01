/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  graph_algorithms_test_scene.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-09-18
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "graph_algorithms_test_scene.h"

#include "cocos/2d/CCSprite.h"

#include "macros.h"
#include "utils_graph.h"

namespace gamer
{
    
GraphAlgorithmsTestScene::~GraphAlgorithmsTestScene()
{
    SAFE_DELETE(sparse_graph_);
}

cocos2d::Scene* GraphAlgorithmsTestScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = cocos2d::Scene::create();

    // 'layer' is an autorelease object
    GraphAlgorithmsTestScene *layer = GraphAlgorithmsTestScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool GraphAlgorithmsTestScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    initVars();
    
    // buttons of source, target, obstacle
    initButtons();

    // image positions of source, target, obstacle
    initPositions();

    // touch event listeners
    initTouchEventListeners();

    initDrawPathLayer();

    initGraphAlgorithms();

    drawTerrain();

    return true;
}

void GraphAlgorithmsTestScene::drawTerrain()
{
    drawGrids();
}

void GraphAlgorithmsTestScene::drawGrids()
{
    // horizontal
    cocos2d::DrawNode* draw_node = cocos2d::DrawNode::create();
    this->addChild(draw_node);

    auto win_size = cocos2d::Director::getInstance()->getWinSize();

    cocos2d::Vec2 from = cocos2d::Vec2(offset_x_, offset_y_);
    cocos2d::Vec2 to = cocos2d::Vec2(win_size.width - offset_x_, offset_y_);

    for (int i = 0; i < num_cells_y_; i++)
    {
        from.y = offset_y_ + i * cell_width_;
        to.y   = from.y;

        draw_node->drawLine(from, to, cocos2d::Color4F::BLUE);
    }

    // vertical
    from = cocos2d::Vec2(offset_x_, offset_y_);
    to = cocos2d::Vec2(offset_x_, win_size.height - offset_y_);
    //
    for (int i = 0; i < num_cells_x_; i++)
    {
        from.x = offset_x_ + i * cell_width_;
        to.x   = from.x;

        draw_node->drawLine(from, to, cocos2d::Color4F::BLUE);
    }
}

void GraphAlgorithmsTestScene::drawPath()
{
    if (!path_.empty())
    {
        draw_node_->clear();

        auto it = path_.begin();
        auto next = it; ++next;

        for (; next != path_.end(); ++it, ++next)
        {
            draw_node_->drawLine(sparse_graph_->getNode(*it).position(), 
                                 sparse_graph_->getNode(*next).position(), 
                                 cocos2d::Color4F::GREEN);
        }
    }
}

void GraphAlgorithmsTestScene::drawPathOfAStarAlgorithms()
{
    path_.clear();
    //astar_->set_source(source_);
    //astar_->set_target(target_);
    //astar_->search();
    AStarSearch astar(*sparse_graph_, source_, target_);
    path_ = astar.getPathToTarget();
    drawPath();
}

void GraphAlgorithmsTestScene::initVars()
{
    touched_btn_type_ = TouchedButtonTypes::BTN_UNKNOWN;

    auto origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    offset_x_ = origin.x + 100; 
    offset_y_ = origin.y + 100;

    cell_width_  = 20;
    cell_height_ = 20;

    num_cells_x_ = 48; 
    num_cells_y_ = 23;
}

void GraphAlgorithmsTestScene::initButtons()
{
    // btn source 
    cocos2d::ui::Button* btn_source = cocos2d::ui::Button::create("icon/rectangle_80x80_source.png");
    this->addChild(btn_source);

    auto win_size = cocos2d::Director::getInstance()->getWinSize();
    auto origin   = cocos2d::Director::getInstance()->getVisibleOrigin();
    
    float x = origin.x + win_size.width - btn_source->getContentSize().width / 2;
    float y = origin.y + btn_source->getContentSize().height / 2;
    btn_source->setPosition(cocos2d::Point(x, y));

    btn_source->addTouchEventListener(CC_CALLBACK_2(GraphAlgorithmsTestScene::onBtnSourceTouch, this));

    // btn target 
    cocos2d::ui::Button* btn_target = cocos2d::ui::Button::create("icon/rectangle_80x80_target.png");
    this->addChild(btn_target);

    x = origin.x + win_size.width - btn_source->getContentSize().width / 2 - btn_source->getContentSize().width - 10;
    y = origin.y + btn_target->getContentSize().height / 2;
    btn_target->setPosition(cocos2d::Point(x, y));

    btn_target->addTouchEventListener(CC_CALLBACK_2(GraphAlgorithmsTestScene::onBtnTargetTouch, this));

    // btn obstacle
    cocos2d::ui::Button* btn_obstacle = cocos2d::ui::Button::create("icon/rectangle_80x80_obstacle.png");
    this->addChild(btn_obstacle);

    x = origin.x + win_size.width - btn_obstacle->getContentSize().width / 2 - 2 * btn_source->getContentSize().width - 20;
    y = origin.y + btn_obstacle->getContentSize().height / 2;
    btn_obstacle->setPosition(cocos2d::Point(x, y));

    btn_obstacle->addTouchEventListener(CC_CALLBACK_2(GraphAlgorithmsTestScene::onBtnObstacleTouch, this));

    // btn astar
    cocos2d::ui::Button* btn_astar = cocos2d::ui::Button::create("icon/rectangle_80x80_blue.png");
    this->addChild(btn_astar);

    x = origin.x + btn_astar->getContentSize().width / 2;
    y = origin.y + btn_astar->getContentSize().height / 2;
    btn_astar->setPosition(cocos2d::Point(x, y));

    btn_astar->setTitleText("A*");
    btn_astar->setTitleFontSize(30);

    btn_astar->addTouchEventListener(CC_CALLBACK_2(GraphAlgorithmsTestScene::onBtnAStarTouch, this));
}

void GraphAlgorithmsTestScene::initPositions()
{
    // load img of source, target, obstacle, then add to scene
    image_red_source_ = cocos2d::ui::ImageView::create("icon/rectangle_10x10_red.png");
    image_purple_target_ = cocos2d::ui::ImageView::create("icon/rectangle_10x10_purple.png"); 
    image_gray_obstacle_ = cocos2d::ui::ImageView::create("icon/rectangle_10x10_gray.png");
    //image_gray_obstacle_->setName("rectangle_10x10_gray.png");

    this->addChild(image_purple_target_);
    this->addChild(image_red_source_);
    this->addChild(image_gray_obstacle_);

    //image_red_source_->setVisible(false);
    //image_purple_target_->setVisible(false);
    image_gray_obstacle_->setVisible(false);
    
    // init pos of source, target, obstacle
    auto win_size = cocos2d::Director::getInstance()->getWinSize();
    auto origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    float center_x = offset_x_ + cell_width_ * (num_cells_x_ - 1) / 2;
    float center_y = offset_y_ + cell_width_ * (num_cells_y_ - 1) / 2;
    float top_center_y    = center_y + cell_width_ * (num_cells_y_ - 1) / 2;
    float bottom_center_y = center_y - cell_width_ * (num_cells_y_ - 1) / 2;
    auto top_center    = cocos2d::Point(center_x, top_center_y);
    auto bottom_center = cocos2d::Point(center_x, bottom_center_y);

    auto source_pos = cocos2d::Point(center_x, top_center.y - image_red_source_->getContentSize().height / 2);
    auto target_pos = cocos2d::Point(center_x, bottom_center.y + image_purple_target_->getContentSize().height / 2);

    image_red_source_->setPosition(source_pos);
    image_purple_target_->setPosition(target_pos);

    // init source node index and target node index
    source_ = this->getNodeByPos(source_pos);
    target_ = this->getNodeByPos(target_pos);
}

void GraphAlgorithmsTestScene::initTouchEventListeners()
{
    auto listener = cocos2d::EventListenerTouchOneByOne::create();

    listener->onTouchBegan = CC_CALLBACK_2(GraphAlgorithmsTestScene::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(GraphAlgorithmsTestScene::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    // key press event listener
    //auto listener2 = cocos2d::EventListenerMouse::create();
    //listener2->onMouseUp = [&](cocos2d::Event* event){ onMouseUp(event); };
    //    //CC_CALLBACK_2(GraphAlgorithmsTestScene::onMouseUp, this);
    //this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, this);
    //event_listener_mouse_ = listener2;
}

void GraphAlgorithmsTestScene::initDrawPathLayer()
{
    draw_path_layer_ = cocos2d::Layer::create();
    this->addChild(draw_path_layer_);

    draw_node_ = cocos2d::DrawNode::create();
    draw_path_layer_->addChild(draw_node_);
}

void GraphAlgorithmsTestScene::initGraphAlgorithms()
{
    sparse_graph_ = new SparseGraph3D(false);
    //AStarSearch astar(*sparse_graph_, source_, target_);

    // create all the nodes
    for (int row = 0; row < num_cells_y_ - 1; row++)
    {
        for (int col = 0; col < num_cells_x_ - 1; col++)
        {
            cocos2d::Vec2 pos(offset_x_ + col * cell_width_ + cell_width_ / 2, 
                              offset_y_ + row * cell_height_ + cell_height_ / 2);
            sparse_graph_->addNode(graph::NavGraphNode<cocos2d::Vec2>(
                                   sparse_graph_->getNextFreeNodeIndex(),
                                   //cocos2d::Vec2(col, row)));
                                   pos));

        }
    }

    // create all the edges
    for (int row = 0; row < num_cells_y_ - 1; row++)
    {
        for (int col = 0; col < num_cells_x_ - 1; col++)
        {
            //auto pos = cocos2d::Vec3();
            gamer::utils_graph::addAllEdgesToNode(*sparse_graph_,
                                                  //pos,
                                                  row, 
                                                  col, 
                                                  num_cells_x_ - 1, 
                                                  num_cells_y_ - 1);
        }
    }

    //astar_ = new AStarSearch(*sparse_graph_, source_, target_);
    //path_ = astar_->getPathToTarget();
}

bool GraphAlgorithmsTestScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    cocos2d::log("[GraphAlgorithmsTestScene::onTouchBegan]");

    //cocos2d::Point touch_point = touch->getLocationInView();
    //touch_point = cocos2d::Director::getInstance()->convertToGL(touch_point); 

    //if (!isTouchValid(touch_point))
    //    return false;

    return true;
}

void GraphAlgorithmsTestScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
    cocos2d::log("[GraphAlgorithmsTestScene::onTouchMoved]");
}

void GraphAlgorithmsTestScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
    cocos2d::log("[GraphAlgorithmsTestScene::onTouchEnded]");

    if (TouchedButtonTypes::BTN_UNKNOWN == touched_btn_type_)
    {
        cocos2d::log("[GraphAlgorithmsTestScene::onTouchEnded] TouchedButtonTypes::BTN_UNKNOWN == touched_btn_type_");
        return;
    }

    cocos2d::Point touch_point = touch->getLocationInView();
    touch_point = cocos2d::Director::getInstance()->convertToGL(touch_point); 

    if (!isTouchValid(touch_point))
        return;

    cocos2d::log("[GraphAlgorithmsTestScene::onTouchEnded] touch_point.x : %f", touch_point.x);
    cocos2d::log("[GraphAlgorithmsTestScene::onTouchEnded] touch_point.y : %f", touch_point.y);

    fixTouchedPoint(touch_point);

    cocos2d::log("[GraphAlgorithmsTestScene::onTouchEnded] affter fixed, touch_point.x : %f", touch_point.x);
    cocos2d::log("[GraphAlgorithmsTestScene::onTouchEnded] affter fixed, touch_point.y : %f", touch_point.y);

    //int index = getNodeByPos(touch_point);
    //cocos2d::log("[GraphAlgorithmsTestScene::onTouchEnded] index of touched node : %d", index);

    if (TouchedButtonTypes::BTN_SOURCE == touched_btn_type_)
    {
        image_red_source_->setPosition(touch_point);
        image_red_source_->setVisible(true);

        source_ = this->getNodeByPos(touch_point);

        drawPathOfAStarAlgorithms();
    }
    else if(TouchedButtonTypes::BTN_TARGET == touched_btn_type_)
    {
        image_purple_target_->setPosition(touch_point);
        image_purple_target_->setVisible(true);

        target_ = this->getNodeByPos(touch_point);

        drawPathOfAStarAlgorithms();
    }
    else if(TouchedButtonTypes::BTN_OBSTACLE == touched_btn_type_)
    {
        //image_gray_obstacle_->setPosition(touch_point);
        //image_gray_obstacle_->setVisible(true);
        auto img_obstacle = cocos2d::ui::ImageView::create("icon/rectangle_10x10_gray.png", 
                                                       cocos2d::ui::Widget::TextureResType::LOCAL);
        if (nullptr != img_obstacle)
        {
            this->addChild(img_obstacle);
            img_obstacle->setPosition(touch_point);
            img_obstacle->setVisible(true);
        }

        // remove the node from the graph
        sparse_graph_->removeNode(this->getNodeByPos(touch_point));

        drawPathOfAStarAlgorithms();
    }
}

void GraphAlgorithmsTestScene::onBtnSourceTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
    cocos2d::log("[GraphAlgorithmsTestScene::onBtnSourceTouch]");
    if (cocos2d::ui::Widget::TouchEventType::ENDED == type)
    {
        touched_btn_type_ = TouchedButtonTypes::BTN_SOURCE;
    }    
}

void GraphAlgorithmsTestScene::onBtnTargetTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
    cocos2d::log("[GraphAlgorithmsTestScene::onBtnTargetTouch]");
    if (cocos2d::ui::Widget::TouchEventType::ENDED == type)
    {
        touched_btn_type_ = TouchedButtonTypes::BTN_TARGET;
    } 
}

void GraphAlgorithmsTestScene::onBtnObstacleTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
    cocos2d::log("[GraphAlgorithmsTestScene::onBtnObstacleTouch]");
    if (cocos2d::ui::Widget::TouchEventType::ENDED == type)
    {
        touched_btn_type_ = TouchedButtonTypes::BTN_OBSTACLE;
    } 
}

void GraphAlgorithmsTestScene::onBtnAStarTouch( cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type )
{
    cocos2d::log("[GraphAlgorithmsTestScene::onBtnAStarTouch]");
    if (cocos2d::ui::Widget::TouchEventType::ENDED == type)
    {
        drawPathOfAStarAlgorithms();
    } 
}

bool GraphAlgorithmsTestScene::isTouchValid(const cocos2d::Point& pos) const
{
    //auto win_size = cocos2d::Director::getInstance()->getWinSize();
    //auto origin   = cocos2d::Director::getInstance()->getVisibleOrigin();

    if (pos.x >= offset_x_ && 
        pos.x <= offset_x_ + num_cells_x_ * cell_width_ &&
        pos.y >= offset_y_ &&
        pos.y <= offset_y_ + num_cells_y_ * cell_width_)
    {
        return true;
    }

    return false;
}

void GraphAlgorithmsTestScene::fixTouchedPoint(cocos2d::Point& pos)
{
    float interval = cell_width_;
    int nx = (int(pos.x - offset_x_)) / interval;
    int ny = (int(pos.y - offset_y_)) / interval;

    pos.x = offset_x_ + nx * interval + interval / 2;
    pos.y = offset_y_ + ny * interval + interval / 2;
}

int GraphAlgorithmsTestScene::getNodeByPos(const cocos2d::Point& pos)
{
    int index = 0;

    float x = pos.x - offset_x_;
    float y = pos.y - offset_y_;

    int nx = y / cell_width_;
    int ny = x / cell_width_;

    index = nx * (num_cells_x_ - 1) + ny;

    return index;
}

} // namespace gamer