#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{
	////�J������ݒ�B
	//MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	//MainCamera().SetNear(10.0f);
	//MainCamera().SetFar(10000.0f);
	//MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	//MainCamera().Update();
}


GameCamera::~GameCamera()
{
}

bool GameCamera::Start()
{
	m_toCameraPos.Set(0.0f, 250.0f, -500.0f);

	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);

	//�΂˃J�����̏�����
	m_springCamera.Init(MainCamera(), 1000.0f, true, 5.0f);
	return true;
}

void GameCamera::Update()
{
	/*float speed = 1.0f;
	if (Pad(0).IsPress(enButtonB)) {
	speed *= 10.0f;
	}
	if (Pad(0).IsPress(enButtonUp)) {
	cameraPos.z -= speed;
	}
	if (Pad(0).IsPress(enButtonDown)) {
	cameraPos.z += speed;
	}*/

	//�����_
	Player* pl = FindGO<Player>("player");
	CVector3 Target = pl->GetPos();
	Target.y += 50.0f;

	//R�X�e�B�b�N�ŃJ��������
	CVector3 toCameraPosOld = m_toCameraPos;
	float x = Pad(0).GetRStickXF();
	float y = Pad(0).GetRStickYF();

	//Y������
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 4.0f * x);
	qRot.Multiply(m_toCameraPos);

	//X������
	/*CVector3 axisX;
	axisX.Cross(CVector3::AxisY, m_toCameraPos);
	axisX.Normalize();
	qRot.SetRotationDeg(axisX, 4.0f * y);
	qRot.Multiply(m_toCameraPos);*/

	CVector3 toPosDir = m_toCameraPos;
	toPosDir.Normalize();
	if (toPosDir.y < -0.5f) {
		//�J���������������
		m_toCameraPos = toCameraPosOld;
	}
	else if (toPosDir.y > 0.8f) {
		//�J����������������
		m_toCameraPos = toCameraPosOld;
	}

	//���_
	CVector3 position = Target + m_toCameraPos;

	m_springCamera.SetTarget(Target);
	m_springCamera.SetPosition(position);
	m_springCamera.Update();

	/*MainCamera().SetTarget(Target);
	MainCamera().SetPosition(position);
	MainCamera().Update();*/
}