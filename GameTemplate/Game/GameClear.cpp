#include "stdafx.h"
#include "GameClear.h"
#include "Game.h"
#include "CoinCount.h"
#include "EnemyCount.h"
#include "Title.h"
#include "Stage.h"

GameClear::GameClear()
{
	
}


GameClear::~GameClear()
{
	sg = FindGO<Stage>("stage");
	DeleteGO(sg);
	DeleteGO(m_spriteRender);
	DeleteGO(m_fontRender);
	DeleteGO(m_fontRender2);
	DeleteGO(m_fontRender3);
	DeleteGO(m_fontRender4);
	DeleteGO(m_fontRender5);
	DeleteGO(m_Sound);
}


bool GameClear::Start()
{

	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/GameClear.dds", 1280.0f, 780.0f);

	//�R�C��
	m_fontRender = NewGO<prefab::CFontRender>(1);
	m_fontRender->SetPosition({ -550,-25 });
	color.x = 0.8f;
	m_fontRender->SetColor(color);
	coinGetCount = FindGO<CoinCount>("CoinCount");
	int coinCount=coinGetCount->GetCoin();

	//�G�l�~�[
	m_fontRender2 = NewGO<prefab::CFontRender>(1);
	m_fontRender2->SetPosition({ -550,-105 });
	color1.z = 0.8f;
	m_fontRender2->SetColor(color1);
	enemyGetCount = FindGO<EnemyCount>("enCount");
	int enemyCount = enemyGetCount->GetEnemy();


	/*wchar_t text[256];
	swprintf(text, L"�R�C���̊l�����@�@�@%d", coinCount);
	m_fontRender->SetText(text);*/
	
	wchar_t text1[256];
	swprintf(text1, L"�G���j�� %d", enemyCount);
	m_fontRender2->SetText(text1);
	m_fontRender2->SetScale({ 3 });

	//�]��C
	m_fontRender3 = NewGO<prefab::CFontRender>(1);
	m_fontRender3->SetPosition({ -550,-105 });
	color.z = 0.8f;
	m_fontRender3->SetColor(color);

	//�]��B
	m_fontRender4 = NewGO<prefab::CFontRender>(1);
	m_fontRender4->SetPosition({ -550,-105 });
	color.z = 0.8f;
	m_fontRender4->SetColor(color);

	//�]��A
	m_fontRender5 = NewGO<prefab::CFontRender>(1);
	m_fontRender5->SetPosition({ -550,-105 });
	color.z = 0.8f;
	m_fontRender5->SetColor(color);

	//�]��A
	if (enemyCount >= 15)
	{
		wchar_t text4[256];
		swprintf(text4, L"�]���@A  ");
		m_fontRender5->SetText(text4);
		m_fontRender5->SetScale({ 3 });
		m_fontRender5->SetPosition({ -530,-280 });
	}
	
	//�]��B
	else if (enemyCount >= 10)
	{
		wchar_t text3[256];
		swprintf(text3, L"�]���@B  ");
		m_fontRender4->SetText(text3);
		m_fontRender4->SetScale({ 3 });
		m_fontRender4->SetPosition({ -530,-280 });
	}


	//�]��C
	else if (enemyCount <= 9)
	{
		wchar_t text2[256];
		swprintf(text2, L"�]���@C  ");
		m_fontRender3->SetText(text2);
		m_fontRender3->SetScale({3});
		m_fontRender3->SetPosition({ -530,-280 });
	}

	
	
	
	
	//���y
	m_Sound = NewGO<prefab::CSoundSource>(0);
	m_Sound->Init(L"sound/GameClear.wav");
	m_Sound->Play(true);

	return true;
}


void GameClear::Update()
{
	m_timer += GameTime().GetFrameDeltaTime();
	if (m_timer > 5) {
		DeleteGO(this);
		NewGO<Title>(0, "Title");
	}
}
