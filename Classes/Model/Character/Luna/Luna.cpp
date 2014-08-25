
#include "Luna.h"
#include "LunaState.h"
#include "ImageUtil.h"
#include "Constants.h"
#include "InputManager.h"
#include "GameMain.h"

using namespace cocos2d;

#pragma mark --- コンストラクタ & デストラクタ ---
CPlayerLuna::CPlayerLuna():
m_state(0){
    m_state = new LunaState(this);
}

CPlayerLuna::~CPlayerLuna(){
	// デリート後、NULLを入れる
	delete m_state;
	m_state = NULL;
}

void CPlayerLuna::update(double deltaTime){
	m_state->update(deltaTime);
}

#pragma mark --- メソッド定義 ---
