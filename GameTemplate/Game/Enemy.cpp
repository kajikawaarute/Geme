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
	m_skinModel = NewGO<prefab::CSkinModelRender>(0);
	m_skinModel->Init(L"modelData/unityChan.cmo");
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
		if (v.Length() < 90.0f) {
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
		enebl->SetSpd({0.0f, 0.0f, -1.0f}, 35.0f);
		m_bltimer = 0;
	}
}

void Enemy::Update()
{
	Move();
	Death();
	Shoot();

	//ˆê’èŽžŠÔ‚Å“G‚ªÁ‚¦‚éB
	m_timer += GameTime().GetFrameDeltaTime();
	if (m_timer > 5) {
		DeleteGO(this);
	}

	m_skinModel->SetPosition(m_position);
	m_skinModel->SetRotation(m_rotation);
}