#pragma once
class Game;
class Timer : public IGameObject
{
public:

	Timer();
	~Timer();

	bool Start();
	void Update();

private:
	prefab::CFontRender* m_fontRender = nullptr;
	CVector2 m_position = CVector2::Zero;
	Game*m_Game;
	int timer = 0;
};


