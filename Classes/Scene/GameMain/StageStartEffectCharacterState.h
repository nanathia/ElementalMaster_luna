//
//  StageStartEffectCharacterState.h
//  Stg14
//
//  Created by 小林　伸 on 2014/08/27.
//
//

#ifndef __Stg14__StageStartEffectCharacterState__
#define __Stg14__StageStartEffectCharacterState__

#include "cocos2d.h"

class StageStartEffectCharacter;
class StageStartEffectCharacterState;

class StageStartEffectCharacterStateChild{
protected:
    StageStartEffectCharacter* m_user;
public:
    StageStartEffectCharacterStateChild(StageStartEffectCharacter* user);
    virtual ~StageStartEffectCharacterStateChild();
    virtual StageStartEffectCharacterStateChild* update(float deltaTime) = 0;
public:
    virtual void retire();
    virtual bool isAppeared() const;
    virtual bool isDisappeared() const;
};

class StageStartEffectCharacterInter: public StageStartEffectCharacterStateChild{
public:
    StageStartEffectCharacterInter(StageStartEffectCharacter* user);
    ~StageStartEffectCharacterInter();
    StageStartEffectCharacterStateChild* update(float deltaTime) override;
};

class StageStartEffectCharacterVisible: public StageStartEffectCharacterStateChild{
    bool m_isNext;
public:
    StageStartEffectCharacterVisible(StageStartEffectCharacter* user);
    ~StageStartEffectCharacterVisible();
    StageStartEffectCharacterStateChild* update(float deltaTime) override;
public:
    void retire() override;
    bool isAppeared() const override;
};

class StageStartEffectCharacterOuter: public StageStartEffectCharacterStateChild{
public:
    StageStartEffectCharacterOuter(StageStartEffectCharacter* user);
    ~StageStartEffectCharacterOuter();
    StageStartEffectCharacterStateChild* update(float deltaTime) override;
};

class StageStartEffectCharacterRetired: public StageStartEffectCharacterStateChild{
public:
    StageStartEffectCharacterRetired(StageStartEffectCharacter* user);
    ~StageStartEffectCharacterRetired();
    StageStartEffectCharacterStateChild* update(float deltaTime) override;
public:
    bool isDisappeared() const override;
};

class StageStartEffectCharacterState{
    StageStartEffectCharacterStateChild* m_child;
public:
    StageStartEffectCharacterState(StageStartEffectCharacter* user);
    ~StageStartEffectCharacterState();
    void update(float deltaTime);
public:
    // 親側から使用するメソッド
    void retire();
    bool isAppeared() const;
    bool isDisappeared() const;
};

#endif /* defined(__Stg14__StageStartEffectCharacterState__) */
