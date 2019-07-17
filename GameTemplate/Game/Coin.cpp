#include "stdafx.h"
#include "Coin.h"
#include "Player.h"
#include "CoinCount.h"
#include "Game.h"
#include "tkEngine/light/tkDirectionLight.h"
Coin::Coin()
{
	//コイン3D
	m_skinModelrender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelrender->Init(L"modelData/coin.cmo");
	
}


Coin::~Coin()
{
	DeleteGO(m_skinModelrender);
}


bool Coin::Start()
{
	player = FindGO<Player>("player");
	CCount = FindGO<CoinCount>("CoinCount");
	m_position.x = (rand() % 900);
	float tate = (rand() % 2);
	if (tate == 1) {
		m_position.x = m_position.x * -1;
	}

	float yoko = (rand() % 2);
	m_position.z = (rand() % 750);
	if (yoko == 1) {
		m_position.z = m_position.z*-1;
	}

	m_skinModelrender->SetPosition(m_position);
	return true;
}


void Coin::Update()
{
	//postEffect::Tonemap().SetLuminance(0.02f);

	//コインの回転処理
	CQuaternion qAddRot;
	qAddRot.SetRotationDeg(CVector3::AxisY, 2.0f);
	m_rotation *= qAddRot;
	m_skinModelrender->SetRotation(m_rotation);
	
	
	//ランダムに発生
	m_timer++;
	if (m_timer <= 30)
	{
		light += {1.8f / 30.0f, 1.8f / 30.0f, 0.12f / 30.0f};
	}
	if (m_timer > 30)
	{
		light -= {1.8f / 30.0f, 1.8f / 30.0f, 0.12f / 30.0f};
	}
	if (m_timer == 60) {

		m_timer = 0;

	}
	
	m_skinModelrender->SetPosition(m_position);

	m_skinModelrender->SetEmissionColor(light);
	//プレイヤーとの当たり判定
	CVector3 diff = player->GetPos() - m_position;
	if (diff.Length() < 70) {
		//エフェクト生成
		prefab::CEffect*effect = NewGO<prefab::CEffect>(0);
		//エフェクト再生
		effect->Play(L"effect/CoinEF.efk");
		effect->SetPosition(m_position);
		//Coin音再生
		m_Sound = NewGO<prefab::CSoundSource>(0);
		m_Sound->Init(L"sound/CoinGet.wav");
		m_Sound->Play(false);
		coinCount++;
		ga = FindGO<Game>("Game");
		ga->Add_BossCoinCount();
		CCount->Addcount(coinCount);
		DeleteGO(this);
	
	}
	
}




