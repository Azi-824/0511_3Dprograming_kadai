//MODEL.cpp
//3Dモデルを管理するクラス

//############# ヘッダファイル読み込み ###################
#include "MODEL.hpp"

//############ クラス定義 #################

//コンストラクタ
/*
引数：const char *：3Dモデルのファイルディレクトリ
引数：const char *：3Dモデルのデータ名
*/
MODEL::MODEL(const char *dir, const char *name)
{
	this->Handle = 0;		//ハンドル初期化
	this->IsLoad = false;	//読み込めていない

	std::string LoadPath;	//ロードファイル名
	LoadPath = dir;			//ディレクトリ名
	LoadPath += name;		//ファイル名

	this->Handle = MV1LoadModel(LoadPath.c_str());	//3Dモデル読み込み
	
	if (this->Handle == -1)	//読み込み失敗したら
	{
		this->IsLoad = false;	//読み込み失敗
		return;					//終了
	}

	this->SetPos(VGet(MODEL_DEF_X, MODEL_DEF_Y, MODEL_DEF_Z));	//3Dモデルをデフォルト位置に設定

	this->IsLoad = true;		//読み込み成功

	return;	//終了

}

//デストラクタ
MODEL::~MODEL()
{
	MV1DeleteModel(this->Handle);	//3Dモデル破棄
	return;
}

//読み込めたか取得
bool MODEL::GetIsLoad()
{
	return this->IsLoad;
}

//位置設定
void MODEL::SetPos(VECTOR pos)
{
	MV1SetPosition(this->Handle, pos);	//3Dモデル位置調整

	return;

}

//描画
void MODEL::Draw()
{
	MV1DrawModel(this->Handle);	//3Dモデル描画
}
