#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H
//#include "Dock.h"
#include "Model.h"


void doSailCommand(Model* model);
void doPortCommand(Model* model);
void doAnchorCommand(Model* model);
void doDockCommand(Model* model);
void doHideCommand(Model* model);
void doGoCommand(Model* model);
void doRunCommand(Model* model);
void doQuitCommand(Model* model);
void doListCommand(Model* model);


#endif // GAMECOMMAND_H