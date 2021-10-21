#ifndef ROTATION_H
#define ROTATION_H

#include <stdlib>
#include <SDL.h>

void init_sdl();
SDL_Surface* load_image(char *path);
SDL_Surface* display_image(SDL_Surface *img);
void wait_for_keypressed();
void SDL_FreeSurface(SDL_Surface *surface);
SDL_Surface* rotozoomSurface(SDL_Surface* image, double angle, double zoom, double smoth);
int main();

#endif