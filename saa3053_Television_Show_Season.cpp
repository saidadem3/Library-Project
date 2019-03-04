#include "saa3053_Television_Show_Season.h"

int Television_Show_Season::get_release_year()
{
		return release_year;
}

string Television_Show_Season::get_producer()
{
		return producer;
}

string Television_Show_Season::get_directors() const
{
		for (std::vector<string>::const_iterator it = director.begin(); it != director.end(); ++it)
				std::cout << '"' << *it << '"' << ' ';
		std::cout << endl;
		return string();
}

string Television_Show_Season::details() const
{
		return "ID number: " + std::to_string(id_number) + "\nCall number: " + call_number + "\nTitle: " + title + "\nGenre: " + genre + "\nRelease year: " + std::to_string(release_year) + "\nProducer: " + producer + "\n" + get_directors();
}
