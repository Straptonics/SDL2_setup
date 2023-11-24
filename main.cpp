#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 1000, HEIGHT = 800;

int main( int argc, char *argv[] )
{
    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *window = SDL_CreateWindow( "this is my", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );

    if ( NULL == window ){
        std::cout << "Could not create window: " << SDL_GetError( ) << std::endl;
        return 1;
    }
    SDL_Event windowEvent;
    bool running = true;
    while (running)
    {
        if ( SDL_PollEvent( &windowEvent ) )
        {
            if ( SDL_QUIT == windowEvent.type ){
               running = false;
               break; 
            }
        }
    }

    SDL_DestroyWindow( window );
    SDL_Quit( );

    return EXIT_SUCCESS;
}
