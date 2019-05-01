#include "Physics.h"
#include "stdafx.h"


/*
Derivative evaluate(const State &init, double t, float dt,
	const Derivative &d)
{
	State s;
	s.x = init.x + d.dx * dt;
	s.v = init.v + d.dv * dt;

	Derivative ret;
	ret.dx = s.v;
	ret.dv = accel(s, t + dt);

	return ret;
}

float accel(const State &s, double t)
{
	const float k = 15.0f;
	const float b = 0.1f;

	return -k * s.x - b * s.v;
}

// integrate Rung-Kutta
//https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods
void integrate(State &s, double t, float dt)
{
	Derivative a, b, c, d;

	a = evaluate(s, t, 0.0f, Derivative());
	b = evaluate(s, t, dt * 0.5f, a);
	c = evaluate(s, t, dt * 0.5f, b);
	d = evaluate(s, t, dt, c);

	float dx_dt = 1.0f / 6.0f *
		(a.dx + 2.0f * (b.dx + c.dx) + d.dx);

	float dv_dt = 1.0f / 6.0f *
		(a.dv + 2.0f * (b.dv + c.dv) + d.dv);

	s.x = s.x + dx_dt * dt;
	s.v = s.v + dv_dt * dt;
}
*/
