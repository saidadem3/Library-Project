#include "saa3053_Media.h"


string Media::get_title()
{
		return title;
}

string Media::get_genre()
{
		return genre;
}

int Media::get_id()
{
		return id_number;
}

string Media::get_call_number()
{
		return call_number;
}

string Media::to_string() const
{
		return "ID number: " + std::to_string(id_number) + "\n" + call_number + "\n" + title + "\n" + genre;
}

bool Media::checks_out()
{
		return checked_out = true;
}

bool Media::checks_in()
{
		return checked_out = false;
}

bool Media::check_out_status()
{
		return checked_out;
}

string Media::get_type()
{
		return type;
}

ostream& operator<<(ostream& ost, const Media& media)
{
		ost << media.to_string();
		return ost;
}
