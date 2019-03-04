CXX= g++
CXX_FLAGS = -std=c++11
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
DEPS = saa3053_Book.h saa3053_Media.h saa3053_Video_Game.h saa3053_Bundle.h saa3053_Customer.h saa3053_Date.h saa3053_Librarian.h saa3053_Library.h saa3053_Television_Show_Season.h saa3053_Transaction.h saa3053_Movie.h saa3053_Music_Album.h saa3053_View.h saa3053_Controller.h saa3053_dialog.h
OBJ = saa3053_Book.o saa3053_Media.o saa3053_Video_Game.o saa3053_Bundle.o saa3053_Customer.o saa3053_Date.o saa3053_Librarian.o saa3053_Library.o saa3053_Television_Show_Season.o saa3053_Transaction.o saa3053_Movie.o saa3053_Music_Album.o saa3053_View.o saa3053_Controller.o saa3053_dialog.o

%.o : %.cpp $(DEPS)
	$(CXX) $(CXX_FLAGS) -c -o $@ $< $(GTKFLAGS)

main: $(OBJ)
	$(CXX) $(CXX_FLAGS) -o $@ $(OBJ) saa3053_main.cpp $(GTKFLAGS)

clean:
	rm *.o main
