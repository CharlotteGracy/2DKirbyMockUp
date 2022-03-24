#include "framework.h"
#include "CPlayer.h"
#include "CBomb.h"
#include "CScene.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CAnimation.h"

CPlayer::CPlayer() {
	CD2DImage* m_pImg = CResourceManager::GetInst()->LoadD2DImage(L"PlayerImg", L"texture\\Animation_Player.bmp");
	SetName(L"Player");
	SetScale(fPoint(70.f, 70.f));

	CreateCollider();
	GetCollider()->SetScale(fPoint(40.f, 40.f));
	GetCollider()->SetOffsetPos(fPoint(0.f, 10.f));

	CreateAnimator();
	GetAnimator()->CreateAnimation(L"LeftNone", m_pImg, fPoint(0.f, 0.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.5f, 2);
	GetAnimator()->CreateAnimation(L"RightNone", m_pImg, fPoint(0.f, 70.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.5f, 2);
	GetAnimator()->CreateAnimation(L"LeftMove", m_pImg, fPoint(0.f, 140.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.25f, 3);
	GetAnimator()->CreateAnimation(L"RightMove", m_pImg, fPoint(0.f, 210.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.25f, 3);
	GetAnimator()->CreateAnimation(L"LeftHit", m_pImg, fPoint(140.f, 0.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.25f, 1);
	GetAnimator()->CreateAnimation(L"RightHit", m_pImg, fPoint(140.f, 70.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.25f, 1);
	GetAnimator()->Play(L"LeftNone");

	CAnimation* pAni;
	pAni = GetAnimator()->FindAnimation(L"LeftMove");
	pAni->GetFrame(1).fptOffset = fPoint(0.f, -20.f);
	pAni = GetAnimator()->FindAnimation(L"RightMove");
	pAni->GetFrame(1).fptOffset = fPoint(0.f, -20.f);

}

CPlayer::~CPlayer() {

}

CPlayer* CPlayer::Clone()
{
	return new CPlayer(*this);
}

void CPlayer::update() {

	fPoint pos = GetPos();
	if (Key(VK_LEFT)) {
		pos.x -= 100 * fDT;
	}
	if (Key(VK_RIGHT)) {
		pos.x += 100 * fDT;
	}
	if (Key(VK_UP)) {
		pos.y -= 100 * fDT;
	}
	if (Key(VK_DOWN)) {
		pos.y += 100 * fDT;
	}

	SetPos(pos);

	if (KeyDown(VK_SPACE)) {
		CreateBomb();
	}

	GetAnimator()->update();

}


void CPlayer::render() {

	component_render();

	/*
	Rectangle(hDC,
		GetPos().x - GetScale().x / 2,
		GetPos().y - GetScale().x / 2,
		GetPos().x + GetScale().x / 2,
		GetPos().y + GetScale().x / 2
		
	);
*/
}

void CPlayer::RegisterPlayer()
{
	instance = this;
}

CPlayer* CPlayer::GetPlayer()
{
	return instance;
}


void CPlayer::CreateBomb() {
	fPoint fpBombPos = GetPos();
	fpBombPos.x += GetScale().x / 2.f;

	//Bomb Object
	CBomb* pBomb = new CBomb;
	pBomb->SetPos(fpBombPos);
	pBomb->SetDir(fVec2(1, 0));

	CreateObj(pBomb, GROUP_GAMEOBJ::BOMB_PLAYER);

}
