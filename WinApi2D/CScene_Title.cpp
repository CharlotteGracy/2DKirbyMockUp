#include "framework.h"
#include "CScene_Title.h"
#include "CImageObject.h"
#include "CImageButton.h"

CScene_Title::CScene_Title() {

}

CScene_Title::~CScene_Title() {

}


void ClickStartButton(DWORD_PTR, DWORD_PTR) {

	//ChangeScn(GROUP_SCENE::STAGE_01);

}

void ClickHelpButton(DWORD_PTR, DWORD_PTR) {
	//TODO: 도움말 화면 출력
}

void ClickExitButton(DWORD_PTR, DWORD_PTR) {
	PostQuitMessage(0);
}

void CScene_Title::Enter() {
	//TODO: 
	//1. 배경 출력, 

	CImageObject* backgroundObject = new CImageObject;
	backgroundObject->Load(L"BackImage", L"texture\\background_start.png");
	backgroundObject->SetPos(fPoint(0.f, 0.f));
	backgroundObject->SetScale(fPoint(WINSIZEX, WINSIZEY));
	AddObject(backgroundObject, GROUP_GAMEOBJ::BACKGROUND);

	
	//2. 로고 출력용 오브젝트 제작,
 	CImageObject* logoObject = new CImageObject;
	logoObject->Load(L"LogoImage", L"texture\\Kirby's-Adventure-Logo.png");
	logoObject->SetPos(fPoint(WINSIZEX / 4.f, 100.f));
	logoObject->SetScale(fPoint(600.f, 300.f));
	AddObject(logoObject, GROUP_GAMEOBJ::BACKGROUND);

	
	//3. 시작 버튼, 
	CImageButton* playButton = new CImageButton;
	playButton->Load(L"Button", L"texture\\button_test.png");
	playButton->SetText(L"PLAY");
	playButton->SetPos(fPoint(WINSIZEX / 2.f - 100.f, 400.f));
	playButton->SetScale(fPoint(200.f, 50.f));
	playButton->SetClickedCallBack(ClickStartButton, 0, 0);
	AddObject(playButton, GROUP_GAMEOBJ::UI);

	//4. 도움말 버튼 
	CImageButton* helpButton = new CImageButton;
	helpButton->Load(L"Button", L"texture\\button_test.png");
	helpButton->SetText(L"HELP");
	helpButton->SetPos(fPoint(WINSIZEX / 2.f - 100.f, 500.f));
	helpButton->SetScale(fPoint(200.f, 50.f));
	helpButton->SetClickedCallBack(ClickStartButton, 0, 0);
	AddObject(helpButton, GROUP_GAMEOBJ::UI);
	
	//5. 종료 버튼
	CImageButton* exitButton = new CImageButton;
	exitButton->Load(L"Button", L"texture\\button_test.png");
	exitButton->SetText(L"EXIT");
	exitButton->SetPos(fPoint(WINSIZEX / 2.f - 100.f, 600.f));
	exitButton->SetScale(fPoint(200.f, 50.f));
	exitButton->SetClickedCallBack(ClickExitButton, 0, 0);
	AddObject(exitButton, GROUP_GAMEOBJ::UI);

}

void CScene_Title::Exit() {

}