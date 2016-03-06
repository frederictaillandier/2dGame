#include "Player.h"
#include "Inputs.h"


Player::Player()
{
	transform.position.x = 3;
	transform.position.y = 3;
}

Player::~Player()
{
}

void Player::Update()
{
	if (Inputs::Instance()->keys['a'])
	{
		transform.position.x -= 0.1f;
	}
	if (Inputs::Instance()->keys['d'])
	{
		transform.position.x += 0.1f;
	}
}