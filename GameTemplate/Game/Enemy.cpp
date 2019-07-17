#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"
#include "EnemyBullet.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
	DeleteGO(m_skinModel);
}

bool Enemy::Start()
{
	m_animClip[enAnim_walk].Load(L"animData/enemy_walk.tka");
	m_animClip[enAnim_walk].SetLoopFlag(true);

	m_skinModel = NewGO<prefab::CSkinModelRender>(0);
	m_skinModel->Init(L"modelData/Enemy.cmo", m_animClip, enAnim_Num);
	m_skinModel->PlayAnimation(enAnim_walk);

	float t = Random().GetRandDouble();
	m_position.x = CMath::Lerp(t, -500.0f, 500.0f);
	m_position.z = CMath::Lerp(t, 650.0f, 300.0f);

	m_charCon.Init(20.0f, 100.0f, m_position);
	return true;
}

void Enemy::Move()
{
	QueryGOs<Player>("player", [&](Player* pl)->bool {
		CVector3 v = pl->GetPos() - m_position;
		if (v.Length() > 10.0f) {
			m_moveSpeed = v;
			m_qRot.SetRotation({ 0.0f, 0.0f, 1.0f }, v);
			m_rotation = m_qRot;
		}
		return true;
		});
	m_position = m_charCon.Execute(m_moveSpeed);
}

void Enemy::Death()
{
	QueryGOs<Bullet>("bullet", [&](Bullet* bl)->bool {
		CVector3 v = bl->GetPos() - m_position;
		if (v.Length() < 40.0f) {
			//エフェクトの表示
			prefab::CEffect* ef = NewGO<prefab::CEffect>(0);
			ef->Play(L"effect/enemydown.efk");
			CVector3 efPos = m_position;
			efPos.y = 50.0f;
			ef->SetPosition(efPos);
			//音を再生
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/Enemydamege.wav");
			m_sound->Play(false);

			DeleteGO(this);
			DeleteGO(bl);
		}
		return true;
		});
}

void Enemy::Shoot()
{
	m_bltimer++;
	if (m_bltimer == 40) {
		EnemyBullet* enebl = NewGO<EnemyBullet>(0);
		enebl->Getpos() = m_position;
		//enebl->SetSpd(, 1000.0f);
		m_bltimer = 0;
	}
}

void Enemy::Update()
{
	Move();
	Death();
	//Shoot();

	//一定時間で敵が消える。
	m_timer += GameTime().GetFrameDeltaTime();
	if (m_timer > 5) {
		DeleteGO(this);
	}

	m_skinModel->SetPosition(m_position);
	m_skinModel->SetRotation(m_rotation);
}