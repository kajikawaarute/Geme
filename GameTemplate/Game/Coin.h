#pragma once
class Player;

class Coin :public IGameObject
{
public:
	Coin();
	~Coin();

	bool Start();
	void Update();
	void Random();

private:
	Player*player = nullptr;

	int m_timer = 0;
	prefab::CSkinModelRender* m_skinModelrender = nullptr;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_position = CVector3::Zero;
};

