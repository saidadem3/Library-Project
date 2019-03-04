#ifndef MUSIC_ALBUM
#define MUSIC_ALBUM
#include "saa3053_Media.h"
using namespace std;

class Music_Album : public Media
{
public:
		Music_Album(int id, string cn, string t, string g, int release_year, string artist, vector <string> tracks) : Media(id, cn, t, g), release_year(release_year), artist(artist), tracks(tracks) 
		{
				type = "Music Album";
		};
		int get_release_year();
		string get_artist();
		string get_tracks() const;
		string to_string() const;
		friend ostream& operator<<(ostream& ost, const Music_Album& media);

private:
		int release_year;
		string artist;
		vector <string> tracks;
};
#endif // !MUSIC_ALBUM
