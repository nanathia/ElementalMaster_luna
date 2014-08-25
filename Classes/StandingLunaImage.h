//
//  StandingLunaImage.h
//  Stg14
//
//  Created by 小林　伸 on 2014/08/26.
//
//

#ifndef __Stg14__StandingLunaImage__
#define __Stg14__StandingLunaImage__

#include "cocos2d.h"


// 現状では、GameMainクラスが生成されている状況でのみ動作するクラス。
// 他のcocos2d::Layerを継承したシーンにも対応できるが、メンドイのでやめとく。
// というかそもそも、GameMain以外で使わんだろ？
class StandingLunaImage{
public:
    enum FaceName{
        FaceName_Hutuu,
        FaceName_Egao,
        FaceName_Hutuu_teawase,
        FaceName_Egao_teawase,
        FaceName_Syobon,
        FaceName_Pokan_teawase,
        FaceName_Komaru_teawase,
        
        FaceName_None = -99,
    };
private:
    cocos2d::Sprite* m_sprite;
    FaceName m_currentFace;
public:
    StandingLunaImage();
    ~StandingLunaImage();
    // 表情を変える
    void changeFace(FaceName name);
    void InterEffect();
public:
    cocos2d::Sprite* getSprite();
    
};

#endif /* defined(__Stg14__StandingLunaImage__) */
