#pragma once

class Fade;
class mTimer;
class Sound;

class Title : public IGameObject
{
public:
	Title();
	~Title();

	bool Start();
	void Update();

private:

	Fade* fade = nullptr;
	mTimer* mtimer = nullptr;
	Sound* sound = nullptr;

	float m_timer = 0.0f;

	CVector3 m_position = CVector3::Zero;
	CVector3 m_position1 = CVector3::Zero;
	CVector3 m_position2 = CVector3::Zero;
	CVector3 m_position3 = CVector3::Zero;

	//2D�摜
	prefab::CSpriteRender*m_spriteRender = nullptr;
	prefab::CSpriteRender*m_spriteRender1 = nullptr;

	//�T�E���h
	prefab::CSoundSource* m_Sound = nullptr;
	prefab::CSoundSource* m_Sound1 = nullptr;

	//Unity�����
	prefab::CSkinModelRender* CSkinmodel = nullptr;
	CQuaternion m_kaiten = CQuaternion::Identity;

	//�^�C�g��
	prefab::CSkinModelRender* CSkinmodel1 = nullptr;
	CQuaternion m_kaiten1 = CQuaternion::Identity;
};

