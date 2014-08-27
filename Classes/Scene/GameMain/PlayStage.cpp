#include "PlayStage.h"
#include "PlayStage1.h"

PlayStage::PlayStage(GameMain* user):
m_child(0){
    m_child = new stage1::PlayStage1(user);
}
PlayStage::~PlayStage(){
    delete m_child;
    m_child = 0;
}
void PlayStage::update(float deltaTime){
    PlayStateChild* nextChild = m_child->update(deltaTime);
    if(nextChild != m_child){
        delete m_child;
        m_child = nextChild;
    }
}

PlayStateChild::PlayStateChild(GameMain*user):
m_user(user){
}
PlayStateChild::~PlayStateChild(){
}


//PlayStage2::PlayStage2(GameMain* user):
//PlayStateChild(user){
//}
//PlayStage2::~PlayStage2(){
//}
//PlayStateChild* PlayStage2::update(float deltaTime){
//    PlayStateChild* next = this;
//    return next;
//}
//PlayStage3::PlayStage3(GameMain* user):
//PlayStateChild(user){
//}
//PlayStage3::~PlayStage3(){
//}
//PlayStateChild* PlayStage3::update(float deltaTime){
//    PlayStateChild* next = this;
//    return next;
//}
