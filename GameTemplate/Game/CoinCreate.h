#pragma once
class Coin;
class CoinCreate : public IGameObject
{
public:
	CoinCreate();
	~CoinCreate();

	bool Start();
	void Update();

private:

	float m_timer = 0.0f;
	Coin* coin = nullptr;

};

