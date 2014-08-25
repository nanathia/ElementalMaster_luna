#ifndef __Stg14__Window__
#define __Stg14__Window__

#include "cocos2d.h"
#include <string>
#include <deque>
#include <string.h>

using namespace cocos2d;

struct _tagTEXTURE;
typedef struct _tagTEXTURE TEXTURE;

// クラスの宣言
/// 使用法は変数宣言と同じ
class CNameWindow;
class CMessageWindow;
class CMessage;
class CLunaFace;
class WindowState;

// まとめ。
class WindowConsole{
	
	// ウィンドウクラスとメッセージクラスをそれぞれメンバに持つ
	CNameWindow* m_Name_win;
	CMessageWindow* m_Message_win;
	CMessage* m_Message;
	CLunaFace* m_lunaFace;
	WindowState* m_windowState;
    // dequeっていうのはいわゆるコンテナクラス。vectorに似てる。
	std::deque<std::string*> m_poolStrings;
	
public:
	// コンストラクタ
	WindowConsole();
	// デストラクタ
	~WindowConsole();
	
	// 更新処理
	void update(double deltaTime);
    // 次の文字送り始まり。
	void nextLabel(const std::string& str);
    // キャラクターの名前をつける。
    void setCharacterName(const std::string& str);
	
public:
	// メッセージウィンドウのアクセスします・ｗ・
	CNameWindow* getNameWindow();
	CMessageWindow* getMessageWindow();
	CMessage* getMessage();
	CLunaFace* getLunaSprite();
	
};

// 名前窓。
class CNameWindow{
	cocos2d::Sprite* m_Window;
    // 領域。でも単に位置でもいい気がしてきた。
	Rect m_rect;
	LabelTTF* m_label;
	
public:
	CNameWindow();
	~CNameWindow();
	void update(double deltaTime);
public:
	void setName(const std::string& str);
	cocos2d::Sprite* getSprite();
};

// メッセージ窓。
class CMessageWindow{
	cocos2d::Sprite* m_Sprite;
    // 領域。でも単に位置でもいい気がしてきた。
	Rect m_rect;
	double m_time;
	
public:
	CMessageWindow();
	~CMessageWindow();
	void update(double input);
public:
    bool isVisibled();
	cocos2d::Sprite* getSprite();
    void setScale(float scaleX);
};

// 文字。
class CChar{
	LabelTTF* m_label;		// cocos2d CCLabelTTF
	Point m_point;			// cocos2d Point型座標変数
	double m_time;			// 描画時間
    CChar* m_next;			// 次に描画する文字列を格納
    CChar* m_prev;			// 前に表示した文字列を格納
	
public:
	// コンストラクタ
	/// 文字列と座標を引数に取る
	CChar(const std::string& str, const Point& point);
	
	// デストラクタ
	~CChar();
	
	// アップデート
	void update(double input);
public:
    // 文字を数珠つなぎにするために、次と前をセットできるようにしてる。
	// 数珠つなぎとは連結のことだと思っている
	// std::dequeを使うための布石かな？
    void setNext(CChar* next);
    void setPrev(CChar* prev);
	
    // 次の文字から呼ばれる。出撃していいですかー？
	/// つまるところ、文字表示が完了しているか調べる関数である
    bool isEnableNextLunch();
	
};

// メッセージ。
class CMessage{
	Point m_point;			//cocos2d Point型 ここも座標
    // dequeっていうのはいわゆるコンテナクラス。vectorに似てる。
	std::deque<CChar*> m_characters;
	
public:
	// コンストラクタ
	/// ここでも文字列とポイント型を引数に取る
	CMessage(const std::string& message, const Point& point);
	
	// デストラクタ
	~CMessage();
	
	// 更新処理
	void update(double deltaTime);
};





#endif /* defined(__Stg14__Window__) */
