all: list

stack_functions.o:
	g++ -c d_l_list_functions.cpp

stack_main.o:
	g++ -c d_l_list_main.cpp

list:	d_l_list_main.o d_l_list_functions.o
	g++ d_l_list_functions.o d_l_list_main.o -o list

clean:
	rm -rf *.o
	rm -rf -f list

