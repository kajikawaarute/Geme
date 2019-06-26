#include "stdafx.h"
#include "Sound.h"


Sound::Sound()
{
}


Sound::~Sound()
{
	DeleteGO(m_Sound);
	DeleteGO(m_Sound1);
}


bool Sound::Start()
{
	/*m_Sound = NewGO<prefab::CSoundSource>(0);
	m_Sound->Init(L"sound/Title.wav");
	m_Sound->Play(true);*/
	return true;
}


void Sound::TitleSound()
{
	m_Sound = NewGO<prefab::CSoundSource>(0);
	m_Sound->Init(L"sound/Title.wav");
	m_Sound->Play(true);
}


void Sound::ButtonStart()
{
	/*m_Sound1 = NewGO<prefab::CSoundSource>(0);
	m_Sound1->Init(L"sound/.wav");
	m_Sound1->Play(false);*/
}


void Sound::Update()
{
}