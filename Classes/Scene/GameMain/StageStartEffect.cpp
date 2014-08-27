#include "StageStartEffect.h"
#include "StageStartEffectCharacter.h"
#include "TextureManager.h"
#include "GameMain.h"

using namespace cocos2d;

StageStartEffect::StageStartEffect(){
    cocos2d::Size winSize = cocos2d::Director::getInstance()->getWinSize();
    cocos2d::Sprite* sprites[5] = {
        gGameMain->getTexMan()->createSprite(GameMain::texName_Ready, gGameMain, cocos2d::Rect(0, 0, 0.2, 1), cocos2d::Point(100, winSize.height)),
        gGameMain->getTexMan()->createSprite(GameMain::texName_Ready, gGameMain, cocos2d::Rect(0.2, 0, 0.2, 1), cocos2d::Point(200, winSize.height)),
        gGameMain->getTexMan()->createSprite(GameMain::texName_Ready, gGameMain, cocos2d::Rect(0.4, 0, 0.2, 1), cocos2d::Point(300, winSize.height)),
        gGameMain->getTexMan()->createSprite(GameMain::texName_Ready, gGameMain, cocos2d::Rect(0.6, 0, 0.2, 1), cocos2d::Point(400, winSize.height)),
        gGameMain->getTexMan()->createSprite(GameMain::texName_Ready, gGameMain, cocos2d::Rect(0.8, 0, 0.2, 1), cocos2d::Point(500, winSize.height)),
    };
    for(int i = 0; i < 5; i++){
        StageStartEffectCharacter* new_char = new StageStartEffectCharacter(sprites[i]);
        if(i != 0){
            m_data.back()->setNext(new_char);
            new_char->setPrev(m_data.back());
        }
        m_data.push_back(new_char);
    }
}

StageStartEffect::~StageStartEffect(){
    if(m_data.empty()) return;
    auto it = m_data.begin();
    while(it != m_data.end()){
        delete *it;
        *it = 0;
        it++;
    }
    m_data.clear();
}

void StageStartEffect::update(double deltaTime){
    if(m_data.empty()) return;
    auto it = m_data.begin();
    while(it != m_data.end()){
        (*it)->update(deltaTime);
        it++;
    }
    if(this->isAllCharacterAppeared()){
        this->allCharacterRetire();
    }
    it = m_data.begin();
    while(it != m_data.end()){
        if((*it)->isDisappeared()){
            delete *it;
            *it = 0;
            it = m_data.erase(it);
            continue;
        }
        it++;
    }
}

bool StageStartEffect::isEnd() const{
    return m_data.empty();
}











#pragma mark ---ここから内部使用メソッド---
bool StageStartEffect::isAllCharacterAppeared() const{
    CCASSERT(!m_data.empty(), "StageStartEffect::isAllCharacterAppeared : allCharacterDeleted");
    auto it = m_data.begin();
    while(it != m_data.end()){
        if(!(*it)->isAppeared()) return false;
        it++;
    }
    return true;
}
void StageStartEffect::allCharacterRetire(){
    CCASSERT(!m_data.empty(), "StageStartEffect::isAllCharacterAppeared : allCharacterDeleted");
    auto it = m_data.begin();
    while(it != m_data.end()){
        (*it)->retire();
        it++;
    }
}


