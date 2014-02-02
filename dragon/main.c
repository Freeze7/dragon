#include <stdio.h>
#include <SDL2/SDL.h>
#include <logger.h>

static const unsigned int screenWidth = 800;
static const unsigned int screenHeight = 600;
static const char* screenTitle = "Dragon";

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

	/* open render window */
	SDL_Window* mainWindow = SDL_CreateWindow( screenTitle, 100, 100, screenWidth, screenHeight, SDL_WINDOW_SHOWN );
	if( !mainWindow )
	{
		log_error( log, "Failed to open main window" );
		return -1;
	}
	SDL_Renderer* mainRenderer = SDL_CreateRenderer( mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	if( !mainRenderer )
	{
		log_error( log, "Failed to get renderer" );
		return -1;
	}

	/* clean up */
	SDL_DestroyRenderer( mainRenderer );
	SDL_DestroyWindow( mainWindow );

	/* de-initialise SDL */
	log_info( log, "shutting down SDL" );
	SDL_Quit();

	/* close log */
	log_close( log );

	return 0;
}
