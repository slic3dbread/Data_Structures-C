/***********************Student Name: Benjamin McConville
************************Date: 2014-11-15
************************Filename: main.c*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define  LINE_SIZE 1000


typedef struct _tree 
{
    char* key;
    int count;
    int height;
    struct _tree * left;/*The left value*/
    struct _tree * right;/*The right pointer*/
}Tree;

int max(int a, int b);
int height(Tree* T);
int getBalance(Tree* T);


Tree* rightRotate(Tree* y);
Tree* leftRotate(Tree* x);

Tree* parse(char* name,Tree* T);
void searchTree(char* key, Tree* T);
Tree* insertKey(char* key, Tree* T);
Tree* removeKey(char* key, Tree* T);
void printTree(int count,Tree*T);

void freeTree(Tree* T);




int main(){

	int freq;
	char* name=malloc(sizeof(char)*100);
    char* key=malloc(sizeof(char)*100);
	char input;
    Tree* T=NULL;


	do 
    {
        /*menu*/
        printf("********************\n");
        printf("AVL tree paradigm\n");
        printf("********************\n");
        printf("1. Initialization\n");
        printf("2. Find\n");
        printf("3. Insert\n");
        printf("4. Remove\n");
        printf("5. Check Height and Size\n");
        printf("6. Find all(above a given frequency)\n");
        printf("7. Exit\n");


        /*accepting user input to enter the menu*/
        scanf(" %c", &input);

        switch (input) 
        {
            case '1':
				printf("Input the file name you want to initialize as an AVL tree:\n");
		        scanf(" %s",name);
				
                T = parse(name,T);
                
                break;
            case '2':
                printf("Input the key name you want to search for:\n");
		        scanf(" %s",key);
				if(T==NULL)
					printf("There is no tree initialized\n");
				else
					searchTree(key,T);
                
                break;
            case '3':
                printf("Input the key name you want to add to the tree:\n");
		        scanf(" %s",key);
				T = insertKey(key,T);

                break;
            case '4':
			    printf("Input the key name you want to be removed in tree:\n");
		        scanf(" %s",key);
				T = removeKey(key,T);
                
                break;
            case '5':
				printf("The height of the tree is: %d\n",T->height);

                break;
            case '6':
				printf("Input a positive integer frequency count for the tree:\n");
				scanf(" %d",&freq);
				
				if(freq<0)
					printf("Not a positive number\n");
				else
					printTree(freq,T);

                break;
            case '7':
                break;
            default:
                printf("Invalid Input. Please input one of the 7 options.\n");
                
        }

    }while(input!='7');
	
	free(name);
	free(key);
	freeTree(T);
	
return 0;
}

/*prints the tree in order if the frequency of the node is above the one the user put*/
void printTree(int count, Tree* T){
	
	if(T==NULL)
		return;
		
	printTree(count,T->left);
		
	if(T->count>=count)
		printf("%s\n",T->key);
		
	printTree(count,T->right);
	
}
/*takes the users file name and checks if it exists
 *If it does it parses the file and inserts it to the Tree*/
Tree* parse(char* name,Tree* T){

    FILE* inFile;
    char* node=NULL;
    char* outFile = malloc(sizeof(char)*LINE_SIZE);

	/*Checks if file is in the current directory*/
    if (access(name, F_OK)!= -1) 
    {
        inFile=fopen(name,"r");
        if (inFile==NULL) 
        {
            printf("Error opening file. Program terminate\n");
            exit(2);
        }
		

        while(!feof(inFile))
        {
			
            fgets(outFile,LINE_SIZE,inFile);
            
            node = strtok(outFile, " \n\t");

            while(node!=NULL)
			{
				if(strlen(node)>2)
					T = insertKey(node,T);

				node= strtok(NULL, " \n\t");
				
			}
        }
    }
    else{
        printf("File does not exist in current directory.\n");
        return NULL;
    }
	
	fclose(inFile);
	free(outFile);

	return T;

}

/*Navigates through the whole tree and checks if the value is in it*/
void searchTree(char* key, Tree* T){

	if(T==NULL)
		return;
	
	if(strcmp(key,T->key)==0){
		printf("The key is: %s and it's frequency is: %d\n",key,T->count);
		return;
	}
	else if(strcmp(key,T->key)<0){
		if(T->left!=NULL)
		searchTree(key,T->left);
	}
	else{
		if(T->right!=NULL)
		searchTree(key,T->right);
	}
	
	//printf("No_such_key\n");
	
}

/*calls it self till it goes to the bottom left and gets the minimum value*/
Tree* minValueNode(Tree* T){
	Tree* temp = T;

	while(temp->left!=NULL)
		temp = temp->left;
		
	return temp;
}

