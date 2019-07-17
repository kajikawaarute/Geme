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

	return true;
}


void EnemyCount::Update()
{
	wchar_t text[256];
	swprintf(text, L"�G���J�E���g=%d", enemyCount);
	m_fontRender->SetText(text);
}