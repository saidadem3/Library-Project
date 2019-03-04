#ifndef MOVIE_H
#define MOVIE_H

#include "saa3053_Media.h"
using namespace std;

class Movie : public Media
{
public:
		Movie(int id, string cn, string t, string g, int release_year, string producer, string director, vector <string> lead) : Media(id, cn, t, g), release_year(release_year), producer(producer), director(director), leading_actors(lead) 
		{ 
				type = "Movie"; 
		};

		int get_release_year();
		string get_producer();
		string get_director();
		string get_leads();

private:
		int release_year;
		string producer;
		string director;
		vector <string> leading_actors;
};
#endif // !MOVIE_H
