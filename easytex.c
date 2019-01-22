
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compilation: tcc file.c -o file 
// usage: cat file.dat | file > file.export 


#define PATH_MAX 2500
int comment = 0;
int gameover = 0;

void proc_interpreter( char *mystring )
{
    int skip = 0;

    if ( strcmp( mystring , "!end" ) == 0)  gameover = 1;
    if ( strcmp( mystring , "!EOF" ) == 0)  gameover = 1;

    if ( skip == 0 )
    if ( mystring[0] == '/' )
    if ( mystring[1] == '/' )
       skip = 1;

    if ( skip == 0 )
    if ( mystring[0] == '/' )
    if ( mystring[1] == '*' )
    {   comment = 1;  skip = 1; }

    if ( skip == 0 )
    if ( mystring[0] == '*' )
    if ( mystring[1] == '/' )
    {  comment = 0; skip = 1;  }

    if ( skip == 0 )  
     if ( comment == 0 )  
      if ( gameover == 0 )  
        printf( "%s", mystring );
}



int main()
{
        int c , co, pcc;
        char lline[PATH_MAX];  

        lline[0]='\0';
        pcc = 0; co = 0;

        c = getchar();
        while( c != EOF )
        {
           if ( c != '\n' )
              lline[pcc++]=c;

           if ( c == '\n' ) 
           {
             lline[pcc++]='\0';

             //printf( "%s", lline );
             if ( gameover == 0 )
               proc_interpreter( lline ); 

             if ( ( co == '\n' ) && ( c ==  '\n' ) )
                //printf( "<br>\n" );
                printf( "\n" );
             else
                printf( "\n" );

             lline[0]='\0';
             pcc = 0;
           }

           co = c; 
           c = getchar();
        }
	return 0;
}


