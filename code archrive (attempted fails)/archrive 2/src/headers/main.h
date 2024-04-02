#ifndef MAIN_H
#define MAIN_H

/* ACCESS FOR WINDOWS  */
#ifdef _WIN32
#include <io.h>
#define F_OK 0
#define R_OK 1
#define access _access
#endif

/* HEADER FILE FOR UNIX  */
#ifdef __unix__
#include <unistd.h>
#endif

/* Include required standard library headers. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <search.h>

/* Define system constants.
 * Throughout this program columns and rows are saved as type integers. 
 * Integer range: -32767 to 32767.
 * THe program will not be able to handle images bigger than 32767 x 32767
 * Therefore, an integer can hold 5 digits within that range.
 * Hence, 32 BUFFER size should be sufficient to read rows and columns line.
 */
#define MAX_BUFFER_SIZE 8

/* Include subsystem headers. */
#include "read.h"

#endif
