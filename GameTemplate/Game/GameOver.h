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
	CVector3 m_position = CVector3::Zero;
	float m_timer = 0.0f;
	prefab::CSpriteRender*m_sprite = nullptr;
	//ƒTƒEƒ“ƒh
	prefab::CSoundSource* m_Sound = nullptr;
};

