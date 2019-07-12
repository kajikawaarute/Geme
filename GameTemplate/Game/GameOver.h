#pragma once
class Player;
class GameOver : public IGameObject
{
public:
	GameOver();
	~GameOver();
	bool Start();
	void Update();

private:


	Player*player;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_position1 = CVector3::Zero;
	CQuaternion m_kaiten = CQuaternion::Identity;
	CVector3 light = { 0.9f,0.3f,0.9f };
	float m_timer = 0.0f;
	CVector3 m_sclae = CVector3::Zero;
	prefab::CSkinModelRender*m_skinRender = nullptr;
	prefab::CSpriteRender*m_sprite = nullptr;
};

