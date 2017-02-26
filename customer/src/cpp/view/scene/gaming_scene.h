/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  gaming_scene.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-10-09
  @ description:  gaming scene.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_GAMING_SCENE_H_
#define CITY_HUNTER_SRC_GAMING_SCENE_H_

#include "cocos2d.h"
#include "cocos/editor-support/cocostudio/CocoStudio.h"
#include "cocos/ui/CocosGUI.h"
#include "cocos/3d/DrawNode3D.h"

#include "graph_typedef.h"
#include "path_finder.h"

namespace gamer
{

class Event;

class GamingScene : public cocos2d::Layer
{
public:
    ~GamingScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init() override;  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // implement the "static node()" method manually
    CREATE_FUNC(GamingScene);

    void drawTerrain();

    //static cocos2d::DrawNode3D* drawer() { return draw_node_; }

    //static cocos2d::DrawNode3D* draw_node_;

private:
    //typedef graph::NavGraphNode<cocos2d::Vec3> NavGraphNode3D;
    //typedef graph::SparseGraph<NavGraphNode3D, graph::NavGraphEdge> SparseGraph3D;
    //typedef graph::AStar<SparseGraph3D, graph::HeuristicEuclid> AStarSearch;

    enum TouchedButtonTypes
    {
        BTN_UNKNOWN,
        BTN_SOURCE,
        BTN_TARGET,
        BTN_OBSTACLE
    };

    GamingScene() {};

    void initVars();

    void initListeners();

    void initTouchEventListeners();

    void initDrawPathLayer();

    void initGraphAlgorithms();

    void initActors();

    void initCamera();

    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;

    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) override;

    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override;

    void onEventActorsCreated(gamer::Event* event);

    void drawGrids();

    void drawPath();

    void drawPathOfAStarAlgorithms();

    bool isTouchValid(const cocos2d::Point& pos) const;

    void fixTouchedPoint(cocos2d::Point& pos);

    //int getNodeIndexByPos(const cocos2d::Vec3& pos);

    void drawSpace();

    void addActorToSpace(ActorType* actor);

    friend class SceneManager;

    int cell_width_;
    int cell_height_;

    graph::Cell cell_;

    int num_cells_x_;
    int num_cells_y_; 
    int num_cells_z_; 

    graph::Size cells_num_;

    TouchedButtonTypes touched_btn_type_;

    cocos2d::EventListenerMouse* event_listener_mouse_;

    cocos2d::ui::ImageView* image_purple_target_;  // target   
    cocos2d::ui::ImageView* image_red_source_;     // source
    cocos2d::ui::ImageView* image_gray_obstacle_;  // obstacle

    //cocos2d::DrawNode* draw_node_;
    //cocos2d::DrawNode3D* draw_node_;

    cocos2d::Layer* draw_path_layer_;

    graph::SparseGraph3D* sparse_graph_;
    graph::AStarSearch* astar_;

    int source_;
    int target_;

    graph::AStarSearch::PathNodes path_; // nodes index

    cocos2d::Camera* camera_;
    cocos2d::Layer* hud_;

    graph::SpacePartition3D* space_partition_;

    float space_ori_x_; 
    float space_ori_y_;
    float space_ori_z_;

    cocos2d::Vec3 space_ori_;

    float space_size_x_;
    float space_size_y_;
    float space_size_z_;

    graph::Size space_size_;

    int num_boxes_x_;
    int num_boxes_y_;
    int num_boxes_z_;

    graph::Size num_space_box_;

    float box_size_x_;
    float box_size_y_;
    float box_size_z_; 

    graph::Size size_space_box_;

    cocos2d::DrawNode3D* draw_node_;
};

} // namespace gamer

#endif