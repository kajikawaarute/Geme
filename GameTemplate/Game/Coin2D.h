#pragma once
class Coin2D : public IGameObject
{
public:
	Coin2D();
	~Coin2D();

	bool Start();
	void Update();

private:

	CVector3 m_position = CVector3::Zero;
	//ÉRÉCÉì2D
	prefab::CSpriteRender* m_sprite = nullptr;

};

