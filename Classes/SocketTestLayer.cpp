//
//  SocketTestLayer.cpp
//  Game
//
//  Created by 咸光金 on 2016/11/21.
//
//

#include "SocketTestLayer.h"

#include "NetUtils.h"


void SocketTestLayer::initThings() {

    connectServer();
//    http();
    
    }

void SocketTestLayer::onCreateGameLayer() {
    addBtn(StringUtils::format("{\"action\":\"login\",\"uid\":%d}", 2), "登录", Vec2(visibleSize.width / 4, visibleSize.height / 8 * 7));
    addBtn("{\"action\":\"exit\"}", "退出", Vec2(visibleSize.width / 4, visibleSize.height / 8 * 6));
    addBtn("{\"action\":\"enterRoom\",\"uid\":2,\"roomId\":91}", "进入房间", Vec2(visibleSize.width / 4, visibleSize.height / 8 * 5));
    addBtn("{\"action\":\"ok\"}", "准备", Vec2(visibleSize.width / 4, visibleSize.height / 8 * 4));
    addBtn("{\"action\":\"pledge\",\"cashPledge\":100}", "押金", Vec2(visibleSize.width / 4, visibleSize.height / 8 * 3));
    addBtn("{\"action\":\"getCard\"}", "补牌", Vec2(visibleSize.width / 4, visibleSize.height / 8 * 2));
    addBtn("{\"action\":\"next\"}", "不补牌", Vec2(visibleSize.width / 4, visibleSize.height / 8 * 1));
 
}


void SocketTestLayer::http(){
    HttpRequest *request=new HttpRequest();
    request->setUrl("http://123.57.237.129/public/api/main/enterRoom?roomId=2");
    request->setRequestType(HttpRequest::Type::GET);
    vector<string> headers;
    headers.push_back("uid:1");
    request->setHeaders(headers);
    request->setResponseCallback([](HttpClient* client, HttpResponse* response){
        vector<char> *charVector= response->getResponseData();
        string str(charVector->begin(),charVector->end());
        
        log(str.c_str());
        
        
    });
    auto client=HttpClient::getInstance();
    client->send(request);
    
    
    
}


void SocketTestLayer::addBtn(string content ,string name,Vec2 position){
    Button *btn_one=Button::create();
    btn_one->setPosition(position);
    btn_one->setTitleText(name);
    btn_one->setTitleFontSize(28);
    
    btn_one->addClickEventListener([this,content](Ref *send){
        // 发送数据 Send
        //auto content= String::createWithFormat("{\"action\":\"login\",\"uid\":1}");
        auto count= socket.Send(content.c_str(),strlen(content.c_str()));
        log("count:%d",count);
    });
    addChild(btn_one);
    
    
    
}



// Socker连接
void SocketTestLayer::connectServer() {
    // 初始化
    // ODSocket socket;
    socket.Init();
    socket.Create(AF_INET, SOCK_STREAM, 0);

    // 设置服务器的IP地址，端口号
    // 并连接服务器 Connect
    const char *ip = "123.57.237.129";
    int port = 10012;
    bool result = socket.Connect(ip, port);

    if (result) {
        CCLOG("connect to server success!");
        // 开启新线程，在子线程中，接收数据
        std::thread recvThread = std::thread(&SocketTestLayer::receiveData, this);
        recvThread.detach(); // 从主线程分离
    } else {
        CCLOG("can not connect to server");
        return;
    }
}

// 接收数据
void SocketTestLayer::receiveData() {
    // 因为是强联网
    // 所以可以一直检测服务端是否有数据传来
    while (true) {
        // 接收数据 Recv
        char data[512] = "";
        int result = socket.Recv(data, 512, 0);
        // 与服务器的连接断开了
        if (result <= 0) break;
        CCLOG("%s", data);
        
        Document d;
        
        d.Parse(data);
        if (d.IsObject()) {
         auto code=d["code"].GetInt();
            log("%d",code);
            
        }
        
        
        
        
        
    }
    // 关闭连接
    socket.Close();
}


void SocketTestLayer::onClick(Ref *sender) {
    Button *view = dynamic_cast<Button *>(sender);

    if (view == nullptr) {
        return;
    }

    switch (view->getTag()) {
        case 1:


            break;

        default:
            break;
    }


}


bool SocketTestLayer::init() {
    if (!Layer::init()) {
        return false;
    }
    director = Director::getInstance();
    visibleSize = director->getVisibleSize();
    visibleOrigin = director->getVisibleOrigin();
    _rootLayer = nullptr;
    _rootLayout = nullptr;
    initThings();

    return true;
}


Scene *SocketTestLayer::createScene() {
    Scene *scene = Scene::create();
    auto layer = SocketTestLayer::create();
    scene->addChild(layer);

    return scene;
}

void SocketTestLayer::onEnter() {
    Layer::onEnter();
    onCreateGameLayer();
}

void SocketTestLayer::onExit() {
    TextureCache::getInstance()->removeUnusedTextures();
    Layer::onExit();

}
