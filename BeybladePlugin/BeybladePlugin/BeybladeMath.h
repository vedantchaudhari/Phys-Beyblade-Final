#pragma once
#include "stdafx.h"
#include <assert.h>
typedef float real;
typedef real r;

real const PI = r(3.14159265358979323846);

// 3x3 matrix
class Mat3
{
public:
	Mat3(void)
	{}

	Mat3(real(*pElements)[3])
	{
		assert(pElements);

		Mat3 &m = *this;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
				m(i, j) = pElements[i][j];
		}
	}

};
