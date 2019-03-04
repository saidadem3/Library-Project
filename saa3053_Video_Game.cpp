#include "saa3053_Video_Game.h"

int Video_Game::get_release_year()
{
		return release_year;
}

string Video_Game::get_studio()
{
		return studio;
}

string Video_Game::details() const
{
		return "ID number: " + std::to_string(id_number) + "\nCall number: " + call_number + "\nTitle: " + title + "\nGenre: " + genre + "\nRelease year: " + std::to_string(release_year) + "\nStudio: " + studio + "\n";
}


