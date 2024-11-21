CC=gcc
CFLAGS=-lm -Wall

DEPS= jogo.h jogador.h jogada.h tabuleiro.h

OBJ= jogo.o jogador.o jogada.o tabuleiro.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	echo "Compilado!"
