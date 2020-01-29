#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define WALKSEC (5)
#define BUFFSIZE (2)
#define INPUTBUFF (BUFFSIZE + 1)
#define MAXSTRESS (5)
#define ESCDIST (20)
#define STOP_TIME (50)

char *pettoDef[7] ={
	"�@�@�@�@�@ ���Q�Q_��\n",
	"�@�@�@�@�@ |�m�@�@ �R\n",
	"�@�@�@�@�@/�@���@ ��|\n",
	"�@ (�R�Q�^�b�@(_��_)�~\n",
	"�@�^�@�@�@�c�@ |��|�~�@�����@����\n",
	"`/�@ �b�@�@ �_ �R�m/\n",
	"�b�@ /�@�@�@�@�P�P�b\n"
};

char *pettoCry[7] = { 
	"�@�@�@�@�@�@  �Q�Q_\n",
	"�@�@�@�@  ���m�@�@ �R��\n",
	"�@�@�@�@�@/�@���@ ��|\n",
	"�@-_-�R�Q�^�b (_��_)�~  \n",
	"�@�^�@�@�@�c�@  �l �~�@�N�D�[��\n",
	"`/�@ �b�@�@ �_     /\n",
	" |�@/�@�@�@�@ �P�P�b\n",
};
	
char *pettoWalk[4][7] = {
	{	"�`�@�@�@�` ���Q�Q_�� \n",
		"�@�[�@�@�@ |�m�@�@ �R\n",
		"�@�@�@�[�@/�@���@ ��| ��\n",
		"�@ (�R�Q�^�b �(_�l_)�~\n",
		"�@�^�@�@�@�c�@     �~\n",
		"`/�@ �b�@�@ �_     /\n",
		"�b�@ /�@�@�@�@�P�P�b\n"
	},
	
	{	"�@�[�@�@�@ ���Q�Q_��\n",
		"�@�[�@�`�@ |�m�@�@ �R ��\n",
		"�@�`�@�@�@/�@���@ ��|\n",
		"�[ (�R�Q�^�b �(_�l_)�~\n",
		"�@�^�@�@�@�c�@     �~\n",
		"`/�@ �b�@�@ �_     /\n",
		"�b�@ /�@�@�@�@�P�P�b\n"
},
	{	"�@�@�@�@�@ ���Q�Q_�� ��\n",
		"�`�[�@�@�` |�m�@�@ �R\n",
		"�@�`�@�@�`/�@���@ ��|\n",
		"�@ (�R�Q�^�b �(_�l_)�~\n",
		"�@�^�@�@�@�c�@     �~\n",
		"`/�@ �b�@�@ �_     /\n",
		"�b�@ /�@�@�@�@�P�P�b\n"
},
	{	"�@�@�@�@�@ ���Q�Q_�� �@��\n",
		"�@�@�`�@�@ |�m�@�@ �R\n",
		"�@�@�[�@�@/�@���@ ��|\n",
		"�@ (�R�Q�^�b �(_�l_)�~\n",
		"�@�^�@�@�@�c�@     �~\n",
		"`/�@ �b�@�@ �_     /\n",
		"�b�@ /�@�@�@�@�P�P�b\n"
}
};
	
char *pettoAgr[7] = { 
	"�@�@�@�@�@�@  �Q�Q_\n",
	"�@�@�@�@  ���m�@�{ �R��\n",
	"�@�@�@�@�@/�@���@ ��|\n",
	"�@-_-�R�Q�^�b (_��_)�~  \n",
	"�@�^�@�@�@�c�@  �l �~\n",
	"`/�@ �b�@�@ �_     /\n",
	" |�@/�@�@�@�@ �P�P�b\n",
};

char *pettoFoot[4][3] = { 
	{	" |  _�^���A(  <�Q�^/\n",
    	" | |   | |�P�_ |�R�b\n",
		" (_|   |_)�@ |_) |_)\n"
},
	{	"/ _�^���A(�@<�Q�^ /\n",
		"L/�@/ �^�P�__) �R�b\n",
		"�@ (_/�@�@�@�@�@|_)\n"
},
	{	"|__�^���A(�@<�Q�^ /\n",
		"�@ �^ �^�P�_ �_ �_ �_\n",
		"�@(_�^�@�@�@�__)  �__)\n"
},							
	{	"/ _�^�� (�@<�Q�^ ) |\n",
		"�_ �_ �_ �_   / / /\n",
		"  �__)  �__) /_/ /_)\n"
}

};

