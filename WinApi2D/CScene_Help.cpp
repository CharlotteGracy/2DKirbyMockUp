#include "framework.h"
#include "CScene_Help.h"
#include "CImageObject.h"
#include "CImageButton.h"


CScene_Help::CScene_Help() {

}

CScene_Help::~CScene_Help() {

}


//Ÿ��Ʋ ȭ������ ���ư�
void ClickBackButton(DWORD_PTR, DWORD_PTR) {

	ChangeScn(GROUP_SCENE::TITLE);
}


void CScene_Help::Enter()
{

	//TODO: ���� ȭ�� �̹��� ���, �ӽ� �̹��� 
	CImageObject* backgroundObject = new CImageObject;
	backgroundObject->Load(L"HelpBackImage", L"texture\\Help_test.png");
	backgroundObject->SetPos(fPoint(0.f, 0.f));
	backgroundObject->SetScale(fPoint(WINSIZEX, WINSIZEY));
	AddObject(backgroundObject, GROUP_GAMEOBJ::BACKGROUND);

	//TODO: Go Back ��ư 
	CImageButton* gobackButton = new CImageButton;
	gobackButton->Load(L"Button", L"texture\\button_test.png");
	gobackButton->SetText(L"BACK");
	gobackButton->SetPos(fPoint(WINSIZEX / 2.f - 100.f, 460.f));
	gobackButton->SetScale(fPoint(200.f, 50.f));
	gobackButton->SetClickedCallBack(ClickBackButton, 0, 0);
	AddObject(gobackButton, GROUP_GAMEOBJ::UI);

}

void CScene_Help::Exit()
{
}