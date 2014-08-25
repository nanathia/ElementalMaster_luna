//
//  StandingLunaImageState.h
//  Stg14
//
//  Created by 小林　伸 on 2014/08/26.
//
//

#ifndef __Stg14__StandingLunaImageState__
#define __Stg14__StandingLunaImageState__

#include "cocos2d.h"

class StandingLunaImage;
class StandingLunaImageState;
class StandingLunaImageStateChild{
protected:
    StandingLunaImage* m_user;
public:
    StandingLunaImageStateChild(StandingLunaImage* user);
    virtual ~StandingLunaImageStateChild();
    virtual StandingLunaImageStateChild* update(float deltaTime) = 0;
public:
    virtual bool isAnyActionNow();
};

class StandingLunaImageNoneAction: public StandingLunaImageStateChild{
public:
    StandingLunaImageNoneAction(StandingLunaImage* user);
    ~StandingLunaImageNoneAction();
    StandingLunaImageStateChild* update(float deltaTime) override;
public:
    bool isAnyActionNow() override;
};

class StandingLunaImageBoundingInterAction: public StandingLunaImageStateChild{
    double m_time;
public:
    StandingLunaImageBoundingInterAction(StandingLunaImage* user);
    ~StandingLunaImageBoundingInterAction();
    StandingLunaImageStateChild* update(float deltaTime) override;
};

class StandingLunaImageOuterAction: public StandingLunaImageStateChild{
    double m_time;
public:
    StandingLunaImageOuterAction(StandingLunaImage* user);
    ~StandingLunaImageOuterAction();
    StandingLunaImageStateChild* update(float deltaTime) override;
};

class StandingLunaImageState{
    StandingLunaImageStateChild* m_child;
public:
    StandingLunaImageState(StandingLunaImage* user);
    ~StandingLunaImageState();
    void update(float deltaTime);
public:
    bool isAnyActionNow();
    void ChangeScene(StandingLunaImageStateChild* new_child);
    void InterAction();
};

#endif /* defined(__Stg14__StandingLunaImageState__) */
