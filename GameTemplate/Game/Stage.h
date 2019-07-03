#pragma once
class Stage : public IGameObject
{
public:
	Stage();
	~Stage();

	bool Start();
	void Update();
private:
	prefab::CSkinModelRender*m_skinModel = nullptr;
};

