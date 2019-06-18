#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
	DeleteGO(m_skinModel);
}

bool Player::Start()
{
	m_skinModel = NewGO<prefab::CSkinModelRender>(0);
	m_skinModel->Init(L"modelData/unityChan.cmo");
	m_charCon.Init(40.0f, 100.0f, m_position);

	return true;
}

void Player::Move()
{
	m_moveSpeed.x = 0;
	m_moveSpeed.y = 0;
	m_moveSpeed.z = 0;

	m_moveSpeed.x = Pad(0).GetLStickXF() * 100.0f;
	m_moveSpeed.z = Pad(0).GetLStickYF() * 100.0f;

	m_position = m_charCon.Execute(m_moveSpeed);
	m_skinModel->SetPosition(m_position);
}

void Player::Update()
{
	Move();
}