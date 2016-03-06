#pragma once
#include "Behaviour.h"

class Unit : public Behaviour
{
public:
	Unit();
	~Unit();
	virtual void Update();
};

