exec = ben.jamin
sources = $(wildcard src/*.c)
objects = $(sources: .c=.o)
flags = -g

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

install:
	make
	cp ./ben.jamin /usr/local/bin/ben

clean:
	-rm *.jamin
	-rm *.o
	-rm src/*.o
