#include "framework.h"
#include "CScene_Stage01.h"
#include "CImageObject.h"
#include "CGameObject.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CBeanBon.h"
#include "CMap.h"
#include "CBackGround.h"
//#include "CSound.h"
#include "CD2DImage.h"
#include "CImageButton.h"



CScene_Stage01::CScene_Stage01() {

}

CScene_Stage01::~CScene_Stage01() {

}



void CScene_Stage01::Enter() {

	//TODO: 스테이지(임시)
	CImageObject* backgroundObject = new CImageObject;
	backgroundObject->Load(L"Stage01BackImage", L"texture\\Stage01_test.png");
	backgroundObject->SetPos(fPoint(0.f, 0.f));
	backgroundObject->SetScale(fPoint(WINSIZEX, WINSIZEY));
	AddObject(backgroundObject, GROUP_GAMEOBJ::BACKGROUND);


	
	//타일 로딩
	wstring path = CPathManager::GetInst()->GetContentPath();
	path += L"tile\\stage1";
	LoadTile(path);



	//플레이어 생성
	CPlayer* pPlayer = new CPlayer;
	pPlayer->SetPos(fPoint(200, 200));
	AddObject(pPlayer, GROUP_GAMEOBJ::PLAYER);
	pPlayer->RegisterPlayer();

	
	// TODO: 몬스터 만들기

	
	CBeanbon* beanbon1 = new CBeanbon;
	beanbon1->SetPos(fPoint(1100, 350));
	AddObject(beanbon1, GROUP_GAMEOBJ::MONSTER);
	

}

void CScene_Stage01::Win() {
	//TODO: Win! 화면 출력
	//
	//ChangeScn(GROUP_SCENE::WIN);

}

void CScene_Stage01::GameOver() {
	//TODO: Game Over! 화면 출력
	//ChangeScn(GROUP_SCENE::GAMEOVER);

}

void CScene_Stage01::Exit()
{
}





