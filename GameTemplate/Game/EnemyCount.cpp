#include "stdafx.h"
#include "EnemyCount.h"


EnemyCount::EnemyCount()
{
}


EnemyCount::~EnemyCount()
{
	DeleteGO(m_fontRender);
}

bool EnemyCount::Start()
{
	m_fontRender = NewGO<prefab::CFontRender>(0);
	m_fontRender->SetPosition({ 280,250 });

	m_color.x = 1.0f;
	m_fontRender->SetColor(m_color);
	return true;
}


void EnemyCount::Update()
{
	wchar_t text[256];
	swprintf(text, L"ŽG‹›ƒJƒEƒ“ƒg=%d", enemyCount);
	m_fontRender->SetText(text);
}