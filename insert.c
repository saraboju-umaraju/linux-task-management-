#include	"head.h"

node* insert  ( int value , node *head ) {

		node *nod ;

		node *temp = head ;
		
		node *temp2 = head ;

		if ( !( nod = malloc ( sizeof ( node ) ) ) ) {

				printf ( "running out of memory\n" );

				exit ( EXIT_FAILURE ) ;

			}

		if ( head == NULL || head -> data > value  ) {


				nod -> data =value ;

				nod -> ptr = head ;

				head = nod ;

				return head ;

		}
		
		while( temp ){


		if(temp -> ptr == NULL || value < temp -> ptr-> data ){
				
				nod -> data =value ;

				nod ->ptr = temp ->ptr;

				temp ->ptr = nod;

				return head ;

		}
				temp = temp -> ptr;
	
		}

}
