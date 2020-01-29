#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "DogFunc.h"

int main(void){
	int ch, stress = 0;
	int loopEnd = 0;

	while( !loopEnd ){
		system("cls");
		printf("ストレス : %d\n", stress);
		printMood( stress );		/*ストレスに応じ、機嫌の状態を出力*/
		printSelect();
		if(stress == MAXSTRESS){	/*ストレスが5のとき、プログラム終了*/
			break;
		}

		ch = inputChar();
		
		switch(ch){
			case WALK:
				printPettoWalk(&stress);	/*犬が走る*/
				break;
			case NOP:
				stress++;	/*ストレスを加算する*/
				break;
			case END:
				loopEnd = 1;
				break;
		}
	}
	printf("キー入力で終了\n");
	getch();
	
	return 0;
}

