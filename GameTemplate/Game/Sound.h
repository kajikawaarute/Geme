#pragma once
class Sound : IGameObject
{
public:
	Sound();
	~Sound();

	bool Start();
	void Update();
	void TitleSound();
	void ButtonStart();

	prefab::CSoundSource* m_Sound = nullptr;
	prefab::CSoundSource* m_Sound1 = nullptr;
	
};

