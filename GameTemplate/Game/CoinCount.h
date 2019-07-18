#pragma once
class Coin;
class Game;

class CoinCount : public IGameObject
{
public:
	CoinCount();
	~CoinCount();

	bool Start();
	void Update();

	void Addcount(int coin) {
		coinCount -= coin;
	}
	int GetCoin()
	{
		return coinCount;
	}



private:
	Game* game = nullptr;
	CVector3 m_color;
	int coinCount = 7;
	//コインカウント2D
	prefab::CFontRender* m_fontRender = nullptr;
};

