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


	float m_timer = 0;
	prefab::CSkinModelRender* m_skinModel = nullptr;
	CoinCount*coinCount = nullptr;
	Coin*m_coin = nullptr;
	float m_restTimer = 10.0f;

	float GetRestTime() const
	{
		return m_restTimer;
	}

	CVector3 m_position = CVector3::Zero;
};

