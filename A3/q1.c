/***********************Student Name: Benjamin McConville
************************Date: 2014-11-03
************************Filename: q1.c*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define MAX_SIZE 100

/*The link list used for the tree*/
typedef struct _tree 
{
    char* value;
    
    struct _tree * left;/*The left value*/
    struct _tree * right;/*The right pointer*/
}Tree;

/*used to create the tree nodes from bottom up and returns the node*/
Tree* createTree(char* parent, char* left, char* right, Tree** stack, int sCount);

/*Print the tree in the 4 different ways*/
void printTree(Tree* root,int space,char* sign);
void printTreeIn(Tree* root);
void printTreePre(Tree* root);
void printTreePost(Tree* root);

/*Used to update the variables and replace their values*/
void update(Tree* root,char* name,char* newValue);
/*Calculates the arithmetic expression*/
double calculate(Tree* root);

/*Frees the tree*/
void deleteTree(Tree* root);
	

int main(int argc,char *argv[])
{
	if (argc!=2) 
    {  
        printf("There was an error for the number of inputs on the command line\n");
        return 1;
    }

    char input;
    Tree* root=NULL;

	char variables[MAX_SIZE];
	char operands[MAX_SIZE];
    /*Array of strucks*/
    Tree** stack= malloc(sizeof(Tree*)*10);
	
	double total;
    /*Used to get inputs for update function*/
	char* name=malloc(sizeof(char)*100);
	char* newValue=malloc(sizeof(char)*100);

    int i;
	int oCount=0,vCount=0, sCount=0;

	char values[strlen(argv[1])];

	int length=strlen(argv[1]);
	char* parent=malloc(sizeof(char)*3);
    char* left=malloc(sizeof(char)*20);
    char* right=malloc(sizeof(char)*20);
	
	
	strcpy(values,argv[1]);
	
	for (i = 0; i < length; i++) 
    {
        /*resets values being passed to the create tree function*/
        parent[0]='\0';
        left[0]='\0';
        right[0]='\0';
       
	    /*checks for the character value*/
		if((values[i]=='(')||(values[i]=='+')||(values[i]=='*')||(values[i]=='/')||(values[i]=='-')){
			operands[oCount]=values[i];/*adds a operands onto the stack*/
			oCount++;
		}
        else if(values[i]==')'||i==length-1){/*when it gets to an end bracket or the end of the expression*/
            parent[0]=operands[oCount-1];    /*It takes the operand off the top of the stack*/
            parent[1]='\0';
            oCount-=2;


			if(variables[vCount-2]=='x'){/*Used to check for variable*/
				right[0]=variables[vCount-2];
				right[1]=variables[vCount-1];
				right[2]='\0';
				vCount-=2;
			}
			else if(variables[vCount-3]=='.'){/*Used to check for a decimal number*/
				right[0]=variables[vCount-4];
				right[1]=variables[vCount-3];
				right[2]=variables[vCount-2];
				right[3]=variables[vCount-1];
				right[4]='\0';
				vCount-=4;
			}
			else if(vCount>0){/*For all other numbers if they are on the stack*/
				right[0]=variables[vCount-1];
				right[1]='\0';
				vCount--;

			}
        

            
            
            if(variables[vCount-2]=='x'){/*Used to check for variable*/
                left[0]=variables[vCount-2];
                left[1]=variables[vCount-1];
                left[2]='\0';
                vCount-=2;
            }
            else if(variables[vCount-3]=='.'){/*Used to check for a decimal number*/
                left[0]=variables[vCount-4];
                left[1]=variables[vCount-3];
                left[2]=variables[vCount-2];
                left[3]=variables[vCount-1];
                left[4]='\0';
                vCount-=4;
            }
            else if(vCount>0){/*For all other numbers if they are on the stack*/
                left[0]=variables[vCount-1];
                left[1]='\0';
                vCount--;
            }
            /*Creates the tree and puts it in a stack which contains tree nodes
             *The trees are then combined in the stack if certain the left or right are empty*/

            stack[sCount]=createTree(parent,left,right,stack,sCount);
            sCount++;

		}
        else{/*Puts variables on the stack*/
            variables[vCount]=values[i];
			vCount++;
		}

    }
        root=stack[sCount-1];
    do 
    {
        /*menu*/
        printf("********************\n");
        printf("Arithmetic Expression\n");
        printf("********************\n");
        printf("1. Display\n");
        printf("2. Preorder\n");
        printf("3. Inorder\n");
        printf("4. Postorder\n");
        printf("5. Update\n");
        printf("6. Calculate\n");
        printf("7. Exit\n");


        /*accepting user input to enter the menu*/
        scanf(" %c", &input);

        switch (input) 
        {
            case '1':
                printTree(root,0,"");
                break;
            case '2':
                printTreePre(root);
                break;
            case '3':
                printTreeIn(root);
                break;
            case '4':
                printTreePost(root);
                break;
            case '5':
				printf("Input the variable name you want to change:\n");
		        scanf(" %s",name);
                printf("Input the value you want to give it:\n");
		        scanf(" %s",newValue);

                update(root,name,newValue);
                break;
            case '6':
                total=calculate(root);
                printf("%lf\n",total);
                break;
            case '7':
                break;
            default:
                printf("Invalid Input. Please input one of the 7 options.\n");
                
        }

    }while(input!='7');
	

    free(stack);
    free(name);
    free(newValue);
    free(parent);
    free(right);
    free(left);
    deleteTree(root);    

    return 0;
}

