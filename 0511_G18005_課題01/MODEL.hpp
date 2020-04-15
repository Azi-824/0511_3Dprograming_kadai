//MODEL.hpp
//3Dモデルを管理するクラス

#pragma once

//########### ヘッダファイル読み込み ################
#include "DxLib.h"
#include <string>

//########### マクロ定義 ##############
#define MODEL_DIR		R"(.\Model\)"					//3Dモデルのディレクトリ
#define MODEL_NAME		R"(0511_G18005_3Dmodel.mqo)"	//3Dモデルの名前

#define MODEL_DEF_X		100.0f			//3DモデルのデフォルトのX位置
#define MODEL_DEF_Y		100.0f			//3DモデルのデフォルトのY位置
#define MODEL_DEF_Z		100.0f			//3DモデルのデフォルトのZ位置

//########## クラス定義 ###############
class MODEL
{
private:

	int Handle;		//ハンドル

	bool IsLoad;	//読み込めたか

public:

	MODEL(const char *, const char *);		//コンストラクタ
	~MODEL();								//デストラクタ

	bool GetIsLoad();						//読み込めたか取得

	void SetPos(VECTOR);					//位置設定
	void Draw();							//描画

};
