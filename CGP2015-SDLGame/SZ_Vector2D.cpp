#include "SZ_Vector2D.h"
#include <math.h>

SZ_Vector2D::SZ_Vector2D() {
	x = 0;
	y = 0;
}

SZ_Vector2D::SZ_Vector2D(int eX, int eY) {
	x = eX;
	y = eY;
}

float SZ_Vector2D::Magnitude() {
	return (sqrtf(x ^ 2 + y ^ 2));
}