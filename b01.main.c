/*
 * author: Nadeem Elahi
 * nadeem.elahi@gmail.com
 * nad@3deem.com
 * license: gpl v3
 */
/*
 * HOW TO
 *
 * Must make a self signed cert:
 *
 * TrustStore.pem
 *
 * $openssl req -new -x509 -days 365 -noenc 
 *	    -out ./TrustStore.pem 
 *	    -keyout ./local.key
 *	    
 * Compiling:
 *
 * gcc -lssl -lcrypto b01.main.c
 *
 *
 * Running:
 *
 * ./a.out 3deem.com /
 * 
 * or
 *
 * ./a.out 3deem.com /html5/js-templating/index.html
 *
 * No buffer read looping included, just does 1 read of max 1024 MB
 *
 */
# include <stdio.h>
# include <stdlib.h>

# include  "openssl/bio.h"
# include  "openssl/ssl.h"

SSL_CTX * ssl_init( void ) ;
void connect2host( BIO *bio , char *argv[] ) ;
void getRequest( BIO *bio , char * argv [ ] ) ;
void getResponse( BIO *bio ) ;

int main ( int argc , char * argv [ ] ) {

	if ( argc != 3 ){
		fprintf( stderr , "USAGE error\n");
		fprintf( stderr , "     $./a.out 3deem.com / \n");
		fprintf( stderr , "     $./a.out 3deem.com /webgl \n");
		exit(1);
	}

	// https://developer.ibm.com/tutorials/l-openssl/
	printf ( "main()\n" ) ;

		
        SSL_CTX *ctx = ssl_init( );
        

	BIO *bio;
	SSL *ssl;

        bio = BIO_new_ssl_connect ( ctx ) ;
	printf("BIO_new_ssl_connect () CHECK\n");

	BIO_get_ssl ( bio , ssl ) ;
	printf("BIO_get_ssl () CHECK\n");


	connect2host( bio , argv ) ;

	getRequest( bio , argv ) ;

	getResponse( bio ) ;


	// finally closing the connection
	SSL_CTX_free ( ctx ) ;
	// BIO_reset ( bio ) ; // if want to re-use for a second connection
	BIO_free_all ( bio ) ;


	return 0;


	// $man BIO_new_ssl_connect
	// client server example programs
}
