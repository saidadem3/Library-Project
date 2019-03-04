#ifndef VIDEO_GAME_H
#define VIDEO_GAME_H
#include "saa3053_Media.h"
using namespace std;


class Video_Game : public Media
{
public:
		Video_Game(int id, string cn, string title, string genre, int ry, string studio) : Media( id,cn,title,genre ), release_year(ry), studio (studio) 
		{
				type = "Video Game";
		};

		int get_release_year();
		string get_studio();
		string details() const;
private:
		int release_year;
		string studio;
};
#endif // !VIDEO_GAME_H

