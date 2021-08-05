CC=gcc
BIN=std_manager
OBJ =main.o admin.o student.o teacher.o  mfunc.o tools.o
STD=-std=gnu99
LIB=-lm
FLAG=-Wall -Werror -DDEBUG

all: $(OBJ)
	$(CC) -o $(BIN) $(OBJ) $(LIB)
%.o:%.c
	$(CC) $(STD) $(FLAG) -c $< -o $@
clean:
	rm -rf $(BIN) $(OBJ)
	rm -rf *~
