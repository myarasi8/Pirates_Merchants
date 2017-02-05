#include <iostream>
#include "Model.h"
#include "View.h"
#include "GameCommand.h"
using namespace std;

int main()
{
	cout << "EC327: Introduction to Software Engineering" << endl;
	cout << "Fall 2015" << endl;
	cout << "Programming Assignment 3" << endl;
	Model* model = new Model();
    View* view = new View();
    doListCommand(model);

    view->clear();
    model->display(view);
    view->draw();



	cout << "Enter command: ";
	char inputCommand;
	cin >> inputCommand;

	while(inputCommand != 'q')
	{
		switch(inputCommand)
		{
		case 's':
			doSailCommand(model);
			
			break;

		case 'p':
			doPortCommand(model);
			break;

		case 'a':
			doAnchorCommand(model);
			break;

		case 'd':
			doDockCommand(model);
			break;

		case 'h':
			doHideCommand(model);
			break;

		case 'g':
			doGoCommand(model);
			break;

		case 'r':
			doRunCommand(model);
			break;
		}
		//return 0;
		//cout << " error coming" << endl;
		model->display(view);
		//cout << " passed" << endl;
		cout << "Enter command: ";
		cin >> inputCommand;
	}
	//cout << "Terminating program" << endl;
	//model->display(view);
	//return 0;
	view->~View();
	model->~Model();
}