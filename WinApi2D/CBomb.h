#pragma once
#include "CGameObject.h"
class CBomb : public CGameObject
{
private:
	fVec2 m_fvDir;
	float m_fVelocity = 400.f;

public:
	CBomb();
	~CBomb();
	virtual CBomb* Clone();

	virtual void update();
	virtual void render(HDC hDC);

	void SetDir(fVec2 vec);
	void SetDir(float theta);

	void OnCollisionEnter(CCollider* pOther);
};

