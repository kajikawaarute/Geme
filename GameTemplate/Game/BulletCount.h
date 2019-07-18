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

	CVector3 color;
	int blCount = 0;
	prefab::CFontRender* m_font = nullptr;
	CVector2 m_position = { -620.0f, -200.0f };
};

