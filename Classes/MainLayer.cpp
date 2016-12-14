//
//  MainLayer.cpp
//  box
//
//  Created by 咸光金 on 2016/12/12.
//
//

#include "MainLayer.h"


void MainLayer::initThings() {


}

void MainLayer::onCreateGameLayer(){
  _rootLayer=CSLoader::createNode("MainLayer.csb");
  if (_rootLayer==nullptr) {
       return;
   }

   addChild(_rootLayer);
   _rootLayout=static_cast<Layout *>(_rootLayer->getChildByName("Panel_Back"));
    
   
    auto layout_panel_2=dynamic_cast<Layout *>(_rootLayout->getChildByName("Panel_2"));
    
    auto btn_11=dynamic_cast<Button *>(_rootLayout->getChildByName("Button_11"));
    btn_11->addClickEventListener([this,layout_panel_2](Ref *sender){
        layout_panel_2->setVisible(true);
       });
    
    auto btn_14=dynamic_cast<Button *>(layout_panel_2->getChildByName("Button_14"));
    btn_14->addClickEventListener([this,layout_panel_2](Ref *sender){
        layout_panel_2->setVisible(false);
       });
    
    auto btn_12=dynamic_cast<Button *>(_rootLayout->getChildByName("Button_12"));
    btn_12->addClickEventListener([this](Ref *sender){
        
        auto transition=TransitionProgressInOut::create(0.3, CreateRoomLayer::createScene());
        director->replaceScene(transition);
        
    });
    
    auto btn_13=dynamic_cast<Button *>(_rootLayout->getChildByName("Button_13"));
    btn_13->addClickEventListener([this](Ref *sender){
        hGet("main/randomRoom", [this](HttpClient* client, HttpResponse* response){
            if (response->isSucceed()) {
                vector<char> *charVector= response->getResponseData();
                string str(charVector->begin(),charVector->end());
                
                Document d;
                d.Parse<rapidjson::kParseDefaultFlags>(str.c_str());
                
                auto code=d["code"].GetInt();
                auto msg=d["msg"].GetString();
                
                if (code==OK) {
                    int roomId=d["data"].GetInt();
                                        
                }else{
                    
                }
            }
        });
        
        
      
    });
    
}


void MainLayer::onClick(Ref *sender){
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


bool MainLayer::init(){
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


Scene * MainLayer::createScene(){
    Scene *scene=Scene::create();
    auto layer=MainLayer::create();
    scene->addChild(layer);

    return scene;
}

void MainLayer::onEnter(){
  Layer::onEnter();
  onCreateGameLayer();
}

void MainLayer::onExit(){
  TextureCache::getInstance()->removeUnusedTextures();
  Layer::onExit();

}
