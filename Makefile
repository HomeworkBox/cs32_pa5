all: main.cpp screen.h tui.h tui.cpp
	g++ -g3 -O0 -Wall main.cpp tui.cpp -o main

screen-example: screen-example.cpp screen.h
	g++ -g -O0 -Wall screen-example.cpp -o screen-example

clean:
	rm -f ./main ./screen-example
