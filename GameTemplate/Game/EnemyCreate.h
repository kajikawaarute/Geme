#pragma once
class Enemy;
class Enemy2;
class EnemyCreate : public IGameObject
{
public:
	EnemyCreate();
	~EnemyCreate();
	void Update();
private:
	float m_timer = 0;
	float m_timer2 = 0;
	Enemy* ene = nullptr;
	Enemy2* ene2 = nullptr;
};

