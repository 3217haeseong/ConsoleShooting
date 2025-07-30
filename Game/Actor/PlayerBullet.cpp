#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(const Vector2& position)
	: Actor("i", Color::Green, position), yPosition((float)position.y)
{

}

void PlayerBullet::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// �̵� ó��.
	yPosition -= moveSpeed * deltaTime;
	
	Vector2 position = Position();
	position.y = /*osition.y - moveSpeed * deltaTime;*/
	position.y = (int)yPosition;

	// ��� ���� ȭ�� ���� ����� ź�� ����.
	if (yPosition < 0.0f)
	{
		Destroy();
		return;
	}

	SetPosition(position);
}
