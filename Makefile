FUNCTIONS_C = functions.c
MAIN_C = main.c
CC = gcc
CFLAGS = -Wall -Werror

all : solve

functions.o : $(FUNCTIONS_H) $(FUNCTIONS_C)
	$(CC) -c -o $@ $(FUNCTIONS_C)

main.o : $(MAIN_C) $(FUNCTIONS_H)
	$(CC) -c -o $@ $(MAIN_C)

solve : functions.o main.o
	$(CC) $(CFLAGS) -o $@ main.o functions.o
	@echo "Done !"

clean :
	rm -f *.o
	rm -f *~
	rm -rf solve
	cd grilles_resolues && rm res.txt

.PHONY : all solve clean
