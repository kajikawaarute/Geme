#include "stdafx.h"
#include "Game.h"
#include "Timer.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Player.h"
#include "GameCamera.h"
#include "Coin.h"
#include "PlayerHP.h"
#include "EnemyCreate.h"
#include "Coin2D.h"
#include "GameOver.h"
#include "CoinCount.h"

CVector3 cameraPos = { 0.0f, 70.0f, 200.0f };
CVector3 cameraTarget;
Game::Game()
{
	NewGO<Player>(0, "player");
	NewGO<GameCamera>(0, "GC");
	NewGO<PlayerHP>(0, "ph");
	NewGO<EnemyCreate>(0, "eneCreate");
	NewGO<Coin>(0, "Coin");
	NewGO<Coin2D>(0, "Coin2D");
	NewGO<CoinCount>(0, "CoinCount");
	NewGO<Timer>(0, "Timer");
	m_skinModel = NewGO<prefab::CSkinModelRender>(0);
	m_skinModel->Init(L"modelData/unityChan.cmo");
	//è∞
	m_skinModel1 = NewGO<prefab::CSkinModelRender>(0);
	m_skinModel1->Init(L"modelData/yuka.cmo");
	m_skinModel1->SetScale({ 9000.0f,9000.0f,9000.0f });
}


Game::~Game()
{
	Player* pl = FindGO<Player>("player");
	DeleteGO(pl);
	GameCamera * gc = FindGO<GameCamera>("GC");
	DeleteGO(gc);
	PlayerHP* ph = FindGO<PlayerHP>("ph");
	DeleteGO(ph);
	EnemyCreate* eneCreate = FindGO<EnemyCreate>("eneCreate");
}
bool Game::Start()
{
	return true;
}

void Game::Update()
{
	/*m_timer += GameTime().GetFrameDeltaTime();
	if (m_timer > 5) {
		NewGO<Coin>(0, "Coin");
		m_timer = 0;
	}*/
	float deltaTime = GameTime().GetFrameDeltaTime();
	m_restTimer -= deltaTime;
	if (m_restTimer < 0.0f) {
		m_restTimer = 0.0f;
		DeleteGO(this);
		NewGO<GameOver>(0,"GameOver");
		
	}
	m_skinModel->SetPosition(m_position);
}
