#ifndef TELEVISION_TV_SEASON_H
#define TELEVISION_TV_SEASON_H
#include "saa3053_Media.h"
using namespace std;

class Television_Show_Season: public Media
{
public:
		Television_Show_Season(int id, string cn, string t, string g, int ry, string pr, vector<string> dir) : Media(id, cn, t, g), release_year(ry), producer(pr), director(dir) 
		{
				type = "Television";
		};
		int get_release_year();
		string get_producer();
		string get_directors() const;
		string details() const;
private:
		int release_year;
		string producer;
		vector<string> director;
};
#endif // !TELEVISION_TV_SEASON_H
