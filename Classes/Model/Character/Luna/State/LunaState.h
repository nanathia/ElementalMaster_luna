

#ifndef state_main_h
#define state_main_h

#include "cocos2d.h"

class CPlayerLuna;
class LunaState;

class LunaStateChild{
protected:
    CPlayerLuna* m_user;
public:
    LunaStateChild(CPlayerLuna* user);
    virtual ~LunaStateChild();
    virtual LunaStateChild* update(double deltaTime) = 0;
};

class LunaWait: public LunaStateChild{
public:
    LunaWait(CPlayerLuna* user);
    ~LunaWait();
    LunaStateChild* update(double deltaTime) override;
};

class LunaWalk: public LunaStateChild{
public:
    LunaWalk(CPlayerLuna* user);
    ~LunaWalk();
    LunaStateChild* update(double deltaTime) override;
};

class LunaShot: public LunaStateChild{
public:
    LunaShot(CPlayerLuna* user);
    ~LunaShot();
    LunaStateChild* update(double deltaTime) override;
};

class LunaJump: public LunaStateChild{
    int m_jumpHoldCounter;				// ジャンプ値変数
public:
    LunaJump(CPlayerLuna* user);
    ~LunaJump();
    LunaStateChild* update(double deltaTime) override;
};

// いらんかも・ｗ・
class LunaFall: public LunaStateChild{
public:
    LunaFall(CPlayerLuna* user);
    ~LunaFall();
    LunaStateChild* update(double deltaTime) override;
};

class LunaLand: public LunaStateChild{
public:
    LunaLand(CPlayerLuna* user);
    ~LunaLand();
    LunaStateChild* update(double deltaTime) override;
};

class LunaDash: public LunaStateChild{
public:
    LunaDash(CPlayerLuna* user);
    ~LunaDash();
    LunaStateChild* update(double deltaTime) override;
};

class LunaWallKick: public LunaStateChild{
public:
    LunaWallKick(CPlayerLuna* user);
    ~LunaWallKick();
    LunaStateChild* update(double deltaTime) override;
};

class LunaWallStick: public LunaStateChild{
public:
    LunaWallStick(CPlayerLuna* user);
    ~LunaWallStick();
    LunaStateChild* update(double deltaTime) override;
};

class LunaDashJump: public LunaStateChild{
public:
    LunaDashJump(CPlayerLuna* user);
    ~LunaDashJump();
    LunaStateChild* update(double deltaTime) override;
};

class LunaDamage: public LunaStateChild{
public:
    LunaDamage(CPlayerLuna* user);
    ~LunaDamage();
    LunaStateChild* update(double deltaTime) override;
};

class LunaState{
    LunaStateChild* m_child;
public:
    LunaState(CPlayerLuna* user);
    ~LunaState();
    void update(double deltaTime);
};


#endif
