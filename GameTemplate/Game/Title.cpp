#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "Fade.h"


Title::Title()
{
}


Title::~Title()
{

	DeleteGO(m_spriteRender);
	DeleteGO(m_spriteRender1);
	DeleteGO(m_spriteRender2);
	DeleteGO(m_Sound);
	DeleteGO(CSkinmodel);

}


bool Title::Start()
{
	MainCamera().SetTarget(m_position3);
	MainCamera().SetPosition({0.0f,0.0f,-400.0f});
	MainCamera().Update();

	//�^�C�g��
	/*m_spriteRender2 = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender2->Init(L"sprite/title.dds", 1280.0f, 720.0f);
	m_spriteRender2->SetPosition(m_position2);*/

	//����
	m_spriteRender = NewGO<prefab::CSpriteRender>(1);
	m_spriteRender->Init(L"sprite/Game.dds", 1280.0f, 720.0f);
	m_position.y = 340;
	m_spriteRender->SetPosition(m_position);

	//����
	m_spriteRender1 = NewGO<prefab::CSpriteRender>(1);
	m_spriteRender1->Init(L"sprite/botanose.dds", 1280.0f, 720.0f);
	m_position1.y = -300;
	m_spriteRender1->SetPosition(m_position1);

	//Unity�����\��
	CSkinmodel = NewGO<prefab::CSkinModelRender>(2);
	CSkinmodel->Init(L"modelData/unityChan.cmo");
	m_position3.z = -200;
	m_position3.y = -50;
	CSkinmodel->SetPosition(m_position3);
	CSkinmodel->SetScale({ 0.8f,0.8f,0.8f });

	//���y�Đ�
	m_Sound = NewGO<prefab::CSoundSource>(0);
	m_Sound->Init(L"sound/Title.wav");
	m_Sound->Play(true);
	
	fade = FindGO<Fade>("Fade");

	return true;
}


void Title::Update()
{
	//CSkinmodel->SetPosition(m_position3);

	//��������������
	m_timer+=GameTime().GetFrameDeltaTime();
	if (m_timer <= 2.0f) {
		m_position.y -= 2.0f;
		m_spriteRender->SetPosition(m_position);
		
	}

	//�{�^�������ƃQ�[���ɍs��
	if (Pad(0).IsPress(enButtonA) == true) {

		//�{�^���������ƌ��ʉ��Đ�
		m_Sound1 = NewGO<prefab::CSoundSource>(0);
		m_Sound1->Init(L"sound/Button.wav");
		m_Sound1->Play(false);

		//�Q�[���Ɉړ�
		NewGO<Game>(0, "Game");
		fade->StartFadeOut();
		DeleteGO(this);
	}
}


