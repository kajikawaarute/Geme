#include "stdafx.h"
#include "PlayerHP.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "EnemyBullet.h"
#include "Game.h"

PlayerHP::PlayerHP()
{
}


PlayerHP::~PlayerHP()
{
	DeleteGO(m_sprite);
	DeleteGO(m_sprite2);
	DeleteGO(m_sprite3);
}

bool PlayerHP::Start()
{
	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/heart.dds", 150, 100);

	m_sprite2 = NewGO<prefab::CSpriteRender>(0);
	m_sprite2->Init(L"sprite/heart2.dds", 150, 100);

	m_sprite3 = NewGO<prefab::CSpriteRender>(0);
	m_sprite3->Init(L"sprite/heart3.dds", 150, 100);

	return true;
}

void PlayerHP::Update()
{
	m_position.x = -570.0f;
	m_position.y = -300.0f;

	m_position2.x = -470.0f;
	m_position2.y = -300.0f;

	m_position3.x = -370.0f;
	m_position3.y = -300.0f;

	Player* pl = FindGO<Player>("player");
	Game* ga = FindGO<Game>("Game");

	//エネミー１に当たるとHPが減る。
	QueryGOs<Enemy>("ene", [&](Enemy* ene)->bool {
		CVector3 v = pl->GetPos() - ene->GetPos();
		if (v.Length() < 80.0f) {
			if (m_sprite != nullptr) {
				DeleteGO(m_sprite);
				m_sprite = nullptr;
				ga->Add_damageCount();
			}
			else if (m_sprite2 != nullptr) {
				DeleteGO(m_sprite2);
				m_sprite2 = nullptr;
				ga->Add_damageCount();
			}
			else if (m_sprite3 != nullptr) {
				DeleteGO(m_sprite3);
				m_sprite3 = nullptr;
				//ga->SetdamageCount(ga->GetdamageCount()+1);
				ga->Add_damageCount();
			}
		}

		return true;
		});

	//エネミー２に当たるとがHPが減る。
	QueryGOs<Enemy2>("ene2", [&](Enemy2* ene2)->bool {
		CVector3 v = pl->GetPos() - ene2->GetPos();
		if (v.Length() < 80.0f) {
			if (m_sprite != nullptr) {
				DeleteGO(m_sprite);
				m_sprite = nullptr;
				ga->Add_damageCount();
			}
			else if (m_sprite2 != nullptr) {
				DeleteGO(m_sprite2);
				m_sprite2 = nullptr;
				ga->Add_damageCount();
			}
			else if (m_sprite3 != nullptr) {
				DeleteGO(m_sprite3);
				m_sprite3 = nullptr;
				ga->Add_damageCount();
			}
		}
		return true;
		});

	//エネミーの弾丸に当たるとHPが減る。
	QueryGOs<EnemyBullet>("enebl", [&](EnemyBullet* enebl)->bool {
		CVector3 v = pl->GetPos() - enebl->Getpos();
		if (v.Length() < 80.0f) {
			if (m_sprite != nullptr) {
				DeleteGO(m_sprite);
				DeleteGO(enebl);
				m_sprite = nullptr;
				ga->Add_damageCount();
				
			}
			else if (m_sprite2 != nullptr) {
				DeleteGO(m_sprite2);
				DeleteGO(enebl);
				m_sprite2 = nullptr;
				ga->Add_damageCount();
			}
			else if (m_sprite3 != nullptr) {
				DeleteGO(m_sprite3);
				DeleteGO(enebl);
				m_sprite3 = nullptr;
				ga->Add_damageCount();
			}
		}
		return true;
		});

	if (m_sprite != nullptr) {
		m_sprite->SetPosition(m_position);
	}

	if (m_sprite2 != nullptr) {
		m_sprite2->SetPosition(m_position2);
	}

	if (m_sprite3 != nullptr) {
		m_sprite3->SetPosition(m_position3);
	}

	if (ga->GetdamageCount() >=3) {
		ga->SetGameOver(true);
	}
}