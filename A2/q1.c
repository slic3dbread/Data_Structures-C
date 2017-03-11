/***********************Student Name: Benjamin McConville
************************Date: 2014-10-09
************************Assignment 2
************************Filename: q1.c*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*The struct used for all 3 link lists*/
typedef struct _linkList
{
    char* plateNumber;
    int mileage;
    int returnDate;
    char status;

    struct _linkList * next;
}List;


/*Used to malloc memory and set values in the link list*/
List* createStruct(char* plateNumber, int mileage, int returnDate, char status);
/*This is used to add the struct to the link list*/
List* add(List* root,List* new);
/*These sorts based on the perameters*/
List* sortAva(List* root, int countA);
List* sortRen(List* root, int countR);
/*These are used to remove from the list set the temp value to the removed struct and return the changed struct*/
List* removeCarA(List* root, List* temp, int returnDate);
List* removeCarRen(List* root, List* temp, int mileageChange);
List* removeCarRep(List* root, List* temp, int mileageChange);
/*Used to free the plateNumber and Struct for all the instances in the link list*/
void freeLists(List* root);
/*Used to print the values Platenumber and Mileage for the lists*/
void printList(List* root);

int main()
{
    char userInput;
    FILE* inFile;
    char* outFile=malloc(sizeof(char)*21);
	List* rootAva=NULL;/*These are the three link lists*/
    List* rootRen=NULL;
    List* rootRep=NULL;
    List* temp=NULL;/*temp struct are used to pass through functions to add or remove from the lists*/
    char* plateNumber;
    int  mileage, returnDate;/*YYMMDD*/
	char status;
	char* type;
	int countA=0,countR=0,mileageChange=0;



    /*Gets files information to be put into the list*/
    inFile=fopen("data.txt", "r+");


     while (!feof(inFile)) 
     {

         fgets(outFile,30,inFile);
         plateNumber=strtok(outFile, ",");
         mileage=atoi(strtok(NULL, ","));
         returnDate=atoi(strtok(NULL, ","));
         type=strtok(NULL, ",");
		 status=type[0];

         
        /*Checks first to see if the list has been created, then which case it is. 
         *After that when it loops back it adds to the original list*/
		if(rootAva==NULL){
			if(status=='a'){
				rootAva=createStruct(plateNumber,mileage,returnDate,status);
                countA++;
            }
		}
		else if(rootAva!=NULL){	
			if(status=='a'){
				temp=createStruct(plateNumber,mileage,returnDate,status);
				rootAva=add(rootAva,temp);
                countA++;
				}
		}
		
		if(rootRen==NULL){
			if(status=='d'){
				rootRen=createStruct(plateNumber,mileage,returnDate,status);
                countR++;
            }
		}
		else if(rootRen!=NULL){	
			if(status=='d'){
				temp=createStruct(plateNumber,mileage,returnDate,status);
				rootRen=add(rootRen, temp);
                countR++;
				}
		}
		
		if(rootRep==NULL){
			if(status=='r'){
				rootRep=createStruct(plateNumber,mileage,returnDate,status);
            }
		}
		else if(rootRep!=NULL){	
			if(status=='r'){
				temp=createStruct(plateNumber,mileage,returnDate,status);
				rootRep=add(rootRep, temp);
				}
		}
		
     }

     rootAva=sortAva(rootAva, countA);
     rootRen=sortRen(rootRen, countR);

    do 
    {
        

        printf("********************************************************************\n");
        printf("Welcome to the car rental company choose from the following choices:\n");
        printf("********************************************************************\n");
        printf("1. add a new car to the available-for-rent list\n");
        printf("2. add a returned car to the available-for-rent list\n");
        printf("3. add a returned car to the repair list\n");
        printf("4. transfer a car from the repair list to the available-for-rent list\n");
        printf("5. rent the first List car\n");
        printf("6. print all the lists\n");
        printf("7. quit\n");
		
		scanf(" %c", &userInput);

        switch (userInput) 
        {
            case '1':
                printf("What is the plate number of the List car?:(reminder only 6 characters)\n");
                scanf(" %s", plateNumber);
                printf("What is the mileage of the car?:\n");
                scanf(" %d", &mileage);

				temp=createStruct(plateNumber,mileage,0,'a');
                rootAva=add(rootAva,temp);
                countA++;
                rootAva=sortAva(rootAva,countA);
                
                /*need to add car to file*/

                break;
            case '2':
                printf("What is the plate number of the returned car?:(reminder only 6 characters)\n");
                scanf(" %s", plateNumber);
                printf("What is the mileage of the car?:\n");
                scanf(" %d", &mileage);
                
				temp=createStruct(plateNumber,mileage,0,'a');
                rootRen=removeCarRen(rootRen, temp, mileageChange);
                countR--;
                rootRen=sortRen(rootRen,countR);
                rootAva=add(rootAva,temp);/*The struct*/
              
                countA++;
                rootAva=sortAva(rootAva,countA);
				
				mileageChange-=100;
				mileageChange*=15;
				mileageChange=mileageChange+4000;
				
				printf("The cost is %d cents\n",mileageChange);
				mileageChange=0;

                break;
            case '3':
                printf("What is the plate number of the returned car?:(reminder only 6 characters)\n");
                scanf(" %s", plateNumber);
                printf("What is the mileage of the car?:\n");
                scanf(" %d", &mileage);

				temp=createStruct(plateNumber,mileage,0,'a');
                rootRen=removeCarRen(rootRen,temp, mileageChange);
                countR--;
                rootRen=sortRen(rootRen,countR);

                rootRep=add(rootRep,temp);/*The struct */
				
				mileageChange-=100;
				mileageChange*=15;
				mileageChange=mileageChange+4000;
				
				printf("The cost is %d cents\n",mileageChange);
				mileageChange=0;

                break;
            case '4':
                printf("What is the plate number of the repaired car?:(reminder only 6 characters)\n");
                scanf(" %s", plateNumber);

				temp=createStruct(plateNumber,0,0,'a');
                rootRep=removeCarRep(rootRep, temp, mileageChange);
                
                rootAva=add(rootAva,temp);/*edit between types*/
                countA++;
                rootAva=sortAva(rootAva,countA);
				
				mileageChange-=100;
				mileageChange*=15;
				mileageChange=mileageChange+4000;
				
				printf("The cost is %d cents\n",mileageChange);
				mileageChange=0;

                
                break;
            case '5':
                printf("For how long to you want to rent the car for? Please put in the form(YYMMDD)\n");

                scanf(" %d", &returnDate);

				temp=createStruct("",0,returnDate,'d');
                rootAva=removeCarA(rootAva, temp, returnDate);/*edit between types*/
                countA--;
                rootRen=add(rootRen, temp);
                countR++;

                rootRen=sortRen(rootRen,countR);
                break;
            case '6':
                printf("The avalible cars are:\n");
                    printList(rootAva);
                printf("\nThe cars that are rented are:\n");
                    printList(rootRen);
                printf("\nThe cars that are out for repair are:\n");
                    printList(rootRep);
                printf("\n");
                break;
            case '7':
                break;
            default:
                printf("Please input one of the 7 options (1,2,3,4,5,6 or 7)\n");
        }


    } while (userInput!='7');
    
    freeLists(rootRep);
    freeLists(rootRen);
    freeLists(rootAva);

	//Print the total income of all the cars

    free(outFile);
	fclose(inFile);

    return 0;
}


