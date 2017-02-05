#ifndef PORT_H
#define PORT_H
#include "GameObject.h"


class Port: public GameObject
{
private:
	double inventory; //amount of supplies currently in Port

public:
	Port(); //default constructor

	~Port();

	Port(int in_id, CartPoint in_loc);

	bool is_empty();
	double provide_supplies(double amount_to_provide = 50.0);
	bool update();
	void show_status();
};





#endif // PORT_H