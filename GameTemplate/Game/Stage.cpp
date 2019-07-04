#include "stdafx.h"
#include "Stage.h"


Stage::Stage()
{
}


Stage::~Stage()
{
}

bool Stage::Start()
{
	m_skinModel = NewGO<prefab::CSkinModelRender>(0);
	m_skinModel->Init(L"modelData/stage.cmo");
	m_staticObject.CreateMesh(CVector3::Zero, CQuaternion::Identity, CVector3::One, m_skinModel);
	return true;
}

void Stage::Update()
{
}
