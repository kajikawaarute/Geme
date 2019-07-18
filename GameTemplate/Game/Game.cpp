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
#include "EnemyCount.h"
#include "CoinCreate.h"

CVector3 cameraPos = { 0.0f, 70.0f, 200.0f };
CVector3 cameraTarget;

Game::Game()
{

	pl =NewGO<Player>(0, "player");
	NewGO<GameCamera>(0, "GC");
	NewGO<PlayerHP>(0, "ph");
	NewGO<EnemyCreate>(0, "eneCreate");
	NewGO<Coin2D>(0, "Coin2D");
	NewGO<CoinCount>(0, "CoinCount");
	NewGO<Timer>(0, "Timer");
	NewGO<Stage>(0, "stage");
	NewGO<BulletCount>(0, "blCount");
	NewGO<EnemyCount>(0, "enCount");
	NewGO<CoinCreate>(0, "Coincreate");

	//BGMÇçƒê∂
	m_sound = NewGO<prefab::CSoundSource>(0);
	m_sound->Init(L"sound/GameBgm (online-audio-converter.com).wav");
	m_sound->Play(true);

	//ÉâÉCÉgÇï\é¶
	m_Light = NewGO<prefab::CDirectionLight>(0);
	m_Light->SetColor({ 0.5f,0.5f, 0.5f, 1.0f });
	m_Light->SetDirection({ -0.707f,-0.707f,0.0f });
	GraphicsEngine().GetDirectionShadowMap().SetLightDirection({ 1.0f, -1.0f, 1.0f });
	
}


Game::~Game()
{
	
	DeleteGO(pl);
	GameCamera * gc = FindGO<GameCamera>("GC");
	DeleteGO(gc);
	PlayerHP* ph = FindGO<PlayerHP>("ph");
	DeleteGO(ph);
	EnemyCreate* eneCreate = FindGO<EnemyCreate>("eneCreate");
	DeleteGO(eneCreate);
	/*Stage* sg = FindGO<Stage>("stage");
	DeleteGO(sg);*/
	Coin2D*coin2D = FindGO<Coin2D>("Coin2D");
	DeleteGO(coin2D);
	Timer*m_timer = FindGO<Timer>("Timer");
	DeleteGO(m_timer);
	CoinCount* coinCount = FindGO<CoinCount>("CoinCount");
	DeleteGO(coinCount);
	BulletCount* bc = FindGO<BulletCount>("blCount");
	DeleteGO(bc);
	/*Coin* coin = FindGO<Coin>("Coin");
	DeleteGOs("Coin");*/
	EnemyCount*enemyCount = FindGO<EnemyCount>("enCount");
	DeleteGO(enemyCount);
	CoinCreate*cc = FindGO<CoinCreate>("Coincreate");
	DeleteGO(cc);
	DeleteGO(m_sound);
	
}
bool Game::Start()
{
	return true;
}

void Game::Update()
{
	//postEffect::Tonemap().SetLuminance(0.02);

	
	/*m_timer += GameTime().GetFrameDeltaTime();
	if (m_timer > 3) {
		m_coin =NewGO<Coin>(0, "Coin");
		m_timer = 0;
	}*/

	if (is_GameClear == true) {
		NewGO<GameClear>(0, "GameClear");
		DeleteGO(this);
	}

	if (is_GameOver == true) {
		NewGO<GameOver>(0, "GameOver");
		prefab::CEffect* ef = NewGO<prefab::CEffect>(0);
		ef->Play(L"effect/playerdown.efk");

		
		/*efPos.y = 50.0f;*/
		ef->SetPosition({pl->GetPos().x,pl->GetPos().y+50.0f, pl->GetPos().z});

		m_Psound = NewGO<prefab::CSoundSource>(0);
		m_Psound->Init(L"sound/Playerdamege.wav");
		m_Psound->Play(false);

		DeleteGO(this);
	}


	/*float deltaTime = GameTime().GetFrameDeltaTime();
	m_restTimer -= deltaTime;
	if (m_restTimer < 0.0f || damageCount == 3) {
		m_Timer += GameTime().GetFrameDeltaTime();
		if (m_Timer > 2) {
			m_restTimer = 0.0f;
			DeleteGO(this);
			NewGO<GameClear>(0, "Game");
		}
	}*/
}
