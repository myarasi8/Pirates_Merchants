#include <iostream>
#include "Port.h"
#include "GameObject.h"

using namespace std;

Port::Port(): GameObject('P', 0)
{
	state = 'f';
	inventory = 500;
	cout << "Port default constructed" << endl;
}

Port::Port(int in_id, CartPoint in_loc): GameObject('P', in_id, in_loc)
{
	state = 'f';
	inventory = 500;
	cout << "Port constructed" << endl;

}

Port::~Port()
{
	cout << "Port deconstructed" << endl;
}

bool Port::is_empty()
{
	if (inventory == 0)
	{
		return true;
	}
	return false;
}

double Port::provide_supplies(double amount_to_provide)
{
	if (inventory >= amount_to_provide)
	{
		inventory = inventory - amount_to_provide;
		//return inventory;
		return amount_to_provide;
	}
	inventory = 0.0;
	return inventory;
}

bool Port::update()
{
	if (is_empty() && state != 'e')
	{
		state = 'e';
		display_code = 'p';
		int id = get_id();
		cout << "Port " << id << "has been depleted of supplies" << endl;
		return true;
	}
	return false;
}

void Port::show_status()
{
	int id = get_id();
	//cout << "display_code is: " << display_code << ", id_num is: " << id << ", location is: " << location << ", amount of inventory is: " << inventory <<endl;
	cout << "Port Status: " << display_code << " with ID " << get_id() << " at location " << get_location() << " containing supplies " << inventory << endl;
}







