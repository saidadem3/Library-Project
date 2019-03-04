#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "saa3053_View.h"
using namespace std;

class Controller {

public:
		Controller(Library &lib, View &v) : liv(lib), view(v) {};
		void cli();
		void execute_cmd(int cmd);


private:
		Library &liv;
		View &view;
};
#endif // !CONTROLLER_H
