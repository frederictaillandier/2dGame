#pragma once

class Vector3
{
public:
	Vector3();
	Vector3(float _x, float _y, float _z);
	~Vector3();

	float x;
	float y;
	float z;

	Vector3 &operator=(Vector3 const &v);
	Vector3 &operator+(Vector3 const &v);
	Vector3 &operator-(Vector3 const &v);
	Vector3 &operator*(Vector3 const &v);
	Vector3 &operator/(Vector3 const &v);
	Vector3 &operator*(float const &f);
	Vector3 &operator/(float const &f);
};

class Transform
{
public:
	Vector3 position;
	Transform();
	~Transform();
};


class Behaviour
{
public:
	Transform transform;
	Behaviour();
	~Behaviour();
	virtual void Update();
};

