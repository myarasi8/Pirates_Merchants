#include <iostream>
#include "Model.h"
using namespace std;

Model::Model()
{
	time = 0;
	num_objects = 10;
	num_sailors = 3;
	num_ports = 4;
	num_docks = 3;

	//Port** port_pointers = port_ptrs;
	/*Port** pptrs = port_ptrs;
	Dock** dptrs = dock_ptrs;
	Sailor** strs = sailor_ptrs;*/

	dock_ptrs = new Dock* [num_docks];
	port_ptrs = new Port* [num_ports];
	sailor_ptrs = new Sailor* [num_sailors];
	//GameObject ** object_ptrs = new GameObject* [num_objects];
	object_ptrs = new GameObject* [num_objects];

    //3 Docks
    Dock* dock1 = new Dock(1, CartPoint(5, 1));
    Dock* dock2 = new Dock(2, CartPoint(6, 2));
    Dock* dock3 = new Dock(3, CartPoint(1, 8));

    dock_ptrs[0] = dock1;
    dock_ptrs[1] = dock2;
    dock_ptrs[2] = dock3;

    object_ptrs[0] = dock1;
    object_ptrs[1] = dock2;
    object_ptrs[2] = dock3;

    //4 Ports
    Port* port1 = new Port(1, CartPoint(1, 20));
    Port* port2 = new Port(2, CartPoint(20, 1));
    Port* port3 = new Port(3, CartPoint(20, 20));
    Port* port4 = new Port(4, CartPoint(7, 2));

    port_ptrs[0] = port1;
    port_ptrs[1] = port2;
    port_ptrs[2] = port3;
    port_ptrs[3] = port4;

    object_ptrs[3] = port1;
    object_ptrs[4] = port2;
    object_ptrs[5] = port3;
    object_ptrs[6] = port4;

    //3 Sailors
    Sailor* sailor1 = new Sailor(1, dock1);
    Sailor* sailor2 = new Sailor(2, dock2);
    Sailor* sailor3 = new Sailor(3, dock3);

    sailor_ptrs[0] = sailor1;
    sailor_ptrs[1] = sailor2;
    sailor_ptrs[2] = sailor3;

    object_ptrs[7] = sailor1;
    object_ptrs[8] = sailor2;
    object_ptrs[9] = sailor3;

    cout << "Model default constructed" << endl;
	

}

Model::~Model()
{
	delete object_ptrs;
	for (int d = 0; d < num_docks; d++)
	{
		delete dock_ptrs[d]; //delete docks
	}

	for (int p = 0; p < num_ports; p++)
	{
		delete port_ptrs[p]; //delete ports
	}
 
	for (int s = 0; s < num_sailors; s++)
	{
		delete sailor_ptrs[s]; // delete sailors
	}

	cout << "Model destructed" << endl;
}

Sailor* Model::get_Sailor_ptr(int id_num)
{
	for (int i = 0; i < num_sailors; i++)
	{
		if (sailor_ptrs[i]->get_id() == id_num)
		{
			return sailor_ptrs[i];
		}
	}
	return NULL;
}

Port* Model::get_Port_ptr(int id_num)
{
	for (int i = 0; i < num_ports; i++)
	{
		if (port_ptrs[i]->get_id() == id_num)
		{
			return port_ptrs[i];
		}
	}
	return NULL;
}

Dock* Model::get_Dock_ptr(int id_num)
{
	for (int i = 0; i < num_docks; i++)
	{
		if (dock_ptrs[i]->get_id() == id_num)
		{
			return dock_ptrs[i];
		}
	}
	return NULL;
}

bool Model::update()
{
	bool output = false;
	time++;
	for (int i = 0; i < num_objects; i++)
	{
		if (object_ptrs[i]->update()) //references GameObject
			output = true;
	}
	return output;
}

void Model::show_status()
{
	/*for(int i = 0; i < num_objects; i++)
	{
		object_ptrs[i]->show_status();
		//cout <<"Time is " << time << endl;
	}*/
	for (int i = 0; i < num_docks; i++)
	{
		dock_ptrs[i]->show_status();
	}
	for (int i = 0; i < num_sailors; i++)
	{
		sailor_ptrs[i]->show_status();
	}
	for (int i = 0; i < num_ports; i++)
	{
		port_ptrs[i]->show_status();
	}
	return;
}

void Model::display(View* view)
{
	cout << "Time: " << time <<endl;
	view->clear();

	for (int i = 0; i < num_objects; i++)
	{
		view->plot(object_ptrs[i]);
	}
	view->draw();
}

















