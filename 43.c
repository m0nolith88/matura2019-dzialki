#include <stdio.h>
#include <stdbool.h>

int main(int argc,char *argv[]){
	char dzialka[51][31][31]; char line[30]; int counter=0;
	char pusher[31];
	FILE *fp=fopen("dzialki.txt","rw");
	if(fp==NULL){
		printf("Nie mozna otworzyc!\n");
		return -1;
	}
	
	for(int i=0; i<51; i++){
		for(int j=0; j<30; j++){
			fscanf(fp,"%s",line);
			for(int k=0; k<30; k++){
				dzialka[i][j][k]=line[k];
			}
		}
	}
	int dlugosc=0;bool bok=false; int maxDl=0; int nrMax;
	for(int m=0; m<51; m++){	
		for(int l=0; l<30; l++){
			for(int j=0; j<l; j++){
				for(int k=0; k<l; k++){
					if(dzialka[m][j][k]=='X' && bok==false){
						bok=true;
						dlugosc=l-1;
					}
				}
			}
		}
		bok=false;
		if(dlugosc>maxDl){
			maxDl=dlugosc;
			nrMax=m;
		}
		dlugosc=0;
	}
	printf("Max %d dla %d\n",maxDl,nrMax+1);
	return 0;
}
