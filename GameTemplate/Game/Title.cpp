#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "Fade.h"
#include "Sound.h"

Title::Title()
{
}


Title::~Title()
{
	DeleteGO(m_spriteRender);
	DeleteGO(m_spriteRender1);
	DeleteGO(m_spriteRender2);

}


bool Title::Start()
{

	//ï∂éö
	m_spriteRender2 = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender2->Init(L"sprite/title.dds", 1280.0f, 720.0f);
	m_spriteRender2->SetPosition(m_position2);

	//îwåi
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/Game.dds", 1280.0f, 720.0f);
	m_position.y = 340;
	m_spriteRender->SetPosition(m_position);

	//ï∂éö
	m_spriteRender1 = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender1->Init(L"sprite/botanose.dds", 1280.0f, 720.0f);
	m_position1.y = -300;
	m_spriteRender1->SetPosition(m_position1);

	
	fade = FindGO<Fade>("Fade");
	return true;
}


void Title::Update()
{

	//ï∂éöÇ™ìÆÇ≠èàóù
	m_timer++;
	if (m_timer == 1) {
		m_position.y -= 1.0f;
		m_spriteRender->SetPosition(m_position);
		m_timer = 0;
	}

	//É{É^ÉìâüÇ∑Ç∆ÉQÅ[ÉÄÇ…çsÇ≠
	if (Pad(0).IsPress(enButtonA) == true) {
		NewGO<Game>(0, "Game");
		fade->StartFadeOut();
		DeleteGO(this);
	}
}


