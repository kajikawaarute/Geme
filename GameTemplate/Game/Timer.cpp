#include "stdafx.h"
#include "Timer.h"
#include "Game.h"

Timer::Timer()
{
}


Timer::~Timer()
{
	DeleteGO(m_fontRender);
}


bool Timer::Start()
{
	m_fontRender = NewGO<prefab::CFontRender>(0);
	m_fontRender->SetPosition({ -640,250 });
	return true;
}


void Timer::Update()
{
	m_Game = FindGO<Game>("Game");
	//int restTime = (int)m_Game->GetRestTime();
	
	//deltaTime += GameTime().GetFrameDeltaTime();
	timer -= GameTime().GetFrameDeltaTime();

	if (timer <= 0.0f) {
		timer = 0.0f;
		m_Game->SetGameClear(true);
	}

	wchar_t text[100];
	swprintf(text, L"Žc‚èŽžŠÔ %.0f", timer);
	m_fontRender->SetText(text);
}


