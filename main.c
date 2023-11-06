/*
**
** PROGRAMMER'S NAME:  Brian W. Basista
**
*/
#include <stdint.h>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <float.h>

#include "llaeceftools.h"

using namespace std;


int
main( int    argc,
      char** argv,
      char** envp )
{
	int        opt        = 0;
	char*      inFileName = NULL;
        //LAAToECEF* pLlaToEcef = NULL;
        LlaEcefTools* llaEcefTools = NULL;

        printf( "long double %d\n", LDBL_DIG );

	while ( ( opt = getopt(argc,argv,"f:") ) != EOF ) {
		switch (opt) {
			/* -------------------------------------------------- */
			case 'f':			/* */
				inFileName = optarg;
				break;
		}
	}

        if ( inFileName == NULL )
        {
		printf( "Usage: getVelocity -f <filename>\n" );
                exit( -1 );
    	}

        printf( "Valid file - %s\n", inFileName );

        llaEcefTools = new LlaEcefTools( inFileName );

        delete llaEcefTools;

	return 0;
}
