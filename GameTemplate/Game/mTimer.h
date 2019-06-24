#pragma once
class mTimer : public IGameObject
{
public:
	mTimer();
	~mTimer();

	bool Start();
	void Update();

	int m_timer = 0;
};

