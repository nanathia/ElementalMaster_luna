//
//  StageStartEffectCharacter.cpp
//  Stg14
//
//  Created by 小林　伸 on 2014/08/27.
//
//

#include "StageStartEffectCharacter.h"
#include "StageStartEffectCharacterState.h"

StageStartEffectCharacter::StageStartEffectCharacter(cocos2d::Sprite* sprite):
m_sprite(sprite),
m_time(0),
m_state(0),
m_prev(0),
m_next(0){
    m_state = new StageStartEffectCharacterState(this);
}

StageStartEffectCharacter::~StageStartEffectCharacter(){
    m_sprite->removeFromParentAndCleanup(true);
    delete m_state;
    m_state = 0;
}

void StageStartEffectCharacter::update(float deltaTime){
    m_state->update(deltaTime);
}

StageStartEffectCharacter* StageStartEffectCharacter::getNext(){
    return m_next;
}

StageStartEffectCharacter* StageStartEffectCharacter::getPrev(){
    return m_prev;
}

void StageStartEffectCharacter::setPrev(StageStartEffectCharacter* prev){
    m_prev = prev;
}

void StageStartEffectCharacter::setNext(StageStartEffectCharacter* next){
    m_next = next;
}

bool StageStartEffectCharacter::isEnableNextLaunch() const{
    return m_time >= 0.2? true: false;
}

bool StageStartEffectCharacter::isAppeared() const{
    return m_state->isAppeared();
}

bool StageStartEffectCharacter::isDisappeared() const{
    return m_state->isDisappeared();
}

void StageStartEffectCharacter::retire(){
    m_state->retire();
}

cocos2d::Sprite* StageStartEffectCharacter::getSprite(){
    return m_sprite;
}

void StageStartEffectCharacter::addTime(float deltaTime){
    m_time += deltaTime;
}
