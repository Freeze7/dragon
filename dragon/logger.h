/* ----------------------------------------------------- */
/* logger.h */
/* ----------------------------------------------------- */

struct FILE;
typedef FILE* LOG;

/*!
 * @brief Opens a log file
 * Will open a log file to write to and return its FILE
 * pointer
 * @param fileName The name of the file to write to
 * @return The created log. Use this to write to later on.
 */
LOG log_open( const char* fileName );

/*!
 * @brief Logs an info message to the specified log file
 * If the log file is invalid, this function will silently
 * fail.
 * @param logFile The log file to write to
 * @param message The message to log
 */
void log_info( LOG logFile, const char* message );

/*!
 * @brief Logs a warning message to the specified log file
 * If the log file is invalid, this function will silently
 * fail.
 * @param logFile The log file to write to
 * @param message The message to log
 */
void log_warning( LOG logFile, const char* message );

/*!
 * @brief Logs an error message to the specified log file
 * Logs the user specified error message followed by an
 * error message from SDL. If the log file is invalid, this
 * function will silently fail.
 * @param logFile The log file to write to
 * @param message The message to log
 */
void log_error( LOG logFile, const char* message );

/*!
 * @brief Closes an open log file
 * If the log file is invalid, this function will silently
 * fail.
 * @param logFile The log file to close.
 */
void log_close( LOG logFile );
