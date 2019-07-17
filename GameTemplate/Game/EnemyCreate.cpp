#include "stdafx.h"
#include "EnemyCreate.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Boss.h"
#include "Game.h"

EnemyCreate::EnemyCreate()
{
}


EnemyCreate::~EnemyCreate()
{
	DeleteGOs("boss");
}

bool EnemyCreate::Start()
{
	
	return true;
}

void EnemyCreate::Update()
{
	Game* ga = FindGO<Game>("Game");
	m_enetimer += GameTime().GetFrameDeltaTime();
	m_ene2timer += GameTime().GetFrameDeltaTime();
	if (m_enetimer > 3) {
			ene = NewGO<Enemy>(0, "ene");
			m_enetimer = 0;
	}
	if (m_ene2timer > 5) {
			ene2 = NewGO<Enemy2>(0, "ene2");
			m_ene2timer = 0;
	}
	if (ga->BossCoinCount() == 5) {
			boss = NewGO<Boss>(0, "boss");
			ga->reset_BossCoinCount();
	}
}