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
	//エネミーカウント
	prefab::CFontRender*m_fontRender = nullptr;
};

