#include "bots.h"
#include <SDL.h>

int main()
{
    Bots bots = Bots(100, 100);


    /* initialize SDL */
    SDL_Init(SDL_INIT_VIDEO);

    /* set the title bar */
    SDL_WM_SetCaption("Bots", "Bots");

    /* create window */
    SDL_Surface* screen = SDL_SetVideoMode(500, 500, 0, 0);

    SDL_Event event;
    bool gameover = 0;

    Uint32 previous_time = SDL_GetTicks();
    /* message pump */
    while (!gameover)
    {

        Uint32 current_time = SDL_GetTicks();

        bots.Step(current_time - previous_time);

        previous_time = current_time;

        /* look for an event */
        if (SDL_PollEvent(&event)) {
            /* an event was found */
            switch (event.type) {
                /* close button clicked */
                case SDL_QUIT:
                    gameover = true;
                    break;
                    /* handle the keyboard */
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                        case SDLK_q:
                            gameover = true;
                            break;
                    }
                    break;
            }
        }

        /* update the screen */
        SDL_UpdateRect(screen, 0, 0, 0, 0);
    }

    /* cleanup SDL */
    SDL_Quit();


    return 0;
}

