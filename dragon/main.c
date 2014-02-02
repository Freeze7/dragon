#include <stdio.h>
#include <SDL2/SDL.h>

int main( int argc, char** argv )
{

	/* initialise SDL */
	printf( "initialising SDL...\n" );
	if( SDL_Init( SDL_INIT_EVERYTHING ) )
	{
	    fprintf( stderr, "\nfailed to initialise SDL: %s\n", SDL_GetError() );
	    return -1;
	}

	/* de-initialise SDL */
	printf( "shutting down SDL...\n" );
	SDL_Quit();
	return 0;
}
