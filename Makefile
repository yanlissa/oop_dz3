all: dz4

%.o: %.cpp *.h Makefile
	g++ -c $< -o $@

dz4: Linear.o Square.o dz4.o
	g++ -o $@ $^

clean:
	dz4 rm *.o

test: all
	./dz4
