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
	CD2DImage* m_pImg = CResourceManager::GetInst()->LoadD2DImage(L"Beanbon", L"texture\\Beanbon_Walk.png");
	SetName(L"Beanbon");
	SetScale(fPoint(25.f, 25.f));


	CreateCollider();
	GetCollider()->SetScale(fPoint(15.f, 15.f));
	GetCollider()->SetOffsetPos(fPoint(0.f, 5.f));


	CreateAnimator();
	GetAnimator()->CreateAnimation(L"BeanbonWalk", m_pImg, fPoint(0, 0), fPoint(37.f, 37.f), fPoint(37.f, 0), 0.1f, 5, true);
	GetAnimator()->Play(L"BeanbonWalk");

	GetAnimator()->CreateAnimation(L"BeanbonTrace", m_pImg, fPoint(0, 0), fPoint(37.f, 37.f), fPoint(37.f, 0), 0.05f, 5, true);
	GetAnimator()->Play(L"BeanbonTrace");
}

CBeanbon::~CBeanbon() {

}


void CBeanbon::render()
{
	component_render();
}

void CBeanbon::update()
{
}

float CBeanbon::GetSpeed()
{
	return 0.0f;
}

const tMonInfo& CBeanbon::GetMonInfo() {
	return tMonInfo();
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





