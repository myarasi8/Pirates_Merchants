#include <iostream>
#include "GameObject.h"
using namespace std;

GameObject::GameObject(char in_code, int in_id)
{
	display_code = in_code;
	id_num = in_id;
	location.x = 0;
	location.y = 0;
	cout << "GameObject default constructed" << endl;
}

GameObject::GameObject(char in_code, int in_id, CartPoint in_loc)
{
	display_code = in_code;
	id_num = in_id;
	location.x = in_loc.x;
	location.y = in_loc.y;
	cout << "GameObject constructed" << endl;
}

GameObject::~GameObject()
{
	cout << "GameObject destructed" <<endl;
}

CartPoint GameObject::get_location()
{
	return location;
}

int GameObject::get_id() //gets private member id_num
{
	return id_num;
}

void GameObject::show_status()
{
	int id = get_id();
	CartPoint loc = get_location();
	cout << "display code: " << display_code << "id_num: " << id<< "at location: " << loc << endl;
}

void GameObject::drawself(char* grid)
{
	*grid = this->display_code;
	*(grid + 1) = '0' + this->id_num;
}

