//
//  MainLayer.h
//  box
//
//  Created by 咸光金 on 2016/12/12.
//
//

#ifndef MainLayer_h
#define MainLayer_h

#include <stdio.h>
using namespace std;

#include "cocos2d.h"
USING_NS_CC;

#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace ui;
using namespace cocostudio;
using namespace cocostudio::timeline;


#include "CreateRoomLayer.h"

#include "NetUtils.h"

class MainLayer :public Layer {

public:
    CREATE_FUNC(MainLayer);
    virtual bool init();
    static Scene * createScene();

    virtual void onEnter();
    virtual void onExit();

    void onCreateGameLayer();

    void onClick(Ref *sender);

    void initThings();


public:
    Size visibleSize;
    Director *director;
    Vec2 visibleOrigin;
    Node *_rootLayer;
    Layout *_rootLayout;

};



#endif /* MainLayer_hpp */
