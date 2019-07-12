#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
class Coin;
class CoinCount;

class Game : public IGameObject

{
public:
	Game();
	~Game();
	bool Start();
	void Update();

	int coinCount = 0; //ボスが出てくるためのコインカウント
	int damageCount = 0;	//プレイヤーのダメージカウント
	float m_Timer = 0;



	float m_timer = 0;
	Coin*m_coin = nullptr;
	float m_restTimer = 60.0f;
	prefab::CDirectionLight* m_Light = nullptr;
	float m_restTimer = 10.0f;

	float GetRestTime() const
	{
		return m_restTimer;
	}
};

