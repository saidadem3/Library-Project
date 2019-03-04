#include "saa3053_dialog.h"

void Dialogs::message(std::string msg, std::string title)
{
    Gtk::MessageDialog *dialog = new Gtk::MessageDialog(title);
    dialog->set_secondary_text(msg, true);
    dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())
        Gtk::Main::iteration();
    
    delete dialog;
}

std::string Dialogs::input(std::string msg, 
                        std::string title, 
                        std::string default_text,
                        std::string cancel_text)
{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);
    
    Gtk::Label *label = new Gtk::Label(msg);
    dialog->get_content_area()->pack_start(*label);
    label->show();
    
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK",1);
    dialog->set_default_response(1);
    
    Gtk::Entry *entry = new Gtk::Entry();
    entry->set_text(default_text);
    entry->set_max_length(50);
    entry->show();
    dialog->get_vbox()->pack_start(*entry);
    
    int result = dialog->run();
    std::string text = entry->get_text();
        
    
    dialog->close();
    while (Gtk::Main::events_pending())
        Gtk::Main::iteration();
    
    delete dialog;
    delete label;
    delete entry;
    
    if(result == 1)
    return text;
    else
        return  cancel_text;
}

int Dialogs::question(std::string msg, 
                        std::string title, 
                        std::vector<std::string> buttons)
{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);
    
    Gtk::Label *label = new Gtk::Label(msg);
    dialog->get_content_area()->pack_start(*label);
    label->show();
    
    for( int i = 0; i < buttons.size(); i++)
        dialog->add_button(buttons[i], i);
        
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())
        Gtk::Main::iteration();
    
    delete dialog;
    delete label;
    return result;
}

void Dialogs::create_dialog(Library* liv)
{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Create a Book");
    
    Gtk::Box *hbox1 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox2 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox3 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox4 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox5 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox6 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    
    Gtk::Label *label1 = new Gtk::Label("ID: ");
    Gtk::Label *label2 = new Gtk::Label("Refrence number: ");
    Gtk::Label *label3 = new Gtk::Label("Title: ");
    Gtk::Label *label4 = new Gtk::Label("Genre: ");
    Gtk::Label *label5 = new Gtk::Label("Author's name: ");
    Gtk::Label *label6 = new Gtk::Label("Copyright year: ");

    
    Gtk::Entry *entry1 = new Gtk::Entry();
    entry1->set_text("");
    entry1->set_max_length(50);
    
    Gtk::Entry *entry2 = new Gtk::Entry();
    entry2->set_text("");
    entry2->set_max_length(50);
    
    Gtk::Entry *entry3 = new Gtk::Entry();
    entry3->set_text("");
    entry3->set_max_length(50);

    Gtk::Entry *entry4 = new Gtk::Entry();
    entry4->set_text("");
    entry4->set_max_length(50);

    Gtk::Entry *entry5 = new Gtk::Entry();
    entry5->set_text("");
    entry5->set_max_length(50);

    Gtk::Entry *entry6 = new Gtk::Entry();
    entry6->set_text("");
    entry6->set_max_length(50);
    
    dialog->get_vbox()->pack_start(*hbox1);
    dialog->get_vbox()->add(*hbox2);
    dialog->get_vbox()->add(*hbox3);
    dialog->get_vbox()->add(*hbox4);
    dialog->get_vbox()->add(*hbox5);
    dialog->get_vbox()->add(*hbox6);
      
    hbox1->pack_start(*label1);
    hbox1->add(*entry1);
    
    hbox2->pack_start(*label2);
    hbox2->add(*entry2);

    hbox3->pack_start(*label3);
    hbox3->add(*entry3);

    hbox4->pack_start(*label4);
    hbox4->add(*entry4);

    hbox5->pack_start(*label5);
    hbox5->add(*entry5);

    hbox6->pack_start(*label6);
    hbox6->add(*entry6);
    
    dialog->get_vbox()->show_all();
    
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK",1);
    dialog->set_default_response(1);
    
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())
        Gtk::Main::iteration();
   
    if(result == 1)
        liv->create_new_book(new Book(stoi(entry1->get_text()), entry2->get_text(), entry3->get_text(), entry4->get_text(), entry5->get_text(), stoi(entry6->get_text())));
    
        
    delete entry1;
    delete entry2;
    delete entry3;
    delete entry4;
    delete entry5;
    delete entry6;
    delete label1;
    delete label2;
    delete label3;
    delete label4;
    delete label5;
    delete label6;
    delete hbox1;
    delete hbox2;    
    delete hbox3;    
    delete hbox4;    
    delete hbox5;    
    delete hbox6;    
    delete dialog;
    
    return;
    
}


