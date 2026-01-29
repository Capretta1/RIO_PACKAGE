CC=gcc

# -Werror:WARNINGS BECOME ERRORS
# -Wall -Wextra: FOR CATCHING BUGS EARLY
 
CFLAGS=-Wall -Wextra -Werror -std=c11 -g
TARGET=RIO_PACKAGE
SRC=cpfile.c
OBJ=$(SRC:.c=.o)


all:$(TARGET)

# $@: TARGET NAME: RIO_PACKAGE
# $^: ALL DEPENDECIES cpfile.o 
$(TARGET):$(OBJ)
	$(CC) $(CFLAGS) -o $@ $^


%.o: %.c rioPackage.h
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f $(OBJ) $(TARGET)


.PHONY: all clean


