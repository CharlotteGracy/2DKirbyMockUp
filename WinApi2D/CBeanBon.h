#pragma once
#include "CMonster.h"
class CD2DImage;
class AI;







class CBeanbon : public CMonster
{
	CBeanbon();
	~CBeanbon();


	void render();
	void update();

	float GetSpeed();

	void SetSpeed(float speed);
	void SetAI(AI* ai);
	void SetMonInfo(const tMonInfo& info);

	void OnCollisionEnter(CCollider* pOther);
};
