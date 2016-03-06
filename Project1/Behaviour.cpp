#include "Behaviour.h"
#include "InGame.h"

Behaviour::Behaviour()
{
	InGame::Instance()->AddBehaviour(this);
}

Behaviour::~Behaviour()
{
}

void Behaviour::Update()
{
}

Transform::Transform()
{}

Transform::~Transform()
{}

Vector3::Vector3()
{
	x = 0;
	y = 0;
	y = 0;
}

Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3::~Vector3()
{
}

Vector3 &Vector3::operator=(Vector3 const &v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	return (*this);
}

Vector3 &Vector3::operator+(Vector3 const &v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	return (*this);
}

Vector3 &Vector3::operator-(Vector3 const &v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
	return (*this);
}

Vector3 &Vector3::operator*(Vector3 const &v)
{
	this->x *= v.x;
	this->y *= v.y;
	this->z *= v.z;
	return (*this);
}

Vector3 &Vector3::operator/(Vector3 const &v)
{
	this->x /= v.x;
	this->y /= v.y;
	this->z /= v.z;
	return (*this);
}

Vector3 &Vector3::operator*(float const &f)
{
	this->x *= f;
	this->y *= f;
	this->z *= f;
	return (*this);
}

Vector3 &Vector3::operator/(float const &f)
{
	this->x /= f;
	this->y /= f;
	this->z /= f;
	return (*this);
}