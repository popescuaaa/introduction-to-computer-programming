//Popescu Andrei-Gabriel 313CA
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	//pentru citirea din mediul de intrare <stdin> vom folosi functia strtok care va separa numerele
	//primite de spatiile din acelasi sir de caractere si astfel vom obtine cei doi vectori <col>
	//respectiv <queen>, vectorii de regine si de coloane ale fagurelui 
	char *p, a[100][155];
	char s[1500],state,aux[250];
	char delim[] = {" "}; // delimitatorul va fi spatiu 
	int col[50],queen[155];
	int count_aux =0, count_col = 0,count_queen = 0;
	int pos,max;
	int i,j,k,l;
	
	while(fgets(s,1500,stdin)){
	p = strtok(s,delim);
	while(p){
//stocam datele preluate intr-un vector auziliar speculand faptul ca atoi va converti orice char in 0
		aux[count_aux] = atoi(p);
		
		if(*p == 'R'|| *p == 'C'){
			state = *p;
		}
		count_aux++;

		p = strtok(NULL,delim);

	}
//prelucram datele de intrare pentru otinerea celor doi vectori 
	for( i =0;i<count_aux;i++){
		if(aux[i] == 0){
		  pos = i;
		}
		
	}
	for( j=0;j<pos;j++){
			col[count_col] = aux[j];
			count_col++;
	}
	for( k = pos+1;k<count_aux;k++){
			queen[count_qeen] = aux[k];
			count_queen++;
	}

		max = col[0];
	for(l=1;l<count_col;l++){
			if(col[l] > max){
				max = col[l];
			}
	}
//dupa ce am obtinut parametrii necesari, formam o matrice, care va merge pana la (2*nr_coloane +1)*(max*2+2)
//undemax, este maximul din vectorul de celule ale fagurelui; matricea va fi initializata toata cu <space> 	
	
	for( j=0;j<2*count_col+1;j++){
			for( i =0;i<max*2 +2;i++){
				a[i][j] = 32;
			}
	}
		
		int t =0;
//fomrmarea matricei 'fagure' consta in identificare positiilor corespunzatore pentru '_',plasarea lor
//urmanad ca apoi sa completam cu '/' sau '\'
	if( state  == 'R'){
			for( j=1;j<2*count_col + 1;j+=2){
				for( i =0;i<2*col[t]+2;i+=2){
						if(((j-1)/2)%2 == 0){
							a[i][j] = 95;
						} else {
							a[i+1][j] = 95;
						}
				}
					t++;
			}

	}

					t =0;
	if( state  == 'C'){
		for( j=1;j<2*count_col + 1;j+=2){
				
				if(((j-1)/2)%2 != 0){
						for( i = 0;i<2*col[t]+1;i+=2){
							a[i][j] = 95;
						}
							t++;
						} else {
						for( i = 0;i<2*col[t]+3;i+=2){
							a[i-1][j] = 95;
						}
							t++;
						}
				}

	}
	for( i =0;i< 2*max+2;i++){
		for( j =0;j< 2*count_col +1; j++){
			if(a[i][j] == 95 && a[i+2][j] == 95){
				a[i+1][j-1] = a[i+2][j+1] = 47;
				a[i+1][j+1] = a[i+2][j-1] = 92;
			}
		}
	}
//odata 'desenat fagurele', pasarea reginelor se va face prin  cautarea coloanelor si liniilor in matricea anterioara 
	for( k=0;k<count_queen;k+=2){
	    if(state == 'R'){ //pentru fagure cu prima coloana ridicata 
	    	if(queen[k]%2 == 1){//coloana ridicata
	    		a[2*queen[k+1]-1][2*queen[k]-1] = 81;
	    	}	else{//coloana coborata 
	    		a[2*queen[k+1]][2*queen[k]-1] = 81;
	    		}
	    	}
	    	if(state == 'C'){//pentru fagure  cu prima coloana coborata
	    	if(queen[k]%2 == 1){//coloana ridicata 
	    		a[2*queen[k+1]][2*queen[k]-1] = 81;
	    	}   else{//coloana coborata 
	    		a[2*queen[k+1]-1][2*queen[k]-1] = 81;
	    	}	
				}
	    	} 
//afisam matricea completata cu regine
	    for( i =0;i< 2*max+2;i++){
			for( j =0;j< 2*count_col+1; j++){
				printf("%c",a[i][j]);
			}
			printf("\n");
			
		}
//initializam totul cu 0 pentru urmatoare citire 
	for( i=0;i<count_col;i++){
		col[i] = 0;//initializam coloanele la 0
	}
	for( j =0;j<count_queen;j++){
		queen[j] = 0;//analog pentru regine
	}
	for( k=0;k<count_aux;k++){
		aux[k] = 0;//si vectorul auxiliar de prelucrare 
	}	
	for( k=0;k<count_aux;k++){
		s[k] =0;
	}	
	count_col =0;
	count_aux =0;
	count_qeen =0;
}
return 0;
}



