#ifndef CARTVECTOR_H
#define CARTVECTOR_H
#include <fstream>
using namespace std;

class CartVector
{
public:
	double x;
	double y;

	//Default Constructor
	CartVector();

	//Constructor
	CartVector(double in_x, double in_y);
	friend ostream& operator <<(ostream& out, const CartVector& p1);
};

CartVector operator*(const CartVector& v1, double d);
CartVector operator/(const CartVector& v1, double d);



//ostream& operator<<(ostream& out, const CartVector& v1);



#endif // CARTVECTOR_H