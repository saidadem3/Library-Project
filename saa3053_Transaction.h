#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "saa3053_Date.h"
#include "saa3053_Librarian.h"
#include "saa3053_Customer.h"
#include "saa3053_Bundle.h"

class Transaction
{
public:
		Transaction(int tn, Date cod, Librarian* librarian, Customer* customer, vector <Media*> bundle, Date cin) : transaction_number(tn), check_out_date(cod), librarian(librarian), customer(customer), bundle(bundle), check_in_date(cin) {};
		double calculate_fee();
		int get_number();
		string get_cus_name();
		string print_transaction();
		string list_media();
		void set_check(int m, int d, int y);
		Media* medias_in_transaction();

private:
		int transaction_number;
		Date check_out_date;
		Librarian* librarian;
		Customer* customer;
		vector <Media*> bundle;
		Date check_in_date;
};
#endif // !TRANSACTION_H
