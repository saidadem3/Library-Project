#include "saa3053_Library.h"

void Library::create_new_media(Media *m)
{
		medias.push_back(m);
}

void Library::create_new_vgame(Video_Game *v)
{
		
		medias.push_back(v);
}

void Library::create_new_movie(Movie *mov)
{
		medias.push_back(mov);
}

void Library::create_new_music(Music_Album *mus)
{
		medias.push_back(mus);
}

void Library::create_new_tv(Television_Show_Season *tv)
{
		medias.push_back(tv);
}

void Library::create_new_book(Book *b)
{
		medias.push_back(b);
}

void Library::create_new_bundle(Bundle *bun)
{
		bundles.push_back(bun);
}

void Library::create_new_librarian(Librarian *l)
{
		librarians.push_back(l);
}

void Library::create_new_customer(Customer *cus)
{
		customers.push_back(cus);
}

void Library::create_new_transaction(Transaction *trans)
{
		transactions.push_back(trans);
}

string Library::get_medias()
{
		stringstream pleasework;
		int i = 1;
		for (Media* cool : medias)
		{		
				if (cool->check_out_status() == false) 
				{
						pleasework << "#" << i << ") " << cool->get_title() << endl;
						pleasework << cool->get_type() << endl;
						i++;
				}
			
		}
		return pleasework.str();
}

string Library::get_bundles()
{
		stringstream pleasework;
		int i = 1;
		for (Bundle* cool : bundles)
		{
						pleasework << "#" << i << ") " << cool->get_name() << endl;
						i++;
				
		}
		return pleasework.str();
}

void Library::add_to_medias(Media *m)
{
		medias.push_back(m);
}

Librarian* Library::get_librarian(string name)
{
		for (std::vector<Librarian*>::iterator it = librarians.begin(); it != librarians.end(); ++it)
		{
				if ((*it)->get_name() == name)
						return *it;
		}
		return nullptr;
}

string Library::print_librarians()
{
		stringstream pleasework;
		int i = 1;
		pleasework << "Current Available Staff:" << endl;
		for (Librarian* cool : librarians)
		{
						cout << "#" << i << ") Name: " << cool->get_name() << ", ID: " << cool->get_id() << endl;
						i++;

		}
		return pleasework.str();
}

Media * Library::get_media(string name)
{
		for (std::vector<Media*>::iterator it = medias.begin(); it != medias.end(); ++it)
		{
				if ((*it)->get_title() == name)
						return *it;
		}
		return nullptr;
}

string Library::print_customers()
{
		stringstream pleasework;
		int i = 1;
		cout << "Customers in the library:" << endl;
		for (Customer* cool : customers)
		{
				pleasework << "#" << i << ") Name: " << cool->get_name() << ", ID: " << cool->get_id() << endl;
				i++;

		}
		return pleasework.str();
}

Customer * Library::get_customers(string name)
{
		for (std::vector<Customer*>::iterator it = customers.begin(); it != customers.end(); ++it)
		{
				if ((*it)->get_name() == name)
						return *it;
		}
		return nullptr;
}

string Library::print_transaction_numbers()
{
		stringstream pleasework;
		int i = 1;
		cout << "Transactions stored:" << endl;
		for (Transaction* cool : transactions)
		{
				pleasework << "#" << i << ": " << endl << cool->print_transaction();
				i++;
		}
		return pleasework.str();
}

Transaction * Library::get_transaction(int tn)
{
		for (std::vector<Transaction*>::iterator it = transactions.begin(); it != transactions.end(); ++it)
		{
				if ((*it)->get_number() == tn)
						return *it;
		}
		return nullptr;
}

Transaction * Library::get_transaction_by_name(string name)
{
		for (std::vector<Transaction*>::iterator it = transactions.begin(); it != transactions.end(); ++it)
		{
				if ((*it)->get_cus_name() == name)
						return *it;
		}
		return nullptr;
}


//void Library::save(string file_name)
//{
//}
//
//void Library::load(string file_name)
//{
//}