void Dialogs::create_dialogGame(Library* liv)
{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Create a Video Game");
    
    Gtk::Box *hbox1 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox2 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox3 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox4 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox5 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox6 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    
    Gtk::Label *label1 = new Gtk::Label("ID: ");
    Gtk::Label *label2 = new Gtk::Label("Refrence number: ");
    Gtk::Label *label3 = new Gtk::Label("Title: ");
    Gtk::Label *label4 = new Gtk::Label("Genre: ");
    Gtk::Label *label5 = new Gtk::Label("Author's name: ");
    Gtk::Label *label6 = new Gtk::Label("Copyright year: ");

    
    Gtk::Entry *entry1 = new Gtk::Entry();
    entry1->set_text("");
    entry1->set_max_length(50);
    
    Gtk::Entry *entry2 = new Gtk::Entry();
    entry2->set_text("");
    entry2->set_max_length(50);
    
    Gtk::Entry *entry3 = new Gtk::Entry();
    entry3->set_text("");
    entry3->set_max_length(50);

    Gtk::Entry *entry4 = new Gtk::Entry();
    entry4->set_text("");
    entry4->set_max_length(50);

    Gtk::Entry *entry5 = new Gtk::Entry();
    entry5->set_text("");
    entry5->set_max_length(50);

    Gtk::Entry *entry6 = new Gtk::Entry();
    entry6->set_text("");
    entry6->set_max_length(50);
    
    dialog->get_vbox()->pack_start(*hbox1);
    dialog->get_vbox()->add(*hbox2);
    dialog->get_vbox()->add(*hbox3);
    dialog->get_vbox()->add(*hbox4);
    dialog->get_vbox()->add(*hbox5);
    dialog->get_vbox()->add(*hbox6);
      
    hbox1->pack_start(*label1);
    hbox1->add(*entry1);
    
    hbox2->pack_start(*label2);
    hbox2->add(*entry2);

    hbox3->pack_start(*label3);
    hbox3->add(*entry3);

    hbox4->pack_start(*label4);
    hbox4->add(*entry4);

    hbox5->pack_start(*label5);
    hbox5->add(*entry5);

    hbox6->pack_start(*label6);
    hbox6->add(*entry6);
    
    dialog->get_vbox()->show_all();
    
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK",1);
    dialog->set_default_response(1);
    
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())
        Gtk::Main::iteration();
   
    if(result == 1)
        liv->create_new_vgame(new Video_Game(stoi(entry1->get_text()), entry2->get_text(), entry3->get_text(), entry4->get_text(), stoi(entry5->get_text()), entry6->get_text()));

    delete entry1;
    delete entry2;
    delete entry3;
    delete entry4;
    delete entry5;
    delete entry6;
    delete label1;
    delete label2;
    delete label3;
    delete label4;
    delete label5;
    delete label6;
    delete hbox1;
    delete hbox2;    
    delete hbox3;    
    delete hbox4;    
    delete hbox5;    
    delete hbox6;    
    delete dialog;
    
    return;
    
}

