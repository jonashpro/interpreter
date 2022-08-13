CC=gcc
CFLAGS=\
		-Wall \
		-Wextra \
		-Wswitch-enum

OBJ_FILES=\
		main.o \
		utils.o \
		lexer.o \
		token.o \
		position.o \
		parser.o \
		node.o \
		interpreter.o

all: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o interpreter $(OBJ_FILES)

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

utils.o: utils.c
	$(CC) $(CFLAGS) -c -o utils.o utils.c

lexer.o: lexer.c
	$(CC) $(CFLAGS) -c -o lexer.o lexer.c

token.o: token.c
	$(CC) $(CFLAGS) -c -o token.o token.c

position.o: position.c
	$(CC) $(CFLAGS) -c -o position.o position.c

parser.o: parser.c
	$(CC) $(CFLAGS) -c -o parser.o parser.c

node.o: node.c
	$(CC) $(CFLAGS) -c -o node.o node.c

interpreter.o: interpreter.c
	$(CC) $(CFLAGS) -c -o interpreter.o interpreter.c

clean: *.o
	rm *.o

