//
//  InputManager.cpp
//  Stg14
//
//  Created by 永瀬鈴久 on 2014/04/09.
//
//	入力管理モジュール
//
//	2014/04/09		永瀬鈴久
//		VERSION:	1.0
//

#include "InputManager.h"
#include "Constants.h"


// 入力管理共有インスタンス本体
InputManager* InputManager::m_sharedInputManager = NULL ;

// コンストラクタ
InputManager::InputManager()
{
	this->m_keyFlag.clear() ;
}

// デストラクタ
InputManager::~InputManager()
{
	this->m_keyFlag.clear() ;
}

//=============================================================================
//	getInstance
//		共有インスタンスの取得
//	-----------------------------------------------------------------------
//	INPUT:	 ---
//	OUTPUT:	 void
//=============================================================================
InputManager* InputManager::getInstance()
{
	if ( InputManager::m_sharedInputManager == NULL )
	{
		InputManager::m_sharedInputManager = new InputManager() ;
	}
	return InputManager::m_sharedInputManager ;
}

//=============================================================================
//	onKeyPressed
//		キーボードを押した際のイベント
//	-----------------------------------------------------------------------
//	INPUT:		cocos2d::EventKeyboard::KeyCode		キーコード
//	OUTPUT:		void
//=============================================================================
void InputManager::onKeyPressed( cocos2d::EventKeyboard::KeyCode keyCode )
{
	// フラグを上げる
	this->m_keyFlag.up( this->changeToKeyFlagFromKeyCode( keyCode ) ) ;
}

//=============================================================================
//	onKeyReleased
//		キーボードを離した際のイベント
//	-----------------------------------------------------------------------
//	INPUT:		cocos2d::EventKeyboard::KeyCode		キーコード
//	OUTPUT:		void
//=============================================================================
void InputManager::onKeyReleased( cocos2d::EventKeyboard::KeyCode keyCode ) 
{
	// フラグを下げる
	this->m_keyFlag.down( this->changeToKeyFlagFromKeyCode( keyCode ) ) ;  
}



//=============================================================================
//	changeToKeyFlagFromKeyCode
//		キーコードからキーフラグへ変換
//	-----------------------------------------------------------------------
//	INPUT:		cocos2d::EventKeyboard::KeyCode		キーコード
//	OUTPUT:		const unsigned int					キーフラグ
//	TIPS:		最適化用、このメソッドまだ使用はしていない
//				このメソッドを使用して上記の３つのメソッドを最適化する
//	-----------------------------------------------------------------------
//	VERSION:	2.0
//=============================================================================
unsigned int InputManager::changeToKeyFlagFromKeyCode( cocos2d::EventKeyboard::KeyCode keyCode )
{
	// エスケープキーかどうか判定
	if ( cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE == keyCode )
	{
		// エスケープキーを返す
		return KEY_FLAG::ESCAPE ;
	}
	// スペースキーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_SPACE == keyCode )
	{
		// スペースキーを返す
		return KEY_FLAG::SPACE ;
	}
	// 上矢印キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW == keyCode )
	{
		// 上矢印キーを返す
		return KEY_FLAG::UP ;
	}
	// 下矢印キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW == keyCode )
	{
		// 下矢印キーを返す
		return KEY_FLAG::DOWN ;
	}
	// 左矢印キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW == keyCode )
	{
		// 左矢印キーを返す
		return KEY_FLAG::LEFT ;
	}
	// 右矢印キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW == keyCode )
	{
		// 右矢印キーを返す
		return KEY_FLAG::RIGHT ;
	}
	// Z キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_Z == keyCode )
	{
		// Z キーを返す
		return KEY_FLAG::Z_KEY ;
	}
	// X キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_X == keyCode )
	{
		// X キーを返す
		return KEY_FLAG::X_KEY ;
	}
	// C キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_C == keyCode )
	{
		// C キーを返す
		return KEY_FLAG::C_KEY ;
	}
	// A キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_A == keyCode )
	{
		// A キーを返す
		return KEY_FLAG::A_KEY ;
	}
	
	// エラー
	return KEY_FLAG::NONE ;	
}

//=============================================================================
//	isKeyPressed
//		指定したキーが押されているかどうかを調べる
//	-----------------------------------------------------------------------
//	INPUT:		unsigned int flag_			キーフラグ
//	OUTPUT:		bool
//						true  = 押されている
//						false = 押されていない
//=============================================================================
bool InputManager::isKeyPressed( unsigned int flag_ )
{
	return this->m_keyFlag.check( flag_ ) ;
}






