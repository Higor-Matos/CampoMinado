#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
int main (){
	int i,j=0;
	
	for(i=0;i<400;i++)
	{
		printf("%c - %d \n",i,j);
		j++;
	}
	system("pause");
}

