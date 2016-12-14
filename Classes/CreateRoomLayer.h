//
//  CreateRoomLayer.h
//  box
//
//  Created by 咸光金 on 2016/12/13.
//
//

#ifndef CreateRoomLayer_h
#define CreateRoomLayer_h

#include <stdio.h>
using namespace std;

#include "cocos2d.h"
USING_NS_CC;

#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace ui;
using namespace cocostudio;
using namespace cocostudio::timeline;

#include "MainLayer.h"



class CreateRoomLayer :public Layer {

public:
    CREATE_FUNC(CreateRoomLayer);
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



#endif /* CreateRoomLayer_hpp */
