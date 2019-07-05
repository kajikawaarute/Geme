#include "stdafx.h"
#include "GameClear.h"
#include "Game.h"


GameClear::GameClear()
{
}


GameClear::~GameClear()
{
	DeleteGO(m_spriteRender);
}


bool GameClear::Start()
{

	return true;
}


void GameClear::Update()
{

}
