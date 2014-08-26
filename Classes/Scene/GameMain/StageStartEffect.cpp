#include "StageStartEffect.h"
#include "TextureManager.h"
#include "GameMain.h"

using namespace cocos2d;

StageStartEffect::StageStartEffect():
m_spriteR(0),
m_spriteE(0),
m_spriteA(0),
m_spriteD(0),
m_spriteY(0)
{
	m_waitCounter = 0;
	m_spriteR = gGameMain->getTexMan()->createSprite(GameMain::texName_Ready, gGameMain, Point(480.0f, 1080), Rect(  0,   0, 128, 128));
	m_spriteE = gGameMain->getTexMan()->createSprite(GameMain::texName_Ready, gGameMain, Point(480.0f, 1080), Rect(128, 128, 256, 256));
	m_spriteA = gGameMain->getTexMan()->createSprite(GameMain::texName_Ready, gGameMain, Point(480.0f, 1080), Rect(256, 256, 384, 384));
	m_spriteD = gGameMain->getTexMan()->createSprite(GameMain::texName_Ready, gGameMain, Point(480.0f, 1080), Rect(384, 384, 512, 512));
	m_spriteY = gGameMain->getTexMan()->createSprite(GameMain::texName_Ready, gGameMain, Point(480.0f, 1080), Rect(512, 512, 640, 640));

}
StageStartEffect::~StageStartEffect(){
	m_spriteR->removeFromParentAndCleanup(true);
	m_spriteR = 0;
	m_spriteE->removeFromParentAndCleanup(true);
	m_spriteE = 0;
	m_spriteA->removeFromParentAndCleanup(true);
	m_spriteA = 0;
	m_spriteD->removeFromParentAndCleanup(true);
	m_spriteD = 0;
	m_spriteY->removeFromParentAndCleanup(true);
	m_spriteY = 0;
}

void StageStartEffect::interAction(){
	if(m_waitCounter == 5){
	DelayTime* delayR = DelayTime::create(0.1f);
	ActionInterval* actionR = MoveTo::create(1.0f, Point(480.0f-128, 360.0f));
	Sequence* sequenceR = Sequence::create(delayR, actionR, NULL);
	m_spriteR->runAction(EaseBounceOut::create(sequenceR));
	}else if(m_waitCounter == 10){
	DelayTime* delayE = DelayTime::create(0.1f);
	ActionInterval* actionE = MoveTo::create(1.0f, Point(480.0f, 360.0f));
	Sequence* sequenceE = Sequence::create(delayE, actionE, NULL);
	m_spriteE->runAction(EaseBounceOut::create(sequenceE));
	}
}
void StageStartEffect::outerAction(){
	
}

void StageStartEffect::update(double deltaTime){
	
	this->interAction();
	this->waitCounterIncrease();
}

cocos2d::Sprite* StageStartEffect::getSprite(char chara){
	switch(chara){
	case 'R':
		return m_spriteR;
		break;
	case 'E':
		return m_spriteE;
		break;
	case 'A':
		return m_spriteA;
		break;
	case 'D':
		return m_spriteD;
		break;
	default:
		return m_spriteY;
		break;
	}
}

void StageStartEffect::waitCounterIncrease(){
	m_waitCounter++;
}
