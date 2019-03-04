#ifndef VIEW_H
#define VIEW_H

#include "saa3053_Media.h"
#include "saa3053_Library.h"
#include "saa3053_dialog.h"

class View {

public:
		View(Library &l) : l(l) {};
		int get_menu();

private:
		Library & l;
};
#endif