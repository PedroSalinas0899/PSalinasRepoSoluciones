#include <stdio.h>

int main (){
	
	printf("Ordenamiento por nucleotidos de a,g,t,c: ");
	
char secuencia[961]="gtgggggggtttatgcctttagaacagcagactactgataactccaatcctgggttgaaaatgccaagggcgccagagagccaaacgatgagcgttggaccacaaacgataaaaactcactttctccgtggggtgaaagcgattctttctggcccgtatccgccagcacttaaagttgcattcggcgcggccctaccgctgctaattggggtaattgtcctaggattgtacgtaacgcttggcgggcacagccgcaagaaagcccacgcagccgcgatagatgctttggtcgagaagcacgaagcatgctacaaggtccaagcaaagattgcacacggcaggcttgccttacagtccgctgtggtgtctgttgcggatgccagcatgcaacaactccagttcgtgcagcaaggaattctcatgtgtgtcggagagctcgacgatatgcagaagttccggacccgactggataatgaaatcagtgccatcaaccagcgaattcccagcattgtcgaggaggtaagaaaacacaccgacgatgcgcttgagtggaatcttgctagaaccaagaacattttagagggcactgaagagcgcctgaaggatatgggcaatgagttggtgcgctacctagacgatgctcgcgccctcattgaaaatgcacgtatagctgcaggatcaatgcaacacctcgttggtgatgaggtgagaaagcagcttgctgaggttctagtaaaagttgcagaagtaagtaatggctttattgcgcttaagaagagtgtatctggctatttggaaaaaagcagtggacttgttgctagggaagttagggcaatcctggatgaccgcatgcgaagcctgcggaccatgtacaaaatgtgggatgcagaacaaaactccgtagtcagcgtgtgtaccacgctccaaaaggcaagcatggaggctgccgcggtagcaagt";
	
	
	
	for(int i=0;i<961;i++){
		printf(" %c,",secuencia[i]);
		}
		printf("\n");
	
	for (int i=0;i<961;i++){
		if (secuencia[i]=='a'){
			secuencia[i]=1;
		}
		else if (secuencia[i]=='g'){
			secuencia[i]=2;
		}
		else if (secuencia[i]=='t'){
			secuencia[i]=3;
		}
		else if (secuencia[i]=='c'){
			secuencia[i]=4;
		}
	}
	
	
	int i,j;
	int aux;
	for (i=1;i<961;i++){
		j=i;
		aux=secuencia[i];
		while (j > 0 && aux < secuencia[j-1]){
			secuencia[j]=secuencia[j-1];
			j--;
		}
		secuencia[j]=aux;
	}	
		
		printf("\n"),
		printf("Secuencia ordenada:\n");
		printf("\n");
		
	for (int i=0;i<961;i++){
		if (secuencia[i]==1){
			secuencia[i]='a';
		}
		else if (secuencia[i]==2){
			secuencia[i]='g';
		}
		else if (secuencia[i]==3){
			secuencia[i]='t';
		}
		else if (secuencia[i]==4){
			secuencia[i]='c';
		}
	}
	
	for(int i=0;i<961;i++){
		printf("%c,",secuencia[i]);
		}
		printf("\n");

}
