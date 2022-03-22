#include "framework.h"
#include "CPlayer.h"


CPlayer::CPlayer() {

}

CPlayer::~CPlayer() {

}


void CPlayer::update() {

	fPoint pos = GetPos();
	if (Key(VK_LEFT)) {
		pos.x -= 100 * fDT;
	}
	if (Key(VK_RIGHT)) {
		pos.x += 100 * fDT;
	}
	if (Key(VK_UP)) {
		pos.y -= 100 * fDT;
	}
	if (Key(VK_DOWN)) {
		pos.y += 100 * fDT;
	}

	SetPos(pos);

	if (KeyDown(VK_SPACE)) {
		CreateBomb();
	}
}


void CPlayer::render(HDC hDC) {


	Rectangle(hDC,
		GetPos().x - GetScale().x / 2,
		GetPos().y - GetScale().x / 2,
		GetPos().x + GetScale().x / 2,
		GetPos().y + GetScale().x / 2

	);

}

void CPlayer::GetPlayer() {



}


void CPlayer::CreateBomb() {

}