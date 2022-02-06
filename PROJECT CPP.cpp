#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct details{
    char name[20];
    char price[10];
    char code[10];
    char qty[10];
      
   }dt[50];

int main()
{
    int n, i, chars;
    FILE *fp;

    fp = fopen("items.txt", "wb");

    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }



    printf("Enter the number of items you want to enter: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter the details of items%d \n", i + 1);

        fflush(stdin);

        printf("Name: ");
        gets(dt[i].name);

        printf("price ");
        gets(dt[i].price);

        printf("code: ");
        scanf("%s", dt[i].code);

        printf("qty ");
        scanf("%s", dt[i].qty);

        chars = fwrite(&dt, sizeof(dt), 1, fp);
        printf("Number of items written to the file: %d\n", chars);
    }

    fclose(fp);
    


   printf(" ***** INVENTORY *****\n");
   printf("------------------------------------------------------------------\n");
   printf("S.N.| NAME | CODE | QUANTITY | PRICE \n");
   printf("------------------------------------------------------------------\n");
   for(i=0;i<n;i++)
	printf("%d   %s     %s      %s        %s    \n",i+1,dt[i].name,dt[i].code,dt[i].qty,dt[i].price);
   printf("------------------------------------------------------------------\n");
  return 0;
}
