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
	int BossCount(int num) 
	{
		return enemyCount += num;
		
	}

	int GetEnemy()
	{
		return enemyCount;
	}


private:
	CVector3 m_color;
	int enemyCount = 0;
	//�G�l�~�[�J�E���g
	prefab::CFontRender*m_fontRender = nullptr;
};

