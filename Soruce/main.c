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
		printf("�X�g���X : %d\n", stress);
		printMood( stress );		/*�X�g���X�ɉ����A�@���̏�Ԃ��o��*/
		printSelect();
		if(stress == MAXSTRESS){	/*�X�g���X��5�̂Ƃ��A�v���O�����I��*/
			break;
		}

		ch = inputChar();
		
		switch(ch){
			case WALK:
				printPettoWalk(&stress);	/*��������*/
				break;
			case NOP:
				stress++;	/*�X�g���X�����Z����*/
				break;
			case END:
				loopEnd = 1;
				break;
		}
	}
	printf("�L�[���͂ŏI��\n");
	getch();
	
	return 0;
}

