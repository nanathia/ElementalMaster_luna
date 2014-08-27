//
//  StageStartEffectCharacterState.cpp
//  Stg14
//
//  Created by 小林　伸 on 2014/08/27.
//
//

#include "StageStartEffectCharacterState.h"
#include "StageStartEffectCharacter.h"

StageStartEffectCharacterState::StageStartEffectCharacterState(StageStartEffectCharacter* user):
m_child(0){
    m_child = new StageStartEffectCharacterInter(user);
}
StageStartEffectCharacterState::~StageStartEffectCharacterState(){
    delete m_child;
    m_child = 0;
}
void StageStartEffectCharacterState::update(float deltaTime){
    StageStartEffectCharacterStateChild* nextChild = m_child->update(deltaTime);
    if(nextChild != m_child){
        delete m_child;
        m_child = nextChild;
    }
}
void StageStartEffectCharacterState::retire(){
    m_child->retire();
}
bool StageStartEffectCharacterState::isAppeared() const{
    return m_child->isAppeared();
}
bool StageStartEffectCharacterState::isDisappeared() const{
    return m_child->isDisappeared();
}

StageStartEffectCharacterStateChild::StageStartEffectCharacterStateChild(StageStartEffectCharacter*user):
m_user(user){
}
StageStartEffectCharacterStateChild::~StageStartEffectCharacterStateChild(){
}
void StageStartEffectCharacterStateChild::retire(){
    // Do nothing
}
bool StageStartEffectCharacterStateChild::isAppeared() const{
    return false;
}
bool StageStartEffectCharacterStateChild::isDisappeared() const{
    return false;
}

StageStartEffectCharacterInter::StageStartEffectCharacterInter(StageStartEffectCharacter* user):
StageStartEffectCharacterStateChild(user){
    
}
StageStartEffectCharacterInter::~StageStartEffectCharacterInter(){
}
StageStartEffectCharacterStateChild* StageStartEffectCharacterInter::update(float deltaTime){
    StageStartEffectCharacterStateChild* next = this;
    if(m_user->getPrev()) if(!m_user->getPrev()->isEnableNextLaunch()) return next;
    m_user->addTime(deltaTime);
    cocos2d::Point pos = m_user->getSprite()->getPosition();
    pos.y -= 10;
    if(pos.y <= 480){
        pos.y = 480;
        next = new StageStartEffectCharacterVisible(m_user);
    }
    m_user->getSprite()->setPosition(pos);
    return next;
}

StageStartEffectCharacterVisible::StageStartEffectCharacterVisible(StageStartEffectCharacter* user):
StageStartEffectCharacterStateChild(user),
m_isNext(false){
}
StageStartEffectCharacterVisible::~StageStartEffectCharacterVisible(){
}
StageStartEffectCharacterStateChild* StageStartEffectCharacterVisible::update(float deltaTime){
    StageStartEffectCharacterStateChild* next = this;
    if(m_isNext){
        next = new StageStartEffectCharacterOuter(m_user);
    }
    return next;
}
void StageStartEffectCharacterVisible::retire(){
    m_isNext = true;
}
bool StageStartEffectCharacterVisible::isAppeared() const{
    return true;
}

StageStartEffectCharacterOuter::StageStartEffectCharacterOuter(StageStartEffectCharacter* user):
StageStartEffectCharacterStateChild(user){
}
StageStartEffectCharacterOuter::~StageStartEffectCharacterOuter(){
}
StageStartEffectCharacterStateChild* StageStartEffectCharacterOuter::update(float deltaTime){
    StageStartEffectCharacterStateChild* next = this;
    cocos2d::Point pos = m_user->getSprite()->getPosition();
    cocos2d::Size winSize = cocos2d::Director::getInstance()->getWinSize();
    pos.x += 10;
    if(pos.x >= winSize.width){
        next = new StageStartEffectCharacterRetired(m_user);
    }
    m_user->getSprite()->setPosition(pos);
    return next;
}

StageStartEffectCharacterRetired::StageStartEffectCharacterRetired(StageStartEffectCharacter* user):
StageStartEffectCharacterStateChild(user){
    user->getSprite()->setVisible(false);
}
StageStartEffectCharacterRetired::~StageStartEffectCharacterRetired(){
}
StageStartEffectCharacterStateChild* StageStartEffectCharacterRetired::update(float deltaTime){
    StageStartEffectCharacterStateChild* next = this;
    return next;
}
bool StageStartEffectCharacterRetired::isDisappeared() const{
    return true;
}