void Dialogs::create_dialogMovie(Library* liv)
{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Create a Movie");
    
    Gtk::Box *hbox1 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox2 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox3 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox4 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox5 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox6 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox7 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox8 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);

    Gtk::Label *label1 = new Gtk::Label("ID: ");
    Gtk::Label *label2 = new Gtk::Label("Call Number: ");
    Gtk::Label *label3 = new Gtk::Label("Title: ");
    Gtk::Label *label4 = new Gtk::Label("Genre: ");
    Gtk::Label *label5 = new Gtk::Label("Release year: ");
    Gtk::Label *label6 = new Gtk::Label("Producer: ");
    Gtk::Label *label7 = new Gtk::Label("Director: ");
    Gtk::Label *label8 = new Gtk::Label("Lead Actors: ");

    
    Gtk::Entry *entry1 = new Gtk::Entry();
    entry1->set_text("");
    entry1->set_max_length(50);
    
    Gtk::Entry *entry2 = new Gtk::Entry();
    entry2->set_text("");
    entry2->set_max_length(50);
    
    Gtk::Entry *entry3 = new Gtk::Entry();
    entry3->set_text("");
    entry3->set_max_length(50);

    Gtk::Entry *entry4 = new Gtk::Entry();
    entry4->set_text("");
    entry4->set_max_length(50);

    Gtk::Entry *entry5 = new Gtk::Entry();
    entry5->set_text("");
    entry5->set_max_length(50);

    Gtk::Entry *entry6 = new Gtk::Entry();
    entry6->set_text("");
    entry6->set_max_length(50);
    
    Gtk::Entry *entry7 = new Gtk::Entry();
    entry6->set_text("");
    entry6->set_max_length(50);

    Gtk::Entry *entry8 = new Gtk::Entry();
    entry6->set_text("");
    entry6->set_max_length(50);
    
    dialog->get_vbox()->pack_start(*hbox1);
    dialog->get_vbox()->add(*hbox2);
    dialog->get_vbox()->add(*hbox3);
    dialog->get_vbox()->add(*hbox4);
    dialog->get_vbox()->add(*hbox5);
    dialog->get_vbox()->add(*hbox6);
    dialog->get_vbox()->add(*hbox7);
    dialog->get_vbox()->add(*hbox8);
      
    hbox1->pack_start(*label1);
    hbox1->add(*entry1);
    
    hbox2->pack_start(*label2);
    hbox2->add(*entry2);

    hbox3->pack_start(*label3);
    hbox3->add(*entry3);

    hbox4->pack_start(*label4);
    hbox4->add(*entry4);

    hbox5->pack_start(*label5);
    hbox5->add(*entry5);

    hbox6->pack_start(*label6);
    hbox6->add(*entry6);

    hbox7->pack_start(*label7);
    hbox7->add(*entry7);

    hbox8->pack_start(*label8);
    hbox8->add(*entry8);
    
    dialog->get_vbox()->show_all();
    
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK",1);
    dialog->set_default_response(1);
    
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())
        Gtk::Main::iteration();
   
    if(result == 1)
		liv->create_new_movie(new Movie(stoi(entry1->get_text()), entry2->get_text(), entry3->get_text(), entry4->get_text(), stoi(entry5->get_text()), entry6->get_text(), entry7->get_text(), Dialogs::GetActorsFromString(entry8->get_text())));
    
    delete entry1;
    delete entry2;
    delete entry3;
    delete entry4;
    delete entry5;
    delete entry6;
    delete entry7;
    delete entry8;
    delete label1;
    delete label2;
    delete label3;
    delete label4;
    delete label5;
    delete label6;
    delete label7;
    delete label8;
    delete hbox1;
    delete hbox2;    
    delete hbox3;    
    delete hbox4;    
    delete hbox5;    
    delete hbox6;    
    delete hbox7;    
    delete hbox8;    
    delete dialog;
    
    return;
 
}

void Dialogs::create_dialogMusic(Library* liv)
{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Create Music Album");
    
    Gtk::Box *hbox1 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox2 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox3 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox4 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox5 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox6 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox7 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);

    Gtk::Label *label1 = new Gtk::Label("ID: ");
    Gtk::Label *label2 = new Gtk::Label("Call Number: ");
    Gtk::Label *label3 = new Gtk::Label("Title: ");
    Gtk::Label *label4 = new Gtk::Label("Genre: ");
    Gtk::Label *label5 = new Gtk::Label("Release year: ");
    Gtk::Label *label6 = new Gtk::Label("Author: ");
    Gtk::Label *label7 = new Gtk::Label("Tracks: ");
    
    Gtk::Entry *entry1 = new Gtk::Entry();
    entry1->set_text("");
    entry1->set_max_length(50);
    
    Gtk::Entry *entry2 = new Gtk::Entry();
    entry2->set_text("");
    entry2->set_max_length(50);
    
    Gtk::Entry *entry3 = new Gtk::Entry();
    entry3->set_text("");
    entry3->set_max_length(50);

    Gtk::Entry *entry4 = new Gtk::Entry();
    entry4->set_text("");
    entry4->set_max_length(50);

    Gtk::Entry *entry5 = new Gtk::Entry();
    entry5->set_text("");
    entry5->set_max_length(50);

    Gtk::Entry *entry6 = new Gtk::Entry();
    entry6->set_text("");
    entry6->set_max_length(50);
    
    Gtk::Entry *entry7 = new Gtk::Entry();
    entry6->set_text("");
    entry6->set_max_length(50);
    
    dialog->get_vbox()->pack_start(*hbox1);
    dialog->get_vbox()->add(*hbox2);
    dialog->get_vbox()->add(*hbox3);
    dialog->get_vbox()->add(*hbox4);
    dialog->get_vbox()->add(*hbox5);
    dialog->get_vbox()->add(*hbox6);
    dialog->get_vbox()->add(*hbox7);
      
    hbox1->pack_start(*label1);
    hbox1->add(*entry1);
    
    hbox2->pack_start(*label2);
    hbox2->add(*entry2);

    hbox3->pack_start(*label3);
    hbox3->add(*entry3);

    hbox4->pack_start(*label4);
    hbox4->add(*entry4);

    hbox5->pack_start(*label5);
    hbox5->add(*entry5);

    hbox6->pack_start(*label6);
    hbox6->add(*entry6);

    hbox7->pack_start(*label7);
    hbox7->add(*entry7);
    
    dialog->get_vbox()->show_all();
    
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK",1);
    dialog->set_default_response(1);
    
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())
        Gtk::Main::iteration();
   
    if(result == 1)
		liv->create_new_music(new Music_Album(stoi(entry1->get_text()), entry2->get_text(), entry3->get_text(), entry4->get_text(), stoi(entry5->get_text()), entry6->get_text(), Dialogs::GetActorsFromString(entry7->get_text())));
    
    delete entry1;
    delete entry2;
    delete entry3;
    delete entry4;
    delete entry5;
    delete entry6;
    delete entry7;
    delete label1;
    delete label2;
    delete label3;
    delete label4;
    delete label5;
    delete label6;
    delete label7;
    delete hbox1;
    delete hbox2;    
    delete hbox3;    
    delete hbox4;    
    delete hbox5;    
    delete hbox6;
    delete hbox7;
    delete dialog;
    
    return;
 
}

