#include "framework.h"
#include "CScene_Win.h"
#include "CImageObject.h"
#include "CImageButton.h"


CScene_Win::CScene_Win() {

}

CScene_Win::~CScene_Win() {

}


//다음 스테이지로 이동함
void ClickNextButton(DWORD_PTR, DWORD_PTR) {

	ChangeScn(GROUP_SCENE::STAGE_02);
}


void CScene_Win::Enter()
{

	//TODO: Win! 화면 이미지 출력, 임시 이미지 
	CImageObject* winbackgroundObject = new CImageObject;
	winbackgroundObject->Load(L"WinImage", L"texture\\Help_test.png");
	winbackgroundObject->SetPos(fPoint(0.f, 0.f));
	winbackgroundObject->SetScale(fPoint(WINSIZEX, WINSIZEY));
	AddObject(winbackgroundObject, GROUP_GAMEOBJ::BACKGROUND);

	//TODO: Next 버튼 
	CImageButton* nextstageButton = new CImageButton;
	nextstageButton->Load(L"NextButton", L"texture\\button_test.png");
	nextstageButton->SetText(L"NEXT");
	nextstageButton->SetPos(fPoint(WINSIZEX / 2.f - 100.f, 460.f));
	nextstageButton->SetScale(fPoint(200.f, 50.f));
	nextstageButton->SetClickedCallBack(ClickNextButton, 0, 0);
	AddObject(nextstageButton, GROUP_GAMEOBJ::UI);

}

void CScene_Win::Exit()
{
}