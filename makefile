CC = gcc
CFLAGS = -g -O3 -Wall
DEPS=dragon_curve.h matrix.h image.h
OBJ = dragon_curve.o image.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

dragon_curve: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


