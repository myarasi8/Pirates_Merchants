#include <iostream>
#include "GameCommand.h"
using namespace std;



	void doSailCommand(Model* model)
	{
		int ID;
		double x;
		double y;

		cin >> ID;
		cin >> x;
		cin >> y;

		CartPoint dest = CartPoint(x, y);

		cout << "Sailing " << ID << "to " << dest << endl;

		model->get_Sailor_ptr(ID)->start_sailing(dest);
	}

	void doPortCommand(Model* model)
	{
		int ID1;
		int ID2;

		cin >> ID1;
		cin >> ID2;

		model->get_Sailor_ptr(ID1)->start_supplying(model->get_Port_ptr(ID2));

	}

	void doAnchorCommand(Model* model)
	{
		int ID;

		cin >> ID;

		model->get_Sailor_ptr(ID)->anchor(); //anchors the sailor with ID, ID.
	}

	void doDockCommand(Model* model)
	{
		int ID1;
		int ID2;

		cin >> ID1;
		cin >> ID2;

		model->get_Sailor_ptr(ID1)->start_docking(model->get_Dock_ptr(ID2));
	}

	void doHideCommand(Model* model)
	{
		int ID;
		cin >> ID;

		model->get_Sailor_ptr(ID)->start_hiding();
	}

	void doGoCommand(Model* model)
	{
		/*for (int i = 0; i < num_objects; i++)
		{
			time++;
			object_ptrs[i]->update();
		}*/
		cout<< "Advancing one time tick" << endl;
		model->update();
		model->show_status();
	}

	void doRunCommand(Model* model)
	{
		int count = 0;
		cout << "Advancing to next event or 5 events" << endl;
		while (count < 5)
		{
			if (model->update())
				break;
			count++;
		}
		model->show_status();
	}

	void doListCommand(Model* model)
	{
		model->show_status();
	}



	





















