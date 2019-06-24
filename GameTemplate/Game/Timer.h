#pragma once
class Timer : public IGameObject
{
public:

	Timer();
	~Timer();

	bool Start();
	void Update();

	int m_timer = 0;
};

