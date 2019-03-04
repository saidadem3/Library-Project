#include "saa3053_Customer.h"

string Customer::to_string()
{
		return "Customer Name: " + name + "\nCustomer ID: " + std::to_string(id) + "\nPhone Number: " + std::to_string(phone) + "\nEmail: " + email + "\nBalance: " + std::to_string(balance);
}

string Customer::get_name()
{
		return name;
}

int Customer::get_id()
{
		return id;
}

double Customer::pay_fee(double pay)
{
		double bal = balance - pay;
		if (bal > 0)
				balance = bal;
		else
				balance = 0;
		 return balance;
}

double Customer::check_balance()
{
		return balance;
}

void Customer::set_balance(double b)
{
		balance = b;
}
