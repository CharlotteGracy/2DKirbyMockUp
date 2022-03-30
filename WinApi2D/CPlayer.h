#pragma once
#include "CGameObject.h"

class CD2DImage;

class CPlayer : public CGameObject
{
private:
	static CPlayer* instance;
	float m_fSpeed = 300;
//	float m_fHorizontalSpeed;
//	UINT m_uiGroundCount;
	bool m_bIsLeft;
	void CreateBomb();


public:
	CPlayer();
	~CPlayer();
	virtual CPlayer* Clone();


	virtual void update();
	virtual void render();
	virtual void OnCollision(CCollider* _pOther);
	void RegisterPlayer();
	static CPlayer* GetPlayer();	
	// ���� ���� �ϳ��� �ִ� �÷��̾� ��ü Ȯ��(���Ƿ� �̱��� ����)
};

