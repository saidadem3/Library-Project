#ifndef DIALOGS_H
#define DIALOGS_H
#include <vector>
#include <iostream>
#include "saa3053_Library.h"
#include <gtkmm.h>

class Dialogs
{
public:
    static void message(std::string msg, std::string title);
    static std::string input(std::string msg, 
                        std::string title, 
                        std::string default_text = "",
                        std::string cancel_text = "CANCEL");
   static int question(std::string msg, 
                        std::string title, 
                        std::vector<std::string> buttons);
    static void create_dialog(Library* liv);
    static void create_dialogGame(Library* liv);
    static void create_dialogMovie(Library* liv);
    static void create_dialogMusic(Library* liv);
    static void create_dialogTV(Library* liv);
    static void create_dialogLibrarian(Library* liv);
    static void create_dialogCustomer(Library* liv);
    static vector<string> GetActorsFromString(string s);
private:
};

#endif
