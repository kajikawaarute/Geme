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
	DeleteGO(m_Sound);
	DeleteGO(CSkinmodel);
	DeleteGO(CSkinmodel1);

}


bool Title::Start()
{
	MainCamera().SetTarget(m_position3);
	MainCamera().SetPosition({0.0f,0.0f,-400.0f});
	MainCamera().Update();

	//タイトル
	/*m_spriteRender2 = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender2->Init(L"sprite/title.dds", 1280.0f, 720.0f);
	m_spriteRender2->SetPosition(m_position2);*/

	//文字
	m_spriteRender = NewGO<prefab::CSpriteRender>(1);
	m_spriteRender->Init(L"sprite/Game.dds", 1280.0f, 720.0f);
	m_position.y = 340;
	m_spriteRender->SetPosition(m_position);

	//文字
	m_spriteRender1 = NewGO<prefab::CSpriteRender>(1);
	m_spriteRender1->Init(L"sprite/botanose.dds", 1280.0f, 720.0f);
	m_position1.y = -300;
	m_spriteRender1->SetPosition(m_position1);

	//Unityちゃん表示
	CSkinmodel = NewGO<prefab::CSkinModelRender>(2);
	CSkinmodel->Init(L"modelData/unityChan.cmo");
	m_position3.z = -200;
	m_position3.y = -50;
	CSkinmodel->SetPosition(m_position3);
	CSkinmodel->SetScale({ 0.8f,0.8f,0.8f });

	//タイトル
	CSkinmodel1 = NewGO<prefab::CSkinModelRender>(2);
	CSkinmodel1->Init(L"modelData/Title.cmo");
	m_position2.z = -100;
	m_position2.y = 10;
	m_position2.x= -10;
	CQuaternion pAddRot;
	pAddRot.SetRotationDeg(CVector3::AxisX, 90.0f);
	m_kaiten1 = pAddRot;
	CSkinmodel1->SetRotation(m_kaiten1);
	CSkinmodel1->SetPosition(m_position2);
	CSkinmodel1->SetScale({ 2.7f,2.6f,2.0f });

	//音楽再生
	m_Sound = NewGO<prefab::CSoundSource>(0);
	m_Sound->Init(L"sound/Title.wav");
	m_Sound->Play(true);
	
	fade = FindGO<Fade>("Fade");

	return true;
}


void Title::Update()
{
	//CSkinmodel->SetPosition(m_position3);
	//プレイヤーの回転処理
	CQuaternion qAddRot;
	qAddRot.SetRotationDeg(CVector3::AxisY, 2.0f);
	m_kaiten *= qAddRot;
	CSkinmodel->SetRotation(m_kaiten);

	//文字が動く処理
	m_timer+=GameTime().GetFrameDeltaTime();
	if (m_timer <= 2.0f) {
		m_position.y -= 2.0f;
		m_spriteRender->SetPosition(m_position);
		
	}

	//ボタン押すとゲームに行く
	if (Pad(0).IsPress(enButtonA) == true) {

		//ボタンを押すと効果音再生
		m_Sound1 = NewGO<prefab::CSoundSource>(0);
		m_Sound1->Init(L"sound/Button.wav");
		m_Sound1->Play(false);

		//ゲームに移動
		NewGO<Game>(0, "Game");
		fade->StartFadeOut();
		DeleteGO(this);
	}
}


