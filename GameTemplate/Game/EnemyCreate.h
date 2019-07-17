#pragma once
class Enemy;
class Enemy2;
class Boss;
class Coin;
class EnemyCreate : public IGameObject
{
public:
	EnemyCreate();
	~EnemyCreate();
	bool Start();
	void Update();
private:
	float m_enetimer = 0;
	float m_ene2timer = 0;
	Enemy* ene = nullptr;
	Enemy2* ene2 = nullptr;
	Boss* boss = nullptr;
	Coin* coin = nullptr;
};

