#include <stdio.h>

int main(int argc,char *argv[]){
	char dzialka[51][31][31]; char line[30]; int counter=0;
	char pusher[31];
	FILE *fp=fopen("dzialki.txt","rw");
	if(fp==NULL){
		printf("Nie mozna otworzyc!\n");
		return -1;
	}
	
	for(int i=0; i<50; i++){
		for(int j=0; j<30; j++){
			fscanf(fp,"%s",line);
			for(int k=0; k<30; k++){
				dzialka[i][j][k]=line[k];
			}
		}
	}
	int trawa=0; int inne=0;
	for(int i=0; i<50; i++){
		for(int j=0; j<30; j++){
			for(int k=0; k<30; k++){
				if(dzialka[i][j][k]=='*'){
					trawa++;
				} 
			}
		}
		if(trawa>=630){
			counter++;
		}
		trawa=0;
	}
	printf("Ilosc takich dzialek:%d\n",counter);
	return 0;
}