List* createStruct(char* plateNumber, int mileage, int returnDate, char status)
{
    List* root;
    root = malloc(sizeof(List));
    root->plateNumber=malloc(sizeof(char)*(strlen(plateNumber)+1));

    if (root->next==NULL)/*causes first value to not be included? root==NULL causes seg fault*/ 
    {
        strcpy(root->plateNumber,plateNumber);
        root->mileage=mileage;
        root->returnDate=returnDate;
        root->status=status;
    }
    else
    {
        return NULL;
    }

    return root;
              
}


List* add(List* root,List* new)
{
	new->next=root;
	return new;
}


List* sortAva(List* root, int count)
{
    int i;
    List* current = root;
    List* previousDummy = malloc(sizeof(List));
    List* previous;
    List* nextVal;

    for (i = 0; i < count; i++) 
    {
        current=root;
        nextVal=current->next;
        previous= previousDummy;

        while (nextVal!=NULL) 
        {
            if(current->mileage>nextVal->mileage){
                if (current == root) 
                {
                    root = nextVal;
                }
                previous->next=nextVal;
                current->next=nextVal->next;
                nextVal->next=current;

                previous = nextVal;
                nextVal=current->next;
            }
            else{
                previous = current;
                current = current->next;
                nextVal=current->next;
            }
        }
        
    }
    return root;

}


