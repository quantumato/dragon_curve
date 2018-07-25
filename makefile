CC = g++
CFLAGS = -g -O -Wall
DEPS=dragon_curve.hpp matrix.hpp image.hpp
OBJ = dragon_curve.o image.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

dragon_curve: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


