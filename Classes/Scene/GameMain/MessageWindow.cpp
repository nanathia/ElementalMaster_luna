#include "MessageWindow.h"
#include "GameMain.h"
#include "Constants.h"
#include "ImageUtil.h"
#include "InputManager.h"
#include "SimpleAudioEngine.h"
#include "WindowState.h"
#include "TextureManager.h"

using namespace std;
using namespace CocosDenshion;

// ウィンドウ総合クラス。
#pragma mark --- ウィンドウ総合 ---

// ウィンドウコンソール、コンストラクタでメッセージウィンドウ２種、インスタンスを生成
WindowConsole::WindowConsole():
m_Name_win(0),
m_Message_win(0),
m_Message(0),
m_lunaFace(0),
m_windowState(0)
{
	m_Message_win = new CMessageWindow;
    m_Name_win = new CNameWindow;
	m_windowState = new WindowState(this);
	
}

// デストラクタ
WindowConsole::~WindowConsole(){
	// メンバである各ウィンドウをデリート
	// その後、NULLポインタを入れておく
    delete m_Message_win;
    m_Message_win = 0;
    delete m_Name_win;
    m_Name_win = 0;
	// メッセージがデリートされてなければデリートします
    if(m_Message) delete m_Message;
}

// ウィンドウコンソール、更新処理
void WindowConsole::update(double deltaTime){
	m_windowState->update(deltaTime);
	// それぞれのインスタンスから更新処理を呼び出す
    m_Message_win->update(deltaTime);
    m_Name_win->update(deltaTime);
	// 呼び出し後、isVisibled()が呼び出されてカウンタが1.0になったらtrueを返すのでtrueを受け取ったらメッセージ更新処理開始
    if(m_Message && m_Message_win->isVisibled()) m_Message->update(deltaTime);
}

// ウィンドウコンソール nextLabel
void WindowConsole::nextLabel(const std::string &str){
	// まずは文字列の削除とNULLを代入
    if(m_Message) delete m_Message;
    m_Message = 0;
	// そして新たに生成
	// コンストラクタに文字列と座標を入れてコンストラクタ呼び出し
    m_Message = new CMessage(str, Point(30, 200));
}

void WindowConsole::setCharacterName(const std::string& str){
    m_Name_win->setName(str);
}


// １枚かまーす・ｗ・
CNameWindow* WindowConsole::getNameWindow()
{
	return m_Name_win;
}

CMessageWindow* WindowConsole::getMessageWindow()
{
	return m_Message_win;
}

CMessage* WindowConsole::getMessage()
{
	return m_Message;
}

CLunaFace* WindowConsole::getLunaSprite()
{
	return m_lunaFace;
}


// メッセージ窓
#pragma mark ---メッセージ窓---
CMessageWindow::CMessageWindow():
m_rect(),
m_time(0),
m_Sprite(0)
{
	// スプライトを指定
	m_Sprite = gGameMain->getTexMan()->createSprite(GameMain::texName_MessageWindow, gGameMain);
	// 画面サイズを取得
    Size ImSize = m_Sprite->getTexture()->getContentSize();
    // テクスチャのセンター位置を指定
	m_rect.origin = ImSize/2;
	
	// オリジンを元に描画設定
	m_Sprite->setPosition(302, 130);//m_rect.origin);
	m_Sprite->setOpacity(200);
	m_Sprite->setZOrder(5);
    m_Sprite->setVisible(true);
}

CMessageWindow::~CMessageWindow(){
	// デストラクタでウィンドウを消去後、NULLを指定
	if(m_Sprite) m_Sprite->removeFromParentAndCleanup(true);
    m_Sprite = 0;
}
void CMessageWindow::update(double deltaTime){
	// ウィンドウのびゅいーんをフレームレートに依存
    m_time += deltaTime;
	
	// びゅいーん時間は1.0以上行かないようにする
    if(m_time >= 1.0){
        m_time = 1.0;
    }
	// スプライト(x, y)大きさをm_timeに依存、と等倍
    //m_Sprite->setScale(m_time, 1.0);
}
bool CMessageWindow::isVisibled(){
	// m_time が 1.0 になれば３項式でtrue を返す
    return m_time == 1.0 ? true: false;
}

cocos2d::Sprite* CMessageWindow::getSprite()
{
	return m_Sprite;
}

void CMessageWindow::setScale(float scaleX){
    m_Sprite->setScale(scaleX, 1.0);
}

