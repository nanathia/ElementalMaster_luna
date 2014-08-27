#ifndef __Stg14__WindowState__
#define __Stg14__WindowState__

#include "cocos2d.h"

// クラス宣言
class WindowConsole;			// ウィンドウコンソール
class WindowState;
struct _tagTEXTURE;
typedef struct _tagTEXTURE TEXTURE;

// ウィンドウステイト 定義は後で

// ここに状態の遷移処理及び子どもたちをもたせる
class WindowStateChild{
protected:
	WindowConsole* m_user;
public:
	// コンストラクタ
	WindowStateChild(WindowConsole* user);
	
	// 仮想デストラクタ
	virtual ~WindowStateChild();
	// 純粋仮想関数でオーバーライドさせる下準備
	virtual WindowStateChild* update(double deltaTime) = 0;
};

// 表示モード
class WindowOn: public WindowStateChild{
public:
	WindowOn(WindowConsole* user);
	~WindowOn();
	WindowStateChild* update(double deltaTime) override;
};

// 非表示モード
class WindowOff: public WindowStateChild{
public:
	WindowOff(WindowConsole* user);
	~WindowOff();
	WindowStateChild* update(double deltaTime) override;
};

// 徐々に出現する状態
class WindowAppear: public WindowStateChild{
    float m_time;
public:
	WindowAppear(WindowConsole* user);
	~WindowAppear();
	WindowStateChild* update(double deltaTime) override;
};

// 徐々に消える状態
class WindowDisappear: public WindowStateChild{
    float m_time;
public:
	WindowDisappear(WindowConsole* user);
	~WindowDisappear();
	WindowStateChild* update(double deltaTime) override;
};

class WindowState{
	WindowStateChild* m_child;
public:
	WindowState(WindowConsole* user);
	~WindowState();
	void update(double deltaTime);
};
#endif /* defined(__Stg14__WindowState__) */
