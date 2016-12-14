//
//  LoginLayer.cpp
//  box
//
//  Created by 咸光金 on 2016/12/12.
//
//

#include "LoginLayer.h"

#include "MainLayer.h"
#include "ForgetPwdLayer.h"

void LoginLayer::initThings() {


}

void LoginLayer::onCreateGameLayer(){
  _rootLayer=CSLoader::createNode("LoginLayer.csb");
  if (_rootLayer==nullptr) {
       return;
   }

   addChild(_rootLayer);
   _rootLayout=static_cast<Layout *>(_rootLayer->getChildByName("Panel_Back"));

    auto btn_1=dynamic_cast<Button *>(_rootLayout->getChildByName("Button_1"));
    btn_1->addClickEventListener([this](Ref *sender){
        login("18354450969","123456");
    });


    auto btn_2=dynamic_cast<Button *>(_rootLayout->getChildByName("Button_2"));
    btn_2->addClickEventListener([this](Ref *sender){
        switchSceneOut(ForgetPwdLayer::createScene());
        });
}




void LoginLayer::login(string user_name, string pwd){

    hPost("user/login", "phone="+user_name+"&pwd="+pwd, [this](HttpClient* client, HttpResponse* response){
        if (response->isSucceed()) {
        vector<char> *charVector= response->getResponseData();
        string str(charVector->begin(),charVector->end());
        
        Document d;
        d.Parse<rapidjson::kParseDefaultFlags>(str.c_str());
        
        auto code=d["code"].GetInt();
        auto msg=d["msg"].GetString();
            
            if (code==OK) {
                int uid=d["data"].GetInt();
                string uidStr=StringUtils::format("%d",uid);
                UserDefault::getInstance()->setStringForKey("uid", uidStr);
                
                switchSceneOut(MainLayer::createScene());
            }else{
                
            }
            
            
            if (d.HasMember("data")&&d.IsObject()) {
            
            
            }
      }
    });
    
  

    
}

void LoginLayer::onClick(Ref *sender){
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







bool LoginLayer::init(){
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


Scene * LoginLayer::createScene(){
    Scene *scene=Scene::create();
    auto layer=LoginLayer::create();
    scene->addChild(layer);

    return scene;
}

void LoginLayer::onEnter(){
  Layer::onEnter();
  onCreateGameLayer();
}

void LoginLayer::onExit(){
  TextureCache::getInstance()->removeUnusedTextures();
  Layer::onExit();

}
