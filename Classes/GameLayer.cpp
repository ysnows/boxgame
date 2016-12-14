//
//  GameLayer.cpp
//  boxgame
//
//  Created by 咸光金 on 2016/12/14.
//
//

#include "GameLayer.h"


void GameLayer::initThings() {


}

void GameLayer::onCreateGameLayer(){
  _rootLayer=CSLoader::createNode("GameLayer.csb");
  if (_rootLayer==nullptr) {
       return;
   }

   addChild(_rootLayer);
   _rootLayout=static_cast<Layout *>(_rootLayer->getChildByName("Panel_1"));



}


void GameLayer::onClick(Ref *sender){
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


bool GameLayer::init(){
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


Scene * GameLayer::createScene(){
    Scene *scene=Scene::create();
    auto layer=GameLayer::create();
    scene->addChild(layer);

    return scene;
}

void GameLayer::onEnter(){
  Layer::onEnter();
  onCreateGameLayer();
}

void GameLayer::onExit(){
  TextureCache::getInstance()->removeUnusedTextures();
  Layer::onExit();

}
