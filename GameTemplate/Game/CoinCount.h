#pragma once
class Coin;
class CoinCount : public IGameObject
{
public:
	CoinCount();
	~CoinCount();

	bool Start();
	void Update();

	void Addcount(int coin) {
		coinCount += coin;
	}
	/*void Setcount(int coin)
	{
		coinCount = coin;
	}*/
	bool GetCoin()
	{
		return coinCount;
	}

private:
	int coinCount = 0;
	//コインカウント2D
	prefab::CFontRender* m_fontRender = nullptr;
};

