#include "Rigidbody.h"

#define ABS(x) (x>=0?x:-x)

Rigidbody::Rigidbody()
{
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::Update()
{
	Vector3 t = behaviour->transform.position + Speed;
	Vector3 p = behaviour->transform.position;
	float a = 0;
	float b = 0;

	a = (t.y - p.y) / (t.x - p.x);
	b = (((t.y) - a * (t.x)) + ((p.y) - a * (p.x))) / 2;


	for (int )


	behaviour->transform.position = ;
}