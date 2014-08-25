
#ifndef __Stg14__Luna__
#define __Stg14__Luna__

#include "cocos2d.h"

// ステイトの宣言
class LunaState;

class CPlayerLuna{
    LunaState* m_state;
public:
    CPlayerLuna();
    ~CPlayerLuna();
public:
    void update(double deltaTime);
};


#endif /* defined(__Stg14__Luna__) */
