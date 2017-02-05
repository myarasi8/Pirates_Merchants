#ifndef CARTPOINT_H
#define CARTPOINT_H
#include "CartVector.h"
#include <fstream>
using namespace std;

//Represents a point on a Cartesian coordinate system
class CartPoint
{
public:
	double x;
	double y;

	//Default Constructor
	CartPoint();

	//Constructor
	CartPoint(double in_x, double in_y);
	friend ostream& operator <<(ostream& out, const CartPoint& p1);
};

double cart_distance(CartPoint p1, CartPoint p2);
double cart_compare(CartPoint p1, CartPoint p2);

CartPoint operator+(const CartPoint& p1, const CartVector& v1);
//CartVector operator+(const CartPoint &p1, const CartPoint &p2);
//CartPoint operator-(const CartPoint& v1);
CartVector operator-(const CartPoint &p1, const CartPoint &p2);


//ostream& operator<<(ostream& out, const CartPoint& v1);


#endif // CARTPOINT_H