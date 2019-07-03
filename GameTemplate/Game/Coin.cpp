#include "stdafx.h"
#include "Coin.h"
#include "Player.h"
#include "CoinCount.h"
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
	return true;
}


void Coin::Update()
{

	//コインの回転処理
	CQuaternion qAddRot;
	qAddRot.SetRotationDeg(CVector3::AxisY, 2.0f);
	m_rotation *= qAddRot;
	m_skinModelrender->SetRotation(m_rotation);


	//ランダムに発生
	m_timer++;
	if (m_timer == 60) {
		m_position.x = (rand() % 1800);
		float tate = (rand() % 2);
		if (tate == 1) {
			m_position.x = m_position.x * -1;
		}

		float yoko = (rand() % 2);
		m_position.z = (rand() % 1800);
		if (yoko == 1) {
			m_position.z = m_position.z*-1;
		}

		m_skinModelrender->SetPosition(m_position);
		m_timer = 0;

	}
	

	//プレイヤーとの当たり判定
	CVector3 diff = player->GetPos() - m_position;
	if (diff.Length() < 70) {
		coinCount++;
		CCount->Addcount(coinCount);
		DeleteGO(this);
	
	}
	
}




