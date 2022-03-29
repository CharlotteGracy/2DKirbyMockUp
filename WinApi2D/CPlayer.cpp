#include "framework.h"
#include "CPlayer.h"
#include "CBomb.h"
#include "CScene.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CAnimation.h"
#include "CTile.h"

CPlayer* CPlayer::instance = nullptr;


CPlayer::CPlayer() {
	CD2DImage* m_pImg = CResourceManager::GetInst()->LoadD2DImage(L"PlayerImg", L"texture\\Player_Kirby.png");
	SetName(L"Player");
	SetScale(fPoint(36.f, 36.f));

	CreateCollider();
	GetCollider()->SetScale(fPoint(20.f, 20.f));
	GetCollider()->SetOffsetPos(fPoint(0.f, 5.f));

	CreateAnimator();

	/*GetAnimator()->CreateAnimation(L"LeftNone", m_pImg, fPoint(0.f, 38.f), fPoint(38.f, 38.f), fPoint(38.f, 0.f), 0.5f, 9);
	GetAnimator()->CreateAnimation(L"RightNone", m_pImg, fPoint(0.f, 38.f), fPoint(38.f, 38.f), fPoint(38.f, 0.f), 0.5f, 9);
	GetAnimator()->CreateAnimation(L"LeftMove", m_pImg, fPoint(0.f, 0.f), fPoint(38.f, 38.f), fPoint(38.f, 0.f), 0.25f, 10);
	GetAnimator()->CreateAnimation(L"RightMove", m_pImg, fPoint(0.f, 0.f), fPoint(38.f, 38.f), fPoint(38.f, 0.f), 0.25f, 10);
	GetAnimator()->CreateAnimation(L"LeftHit", m_pImg, fPoint(114.f, 0.f), fPoint(38.f, 38.f), fPoint(38.f, 0.f), 0.25f, 4);
	GetAnimator()->CreateAnimation(L"RightHit", m_pImg, fPoint(114.f, 38.f), fPoint(38.f, 38.f), fPoint(38.f, 0.f), 0.25f, 4);
	GetAnimator()->Play(L"LeftNone");*/

	//TODO: 프레임 밀리는 거 수정, 방향 바꾸기
	GetAnimator()->CreateAnimation(L"LeftNone", m_pImg, fPoint(0.f, 36.f), fPoint(36.f, 36.f), fPoint(36.f, 0.f), 0.5f, 9);
	GetAnimator()->CreateAnimation(L"RightNone", m_pImg, fPoint(0.f, 36.f), fPoint(38.f, 38.f), fPoint(38.f, 0.f), 0.5f, 9);
	GetAnimator()->CreateAnimation(L"LeftMove", m_pImg, fPoint(0.f, 0.f), fPoint(38.f, 38.f), fPoint(38.f, 0.f), 0.25f, 10);
	GetAnimator()->CreateAnimation(L"RightMove", m_pImg, fPoint(0.f, 0.f), fPoint(38.f, 38.f), fPoint(38.f, 0.f), 0.25f, 10);
	GetAnimator()->CreateAnimation(L"LeftHit", m_pImg, fPoint(114.f, 0.f), fPoint(38.f, 38.f), fPoint(38.f, 0.f), 0.25f, 4);
	GetAnimator()->CreateAnimation(L"RightHit", m_pImg, fPoint(114.f, 38.f), fPoint(38.f, 38.f), fPoint(38.f, 0.f), 0.25f, 4);
	GetAnimator()->Play(L"LeftNone");

	CAnimation* pAni;
	pAni = GetAnimator()->FindAnimation(L"LeftMove");
	pAni->GetFrame(9).fptOffset = fPoint(0.f, 3.f);
	pAni = GetAnimator()->FindAnimation(L"RightMove");
	pAni->GetFrame(9).fptOffset = fPoint(0.f, -3.f);

}

CPlayer::~CPlayer() {
	instance = nullptr;
}

CPlayer* CPlayer::Clone()
{
	return new CPlayer(*this);
}

void CPlayer::update() {

	fPoint pos = GetPos();
	if (Key(VK_LEFT)) {
		pos.x -= 150 * fDT;
		GetAnimator()->Play(L"LeftMove");
	}
	if (Key(VK_RIGHT)) {
		pos.x += 150 * fDT;
		GetAnimator()->Play(L"RightMove");

	}
	if (Key(VK_UP)) {
		pos.y -= 150 * fDT;
	}
	if (Key(VK_DOWN)) {
		pos.y += 150 * fDT;
	}

	SetPos(pos);

	if (KeyDown(VK_SPACE)) {
		CreateBomb();
	}

	GetAnimator()->update();

}


void CPlayer::render() {

	component_render();

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
//	pBomb->SetDir(fVec2(1, 0));

	if (Key(VK_LEFT)/*캐릭터가 왼쪽을 보고 있을 때*/) {
		/*TODO: 왼쪽으로 가고 있을 때(LEFT 키를 누르고 있을 때)는 
		왼쪽으로 폭탄이 나오는데 가만히 있는 상태에서 왼쪽을 보고 있을 때는 
		오른쪽으로 발사되는 문제가 있음.*/
		pBomb->SetDir(fVec2(-1, 0));
	}
	else {
		pBomb->SetDir(fVec2(1, 0));
	}

	//TODO: CreateBomb 애니메이션
	CD2DImage* m_pImg2 = CResourceManager::GetInst()->LoadD2DImage(L"PlayerBomb", L"texture\\Kirby_Bomb.png");
	SetName(L"PlayerBomb");
	SetScale(fPoint(38.f, 38.f));

	CreateCollider();
	GetCollider()->SetScale(fPoint(20.f, 20.f));
	GetCollider()->SetOffsetPos(fPoint(0.f, 5.f));

	CreateAnimator();
	GetAnimator()->CreateAnimation(L"ThrowBomb", m_pImg2, fPoint(0.f, 38.f), fPoint(38.f, 38.f), fPoint(38.f, 0.f), 0.5f, 9);



	CreateObj(pBomb, GROUP_GAMEOBJ::BOMB_PLAYER);

}



