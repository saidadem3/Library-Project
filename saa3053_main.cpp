#include "saa3053_Library.h"
#include "saa3053_Transaction.h"
#include "saa3053_Controller.h"
#include "saa3053_dialog.h"


int main(int argc, char* argv[])
{
		Gtk::Main kit(argc, argv);
		
		// I WAS TESTING BUTTONS HERE. LETS FINISH THE EASIER STUFF FIRST BEFORE WE GET INTO ALL THIS
		//std::vector<std::string> buttons= {"View Media","Create Librarians","Create customer"};
		//std::cout << Dialogs::question("Select from teh following", "Said's Library", buttons) << std::endl;

		Library liv;
		View view(liv);
		Controller controller(liv, view);

		controller.cli();
		return 0;
		
}