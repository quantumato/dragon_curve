CC = gcc
CFLAGS = -g -O3 -Wall
DEPS=dragon_curve.h matrix.h
OBJ = dragon_curve.o
LIB = -lm

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

dragon_curve: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIB)


