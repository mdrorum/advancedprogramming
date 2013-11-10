#include "bots.h"
#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

int main()
{

    const int width = 100;
    const int height = 100;


    bots bots(width, height);

    bots.generate(2, 5);

    /* initialize SDL */
    SDL_Init(SDL_INIT_VIDEO);

    /* set the title bar */
    SDL_WM_SetCaption("Bots", "Bots");

    const int win_width = 500;
    const int win_height = 500;

    /* create window */
    SDL_Surface *screen =
	SDL_SetVideoMode(win_width, win_height, 0, SDL_OPENGL);

    SDL_Event event;
    bool gameover = false;

    std::function < void (void) > team_color[] = {
        []() { glColor3f(1.0f, 0.0f, 0.0); },
        []() { glColor3f(0.0f, 1.0f, 0.0); },
        []() { glColor3f(0.0f, 0.0f, 1.0); },
        []() { glColor3f(1.0f, 1.0f, 0.0); },
        []() { glColor3f(0.0f, 1.0f, 1.0); },
        []() { glColor3f(1.0f, 0.0f, 1.0); },
        []() { glColor3f(1.0f, 1.0f, 1.0); },
    };


    glViewport(0, 0, win_width, win_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    

    Uint32 previous_time = SDL_GetTicks();

    int acc_time = 0;


    // testing... doesn't work if create_bot is private
    //bots.create_bot({5, 5}, 1);
    //bots.create_bot({5, 6}, 2);
    //bot * bottie = bots.find_at({5,6});
    //bottie->try_to_do(S);

    /* message pump */
    while (!gameover) {


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

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        Uint32 current_time = SDL_GetTicks();

        Uint32 delta = current_time - previous_time;

        previous_time = current_time;

        acc_time += delta;

        if (acc_time > 1000) {

            bots.step(delta);
            acc_time = 0;
        }

        /////////////////////////////////////////
        // AI goes here
        //bots.for_each_bot([&team_color, &bots] (bot & the_bot) {
                //the_bot.try_to_do(S);
                //});
        /////////////////////////////////////////

        bots.for_each_bot([&team_color, &bots] (const bot & the_bot) {


                team_color[the_bot.get_team()]();

                // WARNING deprecated OpenGL!
                glPushMatrix();
                const bot::position & pos = the_bot.get_position();

                glTranslatef(pos.first, pos.second, 0);

                glBegin(GL_QUADS); 
                glVertex3f(0.0f, 0.0f, 0.0f);
                glVertex3f(1.0f, 0.0f, 0.0f);
                glVertex3f(1.0f, 1.0f, 0.0f);
                glVertex3f(0.0f, 1.0f, 0.0f); 
                glEnd();

                glPopMatrix();
                }
                );

        SDL_GL_SwapBuffers();
    }

    /* cleanup SDL */
    SDL_Quit();


    return 0;
}


