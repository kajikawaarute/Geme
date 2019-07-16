#include "stdafx.h"
#include "GameOver.h"
#include "Game.h"
#include "Player.h"
#include "Title.h"

GameOver::GameOver()
{
	
}


GameOver::~GameOver()
{
	//DeleteGO(m_skinRender1);
	DeleteGO(m_sprite);
}


bool GameOver::Start()
{

	MainCamera().SetTarget(m_position);
	/*MainCamera().SetPosition({ 0.0f,0.0f,-250.0f });
	MainCamera().Update();*/
	
	//3D
	/*m_skinRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinRender->Init(L"modelData/GameOver.cmo");
	m_skinRender->SetScale({ 4.0f,3.9f,2.0f });
	CQuaternion pAddRot;
	pAddRot.SetRotationDeg(CVector3::AxisX, 90.0f);
	m_kaiten = pAddRot;
	m_skinRender->SetEmissionColor(light);
	m_skinRender->SetRotation(m_kaiten);*/

	/*m_skinRender1 = NewGO<prefab::CSkinModelRender>(0);
	m_skinRender1->Init(L"modelData/Overmoji.cmo");
	m_skinRender1->SetScale({ 1.5f,1.5f,1.5f });
	m_position1.y = 0.0f;
	m_position1.z = -150.0f;
	m_skinRender1->SetPosition(m_position1);*/
	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/GameOver.dds", 1200.0f, 780.0f);
	m_position.y = 199;
	m_sprite->SetPosition(m_position);

	return true;

}


void GameOver::Update()
{

	m_timer += GameTime().GetFrameDeltaTime();
	if (m_timer <= 2.0f) {
		m_position.y -= 2.0f;
		m_sprite->SetPosition(m_position);
	}
	//if (Pad(0).IsPress(enButtonSelect) == true) 
	//	DeleteGO(this);
	//	NewGO<Title>(0);

}

