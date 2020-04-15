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
	//メンバー変数初期化
	this->Handle = 0;			//ハンドル初期化
	this->AnimTotalTime = 0.0;	//アニメーションの総合時間初期化
	this->AnimNowTime = 0.0;	//現在のアニメーションの時間初期化
	this->AnimAttachIndex = 0;	//アタッチするアニメーション番号を初期化
	this->IsLoad = false;		//読み込めていない

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

//アニメーションをアタッチする
bool MODEL::AttachAnim()
{

	//走りアニメーションをアタッチ
	this->AnimAttachIndex = MV1AttachAnim(this->Handle, 1);		
	if (this->AnimAttachIndex == -1)	//エラー発生時
	{
		return false;	//アタッチ失敗
	}

	//走りアニメーションのそう時間を取得
	this->AnimTotalTime = MV1GetAttachAnimTotalTime(this->Handle, this->AnimAttachIndex);

	//アニメーション再生時間を初期化
	this->AnimNowTime = 0.0f;
	MV1SetAttachAnimTime(this->Handle, this->AnimAttachIndex, this->AnimNowTime);
	if (this->AnimNowTime == -1)	//エラー発生時
	{
		return false;		//アタッチ失敗
	}

	return true;	//アタッチ成功

}

//アニメーション処理
/*
引数：int：アニメーション速度：指定がない場合は、デフォルトのスピードが入る
*/
void MODEL::Animation(int speed)
{

	//アニメーションの再生時間を進める
	this->AnimNowTime += speed;

	//アニメーション再生時間がアニメーションのそう時間を超えていたらループさせる
	if (this->AnimNowTime >= this->AnimTotalTime)
	{
		//新しいアニメーション再生時間は、アニメーション再生時間からアニメーションそう時間を引いたもの
		this->AnimNowTime -= this->AnimTotalTime;
	}

	//新しいアニメーション再生時間をセット
	MV1SetAttachAnimTime(this->Handle, this->AnimAttachIndex, this->AnimNowTime);

	//3Dモデルの描画
	this->Draw();

	return;

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
