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
	float m_timer2 = 0.0f;
	int m_timer3 = 0;
	float AngleY = 0.0f;
	float color = 0.1f;

	bool StartFlag = false;

	CVector3 m_position = CVector3::Zero;
	CVector3 m_position1 = CVector3::Zero;
	CVector3 m_position2 = CVector3::Zero;
	CVector3 m_position3 = CVector3::Zero;

	//2D画像
	prefab::CSpriteRender*m_spriteRender = nullptr;
	prefab::CSpriteRender*m_spriteRender1 = nullptr;

	//サウンド
	prefab::CSoundSource* m_Sound = nullptr;
	prefab::CSoundSource* m_Sound1 = nullptr;

	//playerモデル
	prefab::CSkinModelRender* CSkinmodel = nullptr;
	CQuaternion m_kaiten = CQuaternion::Identity;

	//タイトル
	prefab::CSkinModelRender* CSkinmodel1 = nullptr;
	CQuaternion m_kaiten1 = CQuaternion::Identity;

	CQuaternion m_kaiten2 = CQuaternion::Identity;
	
	//ライトの明るさ
	CVector3 light = { 0.8f,0.8f,0.12f };
	
	//文字のライト
	CVector4 m_light = { 1.0f,1.0f,1.0f,color };

};

