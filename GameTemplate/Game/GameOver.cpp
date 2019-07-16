#include "stdafx.h"
#include "GameOver.h"
#include "Game.h"
#include "Player.h"
#include "Title.h"
#include "Stage.h"

GameOver::GameOver()
{
	
}


GameOver::~GameOver()
{
	DeleteGO(m_sprite);
	Stage* sg = FindGO<Stage>("stage");
	DeleteGO(sg);
}


bool GameOver::Start()
{

	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/GameOver.dds", 1200.0f, 780.0f);
	m_position.y = 199;
	m_sprite->SetPosition(m_position);

	return true;

}


void GameOver::Update()
{

	m_timer += GameTime().GetFrameDeltaTime();
	if (m_timer <= 2.0f) {
		m_position.y -= 2.0f;
		m_sprite->SetPosition(m_position);
	}
	if (m_timer > 4.0f) {
		DeleteGO(this);
		NewGO<Title>(0, "Title");
	}
}


