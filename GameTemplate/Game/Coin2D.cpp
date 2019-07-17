#include "stdafx.h"
#include "Coin2D.h"


Coin2D::Coin2D()
{
}


Coin2D::~Coin2D()
{
	DeleteGO(m_sprite);
}


bool Coin2D::Start()
{
	
	//ÉRÉCÉì2D
	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/Coin.dds", 300, 300);
	m_sprite->SetPosition({ 460.0f,280.0f,0.0f });

	
	
	return true;
}


void Coin2D::Update()
{

}

