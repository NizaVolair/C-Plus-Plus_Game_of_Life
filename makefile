PROGS := life 

all: $(PROGS)


Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp

life: Game.o
	g++ -g Life.cpp Game.o -o life

clean:
	rm -f $(PROGS) *.o *~
