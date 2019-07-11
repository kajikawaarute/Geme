#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
class Coin;
class Game : public IGameObject

{
public:
	Game();
	~Game();
	bool Start();
	void Update();

	int coinCount = 0;

	float m_timer = 0;
	Coin*m_coin = nullptr;
	float m_restTimer = 60.0f;

	float GetRestTime() const
	{
		return m_restTimer;
	}
};

