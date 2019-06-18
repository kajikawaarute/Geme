#include "stdafx.h"
#include "Game.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Player.h"

CVector3 cameraPos = { 0.0f, 70.0f, 200.0f };
CVector3 cameraTarget;
Game::Game()
{
	NewGO<Player>(0, "player");
}


Game::~Game()
{
	Player* pl = FindGO<Player>("player");
	DeleteGO(pl);
}
bool Game::Start()
{
	//カメラを設定。
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();

	return true;
}

void Game::Update()
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

	//注視点
	Player* pl = FindGO<Player>("player");
	CVector3 Target = pl->GetPos();
	Target.y += 50.0f;

	//視点
	CVector3 position = Target;
	position.y += 250.0f;
	position.z -= 500.0f;

	MainCamera().SetTarget(Target);
	MainCamera().SetPosition(position);
	MainCamera().Update();
}
