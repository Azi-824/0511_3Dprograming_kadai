//MODEL.hpp
//3D���f�����Ǘ�����N���X

#pragma once

//########### �w�b�_�t�@�C���ǂݍ��� ################
#include "DxLib.h"
#include <string>

//########### �}�N����` ##############
#define MODEL_DIR		R"(.\Model\)"					//3D���f���̃f�B���N�g��
//#define MODEL_NAME		R"(0511_G18005_3Dmodel.mqo)"	//3D���f���̖��O
#define MODEL_ANIM_NAME	R"(DxChara.x)"					//�A�j���[�V��������3D���f���̖��O

#define MODEL_DEF_X		100.0f			//3D���f���̃f�t�H���g��X�ʒu
#define MODEL_DEF_Y		100.0f			//3D���f���̃f�t�H���g��Y�ʒu
#define MODEL_DEF_Z		100.0f			//3D���f���̃f�t�H���g��Z�ʒu

#define MODEL_ANIM_DEF_SPD 100.0f		//3D���f���̃f�t�H���g�̃A�j���[�V�������x

//########## �N���X��` ###############
class MODEL
{
private:

	int Handle;					//�n���h��
	float AnimTotalTime;		//�A�j���[�V�����̑�������
	float AnimNowTime;			//���݂̃A�j���[�V�����̎���
	int AnimAttachIndex;		//�A�^�b�`����A�j���[�V�����ԍ�

	bool IsLoad;	//�ǂݍ��߂���

public:

	MODEL(const char *, const char *);		//�R���X�g���N�^
	~MODEL();								//�f�X�g���N�^

	bool GetIsLoad();						//�ǂݍ��߂����擾

	//********** �A�j���[�V�����֌W **************
	bool AttachAnim();								//�A�j���[�V�������A�^�b�`����
	void Animation(int speed = MODEL_ANIM_DEF_SPD);	//�A�j���[�V��������

	void SetPos(VECTOR);					//�ʒu�ݒ�
	void Draw();							//�`��

};
