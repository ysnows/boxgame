//
//  NetUtils.cpp
//  box
//
//  Created by 咸光金 on 2016/12/12.
//
//

#include "NetUtils.h"



void hGet(string url,const ccHttpRequestCallback &callback){
    HttpRequest *request=new HttpRequest();
    url=BASE_URL+url;
    request->setUrl(url.c_str());
    request->setRequestType(HttpRequest::Type::GET);
    vector<string> headers;
    string uid= UserDefault::getInstance()->getStringForKey("uid");
    
    headers.push_back("uid:"+uid);
    request->setHeaders(headers);
    request->setResponseCallback(callback);
    auto client=HttpClient::getInstance();
    client->send(request);
    request->release();
}



void hPost(string url,string post_data,const ccHttpRequestCallback &callback){
    HttpRequest *request=new HttpRequest();
    url=BASE_URL+url;
    request->setUrl(url.c_str());
    request->setRequestType(HttpRequest::Type::POST);
    vector<string> headers;
    string uid= UserDefault::getInstance()->getStringForKey("uid");
    headers.push_back("uid:"+uid);
    request->setHeaders(headers);
    request->setRequestData(post_data.c_str(), strlen(post_data.c_str()));
    request->setResponseCallback(callback);
    auto client=HttpClient::getInstance();
    client->send(request);
    request->release();
}














