#pragma once
#include "CGameObject.h"

class CPlayer : public CGameObject
{
private:

public:
	CPlayer();
	~CPlayer();

	virtual void update();
	virtual void render(HDC hDC);

	virtual void GetPlayer();

	void CreateBomb();
};

