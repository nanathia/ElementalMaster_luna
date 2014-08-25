//
//  PlayStage1.h
//  Stg14
//
//  Created by 小林　伸 on 2014/08/25.
//
//

#ifndef __Stg14__PlayStage1__
#define __Stg14__PlayStage1__

#include "cocos2d.h"
#include "PlayStage.h"


namespace stage1{
    class State;
    
    class PlayStage1: public PlayStateChild{
        State* m_state;
        cocos2d::Sprite* m_bgSprite;
        
    public:
        PlayStage1(GameMain* user);
        ~PlayStage1();
        PlayStateChild* update(float deltaTime) override;
    };
    
}

#endif /* defined(__Stg14__PlayStage1__) */
