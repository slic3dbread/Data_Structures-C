
/***********************Student Name: Benjamin McConville
************************Date: 2014-10-09
************************Filename: q2.c*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct calculateNum
{
    double number;

    struct calculateNum * next;
};

typedef struct calculateNum calculate;

calculate* removeValue(calculate* root, char value);
calculate* insertValue(calculate* root, char value);


int main(int argc,char *argv[])
{

    calculate* root=NULL;
    double total = 0;
    int i;
    char values[strlen(argv[1])];


    if (argc<2) 
    {  
        printf("There are no inputs to be calculated\n");
        return 1;
    }
    
    strcpy(values,argv[1]);

    for (i = 0; i < strlen(argv[1]); i++) 
    {
        if(values[i]=='+'||values[i]=='*'||values[i]=='/'||values[i]=='-')
            root=removeValue(root,values[i]);
        else
            root=insertValue(root,values[i]);
    }

    total=root->number;


    printf("%.2lf\n",total);

    free(root);

    return 0;
}


calculate* insertValue(calculate* root, char value)
{
    calculate* temp;
    calculate* new=malloc(sizeof(calculate));

    new->number=atof(&value);

    if (root==NULL) 
    {
        root=new;
    }
    else 
    {        
        temp=root;

        while (temp->next!=NULL) 
        {
            temp=temp->next;
        }
        temp->next=new;
    }
    

    return root;

}

calculate* removeValue(calculate* root, char value)
{
    double total;
    calculate* num1;
    calculate* num2;
    calculate* temp=root;


    if (temp->next->next==NULL) 
    {
        num2=temp->next;
        num1=temp;
    }
    else 
    {
        while(temp->next->next!=NULL)
        {
            num2=temp->next->next;
            num1=temp->next;
            temp=temp->next;
        }
    }
    free(temp->next->next);
    temp->next->next=NULL;
    free(temp->next);
    temp->next=NULL;
    
    if (value=='*') 
    {
        total=(num1->number)*(num2->number);
    }
    else if (value=='/') 
    {
        total=(num1->number)/(num2->number);
    }
    else if (value=='+') 
    {
        total=(num1->number)+(num2->number);
    }
    else if (value=='-')
    {
        total=(num1->number)-(num2->number);
    }
    else{
        printf("This symbol is not valid\n");
    }
  
    temp->number=total;

    return root;


}
