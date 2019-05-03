#pragma once
#include "stdafx.h"
#include <math.h>
#include <cmath>
#include <tgmath.h>

extern "C"
{
	/* Physics Data Structs */
	struct Vector3
	{
		float x;
		float y;
		float z;
	};

	__declspec(dllexport) Vector3 CalculateAngularVelocity(float x, float y, float z);
	__declspec(dllexport) int Foo(int a, int b);
}

/*
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

	float cross(Vec v)
	{
		return (x * v.x) + (x * v.y) + (x * v.z) +
			(y * v.x) + (y * v.y) + (y * v.z) +
			(z * v.x) + (z * v.y) + (z * v.z);
	}

	float dot(Vec v)
	{
		return (x * v.x) + (y * v.y) + (z * v.z);
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
	Vec linearV;

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

#include "BeybladeMath.h"
struct RigidBody
{
	State state;
	float friction;
	Vec pos;
	Vec vel;
	Vec com; // center of mass
	Quaternion orientation;
	Vec rot;
	Mat3 orientationMatrix;
	Mat3 orientationMatrxInv;
	Mat3 worldInertiaInv;
	float mass;
	Mat3 inertiaTensorInv;
	Mat3 massMatrixInv;

	// f: force applied
	// s: State
	// p: point to applie force
	void addTorque(float f, State s, Vec p)
	{
		// F_torque = F * (p - x)
					// F = force being applied				- Vec
					// p = point at which force is applied	- Vec
					// x = center of mass of the object		- Vec
		float linear = f;
		Vec torque = (p - com) * f;
	}

	void addForce(Vec f)
	{

	}
};
// derivatives of state values
struct Derivative
{
	Quaternion spin;
	Vec torque;
};

Vec torque(State &s, float t)
{
	return Vec(1, 0, 0) - s.angularVelocity * 0.1f;
}


/*
Lz is constant
^z * L = Lz

L3 is constant
e3 * L = L3

Energy is constant
(1/2)(I_x)(w_x)(w_y) + (M_g)(R_cm)(e3) * ^z = E

speed at which top prevesses:

theta = (Lz - L3cos(theta)) / ((I_star)(sin^2(theta)))

make gyroscope keep balance

get world location

velocity at single point
v_point = v_linear + v_angluar cross(p - x)
									p = point on rigid body
									x = center of mass of the object

*/
*/