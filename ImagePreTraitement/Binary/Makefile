# Simple SDL mini Makefile

CC=gcc

CPPFLAGS= `pkg-config --cflags sdl` -MMD
CFLAGS= -Wall -Wextra -Werror -std=c99 -O3
LDFLAGS=
LDLIBS= `pkg-config --libs sdl SDL_image`

all: display binary

display: display.o
binary: pixel_operations.o binary.o

binary.o: pixel_operations.h

clean:
	${RM} *.o
	${RM} *.d
	${RM} display
	${RM} binary
	${RM} *.bmp

# END
