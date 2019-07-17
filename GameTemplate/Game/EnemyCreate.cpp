#include "stdafx.h"
#include "EnemyCreate.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Boss.h"
#include "Coin.h"
#include "Game.h"

EnemyCreate::EnemyCreate()
{
}


EnemyCreate::~EnemyCreate()
{
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
		if (m_flag == false) {
			ene = NewGO<Enemy>(0, "ene");
			m_enetimer = 0;
		}
	}
	if (m_ene2timer > 6) {
		if (m_flag == false) {
			ene2 = NewGO<Enemy2>(0, "ene2");
			m_ene2timer = 0;
		}
	}
	if (ga->coinCount == 5) {
		if (m_flag == false) {
			boss = NewGO<Boss>(0, "boss");
			ga->coinCount = 0;
			m_flag = true;
		}
	}
}