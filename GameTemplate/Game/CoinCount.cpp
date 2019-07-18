#include "stdafx.h"
#include "CoinCount.h"
#include "Game.h"
#include "Title.h"


CoinCount::CoinCount()
{
}


CoinCount::~CoinCount()
{
	DeleteGO(m_fontRender);
}


bool CoinCount::Start()
{
	game = FindGO<Game>("Game");
	m_fontRender = NewGO<prefab::CFontRender>(0);
	m_fontRender->SetPosition({ 320,305 });
	m_color.x = 1.0f;
	m_color.y = 1.0f;
	m_fontRender->SetColor(m_color);
	return true;
}


void CoinCount::Update()
{

	wchar_t text[256];
	swprintf(text, L"Žc‚è‚Ì–‡”=%d",coinCount);
	m_fontRender->SetText(text);

	if (coinCount == 0) {
		game->SetGameClear(true);
	}

}
