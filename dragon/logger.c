/* ----------------------------------------------------- */
/* logger.c */
/* ----------------------------------------------------- */

/* ----------------------------------------------------- */
/* include files */

#include <stdio.h>
#include <logger.h>
#include <SDL/SDL_error.h>

/* ----------------------------------------------------- */
LOG log_open( const char* fileName )
{
	LOG log;
	log = fopen( fileName, "w" );
	return log;
}

/* ----------------------------------------------------- */
void log_info( LOG logFile, const char* message )
{
	if( !logFile )
		return;
	fprintf( logFile, "[info] %s\n", message );
}

/* ----------------------------------------------------- */
void log_warning( LOG logFile, const char* message )
{
	if( !logFile )
		return;
	fprintf( logFile, "[warning] %s\n", message );
}

/* ----------------------------------------------------- */
void log_error( LOG logFile, const char* message )
{
	if( !logFile )
		return;
	fprintf( logFile, "[error] %s: %s\n", message, SDL_GetError() );
}

/* ----------------------------------------------------- */
void log_close( FILE* logFile )
{
	if( !logFile )
		return;
	fclose( logFile );
}
