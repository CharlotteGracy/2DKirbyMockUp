#pragma once
#include "CScene.h"

class CScene_Stage01 : public CScene {
public:
	CScene_Stage01();
	virtual ~CScene_Stage01();

	virtual void Enter(); //�ش� ���������� ������ �� ȣ��
	virtual void Win(); //�ش� ���������� �̰��� �� ȣ��
	virtual void GameOver(); //�ش� ������������ ���� �� ȣ��
	virtual void Exit(); //TODO: �̰� ������ ������ �ȵǴ��� ���ϱ� 

};

