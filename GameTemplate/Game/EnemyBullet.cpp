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

	return true;
}

void EnemyBullet::Update()
{
	m_position.y = 70.0f;
	m_position += m_Speed;

	//ˆê’èŽžŠÔ‚Å’e‚ªÁ‚¦‚éB
	m_timer++;
	if (m_timer == 40) {
		DeleteGO(this);
	}

	m_skinModel->SetPosition(m_position);
}