//
//  TextureManager.h
//  Stg14
//
//  Created by 小林　伸 on 2014/08/25.
//
//

#ifndef __Stg14__TextureManager__
#define __Stg14__TextureManager__

#include "cocos2d.h"
#include "ImageUtil.h"
#include <map>
#include <string>

class TextureManager{
    std::map<int, TEXTURE*> m_data;
public:
    TextureManager();
    ~TextureManager();
    void add(const std::string& fileName, int key);
    TEXTURE* get(int key);
    cocos2d::Sprite* createSprite(int key);
    cocos2d::Sprite* createSprite(int key, cocos2d::Layer* parent);
    cocos2d::Sprite* createSprite(int key, cocos2d::Layer* parent, const cocos2d::Rect& dest);
    cocos2d::Sprite* createSprite(int key, cocos2d::Layer* parent, const cocos2d::Rect& dest, const cocos2d::Rect& src);
    cocos2d::Sprite* createSprite(cocos2d::Layer* parent, int key, const cocos2d::Rect& src);
    cocos2d::Sprite* createSprite(int key, cocos2d::Layer* parent, const cocos2d::Point& pos, const cocos2d::Rect& src);
    cocos2d::Sprite* createSprite(int key, cocos2d::Layer* parent, const cocos2d::Rect& srcRatio, const cocos2d::Point& pos);
};

#endif /* defined(__Stg14__TextureManager__) */
