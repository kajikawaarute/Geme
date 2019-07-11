#include "stdafx.h"
#include "Bullet.h"
#include "Stage.h"

Bullet::Bullet()
{
}


Bullet::~Bullet()
{
	DeleteGO(m_skinModel);
}

bool Bullet::Start()
{
	m_skinModel = NewGO<prefab::CSkinModelRender>(0);
	m_skinModel->Init(L"modelData/Bullet.cmo");
	m_charCon.Init(10.0f, 10.0f, m_position);

	return true;
}

void Bullet::Update()
{
	m_speed.y = 70.0f;
	m_position += m_speed;

	//ˆê’èŽžŠÔ‚µ‚½‚çÁ‚¦‚é
	m_timer++;
	if (m_timer == 40) {
		DeleteGO(this);
	}
	
	m_position = m_charCon.Execute(m_speed);
	m_skinModel->SetPosition(m_position);
}