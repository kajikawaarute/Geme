#pragma once
class Player;
class EnemyCount;
class Boss : public IGameObject
{
public:
	Boss();
	~Boss();
	bool Start();
	void Update();
	void Move();
	void Death();
	CVector3& GetPos()
	{
		return m_position;
	}
private:

	EnemyCount*enemyCount = nullptr;
	int Bosscount = 5;

	prefab::CSkinModelRender* m_skinModel = nullptr;
	prefab::CSoundSource* m_sound = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	CQuaternion m_qRot = CQuaternion::Identity;
	CCharacterController m_chraCon;
	int bossHP_Count = 5;
	float m_timer = 0;
	Player* pl = nullptr;

	enum EnAnimationClip {
		enAnim_move,	//移動アニメーション
		enAnim_Num		//アニメーションクリップの数
	};

	CAnimationClip m_animClip[enAnim_Num];
};

