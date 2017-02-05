#include <iostream> 
#include "CartVector.h"
#include <fstream>
using namespace std;



CartVector::CartVector()
{
	x = 0.0;
	y = 0.0;
}

CartVector::CartVector(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}


//Multiplication Operator
CartVector operator*(const CartVector& v1, double d)
{
	CartVector v2;
	v2.x = v1.x * d;
	v2.y = v1.y * d;

	return v2;
} 

//Division Operator
CartVector operator/(const CartVector& v1, double d)
{
	CartVector v2;

	if (d == 0)
	{
		return v1;
	}

	v2.x = v1.x / d;
	v2.y = v1.y / d;

	return v2;
} 

//Overloading the << operator
ostream& operator<<(ostream& out, const CartVector& v1)
{
	out << "(" << v1.x << "," << v1.y << ")";
	return out;
}



