//
//  StandingLunaImageState.cpp
//  Stg14
//
//  Created by 小林　伸 on 2014/08/26.
//
//

#include "StandingLunaImageState.h"
#include "StandingLunaImage.h"

StandingLunaImageState::StandingLunaImageState(StandingLunaImage* user):
m_child(0){
    m_child = new StandingLunaImageNoneAction(user);
}
StandingLunaImageState::~StandingLunaImageState(){
    delete m_child;
    m_child = 0;
}
void StandingLunaImageState::update(float deltaTime){
    StandingLunaImageStateChild* nextChild = m_child->update(deltaTime);
    if(nextChild != m_child){
        delete m_child;
        m_child = nextChild;
    }
}
bool StandingLunaImageState::isAnyActionNow(){
    return m_child->isAnyActionNow();
}
void StandingLunaImageState::ChangeScene(StandingLunaImageStateChild* child){
    delete m_child;
    m_child = child;
}

StandingLunaImageStateChild::StandingLunaImageStateChild(StandingLunaImage*user):
m_user(user){
}
StandingLunaImageStateChild::~StandingLunaImageStateChild(){
}
bool StandingLunaImageStateChild::isAnyActionNow(){
    return true;
}

StandingLunaImageNoneAction::StandingLunaImageNoneAction(StandingLunaImage* user):
StandingLunaImageStateChild(user){
    m_user->getSprite()->setOpacity(255);
}
StandingLunaImageNoneAction::~StandingLunaImageNoneAction(){
}
StandingLunaImageStateChild* StandingLunaImageNoneAction::update(float deltaTime){
    StandingLunaImageStateChild* next = this;
    return next;
}
bool StandingLunaImageNoneAction::isAnyActionNow(){
    return false;
}

StandingLunaImageBoundingInterAction::StandingLunaImageBoundingInterAction(StandingLunaImage* user):
StandingLunaImageStateChild(user),
m_time(0){
}
StandingLunaImageBoundingInterAction::~StandingLunaImageBoundingInterAction(){
}
StandingLunaImageStateChild* StandingLunaImageBoundingInterAction::update(float deltaTime){
    StandingLunaImageStateChild* next = this;
    m_time += deltaTime;
    m_user->getSprite()->setOpacity(m_time*255);
    if(m_time >= 1){
        next = new StandingLunaImageNoneAction(m_user);
    }
    return next;
}

StandingLunaImageOuterAction::StandingLunaImageOuterAction(StandingLunaImage* user):
StandingLunaImageStateChild(user),
m_time(0){
}
StandingLunaImageOuterAction::~StandingLunaImageOuterAction(){
}
StandingLunaImageStateChild* StandingLunaImageOuterAction::update(float deltaTime){
    StandingLunaImageStateChild* next = this;
    m_time += deltaTime;
    if(m_time >= 1){
        next = new StandingLunaImageNoneAction(m_user);
    }
    m_user->getSprite()->setOpacity((1-m_time)*255);
    return next;
}

