#ifndef PETTO
#define PETTO

#define MAXSTRESS (5)

char inputChar( void );
void printSelect( void );
void printMood( int );
void printPettoWalk( int * );
void printPettoWalkImage( void );
void printPettoDef( void );
void printPettoCry( void );
void printPettoAgr( void );
void printSpace( int );
void printPettoWalkType( char *arr[], char *chr[], int cnt );
void printPettoAgrImage( int );

enum {
	WALK = '1',
	NOP,
	END
};

#endif

