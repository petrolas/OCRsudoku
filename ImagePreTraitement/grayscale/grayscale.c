#include <err.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "pixel_operations.h"

void init_sdl()
{
    // Init only the video part.
    // If it fails, die with an error message.
    if(SDL_Init(SDL_INIT_VIDEO) == -1)
        errx(1,"Could not initialize SDL: %s.\n", SDL_GetError());
}

SDL_Surface* load_image(char *path)
{
    SDL_Surface *img;

    // Load an image using SDL_image with format detection.
    // If it fails, die with an error message.
    img = IMG_Load(path);
    if (!img)
        errx(3, "can't load %s: %s", path, IMG_GetError());

    return img;
}

SDL_Surface* display_image(SDL_Surface *img)
{
    SDL_Surface *screen;

    // Set the window to the same size as the image
    screen = SDL_SetVideoMode(img->w, img->h, 0, SDL_SWSURFACE|SDL_ANYFORMAT);
    if (screen == NULL)
    {
        // error management
        errx(1, "Couldn't set %dx%d video mode: %s\n",
                img->w, img->h, SDL_GetError());
    }

    // Blit onto the screen surface
    if(SDL_BlitSurface(img, NULL, screen, NULL) < 0)
        warnx("BlitSurface error: %s\n", SDL_GetError());

    // Update the screen
    SDL_UpdateRect(screen, 0, 0, img->w, img->h);

    // return the screen for further uses
    return screen;
}

void wait_for_keypressed()
{
    SDL_Event event;

    // Wait for a key to be down.
    do
    {
        SDL_PollEvent(&event);
    } while(event.type != SDL_KEYDOWN);

    // Wait for a key to be up.screen_surface=
    do
    {
        SDL_PollEvent(&event);
    } while(event.type != SDL_KEYUP);
}

void SDL_FreeSurface(SDL_Surface *surface);

int main()
{
    SDL_Surface* image_surface;

    init_sdl();

    image_surface = load_image("my_image.jpg");

    Uint8 r, g, b, average;
    Uint32 pixel;
    for(int i = 0;i<image_surface->w;i++)
    {
        for(int j = 0;j<image_surface->h;j++)
        {
            pixel = get_pixel(image_surface, i, j);
            SDL_GetRGB(pixel, image_surface->format, &r, &g, &b);
            average = (0.3*r + 0.59*g + 0.11*b);
            
            pixel = SDL_MapRGB(image_surface->format, average,average,average);
            put_pixel(image_surface, i, j, pixel);
        }
    }
    SDL_SaveBMP(image_surface, "my_image_grayscale.bmp");


    SDL_FreeSurface(image_surface);

    if (image_surface == load_image("my_image_grayscale.bmp"))
    {
        printf("Image rotated succefuly \n");
        return 0;
    }
    else{
        return 1;
    }
}
