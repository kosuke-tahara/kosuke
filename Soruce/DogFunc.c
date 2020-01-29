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
	"　　　　　 ∩＿＿_∩\n",
	"　　　　　 |ノ　　 ヽ\n",
	"　　　　　/　●　 ●|\n",
	"　 (ヽ＿／｜　(_●_)ミ\n",
	"　／　　　彡　 |∪|ミ　ワン　ワン\n",
	"`/　 ｜　　 ＼ ヽノ/\n",
	"｜　 /　　　　￣￣｜\n"
};

char *pettoCry[7] = { 
	"　　　　　　  ＿＿_\n",
	"　　　　  ⊂ノ　　 ヽ⊃\n",
	"　　　　　/　●　 ●|\n",
	"　-_-ヽ＿／｜ (_●_)ミ  \n",
	"　／　　　彡　  人 ミ　クゥーン\n",
	"`/　 ｜　　 ＼     /\n",
	" |　/　　　　 ￣￣｜\n",
};
	
char *pettoWalk[4][7] = {
	{	"～　　　～ ∩＿＿_∩ \n",
		"　ー　　　 |ノ　　 ヽ\n",
		"　　　ー　/　●　 ●| ♪\n",
		"　 (ヽ＿／｜ ﾞ(_人_)ミ\n",
		"　／　　　彡　     ミ\n",
		"`/　 ｜　　 ＼     /\n",
		"｜　 /　　　　￣￣｜\n"
	},
	
	{	"　ー　　　 ∩＿＿_∩\n",
		"　ー　～　 |ノ　　 ヽ ♪\n",
		"　～　　　/　●　 ●|\n",
		"ー (ヽ＿／｜ ﾞ(_人_)ミ\n",
		"　／　　　彡　     ミ\n",
		"`/　 ｜　　 ＼     /\n",
		"｜　 /　　　　￣￣｜\n"
},
	{	"　　　　　 ∩＿＿_∩ ♪\n",
		"～ー　　～ |ノ　　 ヽ\n",
		"　～　　～/　●　 ●|\n",
		"　 (ヽ＿／｜ ﾞ(_人_)ミ\n",
		"　／　　　彡　     ミ\n",
		"`/　 ｜　　 ＼     /\n",
		"｜　 /　　　　￣￣｜\n"
},
	{	"　　　　　 ∩＿＿_∩ 　♪\n",
		"　　～　　 |ノ　　 ヽ\n",
		"　　ー　　/　●　 ●|\n",
		"　 (ヽ＿／｜ ﾞ(_人_)ミ\n",
		"　／　　　彡　     ミ\n",
		"`/　 ｜　　 ＼     /\n",
		"｜　 /　　　　￣￣｜\n"
}
};
	
char *pettoAgr[7] = { 
	"　　　　　　  ＿＿_\n",
	"　　　　  ⊂ノ　怒 ヽ⊃\n",
	"　　　　　/　●　 ●|\n",
	"　-_-ヽ＿／｜ (_●_)ミ  \n",
	"　／　　　彡　  人 ミ\n",
	"`/　 ｜　　 ＼     /\n",
	" |　/　　　　 ￣￣｜\n",
};

char *pettoFoot[4][3] = { 
	{	" |  _／＞、(  <＿／/\n",
    	" | |   | |￣＼ |ヽ｜\n",
		" (_|   |_)　 |_) |_)\n"
},
	{	"/ _／＞、(　<＿／ /\n",
		"L/　/ ／￣＼_) ヽ｜\n",
		"　 (_/　　　　　|_)\n"
},
	{	"|__／＞、(　<＿／ /\n",
		"　 ／ ／￣＼ ＼ ＼ ＼\n",
		"　(_／　　　＼_)  ＼_)\n"
},							
	{	"/ _／＞ (　<＿／ ) |\n",
		"＼ ＼ ＼ ＼   / / /\n",
		"  ＼_)  ＼_) /_/ /_)\n"
}

};

char inputChar( void ){
	char buff[INPUTBUFF];//入力文字+改行文字+NULL文字
	
	fgets(buff, INPUTBUFF - 1 , stdin);
	if(buff[0] == '\n'){
		buff[0] = '2';
	}else{
		while(getchar()!= '\n');
	}
	
	return buff[0];
}

void printSelect( void ){
	puts("1 : 散歩 ");
	puts("2 : 何もしない ");
	puts("3 : 終了 ");
	printf("選択 : ");
}

void printSpace( int space ){
	int i ;
	
	for( i = 0 ; i < space ; i++){ /*スペースを入れる*/
		printf(" ");
	}
}

void printPettoWalkType( char *arr[], char *chr[], int cnt){
	int i, k;
	
	for( i = 0 ; i < 7 ; i++){ /*犬の上半身を表示*/
		printSpace(cnt);
		printf(arr[i]);
	}
	for( k = 0 ; k < 3 ; k++ ){/*犬の下半身を表示*/
		printSpace(cnt);
		printf(chr[k]);
	}
	Sleep(STOP_TIME);
}

void printPettoAgr( void ){
	int cnt, i;
	int footType = 0, foot = 0;
	
	for(cnt = 0 ; cnt < ESCDIST ; cnt++){	/*犬が走り去ってしまう処理*/
		system("cls");
		printPettoWalkType( pettoAgr, pettoFoot[foot++], cnt);
		if( foot == 3 ) { //足の絵を順番に表示するために初期化する
			foot = 0;
		}
	}
	system("cls");
}

void printPettoDef(void){//犬の標準時の表情を描画
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC );
	PlaySound("dog.wav", NULL, SND_FILENAME | SND_ASYNC );
	printPettoWalkType( pettoDef, pettoFoot[0], 0);	/*犬の標準絵をセット*/
}

void printPettoCry( void ){//犬の悲しい表情を描画
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC );
	PlaySound("dog_cry.wav", NULL, SND_FILENAME | SND_ASYNC );
	printPettoWalkType( pettoCry, pettoFoot[0], 0);		/*犬のストレス３の絵*/
}

void printPettoAgrImage(void){//犬の怒りの表情を描画
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC );
	PlaySound("dog_angry.wav", NULL, SND_FILENAME | SND_ASYNC );
	printPettoWalkType( pettoAgr, pettoFoot[0], 0);		/*犬のストレス４～５(怒)の絵*/
}

void printMood( int stress ){//犬の状態を描画
	if( 0 <= stress && stress <= 2 ){
		printPettoDef();
		printf("\n");
		puts("機嫌がいいです");
		
	}else if( stress == MAXSTRESS ){
		printPettoAgr();
		printf("\n");
		puts("犬は去ってしまった\n");
	}else{
		if( stress == (MAXSTRESS - 1) ){
			printPettoAgrImage();
		}else{
			printPettoCry();
		}
		printf("\n");
		puts("機嫌がよくないです");
	}
	puts("");
}

void printPettoWalkImage( int petto ){
	system("cls");
	printPettoWalkType( pettoWalk[petto], pettoFoot[petto], 0); /*犬が散歩する動作*/
	Sleep(STOP_TIME);
}

void printPettoWalk( int *stress ){
	int i = 0, k = 0;
	time_t secTimeCp = 0, secTime = 0;
	
	while( i < WALKSEC ){ 
		if( secTimeCp != secTime ){ //WALKSEC秒計測
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



