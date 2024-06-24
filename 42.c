#include <stdio.h>

int main(int argc,char *argv[]){
	char dzialka[51][31][31]; char rdzialka[51][31][31]; char line[30]; int counter=0;
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
	//rev
	for(int i=0; i<50; i++){
		for(int j=0; j<30; j++){
			for(int k=0; k<30; k++){
				rdzialka[i][j][k]=dzialka[i][29-j][29-k];
			}
		}
	}
	int takieSame=0;
	for(int r=0; r<50; r++) {
		for(int i=0; i<50; i++){
			for(int j=0; j<30; j++){
				for(int k=0; k<30; k++){
					if(rdzialka[r][j][k]==dzialka[i][j][k]){
						takieSame++;
					}
				}
			}
			if(takieSame==900){	
				printf("Dla odwrotnosci %d i obrazka %d\n",r+1,i+1);
			}
			takieSame=0;
		}
	}
	return 0;
}
