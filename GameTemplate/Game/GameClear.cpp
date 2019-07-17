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

	//コイン
	m_fontRender = NewGO<prefab::CFontRender>(1);
	m_fontRender->SetPosition({ -550,-25 });
	color.x = 0.8f;
	m_fontRender->SetColor(color);
	coinGetCount = FindGO<CoinCount>("CoinCount");
	int coinCount=coinGetCount->GetCoin();

	//エネミー
	m_fontRender2 = NewGO<prefab::CFontRender>(1);
	m_fontRender2->SetPosition({ -550,-105 });
	color1.z = 0.8f;
	m_fontRender2->SetColor(color1);
	enemyGetCount = FindGO<EnemyCount>("enCount");
	int enemyCount = enemyGetCount->GetEnemy();


	wchar_t text[256];
	swprintf(text, L"コインの獲得数　　　%d", coinCount);
	m_fontRender->SetText(text);

	wchar_t text1[256];
	swprintf(text1, L"雑魚敵撃破数　　　  %d", enemyCount);
	m_fontRender2->SetText(text1);

	return true;
}


void GameClear::Update()
{

}
