#include <iostream>
#include "Dock.h"
//#include "Sailor.h"
//#include "GameObject.h"
using namespace std;

//class Sailor;


Dock::Dock(): GameObject('d', 0)
{
	berths = 30;
	display_code = 'd';
	state = 'u';
	cout << "Default Dock constructed" << endl;
}


Dock::Dock(int in_id, CartPoint in_loc): GameObject('d', in_id, in_loc)
{
	//id_num = in_id;
	berths = 30;
	state = 'u';
	//location.x = in_loc.x;
	//location.y = in_loc.y;
	cout << "Dock constructed" << endl;
}

Dock::~Dock()
{
	cout << "Dock destroyed" << endl;
}

bool Dock::dock_boat(Sailor* sailor_to_dock)
{
	if (berths >= sailor_to_dock->get_size())
	{
		berths = berths - sailor_to_dock->get_size(); //berths is available space
		return true;
	}
	return false;
}

bool Dock::set_sail(Sailor* sailor_to_sail)
{
	if (sailor_to_sail->get_cargo() == 0)
	{
		/*double ship_cargo = sailor_to_sail.get_cargo();
		cargo = cargo - ship_cargo;
		return true;*/
		berths = berths + sailor_to_sail->get_size();//get_preSize();
		return true;
	}
	return false;
}

bool Dock::update()
{
	if (berths == 0)
	{
		state = 'p';
		display_code = 'D';
		int id = get_id();
		cout << "Dock " << id << " is packed" << endl;
		return true;
	}
	else if(berths >= 0)
	{
		return false;
	}

	else if (berths != 0 && state == 'p')
	{
		display_code = 'd';
		state = 'u';
		return true; 
	}
	else
	{
		return false;
	}
}

void Dock::show_status()
{
	if (berths == 0)
	{
		cout << "Dock status: " << display_code << get_id() << " at location " << get_location() << " with " << berths << " berths" << endl;
	}
	else
	{
		cout << "Dock status: " << display_code << ", id_num is: " << get_id() << ", location is: " << get_location() << "and has " << berths << " berths" << endl;
	}

	
	//cout << "The dock is: " << state << endl;
}








