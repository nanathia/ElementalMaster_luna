
#ifndef __Stg14__StageStartEffectCharacter__
#define __Stg14__StageStartEffectCharacter__

#include "cocos2d.h"

class StageStartEffect;
class StageStartEffectCharacterState;

class StageStartEffectCharacter{
    StageStartEffectCharacterState* m_state;
    cocos2d::Sprite* m_sprite;
    StageStartEffectCharacter* m_prev;
    StageStartEffectCharacter* m_next;
    float m_time;
public:
    StageStartEffectCharacter(cocos2d::Sprite* sprite);
    ~StageStartEffectCharacter();
public:
    // 親側から使用するメソッド
    void update(float deltaTime);
    // 文字が退出する
    void retire();
    // 文字が入場終了したかどうか
    bool isAppeared() const;
    // 文字が退場終了したかどうか
    bool isDisappeared() const;
    // 前の文字をセット
    void setPrev(StageStartEffectCharacter* prev);
    // 次の文字をセット
    void setNext(StageStartEffectCharacter* next);
public:
    // 子側から使用するメソッド
    cocos2d::Sprite* getSprite();
    // 前の文字を取得
    StageStartEffectCharacter* getPrev();
    // 次の文字を取得
    StageStartEffectCharacter* getNext();
    // 次の文字の出撃を許可するかどうか
    bool isEnableNextLaunch() const;
    // タイムを追加
    void addTime(float deltaTime);
};

#endif /* defined(__Stg14__StageStartEffectCharacter__) */
