#include "saa3053_Movie.h"

int Movie::get_release_year()
{
		return release_year;
}

string Movie::get_producer()
{
		return producer;
}

string Movie::get_director()
{
		return director;
}

string Movie::get_leads()
{
		for (std::vector<string>::iterator it = leading_actors.begin(); it != leading_actors.end(); ++it)
				std::cout << '"' << *it << '"' << ' ';
		std::cout << endl;
		return string();
}
