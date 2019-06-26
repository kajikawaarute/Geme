#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"

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
	m_charCon.Init(50.0f, 100.0f, m_position);

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

void Enemy::Update()
{
	Move();
	Death();

	//ˆê’èŽžŠÔ‚Å“G‚ªÁ‚¦‚éB
	m_timer += GameTime().GetFrameDeltaTime();
	if (m_timer > 5) {
		DeleteGO(this);
	}

	m_skinModel->SetPosition(m_position);
	m_skinModel->SetRotation(m_rotation);
}