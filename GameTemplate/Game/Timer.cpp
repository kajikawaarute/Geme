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
	int restTime = (int)m_Game->GetRestTime();
	int min, sec;

	float deltaTime = GameTime().GetFrameDeltaTime();

	min = restTime / 60;
	sec = restTime % 60;

	wchar_t text[256];
	swprintf(text, L"Žc‚èŽžŠÔ%.d:%d", min, sec);
	m_fontRender->SetText(text);
}


