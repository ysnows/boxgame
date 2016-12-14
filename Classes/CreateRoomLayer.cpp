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
    
    
    auto btn_2=dynamic_cast<Button *>(_rootLayout->getChildByName("Button_2"));
    btn_2->addClickEventListener([this](Ref *sender){
        auto context=this;
        hPost("main/createRoom", "number=1&person_count=2&playway=2", [context](HttpClient* client, HttpResponse* response){
            if (response->isSucceed()) {
                vector<char> *charVector= response->getResponseData();
                string str(charVector->begin(),charVector->end());
                
                Document d;
                d.Parse<rapidjson::kParseDefaultFlags>(str.c_str());
                
                
                auto code=d["code"].GetInt();
                auto msg=d["msg"].GetString();
                
                if (code==OK) {
                   //进入房间
                    string roomId=d["data"].GetString();
                    
                    context->enterRoom(roomId);
                    
                }else{
                    
                }
            }
        });
        
        
        
    });
    
 }

void CreateRoomLayer::enterRoom(string roomId){
        hGet("main/enterRoom?roomId="+roomId, [this](HttpClient* client, HttpResponse* response){
        if (response->isSucceed()) {
            vector<char> *charVector= response->getResponseData();
            string str(charVector->begin(),charVector->end());
            
            Document d;
            d.Parse<rapidjson::kParseDefaultFlags>(str.c_str());
            
            auto code=d["code"].GetInt();
            auto msg=d["msg"].GetString();
            
            if (code==OK) {
                switchSceneOut(GameLayer::createScene());
               }else{
                
            }
        }
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
