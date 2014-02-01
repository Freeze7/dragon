#include <stdio.h>
#include <SDL2/SDL.h>

int main()
{
	printf( "Hello World!\n" );
	SDL_Init( SDL_INIT_EVERYTHING );
	SDL_Quit();
	return 0;
}
