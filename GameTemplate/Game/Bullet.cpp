#include "stdafx.h"
#include "Bullet.h"


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
	return true;
}

void Bullet::Update()
{
	m_position.y = 70.0f;
	m_position += m_speed;

	//��莞�Ԃ����������
	m_timer++;
	if (m_timer == 40) {
		DeleteGO(this);
	}
	m_skinModel->SetPosition(m_position);
}