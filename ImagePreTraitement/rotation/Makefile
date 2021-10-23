# Simple SDL mini Makefile

CC=gcc

CPPFLAGS= `pkg-config --cflags sdl` -MMD
CFLAGS= -Wall -Wextra -Werror -std=c99 -O3
LDFLAGS=
LDLIBS= `pkg-config --libs sdl SDL_image SDL_gfx`

OBJ = main.o pixel_operation.o rotation.o
DEP = ${OBJ:.o=.d}

all: main

main: ${OBJ}


clean:
	${RM} *.o
	${RM} *.d
	${RM} display
	${RM} grayscale
	${RM} *.bmp

# END