// キャラクター名前窓（名前、窓）
#pragma mark ---名前窓---
CNameWindow::CNameWindow():
m_Window(0),
m_rect(0, 150, 0, 0),
m_label(0)
{
	m_Window = gGameMain->getTexMan()->createSprite(GameMain::texName_MessageNameWindow, gGameMain);
    
    Size ImSize = gGameMain->getTexMan()->get(GameMain::texName_MessageWindow)->m_pTexture->getContentSize();
    ImSize.height += 500;
    m_Window->setPosition(140, 275);//Point(ImSize/2));
	m_Window->setZOrder(5);
	m_Window->setOpacity(200);
    // とりあえずはルナの名前を入れておく
    this->setName("ルナ");
}

CNameWindow::~CNameWindow(){
	// ネームウィンドウの解放
	m_Window->removeFromParentAndCleanup(true);
	
	// メッセージラベルをデリート後、NULLポインタを指定
    if(m_label) m_label->removeFromParentAndCleanup(true);
    m_label = 0;
}

void CNameWindow::setName(const std::string& str){
	// NULLポインタを指定していない場合
	if(m_label){
		m_label->removeFromParentAndCleanup(true);
		m_label = 0;
		// とりあえず解放
	}
	
	// 描画
	m_label = LabelTTF::create(str.c_str(), "Aqua_pfont", 30);
    gGameMain->addChild(m_label);
	// 位置を指定
    m_label->setPosition(50, 280);
	// Ｚオーダを指定
    m_label->setZOrder(6);
}

void CNameWindow::update(double deltaTime){
	
	// ネームウィンドウの更新処理を書く
}

cocos2d::Sprite* CNameWindow::getSprite()
{
	return m_Window;
}

// 一文字。
// 初期化ご、NULLを入れておく
#pragma mark --- １文字 ---
CChar::CChar(const std::string& str, const Point& pos):
m_label(0),
m_time(0),
m_next(0),
m_prev(0),
m_point(pos){
	// 描画
    m_label = CCLabelTTF::create(str.c_str(), "Aqua_pfont", 30);
    gGameMain->addChild(m_label);
	
    // 描画位置を指定
	m_label->setPosition(pos);
	m_label->setOpacity(0);
	
	// ステージセレクトはこれを採用しようかね、かっこいい
	///
	//m_label->setScale(3.0f);
	m_label->setZOrder(6);
}

CChar::~CChar(){
	// デストラクタ
    if(m_label) m_label->removeFromParentAndCleanup(true);
    m_label = 0;
}

void CChar::setNext(CChar* next){
    m_next = next;
}

void CChar::setPrev(CChar* prev){
    m_prev = prev;
}

void CChar::update(double deltaTime){
    if(m_prev){
        // 前の文字があるときは前が「行っていいよ」って言うまで待つのよー。
		/// つまりGOフラグを返すということか
        if(!m_prev->isEnableNextLunch()){
            return;
        }
    }
    m_time += deltaTime*2;
    if(m_time >= 1){
        m_time = 1;
    }
    if(m_label){
		m_label->setOpacity(m_time*255);
		//m_label->setScale(1/m_time);
	}
}

bool CChar::isEnableNextLunch(){
    // ０．２秒たったら次の文字が出るのよー。
    return m_time >= 0.27 ? true: false;
}


// 一回に流れるメッセージ。
#pragma mark ---メッセージ---
CMessage::CMessage(const std::string& str, const Point& point):
m_point(point)
{
    int size = (int)str.size();
    // 最大横文字数１８に。
    const int widthMax = 18;
	int x = 0;
	int y = 0;
    const int characterSize = 32;
    // １文字ずつ生成よ。
    for(int i = 0; i < size; i+=3){
        Point pos(x*characterSize+45, 212-y*characterSize);
        char character[4];
		
        character[0] = str.c_str()[i];
        character[1] = str.c_str()[i+1];
        character[2] = str.c_str()[i+2];
        character[3] = '\0';
		
		if(strcmp(character,"嬲")==0)
		{
			y ++;
			x = 0;
			continue;
		}else if(x > widthMax){
            y++;
            x = 0;
        }
        x++;
        CChar* new_c = new CChar(character, pos);
        if(i != 0){
            // .back() っていうのは一番後ろって意味よー。
            m_characters.back()->setNext(new_c);
            new_c->setPrev(m_characters.back());
		}
        m_characters.push_back(new_c);
    }
    
}

CMessage::~CMessage(){
    // 強参照とか弱参照とか。そういうの使って、delete。
    int size = (int)m_characters.size();
    for(int i = 0; i < size; i++){
        delete m_characters[i];
        m_characters[i] = 0;
    }
}

void CMessage::update(double deltaTime){
    // 強参照とか弱参照とか。そういうの使って、delete。
    int size = (int)m_characters.size();
    for(int i = 0; i < size; i++){
        m_characters[i]->update(deltaTime);
    }
}

