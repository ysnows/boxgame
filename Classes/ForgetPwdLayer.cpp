//
//  ForgetPwdLayer.cpp
//  box
//
//  Created by 咸光金 on 2016/12/12.
//
//

#include "ForgetPwdLayer.h"


void ForgetPwdLayer::initThings() {


}

void ForgetPwdLayer::onCreateGameLayer(){
  _rootLayer=CSLoader::createNode("ForgetPwdLayer.csb");
  if (_rootLayer==nullptr) {
       return;
   }

   addChild(_rootLayer);
   _rootLayout=static_cast<Layout *>(_rootLayer->getChildByName("Panel_Back"));



}


void ForgetPwdLayer::onClick(Ref *sender){
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


bool ForgetPwdLayer::init(){
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


Scene * ForgetPwdLayer::createScene(){
    Scene *scene=Scene::create();
    auto layer=ForgetPwdLayer::create();
    scene->addChild(layer);

    return scene;
}

void ForgetPwdLayer::onEnter(){
  Layer::onEnter();
  onCreateGameLayer();
}

void ForgetPwdLayer::onExit(){
  TextureCache::getInstance()->removeUnusedTextures();
  Layer::onExit();

}
