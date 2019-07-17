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
	DeleteGO(fade);
}


bool Title::Start()
{
	MainCamera().SetTarget(m_position3);
	MainCamera().SetPosition({0.0f,0.0f,-300.0f});
	MainCamera().Update();

	//postEffect::Tonemap().SetLuminance(0.60f);

	//タイトル文字
	m_spriteRender = NewGO<prefab::CSpriteRender>(1);
	m_spriteRender->Init(L"sprite/Game.dds", 1280.0f, 720.0f);
	m_position.y = 340;
	m_spriteRender->SetPosition(m_position);

	//ボタン文字
	m_spriteRender1 = NewGO<prefab::CSpriteRender>(1);
	m_spriteRender1->Init(L"sprite/botanose.dds", 1280.0f, 999.0f);
	m_position1.y = -300;
	m_spriteRender1->SetPosition(m_position1);
	m_spriteRender1->SetMulColor({1.0f,1.0f, 1.0f, 1.0f});

	//Unityちゃん表示
	CSkinmodel = NewGO<prefab::CSkinModelRender>(2);
	CSkinmodel->Init(L"modelData/Player.cmo"/*,m_animClips, enAnimationClip_Num*/);
	m_position3.z = -170;
	m_position3.y = -60;

	CSkinmodel->SetRotation(m_kaiten);
	CSkinmodel->SetPosition(m_position3);
	CSkinmodel->SetScale({ 0.8f,0.8f,0.8f });
	//CSkinmodel->SetEmissionColor(light);

	//タイトル
	CSkinmodel1 = NewGO<prefab::CSkinModelRender>(2);
	CSkinmodel1->Init(L"modelData/Title.cmo");
	m_position2.z = -65;
	m_position2.y =-2;
	m_position2.x= -10;

	CQuaternion pAddRot;
	pAddRot.SetRotationDeg(CVector3::AxisX, 90.0f);
	m_kaiten1 = pAddRot;
	CSkinmodel1->SetRotation(m_kaiten1);
	CSkinmodel1->SetPosition(m_position2);
	CSkinmodel1->SetScale({ 4.5f,5.5f,2.0f });
	//CSkinmodel1->SetEmissionColor(light);

	//音楽
	m_Sound = NewGO<prefab::CSoundSource>(0);
	m_Sound->Init(L"sound/Title.wav");
	m_Sound->Play(true);

	//効果音。
	m_Sound1 = NewGO<prefab::CSoundSource>(0);
	m_Sound1->Init(L"sound/Button.wav");

	//フェイド
	fade = NewGO<Fade>(5, "Fade");
	fade->StartFadeIn();
	return true;
}


void Title::Update()
{

	m_timer3++;
	if (m_timer3 < 40)
	{
		m_spriteRender1->SetActiveFlag(false);
	}
	if (m_timer3 >= 40)
	{
		m_spriteRender1->SetActiveFlag(true);
	}
	if (m_timer3 > 79)
	{
		m_timer3 = 0;
	}
	//CSkinmodel->PlayAnimation(enAnimationClip_run, 0.5f);
	//CSkinmodel->SetPosition(m_position3);
	//プレイヤーの回転処理
	CQuaternion qAddRot;
	AngleY += 1.0f;
	m_kaiten.SetRotationDeg(CVector3::AxisY, AngleY);
	CSkinmodel->SetRotation(m_kaiten);

	//文字が動く処理
	m_timer+=GameTime().GetFrameDeltaTime();
	if (m_timer <= 2.0f) {
		m_position.y -= 2.0f;
		m_spriteRender->SetPosition(m_position);
	}

	/*m_timer2++;
	if (m_timer2 >= 3) 
	{
		color += 0.1;
	}*/
	
	//m_spriteRender1->SetMulColor(m_light);

	//ボタン押すとゲームに行く
	if (Pad(0).IsPress(enButtonA) == true) {
		//アニメーション再生
		//CSkinmodel->PlayAnimation(enAnimationClip_jump, false);
		//ボタンを押すと効果音再生
		m_Sound1->Play(false);
		fade->StartFadeOut();
		StartFlag = true;
	}
	if (StartFlag == true) {
		m_timer2 += GameTime().GetFrameDeltaTime();
		if (m_timer2 >= 1.0f)
		{
			//ゲームに移動
			NewGO<Game>(0, "Game");
			DeleteGO(this);
		}
	}
}


