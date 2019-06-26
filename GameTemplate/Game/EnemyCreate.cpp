#include "stdafx.h"
#include "EnemyCreate.h"
#include "Enemy.h"

EnemyCreate::EnemyCreate()
{
}


EnemyCreate::~EnemyCreate()
{
}

void EnemyCreate::Update()
{
	m_timer += GameTime().GetFrameDeltaTime();
	if (m_timer > 2) {
		ene = NewGO<Enemy>(0, "ene");
		m_timer = 0;
	}
}