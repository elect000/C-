# Makefile
CC = g++  
CPPFLAG = -O2 -Wall -Werror -c -o
EXE = Human.exe
OBJGROUP= Human.out
.PHONY: all
$(EXE):
	$(CC) -o ${EXE} Human.cpp

.PHONY:clean
clean:
	rm -f *.out
	rm -f *.o
run:
	./${EXE}
