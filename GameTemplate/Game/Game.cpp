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
#include "Stage.h"
#include "BulletCount.h"
#include "EnemyBullet.h"
#include "GameClear.h"

CVector3 cameraPos = { 0.0f, 70.0f, 200.0f };
CVector3 cameraTarget;

Game::Game()
{

	NewGO<Player>(0, "player");
	NewGO<GameCamera>(0, "GC");
	NewGO<PlayerHP>(0, "ph");
	NewGO<EnemyCreate>(0, "eneCreate");
	NewGO<Coin2D>(0, "Coin2D");
	NewGO<CoinCount>(0, "CoinCount");
	NewGO<Timer>(0, "Timer");
	//NewGO<Coin>(0, "Coin");
	NewGO<Stage>(0, "stage");
	NewGO<BulletCount>(0, "blCount");
	m_Light = NewGO<prefab::CDirectionLight>(0);
	m_Light->SetColor({ 0.5f,0.5f, 0.5f, 1.0f });
	m_Light->SetDirection({ -0.707f,-0.707f,0.0f });
	GraphicsEngine().GetDirectionShadowMap().SetLightDirection({ 0.0f, -1.0f, 0.0f });
	
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
	DeleteGO(eneCreate);
	Stage* sg = FindGO<Stage>("stage");
	DeleteGO(sg);
	Coin2D*coin2D = FindGO<Coin2D>("Coin2D");
	DeleteGO(coin2D);
	Timer*m_timer = FindGO<Timer>("Timer");
	DeleteGO(m_timer);
	CoinCount* coinCount = FindGO<CoinCount>("CoinCount");
	DeleteGO(coinCount);
	BulletCount* bc = FindGO<BulletCount>("blCount");
	DeleteGO(bc);

	Coin* coin = FindGO<Coin>("Coin");
	DeleteGO(coin);
	
}
bool Game::Start()
{
	return true;
}

void Game::Update()
{
	//postEffect::Tonemap().SetLuminance(0.02);


	m_timer += GameTime().GetFrameDeltaTime();
	if (m_timer > 2) {
		m_coin =NewGO<Coin>(0, "Coin");
		m_timer = 0;
	}

	float deltaTime = GameTime().GetFrameDeltaTime();
	m_restTimer -= deltaTime;
	if (m_restTimer < 0.0f || damageCount == 3) {
		m_Timer += GameTime().GetFrameDeltaTime();
		if (m_Timer > 2) {
			m_restTimer = 0.0f;
			DeleteGO(this);
			NewGO<GameOver>(0, "GameOver");
		}
	}
}
