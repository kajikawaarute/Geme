#include "stdafx.h"
#include "Boss.h"
#include "Player.h"
#include "Bullet.h"

Boss::Boss()
{
}


Boss::~Boss()
{
	DeleteGO(m_skinModel);
}

bool Boss::Start()
{
	m_skinModel = NewGO <prefab::CSkinModelRender>(0);
	m_skinModel->Init(L"modelData/unityChan.cmo");
	m_chraCon.Init(30.0f, 50.0f, m_position);
	return true;
}

void Boss::Move()
{
	QueryGOs<Player>("player", [&](Player* pl)->bool {
		CVector3 v = pl->GetPos() - m_position;
		if (v.Length() > 10.0f) {
			m_moveSpeed = v;
			m_qRot.SetRotation({ 0.0f, 0.0f, 1.0f }, v);
			m_rotation = m_qRot;
		}
		return true;
		});
	m_position = m_chraCon.Execute(m_moveSpeed);
}

void Boss::Death()
{
	QueryGOs<Bullet>("bullet", [&](Bullet* bl)->bool {
		CVector3 v = bl->GetPos() - m_position;
		if (v.Length() < 50.0f) {
			bossHP_Count--;

			//エフェクトの表示
			prefab::CEffect* ef = NewGO<prefab::CEffect>(0);
			ef->Play(L"effect/bossdown.efk");
			CVector3 efPos = m_position;
			efPos.y = 50.0f;
			ef->SetPosition(efPos);

			DeleteGO(this);
			DeleteGO(bl);
		}
		return true;
		});
}



void Boss::Update()
{
	Move();
	Death();

	m_skinModel->SetPosition(m_position);
	m_skinModel->SetRotation(m_rotation);
}
