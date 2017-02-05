#ifndef SAILOR_H
#define SAILOR_H
#include "Port.h"
#include "CartVector.h"
//#include "Dock.h"


class Dock;

class Sailor : public GameObject
{
private:
	double health; 
	double size; 
	double hold; 
	double cargo; 
	CartPoint destination;
	CartVector delta;
	Port* port;
	Dock* dock;
	Dock* hideout;
	bool update_location();
	void setup_destination(CartPoint dest);
	double preSize;
public:
	Sailor();
	~Sailor();
	Sailor(int in_id, Dock* hideout);
	bool update();
	double get_size();
	double get_cargo();
	void start_sailing(CartPoint dest);
	void start_supplying (Port* destPort);
	void start_hiding();
	bool is_hidden();
	void start_docking(Dock* destDock);
	void anchor();
	void show_status();
	double get_speed();
	double get_preSize();

};

#endif // SAILOR_H