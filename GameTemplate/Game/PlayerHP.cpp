#include "stdafx.h"
#include "PlayerHP.h"


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

	if (m_sprite != nullptr) {
		m_sprite->SetPosition(m_position);
	}

	if (m_sprite2 != nullptr) {
		m_sprite2->SetPosition(m_position2);
	}

	if (m_sprite3 != nullptr) {
		m_sprite3->SetPosition(m_position3);
	}
}