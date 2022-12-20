exec = space_invaders.out
sources = $(wildcard src/*.cpp)
objects = $(sources:.cpp=.o)
flags = -g

$(exec): $(objects)
	g++ $(objects) $(flags) -o $(exec)

%.o: %.cpp include/%.h
	g++ -c $(flags) $< -o $@

#install:
#	make
#	cp ./space_invaders.out /usr/local/bin/space_invaders


clean:
	-rm *.out
	-rm src/*.o
