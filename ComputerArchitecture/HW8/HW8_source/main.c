#include <stdio.h>
#include <stdlib.h>

extern void matrix(int (*A)[], int (*B)[], int (*C)[], int *Array_size);

int main(){
	int Array_size[3];
	int idx;
	int index = 3; 
	int i = 0 ;
	int j = 0 ;
	int k = 0 ;
	int** A;
	int** B;
	int** C;
	
	idx = 0;
	printf("\nInput values of s,u,v : ");
	while(idx < 3) {
		Array_size[idx] = getchar() - '0';
		idx++;
	}
	getchar();
	
	A = (int**)malloc(sizeof(int) * Array_size[0]);
	for(idx = 0; idx < Array_size[0]; idx++) {
		A[idx] = (int*)malloc(sizeof(int) * Array_size[1]);
	}
	
	B = (int**)malloc(sizeof(int) * Array_size[1]);
	for(idx = 0; idx < Array_size[1]; idx++) {
		B[idx] = (int*)malloc(sizeof(int) * Array_size[2]);
	}
	
	C = (int**)malloc(sizeof(int) * Array_size[0]);
	for(idx = 0; idx < Array_size[0]; idx++) {
		C[idx] = (int*)malloc(sizeof(int) * Array_size[2]);
	}
	
	printf("\nInput value of A : ");
	for(i=0; i < Array_size[0]; i++){
		for(j=0; j < Array_size[1]; j++){       
			A[i][j] = getchar()-'0';
		}
	}
	j=0; i=0;
	getchar();
		
	printf("\nInput value of B : ");
	for(j=0; j < Array_size[1]; j++){
		for(k=0; k < Array_size[2]; k++){       
			B[j][k] = getchar()-'0';
		}
	}
	k=0; j=0;	
		
	printf("\nArray A \n");
	for(i=0; i < Array_size[0]; i++){
		for(j=0; j < Array_size[1]; j++){  
		printf("%d ",A[i][j]);
		}
		printf("\n");	
	}
	i=0;
	j=0;
		
	printf("Array B \n");
	for(j=0; j < Array_size[1]; j++){
		for(k=0; k < Array_size[2]; k++){   
		printf("%d ",B[j][k]);
		}
		printf("\n");	
	}
	j=0;
	k=0;
				
	matrix( A, B, C, Array_size);
		
	printf("Array C after Operating : \n");
	for(i=0; i < Array_size[0]; i++){
		for(k=0; k < Array_size[2]; k++){  
		printf("%d ",C[i][k]);
		}
		printf("\n");	
	}
	
	return 0;
}
