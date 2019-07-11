#include "stdafx.h"
#include "Enemy2.h"
#include "Player.h"
#include "Bullet.h"
#include "EnemyBullet.h"

Enemy2::Enemy2()
{
}


Enemy2::~Enemy2()
{
	DeleteGO(m_skinModel);
}

bool Enemy2::Start()
{
	m_aninationClip[enAnim_rotation].Load(L"animData/enemy2_rotation.tka");
	m_aninationClip[enAnim_rotation].SetLoopFlag(true);

	m_skinModel = NewGO<prefab::CSkinModelRender>(0);
	m_skinModel->Init(L"modelData/Enemy2.cmo", m_aninationClip, enAnim_Num);
	m_chraCon.Init(30.0f, 50.0f, m_position);
	return true;
}

void Enemy2::Move()
{
	QueryGOs<Player>("player", [&](Player* pl)->bool {
		CVector3 v = pl->GetPos() - m_position;
		if (v.Length() > 10.0f) {
			m_moveSpeed = v;
		}
		return true;
		});
	m_position = m_chraCon.Execute(m_moveSpeed);
}

void Enemy2::Death()
{
	QueryGOs<Bullet>("bullet", [&](Bullet* bl)->bool {
		CVector3 v = bl->GetPos() - m_position;
		if (v.Length() < 50.0f) {
			DeleteGO(this);
			DeleteGO(bl);
		}
		return true;
	});
}

void Enemy2::Shoot()
{
	m_bltimer++;
	if (m_bltimer == 40) {
		EnemyBullet* enebl = NewGO<EnemyBullet>(0 ,"enebl");
		enebl->Getpos() = m_position;
		//enebl->SetSpd(, 1000.0f);
		m_bltimer = 0;
	}
}

void Enemy2::Update()
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
}
