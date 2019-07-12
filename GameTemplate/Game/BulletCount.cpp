#include "stdafx.h"
#include "BulletCount.h"
#include "Player.h"

BulletCount::BulletCount()
{
}


BulletCount::~BulletCount()
{
	DeleteGO(m_font);
}

bool BulletCount::Start()
{
	m_font = NewGO<prefab::CFontRender>(0);
	m_font->SetPosition(m_position);
	return true;
}

void BulletCount::Update()
{
	wchar_t text[64];
	Player* pl = FindGO<Player>("player");
	swprintf(text, L"�e�� %d", pl->GetBullet());
	m_font->SetText(text);
	
}