#pragma once
class Player;
class EnemyBullet : public IGameObject
{
public:
	EnemyBullet();
	~EnemyBullet();
	bool Start();
	void Update();
	CVector3& Getpos()
	{
		return m_position;
	}
	CVector3 SetSpd(CVector3 s, float a)
	{
		m_Speed = s * a;
	}
private:

	prefab::CSkinModelRender* m_skinModel = nullptr;
	CCharacterController m_ChraCon;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_Speed = CVector3::Zero;
	int m_timer = 0;
	CVector3 v = CVector3::Zero;
	Player* pl = nullptr;
};

