#include "stdafx.h"
#include "Enemy2.h"
#include "Player.h"
#include "Bullet.h"
#include "EnemyBullet.h"
#include "EnemyCount.h"

Enemy2::Enemy2()
{
}


Enemy2::~Enemy2()
{
	DeleteGO(m_skinModel);
}

bool Enemy2::Start()
{
	enemygetCount = FindGO<EnemyCount>("enCount");
	m_aninationClip[enAnim_rotation].Load(L"animData/enemy2_rotation.tka");
	m_aninationClip[enAnim_rotation].SetLoopFlag(true);

	m_skinModel = NewGO<prefab::CSkinModelRender>(0);
	m_skinModel->Init(L"modelData/Enemy2.cmo", m_aninationClip, enAnim_Num);

	float t = Random().GetRandDouble();
	m_position.x = CMath::Lerp(t, -500.0f, 500.0f);
	m_position.z = CMath::Lerp(t, 650.0f, 300.0f);

	m_chraCon.Init(33.0f, 50.0f, m_position);
	return true;
}

void Enemy2::Move()
{
	QueryGOs<Player>("player", [&](Player* pl)->bool {
		CVector3 v = pl->GetPos() - m_position;
		if (v.Length() > 10.0f) {
			m_moveSpeed = v;
		}
		return true;
		});
	m_position = m_chraCon.Execute(m_moveSpeed);
}

void Enemy2::Death()
{
	QueryGOs<Bullet>("bullet", [&](Bullet* bl)->bool {
		CVector3 v = bl->GetPos() - m_position;
		if (v.Length() < 80.0f) {
			//エフェクトの表示
			prefab::CEffect* ef = NewGO<prefab::CEffect>(0);
			ef->Play(L"effect/enemy2down.efk");
			CVector3 efPos = m_position;
			efPos.y = 50.0f;
			ef->SetPosition(efPos);
			enemygetCount->Add_enemyCount();
			//音を再生
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/Enemydamege.wav");
			m_sound->Play(false);

			DeleteGO(this);
			DeleteGO(bl);
		}
		return true;
	});
}

void Enemy2::Shoot()
{
	m_bltimer++;
	if (m_bltimer == 40) {
		EnemyBullet* enebl = NewGO<EnemyBullet>(0 ,"enebl");
		enebl->Getpos() = m_position;
		//enebl->SetSpd(, 1000.0f);
		m_bltimer = 0;

		m_sound2 = NewGO<prefab::CSoundSource>(0);
		m_sound2->Init(L"sound/Enemyshot.wav");
		m_sound2->Play(false);
	}
}

void Enemy2::Update()
{
	Move();
	Death();
	Shoot();

	////一定時間で敵が消える。
	//m_timer += GameTime().GetFrameDeltaTime();
	//if (m_timer > 5) {
	//	DeleteGO(this);
	//}

	m_skinModel->SetPosition(m_position);
}
