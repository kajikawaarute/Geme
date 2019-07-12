#pragma once

#include "tkEngine/camera/tkSpringCamera.h"
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start();
	void Update();
private:
	CVector3 m_toCameraPos;
	CSpringCamera m_springCamera;	//‚Î‚ËƒJƒƒ‰
};

