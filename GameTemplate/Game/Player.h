#pragma once

class Bullet;

class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void Move();
	CVector3& GetPos()
	{
		return m_position;
	}
private:
	prefab::CSkinModelRender* m_skinModel = nullptr;		//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	CCharacterController m_charCon;
	Bullet* bl = nullptr;
	int bulletCount = 1000;
};

