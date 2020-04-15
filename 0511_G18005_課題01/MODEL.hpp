//MODEL.hpp
//3D���f�����Ǘ�����N���X

#pragma once

//########### �w�b�_�t�@�C���ǂݍ��� ################
#include "DxLib.h"
#include <string>

//########### �}�N����` ##############
#define MODEL_DIR		R"(.\Model\)"					//3D���f���̃f�B���N�g��
#define MODEL_NAME		R"(0511_G18005_3Dmodel.mqo)"	//3D���f���̖��O

#define MODEL_DEF_X		100.0f			//3D���f���̃f�t�H���g��X�ʒu
#define MODEL_DEF_Y		100.0f			//3D���f���̃f�t�H���g��Y�ʒu
#define MODEL_DEF_Z		100.0f			//3D���f���̃f�t�H���g��Z�ʒu

//########## �N���X��` ###############
class MODEL
{
private:

	int Handle;		//�n���h��

	bool IsLoad;	//�ǂݍ��߂���

public:

	MODEL(const char *, const char *);		//�R���X�g���N�^
	~MODEL();								//�f�X�g���N�^

	bool GetIsLoad();						//�ǂݍ��߂����擾

	void SetPos(VECTOR);					//�ʒu�ݒ�
	void Draw();							//�`��

};
