#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();

	int m_timer = 0;
	prefab::CSkinModelRender* m_skinModel = nullptr;
	CVector3 m_position = CVector3::Zero;
	
};
