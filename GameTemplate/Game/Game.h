#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
class Coin;
class CoinCount;
class Player;
class Enemy2;
class Game : public IGameObject

{
public:
	Game();
	~Game();
	bool Start();
	void Update();

	bool GetisGameOver()
	{
		return is_GameOver;
	}

	void SetGameOver(bool flag)
	{
		is_GameOver = flag;
	}

	bool GetisGameClear()
	{
		return is_GameClear;
	}

	void SetGameClear(bool flag)
	{
		is_GameClear = flag;
	}

	int GetdamageCount()
	{
		return damageCount;
	}

	void SetdamageCount(int num)
	{
		damageCount = num;
	}
	void Add_damageCount()
	{
		damageCount++;
	}

	int BossCoinCount()
	{
		return coinCount;
	}
	
	void Add_BossCoinCount()
	{
		coinCount++;
	}

	void reset_BossCoinCount()
	{
		coinCount = 0;
	}
	
	float m_Timer = 0;

	float m_restTimer = 10.0f;
	float GetRestTime() const
	{
		return m_restTimer;
	}
	Player*pl = nullptr;
private:

	int coinCount = 0; //ボスが出てくるためのコインカウント
	int damageCount = 0;	//プレイヤーのダメージカウント
	bool is_GameOver = false;
	bool is_GameClear = false;

	float m_timer = 0;
	Coin*m_coin = nullptr;
	
	prefab::CSoundSource* m_Psound = nullptr;
	prefab::CSoundSource* m_sound = nullptr;
	prefab::CDirectionLight* m_Light = nullptr;

};