void Dialogs::create_dialogTV(Library* liv)
{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Create Television Show Series");
    
    Gtk::Box *hbox1 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox2 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox3 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox4 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox5 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox6 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox7 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);

    Gtk::Label *label1 = new Gtk::Label("ID: ");
    Gtk::Label *label2 = new Gtk::Label("Call Number: ");
    Gtk::Label *label3 = new Gtk::Label("Title: ");
    Gtk::Label *label4 = new Gtk::Label("Genre: ");
    Gtk::Label *label5 = new Gtk::Label("Release year: ");
    Gtk::Label *label6 = new Gtk::Label("Producer: ");
    Gtk::Label *label7 = new Gtk::Label("Directors: ");
    
    Gtk::Entry *entry1 = new Gtk::Entry();
    entry1->set_text("");
    entry1->set_max_length(50);
    
    Gtk::Entry *entry2 = new Gtk::Entry();
    entry2->set_text("");
    entry2->set_max_length(50);
    
    Gtk::Entry *entry3 = new Gtk::Entry();
    entry3->set_text("");
    entry3->set_max_length(50);

    Gtk::Entry *entry4 = new Gtk::Entry();
    entry4->set_text("");
    entry4->set_max_length(50);

    Gtk::Entry *entry5 = new Gtk::Entry();
    entry5->set_text("");
    entry5->set_max_length(50);

    Gtk::Entry *entry6 = new Gtk::Entry();
    entry6->set_text("");
    entry6->set_max_length(50);
    
    Gtk::Entry *entry7 = new Gtk::Entry();
    entry6->set_text("");
    entry6->set_max_length(50);
    
    dialog->get_vbox()->pack_start(*hbox1);
    dialog->get_vbox()->add(*hbox2);
    dialog->get_vbox()->add(*hbox3);
    dialog->get_vbox()->add(*hbox4);
    dialog->get_vbox()->add(*hbox5);
    dialog->get_vbox()->add(*hbox6);
    dialog->get_vbox()->add(*hbox7);
      
    hbox1->pack_start(*label1);
    hbox1->add(*entry1);
    
    hbox2->pack_start(*label2);
    hbox2->add(*entry2);

    hbox3->pack_start(*label3);
    hbox3->add(*entry3);

    hbox4->pack_start(*label4);
    hbox4->add(*entry4);

    hbox5->pack_start(*label5);
    hbox5->add(*entry5);

    hbox6->pack_start(*label6);
    hbox6->add(*entry6);

    hbox7->pack_start(*label7);
    hbox7->add(*entry7);
    
    dialog->get_vbox()->show_all();
    
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK",1);
    dialog->set_default_response(1);
    
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())
        Gtk::Main::iteration();
   
    if(result == 1)
		liv->create_new_tv(new Television_Show_Season(stoi(entry1->get_text()), entry2->get_text(), entry3->get_text(), entry4->get_text(), stoi(entry5->get_text()), entry6->get_text(), Dialogs::GetActorsFromString(entry7->get_text())));
    
    delete entry1;
    delete entry2;
    delete entry3;
    delete entry4;
    delete entry5;
    delete entry6;
    delete entry7;
    delete label1;
    delete label2;
    delete label3;
    delete label4;
    delete label5;
    delete label6;
    delete label7;
    delete hbox1;
    delete hbox2;    
    delete hbox3;    
    delete hbox4;    
    delete hbox5;    
    delete hbox6;    
    delete hbox7; 
    delete dialog;
    
    return;
 
}

