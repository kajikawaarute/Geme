#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
class Stage;
class Bullet : public IGameObject
{
public:
	Bullet();
	~Bullet();
	bool Start();
	void Update();
	
	CVector3& GetPos()
	{
		return m_position;
	}
	CVector3 SetSpd(CVector3 s, float a)
	{
		s = s * a;
		return m_speed = s;
	}
private:
	prefab::CSkinModelRender* m_skinModel = nullptr;
	CCharacterController m_charCon;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_speed = CVector3::Zero;
	int m_timer = 0;
	Stage* st = nullptr;
};

