#include "stdafx.h"
#include "CoinCount.h"

CoinCount::CoinCount()
{
}


CoinCount::~CoinCount()
{
	DeleteGO(m_fontRender);
}


bool CoinCount::Start()
{
	m_fontRender = NewGO<prefab::CFontRender>(0);
	m_fontRender->SetPosition({ 390,305 });
	
	return true;
}


void CoinCount::Update()
{

	wchar_t text[256];
	swprintf(text, L"‚Ì”=%d",coinCount);
	m_fontRender->SetText(text);

}
