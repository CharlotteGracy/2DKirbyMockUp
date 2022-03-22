#include "framework.h"
#include "CScene_Start.h"

#include "CGameObject.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CMap.h"
#include "CBackGround.h"

#include "CSound.h"
#include "CD2DImage.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::update()
{
	CScene::update();

	if (KeyDown(VK_TAB))
	{
		ChangeScn(GROUP_SCENE::TOOL);
	}

	if (KeyDown('Z'))
	{
		CSoundManager::GetInst()->AddSound(L"bgm", L"sound\\drumloop.wav", true);
		CSoundManager::GetInst()->Play(L"bgm");
	}

	if (KeyDown('X'))
	{
		CSoundManager::GetInst()->Stop(L"bgm");
	}
}

void CScene_Start::Enter()
{
	// Ÿ�� �ε�
	wstring path = CPathManager::GetInst()->GetContentPath();
	path += L"tile\\Start.tile";
	LoadTile(path);

	// Player �߰�
	CPlayer* pPlayer = new CPlayer;
	pPlayer->SetPos(fPoint(200, 200));
	AddObject(pPlayer, GROUP_GAMEOBJ::PLAYER);
	pPlayer->RegisterPlayer();

	// Monster �߰�
	CMonster* pMonster = new CMonster;
	pMonster->SetPos(fPoint(1100, 350));
	AddObject(pMonster, GROUP_GAMEOBJ::PLAYER);

	CMonster* pCloneMonster = pMonster->Clone();
	pCloneMonster->SetPos(fPoint(500, 350));
	AddObject(pCloneMonster, GROUP_GAMEOBJ::MONSTER);

	CMap* map = new CMap;
	map->Load(L"Map_Start", L"texture\\map\\Yoshis Island 2.png");
	AddObject(map, GROUP_GAMEOBJ::MAP);

	CBackGround* backGround = new CBackGround;
	backGround->Load(L"BackGround_Start", L"texture\\background\\background_start.png");
	backGround->SetPos(fPoint(-100.f, -500.f));
	AddObject(backGround, GROUP_GAMEOBJ::BACKGROUND);

	CCollisionManager::GetInst()->CheckGroup(GROUP_GAMEOBJ::PLAYER, GROUP_GAMEOBJ::MONSTER);
	CCollisionManager::GetInst()->CheckGroup(GROUP_GAMEOBJ::MISSILE_PLAYER, GROUP_GAMEOBJ::MONSTER);
	CCollisionManager::GetInst()->CheckGroup(GROUP_GAMEOBJ::PLAYER, GROUP_GAMEOBJ::TILE);

	// Camera Look ����
	CCameraManager::GetInst()->SetLookAt(fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f));
	CCameraManager::GetInst()->SetTargetObj(pPlayer);
	CCameraManager::GetInst()->FadeOut(1.f);
	CCameraManager::GetInst()->FadeIn(1.f);

	// ���� ��ġ
	CMonster* pMon = CMonster::Create(MON_TYPE::NORMAL, fPoint(500.f, 500.f));
	AddObject(pMon, GROUP_GAMEOBJ::MONSTER);
}

void CScene_Start::Exit()
{
	DeleteAll();

	CCollisionManager::GetInst()->Reset();
}
