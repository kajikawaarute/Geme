#pragma once
class Game;
class Timer : public IGameObject
{
public:

	Timer();
	~Timer();

	bool Start();
	void Update();

	float GetTimer()
	{
		return timer;
	}

private:


	float timer = 45.0f;
	float deltaTime=0.0f;
	prefab::CFontRender* m_fontRender = nullptr;
	CVector2 m_position = CVector2::Zero;
	Game*m_Game;

};


