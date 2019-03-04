#ifndef LIBRARIAN_H
#define LIBRARIAN_H


#include "saa3053_Media.h"
using namespace std;

class Librarian //public Media
{
public:
		Librarian(string name, int id) : name(name), id(id) {};
		void check_out(vector <Media*> m);
		void check_in(vector <Media*> m);
		string to_string();
		string get_name();
		int get_id();

private:
		string name;
		int id;
};
#endif // !LIBRARIAN_H