#include "stdafx.h"
#include "Stage.h"
#include "Bullet.h"

Stage::Stage()
{
}


Stage::~Stage()
{
	DeleteGO(m_skinModel);
}

bool Stage::Start()
{
	m_skinModel = NewGO<prefab::CSkinModelRender>(0);
	m_skinModel->Init(L"modelData/stage.cmo");
	m_staticObject.CreateMesh(CVector3::Zero, CQuaternion::Identity, CVector3::One, m_skinModel);
	//PhysicsWorld().SetDebugDrawMode(btIDebugDraw::DBG_DrawWireframe);
	m_skinModel->SetShadowReceiverFlag(true);
	m_skinModel->SetShadowCasterFlag(true);
	return true;
}


void Stage::Update()
{
	
}
