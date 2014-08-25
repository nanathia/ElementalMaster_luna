//
//  ImageUtil.cpp
//  Stg14
//
//  Created by 永瀬鈴久 on 2014/05/16.
//
//	2014/05/16		永瀬鈴久
//
//		画像とテクスチャを汎用的に扱うモジュール
//

#include "ImageUtil.h"

#include "Constants.h"

using namespace cocos2d ;



//=============================================================================
//	loadImage
//		画像の読み込み
//	-----------------------------------------------------------------------
//	INPUT:	std::string						ファイル名
//			TEXTURE*						テクスチャ
//	OUTPUT:	bool	true...読み込み成功
//					false...読み込み失敗
//=============================================================================
bool loadImage( const std::string& fileName, TEXTURE* pTex )
{
	// ファイル名を設定
	pTex->m_fileName = fileName ;
	
	// 画像ファイルをテクスチャに読み込めるよう解析する
	pTex->m_pImage = new Image() ;
	if ( FAILED ( pTex->m_pImage->initWithImageFile( fileName ) ) ) 
	{
		CCLOG( "画像がありません。\n" ) ;
		return false ;
	}
	
	// 解析した画像ファイルをテクスチャに読み込む 
	pTex->m_pTexture = new Texture2D() ;
	if ( FAILED( pTex->m_pTexture->initWithImage( pTex->m_pImage ) ) )
	{
		CCLOG( "テクスチャの生成に失敗。\n" ) ;
		return false ;
	}
	
	return true ;
}

//=============================================================================
//	releaseTexture
//		開放するテクスチャ
//	-----------------------------------------------------------------------
//	INPUT:	TEXTURE*						テクスチャ
//	OUTPUT:	void
//=============================================================================
void releaseTexture( TEXTURE* pTex )
{
	SAFE_DELETE( pTex->m_pImage ) ;
	SAFE_DELETE( pTex->m_pTexture ) ;
	pTex->m_fileName = "" ;
}