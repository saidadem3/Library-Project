#ifndef BUNDLE_H
#define BUNDLE_H
#include "saa3053_Media.h"
#include <vector>

class Bundle
{
public:
		Bundle(string n) : name(n) {};
		void add_to_bundle(Media* media);
		void remove_from_bundle(int id);
		void print_bundle() const;
		string get_name();
		

private:
		string name;
		vector <Media*> medias;
		bool checked_out;

};

#endif // !BUNDLE_H
