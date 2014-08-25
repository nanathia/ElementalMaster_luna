//
//  TextureManager.cpp
//  Stg14
//
//  Created by 小林　伸 on 2014/08/25.
//
//

#include "TextureManager.h"

TextureManager::TextureManager(){
    
}
TextureManager::~TextureManager(){
    auto it = m_data.begin();
    while(it != m_data.end()){
        delete it->second;
        it->second = 0;
        it++;
    }
    m_data.clear();
}

void TextureManager::add(const std::string &fileName, int key){
    TEXTURE* tex = new TEXTURE;
    loadImage(fileName, tex);
    m_data.insert(std::map<int, TEXTURE*>::value_type(key, tex));
}

TEXTURE* TextureManager::get(int key){
    return m_data[key];
}

// 全てのcreateSpriteがこのメソッドに集約され、
// 渡されたkeyコードをそのままz-orderに適用している。
// つまり、使用側のenumの順を変えるだけで描画順番が簡単に変わる仕様。
cocos2d::Sprite* TextureManager::createSprite(int key){
    cocos2d::Sprite* ret = cocos2d::Sprite::createWithTexture(this->get(key)->m_pTexture);
    ret->setZOrder(key);
    return ret;
}

cocos2d::Sprite* TextureManager::createSprite(int key, cocos2d::Layer *parent){
    cocos2d::Sprite* new_sprite = this->createSprite(key);
    parent->addChild(new_sprite);
    return new_sprite;
}

cocos2d::Sprite* TextureManager::createSprite(int key, cocos2d::Layer *parent, const cocos2d::Rect &dest){
    cocos2d::Sprite* new_sprite = this->createSprite(key);
    new_sprite->setPosition(dest.origin);
    cocos2d::Size size = new_sprite->getContentSize();
    size.width = 1.0/size.width;
    size.height = 1.0/size.height;
    size.width *= dest.size.width;
    size.height *= dest.size.height;
    new_sprite->setScale(size.width, size.height);
    parent->addChild(new_sprite);
    return new_sprite;
}

cocos2d::Sprite* TextureManager::createSprite(int key, cocos2d::Layer* parent, const cocos2d::Rect& dest, const cocos2d::Rect& src){
    cocos2d::Sprite* new_sprite = this->createSprite(key);
    new_sprite->setTextureRect(src);
    new_sprite->setPosition(dest.origin);
    cocos2d::Size size = new_sprite->getContentSize();
    size.width = 1.0/size.width;
    size.height = 1.0/size.height;
    size.width *= dest.size.width;
    size.height *= dest.size.height;
    new_sprite->setScale(size.width, size.height);
    parent->addChild(new_sprite);
    return new_sprite;
}

cocos2d::Sprite* TextureManager::createSprite(cocos2d::Layer* parent, int key, const cocos2d::Rect& src){
    cocos2d::Sprite* ret = this->createSprite(key);
    ret->setTextureRect(src);
    parent->addChild(ret);
    return ret;
}

cocos2d::Sprite* TextureManager::createSprite(int key, cocos2d::Layer* parent, const cocos2d::Point& pos, const cocos2d::Rect& src){
    cocos2d::Sprite* ret = this->createSprite(key);
    ret->setTextureRect(src);
    ret->setPosition(pos);
    parent->addChild(ret);
    return ret;
}

cocos2d::Sprite* TextureManager::createSprite(int key, cocos2d::Layer* parent, const cocos2d::Rect& srcRatio, const cocos2d::Point& pos){
    cocos2d::Sprite* ret = this->createSprite(key);
    cocos2d::Rect _src(srcRatio);
    cocos2d::Size imSize = ret->getContentSize();
    _src.origin.x *= imSize.width;
    _src.origin.y *= imSize.height;
    _src.size.width *= imSize.width;
    _src.size.height *= imSize.height;
    ret->setTextureRect(_src);
    ret->setPosition(pos);
    parent->addChild(ret);
    return ret;
}