void Dialogs::create_dialogLibrarian(Library* liv)
{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Create Librarian");
    
    Gtk::Box *hbox1 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox2 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);

    Gtk::Label *label1 = new Gtk::Label("Name: ");
    Gtk::Label *label2 = new Gtk::Label("ID: ");
    
    Gtk::Entry *entry1 = new Gtk::Entry();
    entry1->set_text("");
    entry1->set_max_length(50);
    
    Gtk::Entry *entry2 = new Gtk::Entry();
    entry2->set_text("");
    entry2->set_max_length(50);
    
    dialog->get_vbox()->pack_start(*hbox1);
    dialog->get_vbox()->add(*hbox2);
      
    hbox1->pack_start(*label1);
    hbox1->add(*entry1);
    
    hbox2->pack_start(*label2);
    hbox2->add(*entry2);
    
    dialog->get_vbox()->show_all();
    
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK",1);
    dialog->set_default_response(1);
    
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())
        Gtk::Main::iteration();
   
    if(result == 1)
		liv->create_new_librarian(new Librarian(entry1->get_text(), stoi(entry2->get_text())));
    
    delete entry1;
    delete entry2;
    delete label1;
    delete label2;
    delete hbox1;
    delete hbox2;    
    delete dialog;
    
    return;
 
}

void Dialogs::create_dialogCustomer(Library* liv)
{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Create Customer");
    
    Gtk::Box *hbox1 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox2 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox3 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);
    Gtk::Box *hbox4 = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0);

    Gtk::Label *label1 = new Gtk::Label("Name: ");
    Gtk::Label *label2 = new Gtk::Label("ID: ");
    Gtk::Label *label3 = new Gtk::Label("Phone: ");
    Gtk::Label *label4 = new Gtk::Label("Email: ");
    
    Gtk::Entry *entry1 = new Gtk::Entry();
    entry1->set_text("");
    entry1->set_max_length(50);
    
    Gtk::Entry *entry2 = new Gtk::Entry();
    entry2->set_text("");
    entry2->set_max_length(50);
    
    Gtk::Entry *entry3 = new Gtk::Entry();
    entry3->set_text("");
    entry3->set_max_length(50);

    Gtk::Entry *entry4 = new Gtk::Entry();
    entry4->set_text("");
    entry4->set_max_length(50);
    
    dialog->get_vbox()->pack_start(*hbox1);
    dialog->get_vbox()->add(*hbox2);
    dialog->get_vbox()->add(*hbox3);
    dialog->get_vbox()->add(*hbox4);
      
    hbox1->pack_start(*label1);
    hbox1->add(*entry1);
    
    hbox2->pack_start(*label2);
    hbox2->add(*entry2);

    hbox3->pack_start(*label3);
    hbox3->add(*entry3);

    hbox4->pack_start(*label4);
    hbox4->add(*entry4);
    
    dialog->get_vbox()->show_all();
    
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK",1);
    dialog->set_default_response(1);
    
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())
        Gtk::Main::iteration();
   
    if(result == 1)
		liv->create_new_customer(new Customer(entry1->get_text(), stoi(entry2->get_text()), stoi(entry3->get_text()), entry4->get_text()));
    
    delete entry1;
    delete entry2;
    delete entry3;
    delete entry4;
    delete label1;
    delete label2;
    delete label3;
    delete label4;
    delete hbox1;
    delete hbox2;    
    delete hbox3;    
    delete hbox4;    
    delete dialog;
    
    return;
 
}

vector<string> Dialogs::GetActorsFromString(string s)
{
    std::vector<string> vect;
    std::stringstream ss(s);
    string str;

    while (ss >> str)
    {
        vect.push_back(str);

        if (ss.peek() == ',')
            ss.ignore();
    }

    return vect;    
}