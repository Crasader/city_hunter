/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  graph_algorithms_test_scene.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-09-18
  @ description:  scene for testing graph algorithms.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_GRAPH_ALGORITHMS_TEST_SCENE_H_
#define CITY_HUNTER_SRC_GRAPH_ALGORITHMS_TEST_SCENE_H_

#include "cocos2d.h"
#include "cocos/editor-support/cocostudio/CocoStudio.h"
#include "cocos/ui/CocosGUI.h"

#include "a_star_heuristic_policies.h"
#include "graph.h"
#include "graph_algorithms.h"
#include "graph_edge.h"
#include "graph_node.h"

namespace gamer
{

class GraphAlgorithmsTestScene : public cocos2d::Layer
{
public:
    ~GraphAlgorithmsTestScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init() override;  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // implement the "static node()" method manually
    CREATE_FUNC(GraphAlgorithmsTestScene);

    void drawTerrain();

private:
    typedef graph::SparseGraph<graph::NavGraphNode<cocos2d::Vec2>, graph::NavGraphEdge> SparseGraph3D;
    typedef graph::AStar<SparseGraph3D, graph::HeuristicEuclid> AStarSearch;

    enum TouchedButtonTypes
    {
        BTN_UNKNOWN,
        BTN_SOURCE,
        BTN_TARGET,
        BTN_OBSTACLE
    };

    GraphAlgorithmsTestScene() {};

    void initVars();

    // buttons of source, target, obstacle, astar
    void initButtons();

    // positions of source, target, obstacle
    void initPositions();

    void initTouchEventListeners();

    void initDrawPathLayer();

    void initGraphAlgorithms();

    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event); 

    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event); 

    void onBtnSourceTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

    void onBtnTargetTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

    void onBtnObstacleTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

    void onBtnAStarTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

    void drawGrids();

    void drawPath();

    void drawPathOfAStarAlgorithms();

    bool isTouchValid(const cocos2d::Point& pos) const;

    void fixTouchedPoint(cocos2d::Point& pos);

    int getNodeByPos(const cocos2d::Point& pos);

    float offset_x_; 
    float offset_y_;
    int cell_width_;
    int cell_height_;
    int num_cells_x_;
    int num_cells_y_; 

    TouchedButtonTypes touched_btn_type_;

    cocos2d::EventListenerMouse* event_listener_mouse_;

    cocos2d::ui::ImageView* image_purple_target_;  // target   
    cocos2d::ui::ImageView* image_red_source_;     // source
    cocos2d::ui::ImageView* image_gray_obstacle_;  // obstacle
    
    cocos2d::DrawNode* draw_node_;

    cocos2d::Layer* draw_path_layer_;

    SparseGraph3D* sparse_graph_;

    AStarSearch* astar_;

    int source_;
    int target_;

    std::list<int> path_; // nodes index
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_GRAPH_ALGORITHMS_TEST_SCENE_H_
