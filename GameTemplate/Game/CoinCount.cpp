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
	m_fontRender->SetPosition({ 454,305 });
	
	return true;
}


void CoinCount::Update()
{

	wchar_t text[256];
	swprintf(text, L"‚Ì”=%d",coinCount);
	m_fontRender->SetText(text);

	if (coinCount == 0) {
		game->SetGameClear(true);
	}

}
