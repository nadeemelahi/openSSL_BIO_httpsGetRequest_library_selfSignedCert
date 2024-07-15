/*
 * author: Nadeem Elahi
 * nadeem.elahi@gmail.com
 * nad@3deem.com
 * license: gpl v3
 */
# include <stdio.h>
# include <stdlib.h>

# include  "openssl/ssl.h"

SSL_CTX * ssl_init( void ) {
	
	SSL_load_error_strings();
	//ERR_load_BIO_strings(); // warning: depreciated since OpenSSL 3.0
	// not needed anymore
	OpenSSL_add_all_algorithms();
	printf ( "initialized openssl() \n" );

	// find out version of your systems
	// $openssl version

	SSL_CTX *ctx ;
	ctx = SSL_CTX_new( SSLv23_client_method() );

	// etc/ssl/certs
	// create certs
	// $openssl req -new -x509 -days 365 -noenc 
	//    -out ./TrustStore.pem 
	//    -keyout ./local.key

	int ret = SSL_CTX_load_verify_locations(
			ctx, 
			"./TrustStore.pem", 
			NULL
			);

	if( !ret ) {
		fprintf ( stderr , "SSL_CTX_load_verify_locations() error" );
		exit ( 1 ) ;
	}

	printf("SSL_CTX_load_verify_locations() CHECK\n");

	return ctx;
}
