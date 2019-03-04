#ifndef LIBRARY_H
#define LIBRARY_H

#include "saa3053_Media.h"
#include "saa3053_Video_Game.h"
#include "saa3053_Transaction.h"
#include "saa3053_Movie.h"
#include "saa3053_Book.h"
#include "saa3053_Television_Show_Season.h"
#include "saa3053_Music_Album.h"
using namespace std;

class Library
{
public: 
		Library() {};
		void create_new_media(Media* m);
		void create_new_vgame(Video_Game* v);
		void create_new_movie(Movie *mov);
		void create_new_music(Music_Album *mus);
		void create_new_tv(Television_Show_Season *tv);
		void create_new_book(Book *b);
		void create_new_bundle(Bundle *bun);
		void create_new_librarian(Librarian *l);
		void create_new_customer(Customer *cus);
		void create_new_transaction(Transaction *trans);
		void add_to_medias(Media *m);
		//void save(string file_name);
		//void load(string file_name);
		string get_medias();
		string get_bundles();
		Librarian* get_librarian(string name);
		string print_librarians();
		Media* get_media(string name);
		string print_customers();
		Customer* get_customers(string name);
		string print_transaction_numbers();
		Transaction* get_transaction(int tn);
		Transaction* get_transaction_by_name(string name);

		
private:
		vector <Media*> medias;
		vector <Transaction*> transactions;
		vector <Customer*> customers;
		vector <Librarian*> librarians;
		vector <Bundle*> bundles;
};
#endif