//main.cpp

//#################### �w�b�_�t�@�C���ǂݍ��� #######################
#include "main.hpp"
#include "FPS.hpp"
#include "KEYDOWN.hpp"
#include "MODEL.hpp"

//########## �O���[�o���I�u�W�F�N�g ##########
FPS *fps = new FPS(GAME_FPS_SPEED);			//FPS�N���X�̃I�u�W�F�N�g�𐶐�
KEYDOWN *keydown = new KEYDOWN();			//KEYDOWN�N���X�̃I�u�W�F�N�g�𐶐�
//MODEL *cube;								//3D���f���icube�j
MODEL *anim_model;							//3D���f��(�A�j���[�V����)

//########### �O���[�o���ϐ� ################

//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//�w��̐��l�ŉ�ʂ�\������

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);				//�^�C�g���o�[����

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//�^�C�g���̕���

	SetAlwaysRunFlag(TRUE);										//��A�N�e�B�u�ɐݒ�

	if (DxLib_Init() == -1) { return -1; }						//�c�w���C�u��������������

	SetDrawScreen(DX_SCREEN_BACK);								//Draw�n�֐��͗���ʂɕ`��

	// �J�����̈ʒu�ƌ�����ݒ�
	SetCameraPositionAndTarget_UpVecY(VGet(1340.0f, 600.0f, -420.0f), VGet(0.0f, 400.0f, -420.0f));

	// �J�����̃N���b�s���O������ݒ�
	SetCameraNearFar(16.0f, 3800.0f);

	// �w�i�̐F���D�F�ɂ���
	SetBackgroundColor(128, 128, 128);


	//***************** �I�u�W�F�N�g�̐��� ***********************
	//cube = new MODEL(MODEL_DIR, MODEL_NAME);	//cube��3D���f���𐶐�
	//if (cube->GetIsLoad() == false) { return -1; }	//�ǂݍ��ݎ��s
	anim_model = new MODEL(MODEL_DIR, MODEL_ANIM_NAME);	//anim_model��3D���f���𐶐�
	if (anim_model->GetIsLoad() == false) { return -1; }	//�ǂݍ��ݎ��s
	if (anim_model->AttachAnim() == false) { return -1; }	//�A�^�b�`���s


	//�Q�[���̃��C�����[�v
	while (GameMainLoop())
	{
		/*
		���[�v���ňُ킪��������܂Ŗ������[�v
		�Q�[���I����G���[�������������烋�[�v�I��
		*/
	}

	Delete_Class();			//�g�p�����N���X��j��

	DxLib_End();			//�c�w���C�u�����g�p�̏I������

	return 0;
}

//�������[�v���̃Q�[������
/*
�߂�l�Ftrue�F����
�߂�l�Ffalse�F�G���[�A�����I��
*/
bool GameMainLoop()
{
	if (ProcessMessage() != 0) { return false; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

	if (ClearDrawScreen() != 0) { return false; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

	keydown->KeyDownUpdate();	//�L�[�̓��͏�Ԃ��X�V����

	fps->Update();				//FPS�̏���[�X�V]

	//�����������Q�[���̃V�[���������灥��������

	//cube->Draw();		//3D���f���`��

	anim_model->Animation();	//3D���f���A�j���[�V����

	//�����������Q�[���̃V�[�������܂Ł���������

	fps->Draw(0,0);				//FPS�`��

	ScreenFlip();				//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

	fps->Wait();				//FPS�̏���[�҂�]

	return true;				//����

}

//�Q�[�����Ŏg�p�����N���X���폜���鏈��
void Delete_Class()
{

	delete fps;			//fps�j��
	delete keydown;		//keydown�j��
	//delete cube;		//cube�j��
	delete anim_model;	//anim_model�j��

	return;
}
