#pragma once
class BulletCount : public IGameObject
{
public:
	BulletCount();
	~BulletCount();
	bool Start();
	void Update();
	void blcount(int bl) {
		blCount = bl;
	}
private:

	int blCount = 0;
	prefab::CFontRender* m_font = nullptr;
	CVector2 m_position = { -600.0f, 150.0f };
};