List* sortRen(List* root, int count)
{
    int i;
    List* current = root;
    List* previousDummy = malloc(sizeof(List));
    List* previous;
    List* nextVal;

    for (i = 0; i < count; i++) 
    {
        current=root;
        nextVal=current->next;
        previous= previousDummy;

        while (nextVal!=NULL) 
        {
            if(current->returnDate>nextVal->returnDate){
                if (current == root) 
                {
                    root = nextVal;
                }
                previous->next=nextVal;
                current->next=nextVal->next;
                nextVal->next=current;

                previous = nextVal;
                nextVal=current->next;
            }
            else{
                previous = current;
                current = current->next;
                nextVal=current->next;
            }
        }
        
    }
    return root;

}

void printList(List* root)
{
    List* temp=root;

    while (temp!=NULL) 
    {
        printf("Plate Number: %s\t",temp->plateNumber);
        printf("Mileage: %d\t",temp->mileage);
        printf("Return date: %d\n",temp->returnDate);
        temp=temp->next;
    }
}


List* removeCarA(List* root, List* temp, int returnDate)
{
    
    strcpy(temp->plateNumber,root->plateNumber);
    temp->mileage=root->mileage;

    free(root->plateNumber);
    root->plateNumber=NULL;
    root=root->next;/*free*/


    return root;
}


List* removeCarRen(List* root,List* temp, int mileageChange)
{
    int compare;
    List* current=root;
    List* previous=NULL;

    while (current != NULL) {
		compare=strcmp(current->plateNumber,temp->plateNumber);
        if (compare==0) {
			temp->mileage=current->mileage;
            mileageChange =temp->mileage-current->mileage;
		
            if (previous == NULL) {
                current = current->next;
                free(root);
				root=current;
            } else {
                previous->next = current->next;
                free(current);
                current = previous->next;
            }
        } else {
            previous = current;
            current = current->next;
        }
    }    

    return root;
}


List* removeCarRep(List* root, List* temp, int mileageChange)
{
    int compare;
    List* current=root;
    List* previous=NULL;
/*http://stackoverflow.com/questions/15776381/deleting-a-node-from-a-singly-linked-list-using-malloc-free*/
    while (current != NULL) {
		compare=strcmp(current->plateNumber,temp->plateNumber);
        if (compare==0) {
			
            mileageChange =temp->mileage-current->mileage;
		
            if (previous == NULL) {
                current = current->next;
                free(root);
				root=current;
            } else {
                previous->next = current->next;
                free(current);
                current = previous->next;
            }
        } else {
            previous = current;
            current = current->next;
        }
    }    
    return root;   
}


void freeLists(List* root)
{
    List* temp;

    while (root!=NULL) 
    {
        temp=root;
        free(temp->plateNumber);
        temp->plateNumber=NULL;
        root=root->next;
        free(temp);
    }
}
