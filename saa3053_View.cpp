#include "saa3053_View.h"

int View::get_menu()
{

		string menu = R"(
==========================================
        Welcome To Said's Library
==========================================

Select from one of the following options:

(1) View All Media
(2) View All Bundles
(3) Add New Book
(4) Add New Video Game
(5) Add New Movies
(6) Add New Music ALbum
(7) Add New Television Show Series
(8) Create Librarian
(9) Create Customer
(10) Check out Media
(11) Check in Media
(12) View Customers Currently In The Building
(13) View Transactions on file
(0) Exit
)";
		//Dialogs::message(menu, "Said's Library");
		string result = Dialogs::input(menu, "Main Menu");
		int return_int = stoi(result);
    	return return_int;
		//return menu;
}


