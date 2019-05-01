#pragma once
#include "stdafx.h"
#include <math.h>
#include <cmath>
#include <tgmath.h>

// vector of the object
struct Vec
{
	float x, y, z;

	Vec operator +(const Vec &other)
	{
		Vec ret;

		ret.x = x + other.x;
		ret.y = y + other.y;
		ret.z = z + other.z;

		return ret;
	}

	Vec operator * (float scal)
	{
		Vec ret;

		ret.x = x * scal;
		ret.y = y * scal;
		ret.z = z * scal;

		return ret;
	}

	Vec operator - (Vec v)
	{
		Vec ret;

		ret.x = x - v.x;
		ret.y = y - v.y;
		ret.z = z - v.z;

		return ret;
	}

	Vec()
	{}

	Vec(float a, float b, float c)
	{
		x = a;
		y = b;
		z = c;
	}
};

// Semi-Implicit euler
// velocity += velocity * dt
// position += velocity * dt


// Rung-Kutta methods
//https://gafferongames.com/post/physics_in_3d/
// state of the object
struct Quaternion
{
	float w, x, y, z;

	void normalize()
	{
		float mag = (float)sqrt((w * w) + (x * x) + (y * y) + (z * z));
		w /= mag;
		x /= mag;
		y /= mag;
		z /= mag;
	}

	Quaternion operator * (float scal)
	{
		Quaternion ret;

		ret.w = w * scal;
		ret.x = x * scal;
		ret.y = y * scal;
		ret.z = z * scal;

		return ret;
	}

	Quaternion operator * (Quaternion q)
	{
		Quaternion ret;

		ret.w = -x * q.x - y * q.y - z * q.z + w * q.w;
		ret.x = x * q.w + y * q.z - z * q.y + w * q.x;
		ret.y = -x * q.z + y * q.w + z * q.x + w * q.y;
		ret.z = x * q.y - y * q.x + z * q.w + w * q.z;
		
		return ret;
	}
};

struct State
{
	// primary
	Quaternion orientation;
	Vec angularMomentum;

	// secondary
	Quaternion spin;
	Vec angularVelocity;

	// constant
	float inertia;
	float inertiaInv;

	void recalc()
	{
		angularVelocity = angularMomentum * inertiaInv;

		orientation.normalize();

		Quaternion q;
		q.w = 0.0f;
		q.x = angularVelocity.x;
		q.y = angularVelocity.y;
		q.z = angularVelocity.z;

		spin = q * 0.5f * orientation;
	}
};

// derivatives of state values
struct Derivative
{
	Quaternion spin;
	Vec torque;
};

Vec torque(State &s, double t)
{
	return Vec(1, 0, 0) - s.angularVelocity * 0.1f;
}
