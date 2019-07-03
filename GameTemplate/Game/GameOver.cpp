#include "stdafx.h"
#include "GameOver.h"
#include "Game.h"


GameOver::GameOver()
{
}


GameOver::~GameOver()
{
	DeleteGO(m_spriteRender);
}


bool GameOver::Start()
{
	return true;
}


void GameOver::Update()
{
}
