/*
    (C) 2000 AROS - The Amiga Research OS
    $Id$

    Desc: Get the position in a stream
    Lang: english
*/
#include <errno.h>
#include <stdio.h>

/*****************************************************************************

    NAME */
#include <stdio.h>

	int fgetpos (

/*  SYNOPSIS */
	FILE   * stream,
	fpos_t * pos)

/*  FUNCTION
	Get the current position in a stream. This function is eqivalent
	to ftell(). However, on some systems fpos_t may be a complex
	structure, so this routine may be the only way to portably
	get the position of a stream.

    INPUTS
	stream - The stream to get the position from.
	pos - Pointer to the fpos_t position structure to fill.

    RESULT
	0 on success and -1 on error. If an error occurred, the global
	variable errno is set.

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
	fsetpos()

    INTERNALS

    HISTORY

******************************************************************************/
{
    if ( pos == NULL )
    {
	errno = EINVAL;
	return -1;
    }

    *pos = ftell (stream);

    if ( *pos < 0L )
    {
	return -1;
    }

    return 0;
} /* fgetpos */