char inputChar( void ){
	char buff[INPUTBUFF];//���͕���+���s����+NULL����
	
	fgets(buff, INPUTBUFF - 1 , stdin);
	if(buff[0] == '\n'){
		buff[0] = '2';
	}else{
		while(getchar()!= '\n');
	}
	
	return buff[0];
}

void printSelect( void ){
	puts("1 : �U�� ");
	puts("2 : �������Ȃ� ");
	puts("3 : �I�� ");
	printf("�I�� : ");
}

void printSpace( int space ){
	int i ;
	
	for( i = 0 ; i < space ; i++){ /*�X�y�[�X������*/
		printf(" ");
	}
}

void printPettoWalkType( char *arr[], char *chr[], int cnt){
	int i, k;
	
	for( i = 0 ; i < 7 ; i++){ /*���̏㔼�g��\��*/
		printSpace(cnt);
		printf(arr[i]);
	}
	for( k = 0 ; k < 3 ; k++ ){/*���̉����g��\��*/
		printSpace(cnt);
		printf(chr[k]);
	}
	Sleep(STOP_TIME);
}

void printPettoAgr( void ){
	int cnt, i;
	int footType = 0, foot = 0;
	
	for(cnt = 0 ; cnt < ESCDIST ; cnt++){	/*�������苎���Ă��܂�����*/
		system("cls");
		printPettoWalkType( pettoAgr, pettoFoot[foot++], cnt);
		if( foot == 3 ) { //���̊G�����Ԃɕ\�����邽�߂ɏ���������
			foot = 0;
		}
	}
	system("cls");
}

void printPettoDef(void){//���̕W�����̕\���`��
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC );
	PlaySound("dog.wav", NULL, SND_FILENAME | SND_ASYNC );
	printPettoWalkType( pettoDef, pettoFoot[0], 0);	/*���̕W���G���Z�b�g*/
}

void printPettoCry( void ){//���̔߂����\���`��
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC );
	PlaySound("dog_cry.wav", NULL, SND_FILENAME | SND_ASYNC );
	printPettoWalkType( pettoCry, pettoFoot[0], 0);		/*���̃X�g���X�R�̊G*/
}

void printPettoAgrImage(void){//���̓{��̕\���`��
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC );
	PlaySound("dog_angry.wav", NULL, SND_FILENAME | SND_ASYNC );
	printPettoWalkType( pettoAgr, pettoFoot[0], 0);		/*���̃X�g���X�S�`�T(�{)�̊G*/
}

void printMood( int stress ){//���̏�Ԃ�`��
	if( 0 <= stress && stress <= 2 ){
		printPettoDef();
		printf("\n");
		puts("�@���������ł�");
		
	}else if( stress == MAXSTRESS ){
		printPettoAgr();
		printf("\n");
		puts("���͋����Ă��܂���\n");
	}else{
		if( stress == (MAXSTRESS - 1) ){
			printPettoAgrImage();
		}else{
			printPettoCry();
		}
		printf("\n");
		puts("�@�����悭�Ȃ��ł�");
	}
	puts("");
}

void printPettoWalkImage( int petto ){
	system("cls");
	printPettoWalkType( pettoWalk[petto], pettoFoot[petto], 0); /*�����U�����铮��*/
	Sleep(STOP_TIME);
}

void printPettoWalk( int *stress ){
	int i = 0, k = 0;
	time_t secTimeCp = 0, secTime = 0;
	
	while( i < WALKSEC ){ 
		if( secTimeCp != secTime ){ //WALKSEC�b�v��
			i++;
		}
		secTimeCp = secTime; 
		secTime = time(NULL);
		printPettoWalkImage(k++);
		if( k > 3 ){
			k = 0;
		}
	}
	*stress = 0;
}



