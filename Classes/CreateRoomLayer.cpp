//
//  CreateRoomLayer.cpp
//  box
//
//  Created by 咸光金 on 2016/12/13.
//
//

#include "CreateRoomLayer.h"


void CreateRoomLayer::initThings() {


}

void CreateRoomLayer::onCreateGameLayer(){
  _rootLayer=CSLoader::createNode("CreateRoomLayer.csb");
  if (_rootLayer==nullptr) {
       return;
   }

   addChild(_rootLayer);
   _rootLayout=static_cast<Layout *>(_rootLayer->getChildByName("Panel_1"));

    
    auto btn_1=dynamic_cast<Button *>(_rootLayout->getChildByName("Button_1"));
    btn_1->addClickEventListener([this](Ref *sender){
        
        auto transition=TransitionProgressOutIn::create(0.3, MainLayer::createScene());
        director->replaceScene(transition);
        
        });
    }


void CreateRoomLayer::onClick(Ref *sender){
  Button *view=dynamic_cast<Button *>(sender);

  if (view==nullptr) {
      return;
  }

  switch (view->getTag()) {
      case 1:


          break;

      default:
          break;
  }


}


bool CreateRoomLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    director=Director::getInstance();
    visibleSize=director->getVisibleSize();
    visibleOrigin=director->getVisibleOrigin();
    _rootLayer=nullptr;
    _rootLayout=nullptr;
    initThings();

    return true;
}


Scene * CreateRoomLayer::createScene(){
    Scene *scene=Scene::create();
    auto layer=CreateRoomLayer::create();
    scene->addChild(layer);

    return scene;
}

void CreateRoomLayer::onEnter(){
  Layer::onEnter();
  onCreateGameLayer();
}

void CreateRoomLayer::onExit(){
  TextureCache::getInstance()->removeUnusedTextures();
  Layer::onExit();

}
