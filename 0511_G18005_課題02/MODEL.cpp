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
	//�����o�[�ϐ�������
	this->Handle = 0;			//�n���h��������
	this->AnimTotalTime = 0.0;	//�A�j���[�V�����̑������ԏ�����
	this->AnimNowTime = 0.0;	//���݂̃A�j���[�V�����̎��ԏ�����
	this->AnimAttachIndex = 0;	//�A�^�b�`����A�j���[�V�����ԍ���������
	this->IsLoad = false;		//�ǂݍ��߂Ă��Ȃ�

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

//�A�j���[�V�������A�^�b�`����
bool MODEL::AttachAnim()
{

	//����A�j���[�V�������A�^�b�`
	this->AnimAttachIndex = MV1AttachAnim(this->Handle, 1);		
	if (this->AnimAttachIndex == -1)	//�G���[������
	{
		return false;	//�A�^�b�`���s
	}

	//����A�j���[�V�����̂������Ԃ��擾
	this->AnimTotalTime = MV1GetAttachAnimTotalTime(this->Handle, this->AnimAttachIndex);

	//�A�j���[�V�����Đ����Ԃ�������
	this->AnimNowTime = 0.0f;
	MV1SetAttachAnimTime(this->Handle, this->AnimAttachIndex, this->AnimNowTime);
	if (this->AnimNowTime == -1)	//�G���[������
	{
		return false;		//�A�^�b�`���s
	}

	return true;	//�A�^�b�`����

}

//�A�j���[�V��������
/*
�����Fint�F�A�j���[�V�������x�F�w�肪�Ȃ��ꍇ�́A�f�t�H���g�̃X�s�[�h������
*/
void MODEL::Animation(int speed)
{

	//�A�j���[�V�����̍Đ����Ԃ�i�߂�
	this->AnimNowTime += speed;

	//�A�j���[�V�����Đ����Ԃ��A�j���[�V�����̂������Ԃ𒴂��Ă����烋�[�v������
	if (this->AnimNowTime >= this->AnimTotalTime)
	{
		//�V�����A�j���[�V�����Đ����Ԃ́A�A�j���[�V�����Đ����Ԃ���A�j���[�V�����������Ԃ�����������
		this->AnimNowTime -= this->AnimTotalTime;
	}

	//�V�����A�j���[�V�����Đ����Ԃ��Z�b�g
	MV1SetAttachAnimTime(this->Handle, this->AnimAttachIndex, this->AnimNowTime);

	//3D���f���̕`��
	this->Draw();

	return;

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
