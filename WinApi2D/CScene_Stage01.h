#pragma once
#include "CScene.h"

class CScene_Stage01 : public CScene {
public:
	CScene_Stage01();
	virtual ~CScene_Stage01();

	virtual void Enter(); //해당 스테이지에 진입할 때 호출
	virtual void Win(); //해당 스테이지를 이겼을 때 호출
	virtual void GameOver(); //해당 스테이지에서 졌을 때 호출
	virtual void Exit(); //TODO: 이게 없으면 실행이 안되던데 왜일까 

};

