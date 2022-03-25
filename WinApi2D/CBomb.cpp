#include "framework.h"
#include "CBomb.h"
#include "CCollider.h"

CBomb* CBomb::Clone() {
	return new CBomb(*this);
}


CBomb::CBomb() {
	SetScale(fPoint(25.f, 25.f));
	m_fvDir = fVec2(0, 0);

	SetName(L"Bomb_Player");

	CreateCollider();
	GetCollider()->SetScale(fPoint(15.f, 15.f));
}

CBomb::~CBomb() {


}

void CBomb::update() {

	fPoint pos = GetPos();
	pos.x += m_fVelocity * m_fvDir.x * fDT;
	pos.y += m_fVelocity * m_fvDir.y * fDT;

	SetPos(pos);

	
	if (pos.x < 0 || pos.x > WINSIZEX
		|| pos.y < 0 || pos.y > WINSIZEY) {
		DeleteObj(this);
	}
}
void CBomb::render(HDC hDC)
{
	fPoint pos = GetPos();
	fPoint scale = GetScale();

	fPoint fptRenderPos = CCameraManager::GetInst()->GetRenderPos(pos);

	CRenderManager::GetInst()->RenderEllipse(
		fptRenderPos.x,
		fptRenderPos.y,
		scale.x /2.f,
		scale.y / 2.f);
	component_render();
}

//TODO: 캐릭터가 왼쪽을 보고 있을 때는 폭탄이 왼쪽으로 날아가도록 해야 함


void CBomb::SetDir(fVec2 vec)
{
	m_fvDir = vec.Normalize();
}
void CBomb::SetDir(float theta)
{
	m_fvDir.x = (float)cos(theta);
	m_fvDir.y = (float)sin(theta);
}

void CBomb::OnCollisionEnter(CCollider* pOther)
{
	CGameObject* pOtherObj = pOther->GetObj();
	if (pOtherObj->GetName() == L"Monster")
	{
		DeleteObj(this);
	}
}