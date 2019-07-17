#include "stdafx.h"
#include "GameClear.h"
#include "Game.h"
#include "CoinCount.h"
#include "EnemyCount.h"

GameClear::GameClear()
{
	
}


GameClear::~GameClear()
{
	DeleteGO(m_spriteRender);
	DeleteGO(m_fontRender);
	DeleteGO(m_fontRender2);
}


bool GameClear::Start()
{

	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/GameClear.dds", 1280.0f, 780.0f);

	m_fontRender = NewGO<prefab::CFontRender>(1);
	m_fontRender->SetPosition({ -300,105 });
	color.x = 0.8f;
	m_fontRender->SetColor(color);

	
	coinGetCount = FindGO<CoinCount>("CoinCount");
	int coinCount=coinGetCount->GetCoin();

	wchar_t text[256];
	swprintf(text, L"コインの獲得数　　　%d", coinCount);
	m_fontRender->SetText(text);

	return true;
}


void GameClear::Update()
{

}
