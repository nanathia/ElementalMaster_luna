#include "PlayStage1.h"
#include "PlayStage1State.h"
#include "GameMain.h"
#include "TextureManager.h"

namespace stage1{
    
    PlayStage1::PlayStage1(GameMain* user):
    PlayStateChild(user),
    m_state(0),
    m_bgSprite(0){
        m_state = new State(this);
        cocos2d::Size winSize = cocos2d::Director::getInstance()->getWinSize();
        m_bgSprite = gGameMain->getTexMan()->createSprite(GameMain::texName_StageBGI, gGameMain,
                                                          cocos2d::Rect(winSize.width/2, winSize.height/2,
                                                                        winSize.width, winSize.height));
    }
    PlayStage1::~PlayStage1(){
        delete m_state;
        m_state = 0;
        m_bgSprite->removeFromParentAndCleanup(true);
        m_bgSprite = 0;
    }
    PlayStateChild* PlayStage1::update(float deltaTime){
        PlayStateChild* next = this;
        m_state->update(deltaTime);
        return next;
    }
    
}