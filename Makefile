make: drone_movement.o main.o
	gcc -o main_code drone_movement.o main.o
main.o: main.c drone_movement.h
	gcc -c main.c -Wall -lpthread -g 
drone_movement.o: drone_movement.c drone_movement.h
	gcc -c drone_movement.c -lm
clean:
	rm -rf *o
