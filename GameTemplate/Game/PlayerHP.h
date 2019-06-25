#pragma once
class PlayerHP : public IGameObject
{
public:
	PlayerHP();
	~PlayerHP();
	bool Start();
	void Update();
private:
	prefab::CSpriteRender* m_sprite = nullptr;
	prefab::CSpriteRender* m_sprite2 = nullptr;
	prefab::CSpriteRender* m_sprite3 = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_position2 = CVector3::Zero;
	CVector3 m_position3 = CVector3::Zero;
};

