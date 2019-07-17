#include "stdafx.h"
#include "CoinCreate.h"
#include "Coin.h"
#include "Game.h"

CoinCreate::CoinCreate()
{
}


CoinCreate::~CoinCreate()
{
	DeleteGOs("coin");
}

bool CoinCreate::Start()
{
	return true;
}


void CoinCreate::Update()
{
	Game* ga = FindGO<Game>("Game");
	m_timer += GameTime().GetFrameDeltaTime();
	if (m_timer>3) 
	{
		coin = NewGO<Coin>(0, "coin");
		m_timer = 0.0f;
	}
}