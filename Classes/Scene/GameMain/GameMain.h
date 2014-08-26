
#ifndef __Stg14__GameMain__
#define __Stg14__GameMain__

#include "cocos2d.h"


class PlayStage;
class TextureManager;
class CPlayerLuna;

// ゲームのメイン部分。プレイシーン。
// プレイシーンで共通するものとしては、
// uiとメニュー画面は共通だろう。
// なので、とりあえずここにスプライトを置く。
// 追々、クラスにすることが推奨される。
class GameMain : public cocos2d::Layer {
    // ステージ
    PlayStage* m_currentScene;
    // テクスチャ管理クラス。
    TextureManager* m_TexMan;
    // ルナ
    CPlayerLuna* m_Luna;
    // メニュー画面
    cocos2d::Sprite* m_Menu;
    // ui
    cocos2d::Sprite* m_StatusUi;
public:
    // 画像を列挙型でナンバリング。std::mapのキーとして使用。
    // 同時に、z-orderとして使用する。
    enum texName{
        texName_StageBGI,
        texName_StatusUI,
        texName_Asiba,
        texName_Ready,
        texName_Smoke,
        texName_Block,
        texName_MessageNameWindow,
        texName_MessageWindow,
        texName_ShootingBlaze,
        texName_Ground,
        texName_ForceAllow,
        texName_LunaChips,
        texName_LunaFace,
        texName_Pause,
        texName_PushCKey,
        texName_Menu,
    };
	GameMain();
	~GameMain();
	static cocos2d::Scene* createScene() ;
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) override ;
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event) override;
    bool init() override;
    bool initGame();
    // ここまでテンプレ。
public:
    // ここからを主に変更。
	virtual void update(float deltaTime) override;
public:
    // プレイシーン内部から使うメソッド
    TextureManager* getTexMan();
    CPlayerLuna* getLuna();
};

extern GameMain* gGameMain;

#endif /* defined(__Stg14__GameMain__) */
