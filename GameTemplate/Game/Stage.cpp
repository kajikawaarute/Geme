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
	return true;
}

void Stage::Update()
{
}
