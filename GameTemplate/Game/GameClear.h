#pragma once
class CoinCount;
class EnemyCount;

class GameClear : public IGameObject
{
public:
	GameClear();
	~GameClear();

	bool Start();
	void Update();

private:

	CVector3 color;

	CoinCount* coinGetCount =nullptr;
	prefab::CFontRender* m_fontRender = nullptr;
	prefab::CFontRender* m_fontRender2 = nullptr;
	prefab::CSpriteRender*m_spriteRender = nullptr;
};

