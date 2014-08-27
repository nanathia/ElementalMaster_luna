#ifndef __Stg14__PlayStage1State__
#define __Stg14__PlayStage1State__

#include "cocos2d.h"

class StandingLunaImage;
class WindowConsole;
class StageStartEffect;

namespace stage1{
    
    class PlayStage1;
    class State;
    // 基底
    class StateChild{
    protected:
        PlayStage1* m_user;
    public:
        StateChild(PlayStage1* user);
        virtual ~StateChild();
        virtual StateChild* update(float deltaTime) = 0;
    };
	
	// ステージ開始 レディー？シーン
    class ReadyScene: public StateChild{
		StageStartEffect* m_startEffect;
    public:
        ReadyScene(PlayStage1* user);
        ~ReadyScene();
        StateChild* update(float deltaTime) override;
    };
	
	// 最初にルナちゃんが喋るシーン
    class SpeakScene1: public StateChild{
        StandingLunaImage* m_Tatie;
        WindowConsole* m_messageWindow;
    public:
        SpeakScene1(PlayStage1* user);
        ~SpeakScene1();
        StateChild* update(float deltaTime) override;
    };
	
	

    
    // 落下を開始する前に、自由に動けるシーン
    class FirstFreeMove_Scene: public StateChild{
    public:
        FirstFreeMove_Scene(PlayStage1* user);
        ~FirstFreeMove_Scene();
        StateChild* update(float deltaTime) override;
    };
    
    // 落下しながら、出てくる敵と戦うシーン
    class FallAndFight_Scene: public StateChild{
    public:
        FallAndFight_Scene(PlayStage1* user);
        ~FallAndFight_Scene();
        StateChild* update(float deltaTime) override;
    };
    
    // 着地シーン
    class Grounding_Scene: public StateChild{
    public:
        Grounding_Scene(PlayStage1* user);
        ~Grounding_Scene();
        StateChild* update(float deltaTime) override;
    };
    
    // ボスと戦うシーン
    class BossFight_Scene: public StateChild{
    public:
        BossFight_Scene(PlayStage1* user);
        ~BossFight_Scene();
        StateChild* update(float deltaTime) override;
    };
    
    // KA☆MA☆SU パターン
    class State{
        StateChild* m_child;
    public:
        State(PlayStage1* user);
        ~State();
        void update(float deltaTime);
    };
    
    
}

#endif /* defined(__Stg14__PlayStage1State__) */
