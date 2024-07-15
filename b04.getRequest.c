/*
 * author: Nadeem Elahi
 * nadeem.elahi@gmail.com
 * nad@3deem.com
 * license: gpl v3
 */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include  "openssl/bio.h"
# include  "openssl/ssl.h"

void getRequest( BIO *bio , char * argv [ ] ) {


	char getBuf[200] = {0};
	char *get = getBuf;

	sprintf ( 
			get , 
			"GET %s HTTP/1.1\r\nHost: %s\r\n\r\n" , 
			argv[2] ,
			argv[1] 
		);

	int ret =  BIO_write ( bio , get , strlen ( get ) ); 

	if ( ret < 1 ) {
		fprintf ( stderr , "BIO_write() error" );
		exit ( 1 ) ;
	}

	printf ( "BIO_write() CHECK\n" );

}
