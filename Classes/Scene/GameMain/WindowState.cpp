#include "WindowState.h"
#include "ImageUtil.h"
#include "InputManager.h"
#include "MessageWindow.h"


#pragma mark --- WindowState 定義 ---
// コンストラクタ
WindowState::WindowState(WindowConsole* user):
m_child(0){
	// ウィンドウ非表示モードで初期化
	m_child = new WindowAppear(user);
}
// デストラクタ
WindowState::~WindowState(){
	delete m_child;
	m_child = 0;
}

// アップデート処理
void WindowState::update(double deltaTime){
	WindowStateChild* nextChild = m_child->update(deltaTime);
	if(nextChild != m_child){
		delete m_child;
		m_child = nextChild;
	}
}

#pragma mark --- WindowStateChild 定義 ---
// コンストラクタ
WindowStateChild::WindowStateChild(WindowConsole*user):
m_user(user)
{
}

// デストラクタ
WindowStateChild::~WindowStateChild(){
}

////////////////////////////////////////////////////////////////////

#pragma mark --- WindowOff 定義 ---
/// 徐々に
// コンストラクタ
WindowOff::WindowOff(WindowConsole* user):
WindowStateChild(user){
	
	// setVisible()を使うためにメンバにアクセス
	// いっぱい噛ませてアクセーす・ｗ・ｂ
	user->getMessageWindow()->getSprite()->setVisible(false);
	user->getNameWindow()->getSprite()->setVisible(false);
}
// デストラクタ
WindowOff::~WindowOff(){
}

WindowStateChild* WindowOff::update(double deltaTime){
	WindowStateChild* next = this;
	// ここに各処理を書いていくのよ・ｗ・
	return next;
}


#pragma mark --- WindowAppear 定義 ---
// コンストラクタ
WindowAppear::WindowAppear(WindowConsole* user):
WindowStateChild(user),
m_time(0){
	user->getMessageWindow()->getSprite()->setVisible(true);
	user->getNameWindow()->getSprite()->setVisible(true);
	
	DelayTime* delay = DelayTime::create(2);
	ActionInterval* actionLuna = MoveTo::create(1.5f, Point(760.0f, 240.0f));
	Sequence* sequence = Sequence::create(delay, actionLuna, NULL);
}
// デストラクタ
WindowAppear::~WindowAppear(){
}

WindowStateChild* WindowAppear::update(double deltaTime){
	WindowStateChild* next = this;
	// ここに各処理を書いていくのよ・ｗ・
    m_time += deltaTime;
    if(m_time >= 1)
        next = new WindowOn(m_user);
    
    m_user->getMessageWindow()->setScale(m_time);
	
	return next;
}


#pragma mark --- WindowOn 定義 ---
// コンストラクタ
WindowOn::WindowOn(WindowConsole* user):
WindowStateChild(user){
}
// デストラクタ
WindowOn::~WindowOn(){
}
WindowStateChild* WindowOn::update(double deltaTime){
	WindowStateChild* next = this;
	// ここに各処理を書いていくのよ・ｗ・
	return next;
}


#pragma mark --- WindowDisappear 定義 ---
// コンストラクタ
WindowDisappear::WindowDisappear(WindowConsole* user):
WindowStateChild(user),
m_time(0){
}
// デストラクタ
WindowDisappear::~WindowDisappear(){
}

WindowStateChild* WindowDisappear::update(double deltaTime){
	WindowStateChild* next = this;
	// ここに各処理を書いていくのよ・ｗ・
    m_time += deltaTime;
    if(m_time >= 1){
        m_time = 1;
    }
	
	
    m_user->getMessageWindow()->setScale((1-m_time)*127);	
	if(m_time >= 1)
		next = new WindowOff(m_user);
	
	return next;
}
