#pragma once

#include "Behaviour.h"

class Rigidbody
{
public:
	Vector3 Speed;
	float weight = 1.0f;
	Behaviour *behaviour;

	Rigidbody();
	~Rigidbody();
	void Update();
};

