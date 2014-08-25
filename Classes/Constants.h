//
//  Constants.h
//  Stg14
//
//  Created by 永瀬鈴久 on 2014/04/06.
//
//	汎用定数・定義用ヘッダファイル
//
//	2014/04/06		永瀬鈴久
//		VERSION:	1.0
//

#ifndef Stg14_Constants_h
#define Stg14_Constants_h

// マクロ定義 ===========================================================================
#define SAFE_DELETE(p_)			{if(p_){delete p_;p_=NULL;}}
#define SAFE_DELETE_ARRAY(p_)	{if(p_){delete [] p_;p_=NULL;}}

template <typename T>
void SafeCleanSwap(T* p_){p_->clear();T().swap(*p_);}
#define SAFE_CLEAN_SWAP(p_) SafeCleanSwap(p_)

#define FAILED(a_)	a_==false?true:false

// 記号定数定義 ===========================================================================
#define PI			(3.1415926535897932384626433832795)

#define NO_DATA		(-1)


#endif	// Stg14_Constants_h
