#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "CartPoint.h"

class GameObject //declares Class
{
private:
	int id_num;
protected:
	CartPoint location;
	char display_code;
	char state;
public:
	GameObject(char in_code, int in_id);
	virtual ~GameObject();
	//~GameObject();

	GameObject(char in_code, int in_id, CartPoint in_loc);

	CartPoint get_location();
	int get_id();
	//void show_status();
	virtual void show_status();

	virtual bool update() = 0;

	void drawself(char* grid);
};



#endif // GAMEOBJECT_H