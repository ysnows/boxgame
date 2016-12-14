//
//  LoginLayer.h
//  box
//
//  Created by 咸光金 on 2016/12/12.
//
//

#ifndef LoginLayer_h
#define LoginLayer_h

#include <stdio.h>
using namespace std;

#include "cocos2d.h"
USING_NS_CC;

#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace ui;
using namespace cocostudio;
using namespace cocostudio::timeline;

#include "NetUtils.h"

#include "Common.h"


class LoginLayer :public Layer {

public:
    CREATE_FUNC(LoginLayer);
    virtual bool init();
    static Scene * createScene();

    virtual void onEnter();
    virtual void onExit();

    void onCreateGameLayer();

    void onClick(Ref *sender);

    void initThings();
    
    void login(string user_name,string pwd);


public:
    cocos2d::Size visibleSize;
    Director *director;
    Vec2 visibleOrigin;
    Node *_rootLayer;
    Layout *_rootLayout;

};



#endif /* LoginLayer_hpp */
