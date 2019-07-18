#pragma once
class EnemyCount;
class Enemy2 : public IGameObject
{
public:
	Enemy2();
	~Enemy2();
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
	EnemyCount* enemygetCount = nullptr;
	prefab::CSkinModelRender* m_skinModel = nullptr;
	prefab::CSoundSource* m_sound = nullptr;
	prefab::CSoundSource* m_sound2 = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;
	CCharacterController m_chraCon;
	float m_timer = 0;
	int m_bltimer = 0;

	enum EnAnimationClip {
		enAnim_rotation,	//回転
		enAnim_Num		//アニメーションクリップの数
	};
	CAnimationClip m_aninationClip[enAnim_Num];
};

