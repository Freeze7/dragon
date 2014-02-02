#include <stdio.h>
#include <SDL2/SDL.h>

int main()
{

    /* initialise SDL */
	if( SDL_Init( SDL_INIT_EVERYTHING ) )
	{
	    fprintf( stderr, "\nfailed to initialise SDL: %s\n", SDL_GetError() );
	    return -1;
	}

	/* de-initialise SDL */
	SDL_Quit();
	return 0;
}
