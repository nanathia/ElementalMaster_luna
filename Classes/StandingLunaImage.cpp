//
//  StandingLunaImage.cpp
//  Stg14
//
//  Created by 小林　伸 on 2014/08/26.
//
//

#include "StandingLunaImage.h"
#include "GameMain.h"
#include "TextureManager.h"

StandingLunaImage::StandingLunaImage():
m_sprite(0),
m_currentFace(FaceName_None){
    m_sprite = gGameMain->getTexMan()->createSprite(GameMain::texName_LunaFace, gGameMain, cocos2d::Point(750, 270), cocos2d::Rect(0, 0, 100, 100));
    m_sprite->setVisible(false);
}
StandingLunaImage::~StandingLunaImage(){
    m_sprite->removeFromParentAndCleanup(true);
}

void StandingLunaImage::InterEffect(){
    
}
cocos2d::Sprite* StandingLunaImage::getSprite(){
    return m_sprite;
}
void StandingLunaImage::changeFace(StandingLunaImage::FaceName name){
    if(name == FaceName_None){
        m_sprite->setVisible(false);
        return;
    }
    cocos2d::Size imSize = m_sprite->getTexture()->getContentSize();
    imSize.width /=7;
    cocos2d::Rect src = cocos2d::Rect(imSize.width*name, 0, imSize.width, imSize.height);
    m_sprite->setTextureRect(src);
    m_sprite->setVisible(true);
}