#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class CoinCount;
class Game;

class Coin :public IGameObject
{
public:

	Coin();
	~Coin();
	bool Start();
	void Update();
	void SetPosition(CVector3 pos)
	{
		m_position = pos;
	}
	
	
private:
	Player*player = nullptr;
	CoinCount*CCount = nullptr;
	Game* ga = nullptr;

	int m_timer = 0;
	int coinCount = 0;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_position = CVector3::Zero;		
	//コイン3D
	prefab::CSkinModelRender* m_skinModelrender = nullptr;
	//ライト
	prefab::CDirectionLight* m_directionLig = nullptr;
	//サウンド
	prefab::CSoundSource* m_Sound = nullptr;

	CVector3 light = {1.8f,1.8f,0.12f};
};

