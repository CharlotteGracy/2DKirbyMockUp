#include "framework.h"
#include "CMonster.h"
#include "CCollider.h"
#include "CD2DImage.h"
#include "CAnimator.h"
#include "AI.h"
#include "CIdleState.h"
#include "CTraceState.h"

CMonster::CMonster()
{
	CD2DImage* m_pImg = nullptr;

	m_pAI = nullptr;

	SetName(L"Monster");
	SetScale(fPoint(100, 100));

	CreateCollider();
	GetCollider()->SetScale(fPoint(20.f, 20.f));
	GetCollider()->SetOffsetPos(fPoint(0.f, 5.f));


}

CMonster::~CMonster()
{
	if (nullptr != m_pAI)
	{
		delete m_pAI;
	}
}

CMonster* CMonster::Clone()
{
	CMonster* newMonster = new CMonster;
	if (nullptr != m_pAI)
	{
		newMonster->m_pAI = new AI;
	}
	return new CMonster(*newMonster);
}

CMonster* CMonster::Create(MON_TYPE type, fPoint pos)
{
	CMonster* pMon = nullptr;

	
	
//	assert(pMon);
	return pMon;
}

void CMonster::render()
{
	fPoint pos = GetPos();
	fPoint scale = GetScale();
	pos = CCameraManager::GetInst()->GetRenderPos(pos);

	component_render();
}

void CMonster::update()
{
	if (nullptr != GetAnimator())
		GetAnimator()->update();
	if (nullptr != m_pAI)
		m_pAI->update();

}

float CMonster::GetSpeed()
{
	return m_tInfo.fSpeed;
}

const tMonInfo& CMonster::GetMonInfo()
{
	return m_tInfo;
}

void CMonster::SetSpeed(float speed)
{
	m_tInfo.fSpeed = speed;
}

void CMonster::SetAI(AI* ai)
{
	m_pAI = ai;
	m_pAI->m_pOwner = this;
}

void CMonster::SetMonInfo(const tMonInfo& info)
{
	m_tInfo = info;
}


void CMonster::OnCollisionEnter(CCollider* pOther)
{
	CGameObject* pOtherObj = pOther->GetObj();

	if (pOtherObj->GetName() == L"Bomb_Player")
	{
		m_tInfo.fHP -= 1;
		if (m_tInfo.fHP <= 0)
			DeleteObj(this);
	}
}