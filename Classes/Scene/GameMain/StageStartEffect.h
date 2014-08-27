#ifndef __Stg14__StageStartEffect__
#define __Stg14__StageStartEffect__

#include "cocos2d.h"
#include <list>

class StageStartEffectCharacter;

class StageStartEffect{
    std::list<StageStartEffectCharacter*> m_data;
    bool isAllCharacterAppeared() const;
    void allCharacterRetire();
public:
	StageStartEffect();
	~StageStartEffect();
public:
	void update(double deltaTime);
    bool isEnd() const;
};

#endif /* defined(__Stg14__StageStartEffect__) */
