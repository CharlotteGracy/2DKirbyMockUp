#include "framework.h"
#include "CBeanBon.h"


CBeanBon::CBeanBon() {
	CD2DImage* m_pImg = CResourceManager::GetInst()->LoadD2DImage(L"MonsterTex", L"texture\\PlayerStand.png");

}

CBeanBon::~CBeanBon() {

}