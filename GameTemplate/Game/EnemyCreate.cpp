#include "stdafx.h"
#include "EnemyCreate.h"
#include "Enemy.h"
#include "Enemy2.h"

EnemyCreate::EnemyCreate()
{
}


EnemyCreate::~EnemyCreate()
{
}

void EnemyCreate::Update()
{
	m_timer += GameTime().GetFrameDeltaTime();
	m_timer2 += GameTime().GetFrameDeltaTime();
	if (m_timer > 2) {
		ene = NewGO<Enemy>(0, "ene");
		m_timer = 0;
	}
	if (m_timer2 > 5) {
		ene2 = NewGO<Enemy2>(0, "ene2");
		m_timer2 = 0;
	}
}