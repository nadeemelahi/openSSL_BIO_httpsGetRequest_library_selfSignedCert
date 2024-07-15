/*
 * author: Nadeem Elahi
 * nadeem.elahi@gmail.com
 * nad@3deem.com
 * license: gpl v3
 */
# include <stdio.h>
# include <stdlib.h>

# include  "openssl/bio.h"

void connect2host ( BIO *bio , char *argv [ ] ) {

	char hostNportBuf[200] = {0};
	char *hostNport = hostNportBuf;

	sprintf( hostNport , "%s:443" , argv[1] ) ;
		
	BIO_set_conn_hostname ( bio , hostNport ) ;
	printf("BIO_set_conn_hostname() CHECK\n");


	int ret = BIO_do_connect ( bio ) ;
	if ( ret < 1 ) {
		fprintf ( stderr , "BIO_do_connect() error" );
		exit ( 1 ) ;
	}

	printf("BIO_do_connect () CHECK\n");
}
