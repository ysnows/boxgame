//
//  SocketTestLayer.h
//  Game
//
//  Created by 咸光金 on 2016/11/21.
//
//

#ifndef SocketTestLayer_h
#define SocketTestLayer_h

#include <stdio.h>
#include <ui/UIWebView.h>

using namespace std;

#include "cocos2d.h"

USING_NS_CC;

#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "extensions/cocos-ext.h"

USING_NS_CC_EXT;

using namespace ui;

using namespace cocostudio;
using namespace cocostudio::timeline;

#include "ODSocket.h"
#include "json/document.h"
#include "network/httpClient.h"
using namespace network;

using namespace rapidjson;


class SocketTestLayer : public Layer {

public:
    CREATE_FUNC(SocketTestLayer);

    virtual bool init();

    static Scene *createScene();

    virtual void onEnter();

    virtual void onExit();

    void onCreateGameLayer();

    void onClick(Ref *sender);

    void initThings();

    void connectServer();
    void http();

    void receiveData();

    void addBtn(string content, string name, Vec2 position);

public:
    cocos2d::Size visibleSize;
    Director *director;
    Vec2 visibleOrigin;
    Node *_rootLayer;
    Layout *_rootLayout;

    ODSocket socket;


};


#endif /* SocketTestLayer_hpp */
