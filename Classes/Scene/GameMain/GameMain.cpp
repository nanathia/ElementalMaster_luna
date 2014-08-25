//
//
//	Arumi,制作
//		月光の精霊姫 ルナ 〜 ElementalMaster Luna,
//
//		ゲームメイン Src
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "GameMain.h"
#include "Constants.h"
#include "InputManager.h"
#include "SimpleAudioEngine.h"
#include "MessageWindow.h"
#include "PlayStage.h"
#include "TextureManager.h"
#include "Luna.h"


using namespace std;
using namespace cocos2d;
using namespace CocosDenshion;

GameMain* gGameMain = 0;

GameMain::GameMain():
m_currentScene(0),
m_TexMan(0),
m_Luna(0),
m_Menu(0),
m_StatusUi(0)
{
	gGameMain = this;
}
GameMain::~GameMain()
{
    m_StatusUi->removeFromParentAndCleanup(true);
    m_Menu->removeFromParentAndCleanup(true);
    delete m_Luna;
    m_Luna = 0;
    delete m_currentScene;
    m_currentScene = 0;
    delete m_TexMan;
    m_TexMan = 0;
}

#pragma mark ---シーンの生成---
Scene* GameMain::createScene()
{
    // シーンの生成
    Scene* scene = Scene::create();
    // レイヤーの生成
    GameMain* layer = new GameMain();
    // レイヤーをシーンに取り付ける
    scene->addChild(layer);
    // 生成したシーンを返す
    return scene ;
}

#pragma mark ---入力---
void GameMain::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	InputManager::getInstance()->onKeyPressed( keyCode ) ;
}
void GameMain::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event)
{
	InputManager::getInstance()->onKeyReleased( keyCode ) ;
}

#pragma mark ---初期化---
bool GameMain::init()
{
	// 親レイヤーの初期化
	if ( Layer::init() == false ){
		return false ;
	}
	// キーボード入力イベント受け取り設定
	this->setKeyboardEnabled(true);
	// 更新処理の設定
	this->scheduleUpdate();
	// 開始処理
	if (this->initGame() == false){
		return false ;
	}
	return true ;
}
bool GameMain::initGame()
{
    m_TexMan = new TextureManager;
    // プレイシーンで使う画像を一気に読み込み
    m_TexMan->add("asiba.png", texName_Asiba);
    m_TexMan->add("ready.png", texName_Ready);
    m_TexMan->add("smoke.png", texName_Smoke);
    m_TexMan->add("block.jpg", texName_Block);
    m_TexMan->add("MessageName.png", texName_MessageNameWindow);
    m_TexMan->add("MessageBack2.png", texName_MessageWindow);
    m_TexMan->add("menu.png", texName_Menu);
    m_TexMan->add("shootingBlaze.png", texName_ShootingBlaze);
    m_TexMan->add("UI.png", texName_StatusUI);
    m_TexMan->add("ground.png", texName_Ground);
    m_TexMan->add("lunaFace.png", texName_LunaFace);
    m_TexMan->add("bullet.png", texName_ForceAllow);
    m_TexMan->add("ChrChip2.png", texName_LunaChips);
    m_TexMan->add("openingBg.jpeg", texName_StageBGI);
    m_TexMan->add("pause.png", texName_Pause);
    m_TexMan->add("push.png", texName_PushCKey);
    m_currentScene = new PlayStage(this);
    m_Luna = new CPlayerLuna;
    cocos2d::Size winSize = cocos2d::Director::getInstance()->getWinSize();
    m_Menu = m_TexMan->createSprite(texName_Menu, this,
                                    cocos2d::Rect(winSize.width/2, winSize.height/2, winSize.width, winSize.height));
    m_Menu->setVisible(false);
    m_StatusUi = m_TexMan->createSprite(texName_StatusUI, this, cocos2d::Rect(270, 650, 500, 100));
    return true;
}

cocos2d::Sprite* test = 0;

#pragma mark ---更新---
void GameMain::update(float deltaTime)
{
    m_currentScene->update(deltaTime);
}

#pragma ---プレイシーン内部から使用するメソッド
TextureManager* GameMain::getTexMan(){
    return m_TexMan;
}
CPlayerLuna* GameMain::getLuna(){
    return m_Luna;
}
