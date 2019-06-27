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

	CQuaternion m_kaiten = CQuaternion::Identity;

	//2D‰æ‘œ
	prefab::CSpriteRender*m_spriteRender = nullptr;
	prefab::CSpriteRender*m_spriteRender1 = nullptr;
	prefab::CSpriteRender*m_spriteRender2 = nullptr;

	//ƒTƒEƒ“ƒh
	prefab::CSoundSource* m_Sound = nullptr;
	prefab::CSoundSource* m_Sound1 = nullptr;

	//Unity‚¿‚á‚ñ
	prefab::CSkinModelRender* CSkinmodel = nullptr;
};

