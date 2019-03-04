#include "saa3053_Controller.h"

void Controller::cli()
{
	Video_Game Jak(1000, "AAA", "Jak and Daxter", "Action", 2001, "Naughty Dog");
	Book Goblet(2135, "BAC", "Harry Potter And The Goblet Of Fire", "Fantasy Fiction", "J.K Rowling", 2000);
	Book Ringbook(3336, "FDE", "The Lord of The Rings: The Fellowship of the Ring", "Fantasy Fiction", "J.R.R Tolkein", 1954);
	Movie Ring(3336, "POI", "The Lord of The Rings: The Fellowship of the Ring", "Fantasy Fiction", 2001, "Allen & Unwin", "Peter Jackson", {"Elijah Wood", "Viggo Mortensen", "Ian McKellen", "Orlando Bloom", "Sean Bean"});
	Music_Album Blink(5261, "QWE", "Blink-182: Greatest Hits", "Alternative-Rock", 2005, "Blink-182", {"What's My Age Again?", "All The Small Things", "Adam's Song", "First Date", "Feeling This", "I Miss You"});
	liv.add_to_medias(&Jak);
	liv.add_to_medias(&Goblet);
	liv.add_to_medias(&Ringbook);
	liv.add_to_medias(&Ring);
	liv.add_to_medias(&Blink);
	Bundle Hobit("The FellowShip Bundle");
	Hobit.add_to_bundle(&Ring);
	Hobit.add_to_bundle(&Ringbook);
	liv.create_new_bundle(&Hobit);
	Librarian lib("Sarah", 10002);
	liv.create_new_librarian(&lib);
	Customer cus("Ahmad", 20053, 2145556825, "ahmad@gmail.com");
	liv.create_new_customer(&cus);
	vector<Media *> goodie;
	Date t(10, 10, 2017);
	goodie.push_back(liv.get_media("Jak and Daxter"));
	Transaction test(2305, t, &lib, &cus, goodie, t);
	liv.create_new_transaction(&test);

	int cmd = -1;
	while (cmd != 0)
	{
		cmd = view.get_menu();
		execute_cmd(cmd);
	}
}

