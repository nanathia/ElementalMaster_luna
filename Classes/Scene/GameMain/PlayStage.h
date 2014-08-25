//
//  PlayStage.h
//  Stg14
//
//  Created by 小林　伸 on 2014/08/25.
//
//

#ifndef __Stg14__PlayStage__
#define __Stg14__PlayStage__

class GameMain;
class PlayStage;
class PlayStateChild{
protected:
    GameMain* m_user;
public:
    PlayStateChild(GameMain* user);
    virtual ~PlayStateChild();
    virtual PlayStateChild* update(float deltaTime) = 0;
};

//class PlayStage2: public PlayStateChild{
//public:
//    PlayStage2(GameMain* user);
//    ~PlayStage2();
//    PlayStateChild* update(float deltaTime) override;
//};
//
//class PlayStage3: public PlayStateChild{
//public:
//    PlayStage3(GameMain* user);
//    ~PlayStage3();
//    PlayStateChild* update(float deltaTime) override;
//};

class PlayStage{
    PlayStateChild* m_child;
public:
    PlayStage(GameMain* user);
    ~PlayStage();
    void update(float deltaTime);
};


#endif /* defined(__Stg14__PlayStage__) */
