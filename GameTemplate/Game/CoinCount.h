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
	int GetCoin()
	{
		return coinCount;
	}

private:

	int coinCount = 0;
	//�R�C���J�E���g2D
	prefab::CFontRender* m_fontRender = nullptr;
};

