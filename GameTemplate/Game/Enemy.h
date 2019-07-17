#pragma once
class Player;
class EnemyCount;
class Enemy : public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start();
	void Update();
	void Move();
	void Death();
	void Shoot();
	CVector3& GetPos()
	{
		return m_position;
	}

private:
	prefab::CSkinModelRender* m_skinModel = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	CQuaternion m_qRot = CQuaternion::Identity;
	CCharacterController m_charCon;
	float m_timer = 0;
	int m_bltimer = 0;

	Player* pl = nullptr;
	EnemyCount*ECount = nullptr;

	enum EnAnimationClip {
		enAnim_walk,	//歩きアニメーション
		enAnim_Num		//アニメーションクリップの数
	};

	CAnimationClip m_animClip[enAnim_Num];
};