/*Removes the key in the Tree and rebalances the Tree
 *some parts of the function came from this website
 *http://www.geeksforgeeks.org/avl-tree-set-2-deletion/*/
Tree* removeKey(char* key, Tree* T){
 
    if (T == NULL)
        return T;
 
    if (strcmp(key,T->key)<0)
        T->left = removeKey(key,T->left);
	else if(strcmp(key,T->key)>0)
        T->right = removeKey(key,T->right);
    else
    {
        if( (T->left == NULL) || (T->right == NULL) )
        {
            Tree* temp = T->left ? T->left : T->right;

            if(temp == NULL)
            {
                temp = T;
                T = NULL;
            }
            else 
             *T = *temp; 
 
            free(temp);
        }
        else
        {
            Tree* temp = minValueNode(T->right);
 
            strcpy(T->key,temp->key);
 
            T->right = removeKey(temp->key,T->right);
        }
    }
 
    if (T == NULL)
      return T;
	  
	/*Updates height*/
	T->height = max(height(T->right), height(T->right)) + 1;
	
	/*get balance*/
	int balance = getBalance(T);
	
	/*Left left case*/
	if(balance > 1 && getBalance(T->left)>=0)
		return rightRotate(T);
		
	 /*Right Right Case*/
    if(balance < -1 && getBalance(T->right)<=0)
        return leftRotate(T);
 
    /*Left Right Case*/
    if (balance > 1 && getBalance(T->left)<0)
    {
        T->left =  leftRotate(T->left);
        return rightRotate(T);
    }
 
    /*Right Left Case*/
    if (balance < -1 && getBalance(T->right)>0)
    {
        T->right = rightRotate(T->right);
        return leftRotate(T);
    }
 
    /* return the (unchanged) node pointer */
    return T;
}

/*returns the height of the Tree*/
int height(Tree* T){
	if(T==NULL)
		return 0;
	return T->height;
}

/*Returns the max value between the two numbers*/
int max(int a, int b){
	return (a>b)? a : b;
}

/*Returns the balancing factor of the node*/
int getBalance(Tree* T){
	if(T==NULL)
		return 0;
	return height(T->left)-height(T->right);
}

/*Takes in the Tree and rotates the nodes to balance the Tree*/
Tree* rightRotate(Tree* y)
{
	if(y->left==NULL)
		return NULL;
		
    Tree* x = y->left;
	
    Tree* T2 = x->right;
 
    /*Perform rotation*/
    x->right = y;
    y->left = T2;
 
    /*Update heights*/
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    return x;
}
 
/*Takes in the Tree and rotates the nodes to balance the Tree*/
Tree* leftRotate(Tree* x)
{
	if(x->right==NULL)
		return NULL;
		
    Tree* y = x->right;
    Tree* T2 = y->left;
 
    /* Perform rotation*/
    y->left = x;
    x->right = T2;
 
    /*  Update heights*/
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    return y;
}

/*Used to insert into the Tree and initialize the Tree
 *It takes in the Tree and value to be inserted
 *It will balance the Tree and change the count and and insert to the Tree*/
Tree* insertKey(char* value,Tree* T){
	if(T==NULL){
        Tree* temp=(Tree*)malloc(sizeof(Tree));/*mallocs Tree*/
		if(temp == NULL){
			printf("out of memorey\n");
			exit(1);
		}
        temp->key = malloc(sizeof(char)*(strlen(value)+1));
		strcpy(temp->key,value);
        temp->left = NULL;
        temp->right = NULL;
        temp->height = 0;
        temp->count = 1;

		return temp;
    }

	if(strcmp(value,T->key)<0)
		T->left=insertKey(value,T->left);
    else if(strcmp(value,T->key)==0)
        T->count++;
	else
		T->right=insertKey(value,T->right);
	
	/*Updates height*/
	T->height = max(height(T->right), height(T->right)) + 1;
	
	/*get balance*/
	int balance = getBalance(T);
	
	/*Left left case*/
	if(balance > 1 && (strcmp(value,T->left->key)<0))
		return rightRotate(T);
		
	 /*Right Right Case*/
    if(balance < -1 && (strcmp(value,T->right->key)>0))
        return leftRotate(T);
 
    /*Left Right Case*/
    if (balance > 1 && (strcmp(value,T->left->key)>0))
    {
        T->left =  leftRotate(T->left);
        return rightRotate(T);
    }
 
    /*Right Left Case*/
    if (balance < -1 && (strcmp(value,T->right->key)<0))
    {
        T->right = rightRotate(T->right);
        return leftRotate(T);
    }
 
    /* return the (unchanged) node pointer */
    return T;
}

/*Used to free the tree*/
void freeTree(Tree* temp){
	if(temp==NULL)
        return;
    
    freeTree(temp->left);
	freeTree(temp->right);
        /*might have to free the key values too*/
	free(temp);
	
}