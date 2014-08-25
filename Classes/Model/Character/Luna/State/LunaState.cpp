#include "LunaState.h"
#include "InputManager.h"
#include "Constants.h"
#include "GameMain.h"
#include "Luna.h"

	
#pragma mark --- ルナステイト ---
LunaState::LunaState(CPlayerLuna* user):
m_child(0){
	m_child = new LunaWait(user);
}
LunaState::~LunaState(){
	delete m_child;
	m_child = 0;
}
void LunaState::update(double deltaTime){
	LunaStateChild* nextChild = m_child->update(deltaTime);
	if(nextChild != m_child){
		
		delete m_child;
		m_child = nextChild;
	}
}

#pragma mark --- ルナステイトチャイルド ---
LunaStateChild::LunaStateChild(CPlayerLuna*user):
m_user(user){
}
LunaStateChild::~LunaStateChild(){
}

	
#pragma mark --- 待機 ---
LunaWait::LunaWait(CPlayerLuna* user):
LunaStateChild(user){
}
LunaWait::~LunaWait(){
}
LunaStateChild* LunaWait::update(double deltaTime){
	LunaStateChild* next = this;
	
	// 歩行処理
	if(IsKeyPressed(KEY_FLAG::LEFT) || IsKeyPressed(KEY_FLAG::RIGHT))
		next = new LunaWalk(m_user);
	
	// ダッシュ処理
	if(IsKeyPressed(KEY_FLAG::C_KEY))
		next = new LunaDash(m_user);
	
	// ジャンプ処理
	if(IsKeyPressed(KEY_FLAG::X_KEY))
		next = new LunaJump(m_user);
	
	// ショット処理
	if(IsKeyPressed(KEY_FLAG::Z_KEY))
		next = new LunaShot(m_user);
	
	/// ダメージ処理
	///if()
		///next = new LunaDamage(m_user);
	
	return next;
}
	
#pragma mark --- 歩行 ---
LunaWalk::LunaWalk(CPlayerLuna* user):
LunaStateChild(user){
}
LunaWalk::~LunaWalk(){
}
LunaStateChild* LunaWalk::update(double deltaTime){
	LunaStateChild* next = this;
	return next;
}
	
#pragma mark --- 射出 ---
LunaShot::LunaShot(CPlayerLuna* user):
LunaStateChild(user){
}
LunaShot::~LunaShot(){
}
LunaStateChild* LunaShot::update(double deltaTime){
	LunaStateChild* next = this;
	return next;
}
	
#pragma mark --- ジャンプ ---
LunaJump::LunaJump(CPlayerLuna* user):
LunaStateChild(user){
	m_jumpHoldCounter = 0;
}
LunaJump::~LunaJump(){
}
LunaStateChild* LunaJump::update(double deltaTime){
	LunaStateChild* next = this;
	return next;
}
	
#pragma mark --- 落下 ---
LunaFall::LunaFall(CPlayerLuna* user):
LunaStateChild(user){
}
LunaFall::~LunaFall(){
}
LunaStateChild* LunaFall::update(double deltaTime){
	LunaStateChild* next = this;
	return next;
}
	
#pragma mark --- 着地 ---
LunaLand::LunaLand(CPlayerLuna* user):
LunaStateChild(user){
}
LunaLand::~LunaLand(){
}
LunaStateChild* LunaLand::update(double deltaTime){
	LunaStateChild* next = this;
	return next;
}
	
#pragma mark --- ダッシュ ---
LunaDash::LunaDash(CPlayerLuna* user):
LunaStateChild(user){
}
LunaDash::~LunaDash(){
}
LunaStateChild* LunaDash::update(double deltaTime){
	LunaStateChild* next = this;
	return next;
}

#pragma mark --- 壁蹴り ---
LunaWallKick::LunaWallKick(CPlayerLuna* user):
LunaStateChild(user){
}
LunaWallKick::~LunaWallKick(){
}
LunaStateChild* LunaWallKick::update(double deltaTime){
	LunaStateChild* next = this;
	return next;
}
	
#pragma mark --- 壁捕まり ---
LunaWallStick::LunaWallStick(CPlayerLuna* user):
LunaStateChild(user){
}
LunaWallStick::~LunaWallStick(){
}
LunaStateChild* LunaWallStick::update(double deltaTime){
	LunaStateChild* next = this;
	return next;
}
	
#pragma mark --- ダッシュジャンプ ---
LunaDashJump::LunaDashJump(CPlayerLuna* user):
LunaStateChild(user){
}
LunaDashJump::~LunaDashJump(){
}
LunaStateChild* LunaDashJump::update(double deltaTime){
	LunaStateChild* next = this;
	return next;
}
	
#pragma mark --- ダメージ ---
LunaDamage::LunaDamage(CPlayerLuna* user):
LunaStateChild(user){
}
LunaDamage::~LunaDamage(){
}
LunaStateChild* LunaDamage::update(double deltaTime){
	LunaStateChild* next = this;
	return next;
}

