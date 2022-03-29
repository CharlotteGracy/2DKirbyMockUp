#include "framework.h"
#include "CBeanBon.h"
#include "framework.h"
#include "CMonster.h"
#include "CCollider.h"
#include "CD2DImage.h"
#include "CAnimator.h"
#include "AI.h"
#include "CIdleState.h"
#include "CTraceState.h"

CBeanbon::CBeanbon() {
	CD2DImage* m_pImg = CResourceManager::GetInst()->LoadD2DImage(L"Beanbon", L"texture\\Beanbon.png");
	SetName(L"Beanbon");
	SetScale(fPoint(38.f, 38.f));


	SetName(L"Beanbon");
	SetScale(fPoint(100, 100));

	CreateCollider();
	GetCollider()->SetScale(fPoint(20.f, 20.f));
	GetCollider()->SetOffsetPos(fPoint(0.f, 5.f));


	CreateAnimator();
	GetAnimator()->CreateAnimation(L"BeanbonWalk", m_pImg, fPoint(0, 0), fPoint(32.f, 32.f), fPoint(32.f, 0), 0.1f, 5, true);
	GetAnimator()->Play(L"BeanbonWalk");

	GetAnimator()->CreateAnimation(L"BeanbonTrace", m_pImg, fPoint(0, 0), fPoint(70.f, 70.f), fPoint(70.f, 0), 0.3f, 1, true);
	GetAnimator()->Play(L"BeanbonTrace");
}

CBeanbon::~CBeanbon() {

}


void CBeanbon::render()
{
}

void CBeanbon::update()
{
}

float CBeanbon::GetSpeed()
{
	return 0.0f;
}

const tMonInfo& CBeanbon::GetMonInfo()
{
	// TODO: 여기에 return 문을 삽입합니다.
	return;
}

void CBeanbon::SetSpeed(float speed)
{
}

void CBeanbon::SetAI(AI* ai)
{
}

void CBeanbon::SetMonInfo(const tMonInfo& info)
{
}

void CBeanbon::OnCollisionEnter(CCollider* pOther)
{
}