/*This function takes in the 3 variables of the tree and will add them to the tree nodes
 *it checks if the values are empty. If they are that means the values have been put on
 *the stack since they are trees them selves. The function returns its the head*/
Tree* createTree(char* parent, char* leftVal, char* rightVal, Tree** stack, int sCount){

    Tree* root = malloc(sizeof(Tree));
    root->value=malloc(sizeof(char)*(strlen(parent)+1));


    Tree* tempR = malloc(sizeof(Tree));
    Tree* tempL = malloc(sizeof(Tree));
    tempR->value=malloc(sizeof(char)*(strlen(rightVal)+1));
    tempR->right=NULL;
    tempR->left=NULL;
    tempL->value=malloc(sizeof(char)*(strlen(leftVal)+1));
    tempL->left=NULL;
    tempL->right=NULL;
    
	strcpy(root->value,parent);



	if(leftVal[0]!='\0'&&rightVal[0]!='\0'){
        strcpy(tempL->value,leftVal);
		strcpy(tempR->value,rightVal);
	}
    else if(leftVal[0]=='\0'&&rightVal[0]=='\0'){
        tempL=stack[sCount-2];
		tempR=stack[sCount-1];
	}
    else if(leftVal[0]=='\0'&&rightVal[0]!='\0'){
        tempL=stack[sCount-1];
        strcpy(tempR->value,rightVal);
    }
    else if(leftVal[0]!='\0'&&rightVal[0]=='\0'){
        tempR=stack[sCount-1];
        strcpy(tempL->value,leftVal);
    }
    root->left=tempL;
    root->right=tempR;

	return root;

}

/*displays the tree in a format so the user can see the tree visually*/
void printTree(Tree* root,int space,char* sign){
	Tree* temp=root;
    int i;
	
	if(root == NULL){
		return;
    }
    else{
        printTree(temp->right,space+1,"/");
        for (i = 0; i < space; i++) 
        {
            printf("\t");   
        }
        printf("%s",sign);
        printf("%s\n",temp->value);
        printTree(temp->left,space+1,"\\");
    }
}

/*Prints out the preorder of the values in the tree*/
void printTreePre(Tree* root){
	Tree* temp=root;
	
	if(root == NULL)
		return;
	printf("%s\n",temp->value);
	printTreePre(temp->left);
	printTreePre(temp->right);

}

/*Prints out the tree in order*/
void printTreeIn(Tree* root){
		
	if(root == NULL)
		return;
	printTreeIn(root->left);
	printf("%s\n",root->value);
	printTreeIn(root->right);

}

/*Prints out the tree in post oreder*/
void printTreePost(Tree* root){
	Tree* temp=root;
	
	if(root == NULL)
		return;
	printTreePost(temp->left);
	printTreePost(temp->right);
	printf("%s\n",temp->value);

}

/*calls itself to find the value to be replaced and replaces it*/
void update(Tree* root,char* name,char* newValue){
	
	while(root){
	
       if(strcmp(root->value,name)==0){
            strcpy(root->value,newValue);
            return;
        }
        else if(root->left==NULL)
            return;
        else{
            printf("Working\n");
            update(root->left,name,newValue);
            update(root->right,name,newValue);
            return;
        }	
	
    }
    return;
}


/*calls it self recursivly for each of the nodes of the tree and the when it reaches the
 *bottom it returns the value which is then calculated*/
double calculate(Tree* root){
	double x, y;
	
    if(root->left==NULL){
		/*atof will make a string that isn't all numbers to 0.00*/
		return  atof(root->value);
	}
	else{
		x=calculate(root->left);
		y=calculate(root->right);
		
		if (root->value[0]=='*') 
		{
			return x*y;
		}
		else if (root->value[0]=='/') 
		{
			return x/y;
		}
		else if (root->value[0]=='+') 
		{
			return x+y;
		}
		else if (root->value[0]=='-')
		{
			return x-y;
		}
        else
            return 0.0;
		
	}
}


/*Used to free the tree*/
void deleteTree(Tree* temp){


	if(temp==NULL)
        return;
    
    deleteTree(temp->left);
	deleteTree(temp->right);
        
	free(temp);
	


}

