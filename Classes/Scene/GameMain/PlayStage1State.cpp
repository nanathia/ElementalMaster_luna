//
//  PlayStage1State.cpp
//  Stg14
//
//  Created by 小林　伸 on 2014/08/25.
//
//

#include "PlayStage1State.h"
#include "StandingLunaImage.h"
#include "MessageWindow.h"


namespace stage1{
    
    State::State(PlayStage1* user):
    m_child(0){
        m_child = new SpeakScene1(user);
    }
    State::~State(){
        delete m_child;
        m_child = 0;
    }
    void State::update(float deltaTime){
        StateChild* nextChild = m_child->update(deltaTime);
        if(nextChild != m_child){
            delete m_child;
            m_child = nextChild;
        }
    }
    
    StateChild::StateChild(PlayStage1*user):
    m_user(user){
    }
    StateChild::~StateChild(){
    }
    
    SpeakScene1::SpeakScene1(PlayStage1* user):
    StateChild(user),
    m_Tatie(0),
    m_messageWindow(0){
        m_messageWindow = new WindowConsole;
        m_Tatie = new StandingLunaImage;
        m_Tatie->changeFace(StandingLunaImage::FaceName_Egao);
    }
    SpeakScene1::~SpeakScene1(){
        delete m_Tatie;
        m_Tatie = 0;
        delete m_messageWindow;
        m_messageWindow = 0;
    }
    StateChild* SpeakScene1::update(float deltaTime){
        StateChild* next = this;
        m_messageWindow->update(deltaTime);
        return next;
    }
    FirstFreeMove_Scene::FirstFreeMove_Scene(PlayStage1* user):
    StateChild(user){
    }
    FirstFreeMove_Scene::~FirstFreeMove_Scene(){
    }
    StateChild* FirstFreeMove_Scene::update(float deltaTime){
        StateChild* next = this;
        return next;
    }
    FallAndFight_Scene::FallAndFight_Scene(PlayStage1* user):
    StateChild(user){
    }
    FallAndFight_Scene::~FallAndFight_Scene(){
    }
    StateChild* FallAndFight_Scene::update(float deltaTime){
        StateChild* next = this;
        return next;
    }
    Grounding_Scene::Grounding_Scene(PlayStage1* user):
    StateChild(user){
    }
    Grounding_Scene::~Grounding_Scene(){
    }
    StateChild* Grounding_Scene::update(float deltaTime){
        StateChild* next = this;
        return next;
    }
    BossFight_Scene::BossFight_Scene(PlayStage1* user):
    StateChild(user){
    }
    BossFight_Scene::~BossFight_Scene(){
    }
    StateChild* BossFight_Scene::update(float deltaTime){
        StateChild* next = this;
        return next;
    }
    
}