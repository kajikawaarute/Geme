#include "stdafx.h"
#include "Game.h"

#include "tkEngine/light/tkDirectionLight.h"
#include "Player.h"
#include "GameCamera.h"
#include "Coin.h"

CVector3 cameraPos = { 0.0f, 70.0f, 200.0f };
CVector3 cameraTarget;
Game::Game()
{
	NewGO<Player>(0, "player");
	NewGO<GameCamera>(0, "GC");
	//NewGO<Coin>(0, "Coin");
	m_skinModel = NewGO<prefab::CSkinModelRender>(0);
	m_skinModel->Init(L"modelData/unityChan.cmo");
}


Game::~Game()
{
	Player* pl = FindGO<Player>("player");
	DeleteGO(pl);
	GameCamera * gc = FindGO<GameCamera>("GC");
	DeleteGO(gc);
}
bool Game::Start()
{
	return true;
}

void Game::Update()
{
	//NewGO<Coin>(0, "Coin");
	m_skinModel->SetPosition(m_position);
}
