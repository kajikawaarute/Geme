#pragma once
class Player;
class CoinCount;

class Coin :public IGameObject
{
public:

	Coin();
	~Coin();

	bool Start();
	void Update();

private:
	Player*player = nullptr;
	CoinCount*CCount = nullptr;

	int m_timer = 0;
	int coinCount = 0;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_position = CVector3::Zero;		
	//ÉRÉCÉì3D
	prefab::CSkinModelRender* m_skinModelrender = nullptr;

};

