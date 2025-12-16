#include<stdio.h>
struct stu
{
    int rn;
    char name[50];
};

void getdata(struct stu x[])
{
    for(int i=0;i<10;i++)
    {
    printf("enter your roll number\n");
    scanf("%d",&x[i].rn);
    printf("enter your name\n");
    fflush(stdin);// used when gets() doesnt input data 
    gets(x[i].name);
    }
   
}

void display(struct stu x[])
{
    for(int i=0;i<10;i++)
    printf("your name is %s and ur roll no. is %d\n",x[i].name,x[i].rn);

}

int main()
{
    struct stu x[10];
    getdata(x);
    display(x);
    return 0;
}
