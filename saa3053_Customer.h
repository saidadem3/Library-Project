#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
using namespace std;

class Customer
{
public:
		Customer(string name, int id, int phone, string email): name(name), id(id), phone(phone), email(email) 
		{
				balance = 0;
		};
		string to_string();
		string get_name();
		int get_id();
		double pay_fee(double pay);
		double check_balance();
		void set_balance(double b);
private:
		string name;
		int id;
		int phone;
		string email;
		double balance;
};

#endif // !CUSTOMER_H

