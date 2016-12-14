//
//  Common.cpp
//  box
//
//  Created by 咸光金 on 2016/12/14.
//
//

#include "Common.h"


void switchSceneOut(Scene *scene){
    Director::getInstance()->replaceScene(TransitionProgressInOut::create(0.3, scene));
}

void switchSceneIn(Scene *scene){
    Director::getInstance()->replaceScene(TransitionProgressOutIn::create(0.3, scene));
}
