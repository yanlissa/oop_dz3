all: dz3

%.o: %.cpp *.h Makefile
	g++ -c $< -o $@

dz3: Linear.o Square.o Application.o dz3.o
	g++ -o $@ $^

clean:
	rm dz3 *.o

test: all
	cat test_input.txt | ./dz3
