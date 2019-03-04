#include "saa3053_Bundle.h"

void Bundle::add_to_bundle(Media* media)
{
		medias.push_back(media);
}

void Bundle::remove_from_bundle(int id)
{

}

void Bundle::print_bundle()  const
{
		int i = 1;
		for (Media* cool : medias)
		{
				if (cool->check_out_status() == false)
				{
						cout << "#" << i << ") " << cool->get_title() << endl;
						cout << cool->get_type() << endl;
						i++;
				}
		}
}

string Bundle::get_name()
{
		return name;
}

