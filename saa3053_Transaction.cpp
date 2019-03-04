#include "saa3053_Transaction.h"

double Transaction::calculate_fee()
{
		int days_in_months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


		int years_difference, days_difference;

		int months_total;

		int reg_year = 365;

		/////////////////////////////Years/////////////////////////////////


		if (check_out_date.get_year() == check_in_date.get_year())
		{
				years_difference = 0;
		}
		else
		{
				if (check_out_date.get_year() % 4 == 0 && check_out_date.get_year() % 100 != 0 || check_out_date.get_year() % 400 == 0)
				{
						if (check_in_date.get_year() % 4 == 0 && check_in_date.get_year() % 100 != 0 || check_in_date.get_year() % 400 == 0)
						{
								if (check_out_date.get_year() > check_in_date.get_year())
								{
										years_difference = (check_out_date.get_year() - check_in_date.get_year()) * (reg_year)+2;
								}
								else
								{
										years_difference = (check_in_date.get_year() - check_out_date.get_year()) * (reg_year)+2;
								}
								if (check_in_date.get_month() > check_out_date.get_month())
								{
										if (days_in_months[check_out_date.get_month() - 1] > days_in_months[1])
										{
												--years_difference;
										}
								}
						}
						else
						{
								if (check_out_date.get_year() > check_in_date.get_year())
								{
										years_difference = (check_out_date.get_year() - check_in_date.get_year()) * (reg_year)+1;
								}
								else
								{
										years_difference = (check_in_date.get_year() - check_out_date.get_year()) * (reg_year)+1;
								}
								if (check_out_date.get_month() > check_in_date.get_month())
								{
										if (days_in_months[check_in_date.get_month() - 1] > days_in_months[1])
										{
												--years_difference;
										}
								}
						}
				}
				else
				{
						if (check_out_date.get_year() > check_in_date.get_year())
						{
								years_difference = (check_out_date.get_year() - check_in_date.get_year()) * (reg_year);
						}
						else
						{
								years_difference = (check_in_date.get_year() - check_out_date.get_year()) * (reg_year);
						}
				}
		}

		/////////////////////////////Months////////////////////////////////////


		if (check_out_date.get_month() == check_in_date.get_month())
		{
				months_total = 0;
		}
		else
		{
				if (check_out_date.get_month() > check_in_date.get_month())
				{
						for (int i = (check_out_date.get_month() - 1); i > (check_in_date.get_month() - 1); i--)
						{
								static int months_total_temp = 0;
								months_total_temp += days_in_months[i];
								months_total = months_total_temp;
						}
				}
				else
				{
						for (int i = (check_out_date.get_month() - 1); i < (check_in_date.get_month() - 1); i++)
						{
								static int months_total_temp = 0;
								months_total_temp += days_in_months[i];
								months_total = months_total_temp;
						}
				}
		}

		////////////////////////////Days//////////////////////////////////

		int days_total;

		if (check_out_date.get_day() == check_in_date.get_day())
		{
				days_difference = 0;
				days_total = (years_difference + months_total) - days_difference;
		}
		else
		{
				if (check_out_date.get_day() > check_in_date.get_day())
				{
						days_difference = check_in_date.get_day() - check_out_date.get_day(); // check
						days_total = (years_difference + months_total) - days_difference;
				}
				else
				{
						days_difference = check_out_date.get_day() - check_in_date.get_day(); // check
						days_total = (years_difference + months_total) + days_difference;
				}
		}

		//////////////////////////In Between Leap Years///////////////////////////////

		if (check_out_date.get_year() == check_in_date.get_year())
		{
		}
		else
		{
				if (check_out_date.get_year() > check_in_date.get_year())
				{
						for (int i = (check_in_date.get_year() + 1); i < check_out_date.get_year(); i++)
						{
								if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
								{
										cout << endl;
										cout << i << endl;
										++days_total;
								}
						}
				}
				else
				{
						for (int i = (check_out_date.get_year() + 1); i < check_in_date.get_year(); i++)
						{
								if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
								{
										cout << endl;
										cout << i << endl;
										++days_total;
								}
						}
				}
		}


		if (days_total > 0)
				return (days_total *0.5);
		else
				return 0.00;
}

int Transaction::get_number()
{
		return transaction_number;
}

string Transaction::get_cus_name()
{
		return customer->get_name();
}

string Transaction::print_transaction()
{
		string cid = check_in_date.to_string();
		if (check_out_date.to_string() == check_in_date.to_string())
				cid = "No media currently checked in\n";
		return "Transaction number: " + to_string(transaction_number) + "\n" + "Check out date: " + check_out_date.to_string() + "\n" + librarian->to_string() + "\n" + customer->to_string() + "\n" + list_media() + "Check in date: " + cid + "\n";
		
}

string Transaction::list_media()
{
		stringstream tr;
		int i = 1;
		tr << "Media:" << endl;
		for (Media* cool : bundle)
		{
				tr << "#" << i << ") Name: " << cool->get_title() << endl;
				i++;
		}
		return tr.str();
}

void Transaction::set_check(int m, int d, int y)
{
		check_in_date.set_date(m,d,y);
}

Media * Transaction::medias_in_transaction()
{
		for (std::vector<Media*>::iterator it = bundle.begin(); it != bundle.end(); ++it)
						return *it;
}
