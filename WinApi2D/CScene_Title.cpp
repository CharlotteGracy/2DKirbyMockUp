#include "framework.h"
#include "CScene_Title.h"
 #include "CImageObject.h"
 //#include "CImageButton.h"

CScene_Title::CScene_Title() {

}

CScene_Title::~CScene_Title() {

}


void ClickStartButton(DWORD_PTR, DWORD_PTR) {

	//ChangeScn(GROUP_SCENE::STAGE_01);

}

void ClickHelpButton(DWORD_PTR, DWORD_PTR) {
	//TODO: ���� ȭ�� ���
}

void ClickExitButton(DWORD_PTR, DWORD_PTR) {
	PostQuitMessage(0);
}

void CScene_Title::Enter() {
	//TODO: 
	//1. ��� ���, 

	/*
	CImageObject* backgroundObject = new CImageObject;
	backgroundObject->Load(L"BackImage", L"texture\\background_start.png");
	backgroundObject->SetPos(fPoint(0.f, 0.f));
	backgroundObject->SetScale(fPoint(WINSIZEX, WINSIZEY));
	AddObject(backgroundObject, GROUP_GAMEOBJ::BACKGROUND);

	//2. �ΰ� ��¿� ������Ʈ ����,
 	CImageObject* logoObject = new CImageObject;
	logoObject->Load(L"LogoImage", L"texture\\Kirby's-Adventure-Logo.png");
	logoObject->SetPos(fPoint(100.f, 100.f));
	logoObject->SetScale(fPoint(1080.f, 200.f));
	AddObject(logoObject, GROUP_GAMEOBJ::BACKGROUND);

	*/
	//3. ���� ��ư, 
	//4. ���� ��ư 
	//5. ���� ��ư
}

void CScene_Title::Exit() {

}