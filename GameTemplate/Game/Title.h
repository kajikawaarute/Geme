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
	
	float AngleY = 0.0f;

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

	//Unityちゃん
	prefab::CSkinModelRender* CSkinmodel = nullptr;
	CQuaternion m_kaiten = CQuaternion::Identity;

	//タイトル
	prefab::CSkinModelRender* CSkinmodel1 = nullptr;
	CQuaternion m_kaiten1 = CQuaternion::Identity;

	CQuaternion m_kaiten2 = CQuaternion::Identity;
	//ライトの明るさ
	CVector3 light = { 0.8f,0.8f,0.12f };
	
	CVector4 m_light = { 0.9f,0.9f,0.18f,0.18f };
	CVector4 m_light2 = { 100.8f,100.8f,110.12f,110.12f };

	//アニメーション
	enum EnAnimationClip {
		//enAnimationClip_jump,   //ジャンプアニメーション
		//enAnimationClip_idle,   //立ってる 
		enAnimationClip_run,	//走る
		enAnimationClip_Num,	//アニメーションクリップの数。
	};
	CAnimationClip m_animClips[enAnimationClip_Num];
};

