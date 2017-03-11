/***********************Student Name: Benjamin McConville
************************Date: 2014-11-03
************************Assignment 3
************************Filename: q2.c*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*passes the array through and checks and swaps then returns the array*/
void downHeap(int a[],int root, int bottom);


int main(){
	
	FILE* inFile;
    char* outFile=malloc(sizeof(char)*35);
	int list[20][10];
	int newList[20][10];
	int listCompare[20][2];
    int checkSum[20];
	int sort[20];
	int i=0,j=0,k;

	/*opens file*/
	inFile=fopen("f1.dat", "r");

    /*gets line and tokenizes the values putting them in an array*/
	for (i = 0; i < 20; i++){
        fgets(outFile,35,inFile);
        list[i][j]=atoi(strtok(outFile, " "));
        j++;

        for (j = 1; j <10; j++){
            list[i][j]=atoi(strtok(NULL, " "));
        }
        j=0;/*for when it is called again since for the first strtok it has to use outFile*/
	}

    /*sets an array of the key values and an array of key values with their positions
     *in the original list*/
    for (i = 0; i < 20; i++){
        checkSum[i]=list[i][0]+list[i][1]+list[i][2];
		listCompare[i][0]=i;
		listCompare[i][1]=checkSum[i];
    }

    /*calling of the down heap for half the array size -1*/
    for (k = 9; k >= 0; k--){
        downHeap(checkSum,k,19);
    }

    /*checks for the the position of the key in the original array and sets those positions
     *in an array*/
	for(i = 0; i < 20; i++){
		for(j = 0; j < 20; j++){
			if(listCompare[j][1]==checkSum[i])
				sort[i]=listCompare[j][0];
		}
	}
	
	/*creates a new list with the values of the original which has the new order*/
	for(i = 0; i < 20; i++){
		for(j = 0; j < 10; j++){
			newList[i][j]= list[sort[i]][j];
		}
	}
	
    /*Prints out the list*/
	for (i = 0; i < 20; i++){
        for (j = 0; j <10; j++){
            printf("%2d ", newList[i][j]);
        }
        printf("\n");
	}

    fclose(inFile);
    free(outFile);

return 0;
}

/*http://www.codebeach.com/2008/09/sorting-algorithms-in-c.html*/
/*check for minvalue instead so its a downheap*/
void downHeap(int a[],int root, int bottom)
{
     int minchild, temp, child;
     while (root*2 < bottom){

          child = root * 2 + 1;

          if (child == bottom){
               minchild = child;
          }
          else{
               if (a[child] < a[child + 1])
                    minchild = child;
               else
                    minchild = child+1;
          }

          if (a[root] > a[minchild]){
               temp = a[root];
               a[root] = a[minchild];
               a[minchild] = temp;
          }
          else
              return;

          root = minchild;
     }
}





