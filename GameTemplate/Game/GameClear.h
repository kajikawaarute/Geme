#pragma once
class CoinCount;

class GameClear : public IGameObject
{
public:
	GameClear();
	~GameClear();

	bool Start();
	void Update();

private:

	CoinCount* coinGetCount =nullptr;
	prefab::CFontRender* m_fontRender = nullptr;
	prefab::CSpriteRender*m_spriteRender = nullptr;
};

