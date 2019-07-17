#pragma once
class CoinCount;
class EnemyCount;
class Stage;

class GameClear : public IGameObject
{
public:
	GameClear();
	~GameClear();

	bool Start();
	void Update();

private:

	Stage* sg = nullptr;

	CVector3 color;
	CVector3 color1;

	float m_timer = 0.0f;

	EnemyCount* enemyGetCount = nullptr;
	CoinCount* coinGetCount =nullptr;
	prefab::CFontRender* m_fontRender = nullptr;
	prefab::CFontRender* m_fontRender2 = nullptr;
	prefab::CSpriteRender*m_spriteRender = nullptr;
};

