#include "AppDelegate.h"
#include "HelloWorldScene.h"

#include "GameMain.h"
#include "InputManager.h"

#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;


// ゲームメインレイヤー
static GameMain* g_gameMainLayer_ = NULL ;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
	// ゲームメインレイヤーの開放
	if ( g_gameMainLayer_ != NULL )
	{
		// 親ノードから取り外す
		g_gameMainLayer_->removeFromParent() ;
		
		// 開放する
		delete g_gameMainLayer_ ;
		g_gameMainLayer_ = NULL ;
	}
}


bool AppDelegate::applicationDidFinishLaunching() {
	
	// ディレクターの生成と初期化
    Director* director = Director::getInstance();

	// OpenGL ビューの生成と初期化
    EGLView* eglView = EGLView::getInstance();

	{
		// 画像の調整
		//eglView->getInstance()->setDesignResolutionSize( 240, 160, ResolutionPolicy::EXACT_FIT ) ;
		
		// フレームサイズの変更
		//eglView->getInstance()->setFrameSize( 240, 160 ) ;
	}

	// ディレクターに OpenGL ビューを取り付ける
    director->setOpenGLView(eglView);
	
    // FPS 表示設定を true にする
    director->setDisplayStats(true);

	// FPS を 1.0 / 60 に設定する 
    director->setAnimationInterval(1.0 / 60);

	
	
	

	// 入力管理の生成
	InputManager::getInstance() ;
	

	
	{
		/*
		// デフォルトのテストクラスからの起動
		
		// シーンの生成と設定
		Scene* scene = HelloWorld::createScene() ;
		
		// 生成した初回のシーンをディレクターに設定し cocos2dx を起動
		director->runWithScene(scene);
		 */
	}
	
	
	
	
	{
		// 生成したゲームメインクラスからの起動
		
		// シーンの生成
		Scene* gameMainScene_ = Scene::create() ;
		
		// レイヤーの生成
		g_gameMainLayer_ = new GameMain() ;
		
		// レイヤーの初期化処理
		g_gameMainLayer_->init() ;
		
		// レイヤーをシーンに取り付ける
		gameMainScene_->addChild( g_gameMainLayer_ ) ;
		
		// 生成した初回のシーンをディレクターに設定し cocos2dx を起動
		director->runWithScene( gameMainScene_ ) ;
		 
	}
	
	
	
	
	


    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
	
	// アニメーションの停止
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	
	// アニメーションの開始
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