void Controller::execute_cmd(int cmd)
{
	int choice = 0, id, release_year, copyrright_year, season_number, option = 0, phone, tn, day, month, year, selection = ' ';
	string call_number, title, genre, studio, author, track = " ";
	vector<string> tracks;
	string producer, director, actor, name, email, cusname, libname, cusid, libid;
	vector<string> lead;
	vector<string> directors;
	double balance;
	vector<Media *> goodies;

	Music_Album Blink(5261, "QWE", "Blink-182: Greatest Hits", "Alternative-Rock", 2005, "Blink-182", {"What's My Age Again?", "All The Small Things", "Adam's Song", "First Date", "Feeling This", "I Miss You"});

	switch (cmd)
	{
	case 0:
		Dialogs::message("Have a nice day.", "Please be sure to visit us again.");
		exit(0);
	case 1:
		Dialogs::message(liv.get_medias(), "All Media");
		break;
	case 2:
		Dialogs::message(liv.get_bundles(), "All Bundles");
		break;
	case 3:
	{
		Dialogs::create_dialog(&liv);
		break;
	}
	case 4:
		Dialogs::create_dialogGame(&liv);	
		break;
	case 5:
		Dialogs::create_dialogMovie(&liv);	
		break;
	case 6:
		Dialogs::create_dialogMusic(&liv);
		break;
	case 7:
		Dialogs::create_dialogTV(&liv);
		break;
	case 8:
	
		Dialogs::create_dialogLibrarian(&liv);
		break;
	case 9:
		
		Dialogs::create_dialogCustomer(&liv);
		break;
	case 10:
	{
		Dialogs::message("IT'S A FEATURE!","Check-out using cli.");
		
		cout << "Select from the following customers." << endl << endl;
		cout << liv.print_customers();
		cout << endl << endl;
		cout << "Customer's name (case sensitive): ";
		getline(cin, cusname);
		cin.clear();
		Customer *cus1 = liv.get_customers(cusname);
		cout << "Please enter the date." << endl;
		cout << "Day: ";
		cin >> day;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Month: ";
		cin >> month;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Year: ";
		cin >> year;
		cin.clear();
		cin.ignore(256, '\n');
		Date d(month, day, year);
		liv.get_transaction_by_name(cus1->get_name())->set_check(month, day, year);
		balance = liv.get_transaction_by_name(cus1->get_name())->calculate_fee();
		cus1->set_balance(balance);
		if (cus1->check_balance() > 0)
		{
			cout << "Customer currently has a balance of " << cus1->check_balance() << " that must be paid before checking out." << endl;
			cout << "Would you like to clear your balance today? (Y/N): ";
			selection = cin.get();
			cin.clear();
			cin.ignore(256, '\n');
			while (selection != 'Y' && selection != 'N')
			{
				cout << "Please enter a valid choice: ";
				selection = cin.get();
				cin.clear();
				cin.ignore(256, '\n');
			}
			if (selection == 'Y')
			{
				cout << "Balance paid in full. You may proceed with checking out.";
			}
			else
			{
				cout << "You cannot currently check out due to account unpaid account balance.";
				break;
			}
		}
		cout << "\nSelect from the following available Media (type end to stop):" << endl;
		cout << liv.get_medias();

		do
		{
			cout << "Media: ";
			getline(cin, director);
			if (director != "end")
			{
				goodies.push_back(liv.get_media(director));
			}
		} while (director != "end");

		cout << "\nPlease take your items to one of the following staff to check out." << endl;
		cout << liv.print_librarians();

		cout << "\nWhich staff member would you like to go to (Names are case sensitive): ";
		getline(cin, libname);
		cin.clear();
		Librarian *lib1 = liv.get_librarian(libname);
		lib1->check_out(goodies);
		cout << "Please enter the transaction number: ";
		cin >> tn;
		cin.clear();
		cin.ignore(256, '\n');
		liv.create_new_transaction(new Transaction(tn, d, lib1, cus1, goodies, d));
		break;
	}
	case 11:
		Dialogs::message("IT'S A FEATURE!","Check-in using cli.");
		
		cout << "\nPlease check in with one of the following staff." << endl;
		cout << liv.print_librarians();

		cout << "\nWhich staff member would you like to go to (Names are case sensitive): ";
		getline(cin, libname);
		cin.clear();
		Librarian *lib1;
		lib1 = liv.get_librarian(libname);
		cout << "\nPlease select from one of the following accounts:" << endl;
		cout << liv.print_transaction_numbers();
		cout << "Enter the transaction number: ";
		cin >> id;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "What is the date (Month, Day, Year): " << endl;
		cout << "Day: ";
		cin >> day;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Month: ";
		cin >> month;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Year: ";
		cin >> year;
		cin.clear();
		cin.ignore(256, '\n');
		liv.get_transaction(id)->set_check(month, day, year);
		cout << endl
			 << "Your current balance is : " << liv.get_transaction(id)->calculate_fee() << endl;
		cout << "Would you like to clear your balance today? (Y/N): ";
		selection = cin.get();
		cin.clear();
		cin.ignore(256, '\n');
		while (selection != 'Y' && selection != 'N')
		{
			cout << "Please enter a valid choice: ";
			selection = cin.get();
			cin.clear();
			cin.ignore(256, '\n');
		}
		if (selection == 'Y')
		{
			goodies.push_back(liv.get_transaction(id)->medias_in_transaction());
			lib1->check_in(goodies);
			cout << "Balance paid in full. Have a nice day.";
		}
		else
		{
			cout << "Account balance must be paid to check in. Have a nice day.";
			break;
		}
		break;
	case 12:
		Dialogs::message(liv.print_customers(), "All Customers");
		break;
	case 13:
		Dialogs::message(liv.print_transaction_numbers(), "All Customers");
		break;
	default:
		Dialogs::message("Return to main menu", "Invalid choice");
		break;
	}
}