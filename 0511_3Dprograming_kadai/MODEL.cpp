//MODEL.cpp
//3D���f�����Ǘ�����N���X

//############# �w�b�_�t�@�C���ǂݍ��� ###################
#include "MODEL.hpp"

//############ �N���X��` #################

//�R���X�g���N�^
/*
�����Fconst char *�F3D���f���̃t�@�C���f�B���N�g��
�����Fconst char *�F3D���f���̃f�[�^��
*/
MODEL::MODEL(const char *dir, const char *name)
{
	this->Handle = 0;		//�n���h��������
	this->IsLoad = false;	//�ǂݍ��߂Ă��Ȃ�

	std::string LoadPath;	//���[�h�t�@�C����
	LoadPath = dir;			//�f�B���N�g����
	LoadPath += name;		//�t�@�C����

	this->Handle = MV1LoadModel(LoadPath.c_str());	//3D���f���ǂݍ���
	
	if (this->Handle == -1)	//�ǂݍ��ݎ��s������
	{
		this->IsLoad = false;	//�ǂݍ��ݎ��s
		return;					//�I��
	}

	this->SetPos(VGet(MODEL_DEF_X, MODEL_DEF_Y, MODEL_DEF_Z));	//3D���f�����f�t�H���g�ʒu�ɐݒ�

	this->IsLoad = true;		//�ǂݍ��ݐ���

	return;	//�I��

}

//�f�X�g���N�^
MODEL::~MODEL()
{
	MV1DeleteModel(this->Handle);	//3D���f���j��
	return;
}

//�ǂݍ��߂����擾
bool MODEL::GetIsLoad()
{
	return this->IsLoad;
}

//�ʒu�ݒ�
void MODEL::SetPos(VECTOR pos)
{
	MV1SetPosition(this->Handle, pos);	//3D���f���ʒu����

	return;

}

//�`��
void MODEL::Draw()
{
	MV1DrawModel(this->Handle);	//3D���f���`��
}
