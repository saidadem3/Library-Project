#include "saa3053_Music_Album.h"

int Music_Album::get_release_year()
{
		return release_year;
}

string Music_Album::get_artist()
{
		return artist;
}

string Music_Album::get_tracks() const
{
		stringstream tr;
		int count = 1;
		tr << "Tracks:" << endl;
		for (std::vector<string>::const_iterator it = tracks.begin(); it != tracks.end(); ++it)
		{
				tr << "#" << count << ": " << *it << endl;
				count++;
		}

		return tr.str();
}

string Music_Album::to_string() const
{
		return "ID number: " + std::to_string(id_number) + "\n" + call_number + "\n" + title + "\n" + genre  +"\n" + std::to_string(release_year) + "\n" + artist + "\n" + get_tracks();
}

ostream& operator<<(ostream& ost, const Music_Album& music)
{
		ost << music.to_string();
		return ost;
}
