#pragma once
class EnemyCount : public IGameObject
{
public:
	EnemyCount();
	~EnemyCount();

	bool Start();
	void Update();

	void Add_enemyCount()
	{
		enemyCount++;
	}
	int GetEnemy()
	{
		return enemyCount;
	}

private:
	int enemyCount = 0;
	//�G�l�~�[�J�E���g
	prefab::CFontRender*m_fontRender = nullptr;
};

