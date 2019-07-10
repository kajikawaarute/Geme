#include "stdafx.h"
#include "EnemyBullet.h"
#include "Player.h"
#include "Enemy.h"

EnemyBullet::EnemyBullet()
{
}


EnemyBullet::~EnemyBullet()
{
	DeleteGO(m_skinModel);
}

bool EnemyBullet::Start()
{
	m_skinModel = NewGO<prefab::CSkinModelRender>(0);
	m_skinModel->Init(L"modelData/EnemyBullet.cmo");
	m_ChraCon.Init(10.0f, 10.0f, m_position);

	return true;
}

void EnemyBullet::Update()
{
	

	//ˆê’èŠÔ‚Å’e‚ªÁ‚¦‚éB
	m_timer++;
	if (m_timer == 40) {
		DeleteGO(this);
	}

	//’e‚ª’Ç]‚·‚é
	QueryGOs<Player>("player", [&](Player* pl)->bool {
		v = pl->GetPos() - m_position;
		v.Length();
		v.Normalize();
		m_Speed += v * 70.0f;
		m_Speed.y = 70.0f;
		m_position += m_Speed;
		return true;
		});

	m_position = m_ChraCon.Execute(m_Speed);
	
	m_skinModel->SetPosition(m_position);
}