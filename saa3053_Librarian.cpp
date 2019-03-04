#include "saa3053_Librarian.h"

void Librarian::check_out(vector <Media*> m)
{
		for (std::vector<Media*>::iterator it = m.begin(); it != m.end(); ++it)
				(*it)->checks_out();
}

void Librarian::check_in(vector <Media*> m)
{
		for (std::vector<Media*>::iterator it = m.begin(); it != m.end(); ++it)
				(*it)->checks_in();
}

string Librarian::to_string()
{
		return "Librarian Name: " + name + "\nLibrarian ID: " +  std::to_string(id);
}

string Librarian::get_name()
{
		return name;
}

int Librarian::get_id()
{
		return id;
}
