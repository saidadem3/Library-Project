#ifndef BOOK_H
#define BOOK_H
#include "saa3053_Media.h"
using namespace std;

class Book: public Media
{
public:
		Book(int id, string cn, string t, string g, string au, int cry) : Media(id, cn, t, g), author(au), copyright_year(cry) {
				type = "Book";
		}
		string get_author();
		int get_copyright_year();
private:
		string author;
		int copyright_year;
};

#endif // !BOOK_H
