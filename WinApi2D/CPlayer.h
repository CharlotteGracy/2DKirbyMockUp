#pragma once
#include "CGameObject.h"

class CD2DImage;

class CPlayer : public CGameObject
{
private:
	static CPlayer* instance;
	float m_fSpeed = 300;
	bool m_bIsLeft;
	void CreateBomb();


public:
	CPlayer();
	~CPlayer();
	virtual CPlayer* Clone();


	virtual void update();
	virtual void render();

	void RegisterPlayer();
	static CPlayer* GetPlayer();	
	// 게임 내에 하나만 있는 플레이어 객체 확인(임의로 싱글톤 선언)
};

