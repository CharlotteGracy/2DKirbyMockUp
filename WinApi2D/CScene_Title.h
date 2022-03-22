#pragma once
#include "CScene.h"
class CScene_Title : public CScene
{
public:
	CScene_Title();
	virtual ~CScene_Title();

	virtual void Enter(); //해당 씬에 진입할 때 호출
	virtual void Exit(); //해당 씬을 나갈 때 호출

};

