#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "BulletCount.h"
#include "PlayerHP.h"
#include "Game.h"

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
	m_skinModel->Init(L"modelData/Player.cmo");
	m_charCon.Init(40.0f, 100.0f, m_position);
	m_skinModel->SetShadowCasterFlag(true);

	return true;
}

void Player::Move()
{
	float LStick_x = Pad(0).GetLStickXF() * 500.0f;
	float LStick_y = Pad(0).GetLStickYF() * 500.0f;

	//カメラの前方向と右方向を取得
	CVector3 cameraFoward = MainCamera().GetForward();
	CVector3 cameraRight = MainCamera().GetRight();

	//XZ平面での前方向と右方向に変換する
	cameraFoward.y = 0.0f;
	cameraFoward.Normalize();
	cameraRight.y = 0.0f;
	cameraRight.Normalize();

	//XZ成分の移動速度をクリア
	m_moveSpeed.x = 0;
	m_moveSpeed.y -= 100;
	m_moveSpeed.z = 0;

	m_moveSpeed += cameraFoward * LStick_y;
	m_moveSpeed += cameraRight * LStick_x;

	//弾丸を撃つ
	if (Pad(0).IsTrigger(enButtonB)) {
		if (bulletCount != 0) {
			bl = NewGO<Bullet>(0, "bullet");
			bl->GetPos() = m_position;
			bl->SetSpd(cameraFoward, 1000.0f);
			bulletCount--;
			
			sound = NewGO<prefab::CSoundSource>(0);
			sound->Init(L"sound/shot.wav");
			sound->Play(false);
		}
	}

	CQuaternion qRot;
	qRot.SetRotation({ 1.0f, 0.0f, 0.0f }, cameraRight);
	m_rotation = qRot;

}

void Player::Death()
{
	ga = FindGO<Game>("Game");
	if (ga->GetdamageCount() == 3) {
		m_timer += GameTime().GetFrameDeltaTime();
		//一定時間エフェクトの表示
		/*if (m_timer < 1.0f) {
			prefab::CEffect* ef = NewGO<prefab::CEffect>(0);
			ef->Play(L"effect/playerdown.efk");
			
			CVector3 efPos = m_position;
			efPos.y = 50.0f;
			ef->SetPosition(efPos);
		}*/
	}
}

void Player::Update()
{
	Move();
	//Death();

	m_position = m_charCon.Execute(m_moveSpeed);
	m_skinModel->SetPosition(m_position);
	m_skinModel->SetRotation(m_rotation);
}