#include <stdio.h>
#include <SDL2/SDL.h>
#include <logger.h>

int main( int argc, char** argv )
{

	/* open log */
	LOG log = log_open( "log.log" );

	/* initialise SDL */
	log_info( log, "initialising SDL" );
	if( SDL_Init( SDL_INIT_EVERYTHING ) )
	{
	    log_error( log, "failed to initialise SDL" );
	    return -1;
	}

	/* de-initialise SDL */
	log_info( log, "shutting down SDL" );
	SDL_Quit();

	/* close log */
	log_close( log );

	return 0;
}
