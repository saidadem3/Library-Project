#ifndef MEDIA_H
#define MEDIA_H
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Media
{
public:
		Media(int id, string cn, string t, string g) : id_number{ id }, call_number{ cn }, title{ t }, genre{ g }
		{
				checked_out = false;
				type = "Media";
		};
		string get_title();
		string get_genre();
		int get_id();
		string get_call_number();
		string to_string() const;
		friend ostream& operator<<(ostream& ost, const Media& media);
		bool checks_out();
		bool checks_in();
		bool check_out_status();
		string get_type();

protected:
		int id_number;
		string call_number;
		string title;
		string genre;
		string type;

private:
		bool checked_out;
};

#endif