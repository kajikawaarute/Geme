#pragma once
class Enemy;
class EnemyCreate : public IGameObject
{
public:
	EnemyCreate();
	~EnemyCreate();
	void Update();
private:
	float m_timer = 0;
	Enemy* ene = nullptr;
};

