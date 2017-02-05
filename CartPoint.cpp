#include <iostream> 
#include "CartPoint.h"
#include <cmath>
#include <fstream>
using namespace std;

//Represents a point on a Cartesian coordinate system


//Default Constructor
CartPoint::CartPoint()
{
	x = 0.0;
	y = 0.0;
}

//Constructor 
CartPoint::CartPoint(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}



double cart_distance(CartPoint p1, CartPoint p2)
{
	//returns the distance between p1 and p2
	double distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));  //distance formula
	return distance;
}

double cart_compare(CartPoint p1, CartPoint p2)
{
if (p1.x == p2.x && p1.y == p2.y)
{
	return true;
}
return false;
}

//Addition Operator
CartPoint operator+(const CartPoint& p1, const CartVector& v1) 
{
	CartPoint p3;
	p3.x = p1.x + v1.x;
	p3.y = p1.y + v1.y;
	//return CartPoint(p3.x, p3.y);
	//return CartPoint(p3.x, p3.y);
	return p3;
}

CartVector operator+(const CartPoint& p1, CartPoint& p2)
//return CartVector
{
	CartVector v1;
	v1.x = p1.x + p2.x;
	v1.y = p1.y + p2.y;
	//return CartVector(v1.x, v1.y);
	return v1;
}

//Subtraction Operator
/*CartPoint operator-(const CartPoint& p1, const CartVector& v1) 
{
	CartPoint p3;
	p3.x = p1.x - v1.x;
	p3.y = p1.y - v1.y;
	//return CartPoint(p3.x, p3.y);
	//return CartPoint(p3.x, p3.y);
	return p3;
}*/

CartVector operator-(const CartPoint& p1, const CartPoint& p2)
//return CartVector
{
	CartVector v1;
	v1.x = p1.x - p2.x;
	v1.y = p1.y - p2.y;
	//return CartVector(v1.x, v1.y);
	return v1;
}

//Overloading the << operator
ostream& operator<<(ostream& out, const CartPoint& p1)
{
	out << "(" << p1.x << "," << p1.y << ")";
	return out;
}






