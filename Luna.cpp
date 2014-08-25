
#include "Luna.h"
#include "LunaState.h"
#include "ImageUtil.h"
#include "Constants.h"
#include "InputManager.h"
#include "GameMain.h"

using namespace cocos2d;

// 名前空間定義
// 忘れないように・ｗ・ｂ
namespace luna{

#pragma mark --- コンストラクタ & デストラクタ ---
CPlayerLuna::CPlayerLuna():
m_lunaState(0),
m_lunaHp(0),
m_lunaMp(0),
m_lunaOverDrive(0)
{
	m_lunaState = new LunaState(this);
	
	///loadImage("ChrChip2.png", m_lunaTex);
}

CPlayerLuna::~CPlayerLuna(){
	// デリート後、NULLを入れる
	delete m_lunaState;
	m_lunaState = 0;
}

void update(double deltaTime){
	///m_lunaState->update(deltaTime);
	
}

#pragma mark --- メソッド定義 ---
// KA☆MA☆SU パターン
float* CPlayerLuna::getHp(){
	return m_lunaHp;
}
float* CPlayerLuna::getMp(){
	return m_lunaMp;
}
float* CPlayerLuna::getOd(){
	return m_lunaOverDrive;
}

}



