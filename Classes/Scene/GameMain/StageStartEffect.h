#ifndef __Stg14__StageStartEffect__
#define __Stg14__StageStartEffect__

#include "cocos2d.h"


class StageStartEffect{
	cocos2d::Sprite* m_spriteR;
	cocos2d::Sprite* m_spriteE;
	cocos2d::Sprite* m_spriteA;
	cocos2d::Sprite* m_spriteD;
	cocos2d::Sprite* m_spriteY;
	int m_waitCounter;
	
public:
	StageStartEffect();
	~StageStartEffect();
	
	void interAction();
	void outerAction();
	
public:
	void update(double deltaTime);
	cocos2d::Sprite* getSprite(char chara);
	void waitCounterIncrease();
};

#endif /* defined(__Stg14__StageStartEffect__) */
