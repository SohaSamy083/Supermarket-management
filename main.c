#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <conio.h>
#define normalcolor 15
#define highlightcolor 334
const int RED = 12;
const int GREEN = 10;
const int BLUE = 9;
const int YELLOW = 14;
const int MAGENTA = 13;
const int WHITE = 15;
const int turkuaz = 11;

COORD coord={0,0};

 void gotoxy(int x,int y)
 {
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

void changeConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
typedef struct product product;
struct product{
char product_name[20];
float product_price;
int quantity;
};
typedef struct category category ;
struct category{
    char category_name[20];
    product products[20];
    int product_count;
};
typedef struct supermarket supermarket;
struct supermarket{
    category categories[20];
    int category_count;
};
void DrawMenu(char Menu[][45], int menusize, int col, int row, int current_item)
{
    system("cls");
    for (int i = 0; i < menusize; i++)
    {
        gotoxy(col, row + i);
        if (current_item == i)
        {
            changeConsoleColor(highlightcolor);
        }
        else
        {
            changeConsoleColor(normalcolor);
        }
        printf("%s", Menu[i]);
        changeConsoleColor(normalcolor);
    }
}
//intialSupermarket
void intialSupermarket(supermarket *s){
   s->category_count=2;
    for(int i=0;i<2;i++){
            s->categories[i].product_count=2;
    }
            strcpy(s->categories[0].category_name,"Dairy");
            strcpy(s->categories[1].category_name,"Drinks");
            gotoxy(5, 8);
            strcpy(s->categories[0].products[0].product_name,"Juhayna ");
            strcpy(s->categories[0].products[1].product_name,"NIDO");
            s->categories[0].products[0].product_price=20;
            s->categories[0].products[0].quantity=40;
            s->categories[0].products[1].product_price=16;
            s->categories[0].products[1].quantity=60;
            strcpy(s->categories[1].products[0].product_name,"SinaCola");
            s->categories[1].products[0].product_price=18;
            s->categories[1].products[0].quantity=70;
            strcpy(s->categories[1].products[1].product_name,"BIG");
            s->categories[1].products[1].product_price=10;
            s->categories[1].products[1].quantity=50;
}
//DisplaySupermarket
void DisplaySupermarket(supermarket *s){
    for(int i=0;i<s->category_count;i++){
        SetColor(14);
        printf("Category name is : %s  \n\n",s->categories[i].category_name);
       SetColor(15);
        for(int j=0;j<s->categories[i].product_count;j++){
            printf("\t product name is %s || ",s->categories[i].products[j].product_name);
            printf("Product price is %.2f || ",s->categories[i].products[j].product_price);
            printf("Product quantity is %d \n\n",s->categories[i].products[j].quantity);
        }
    }

}

//addCategory
void addCategory(supermarket *s)
{
    char nCategory[30];
    SetColor(9);
    printf("please add categoryName: \n\n");
    SetColor(15);
    scanf("%s",nCategory);
    int foundCategory = -1;
    for(int i=0; i<s->category_count; i++)
    {
        if(strcmp(s->categories[i].category_name,nCategory)==0)
        {
            foundCategory=i;
            break;
        }

    }
    if(foundCategory==-1)
    {
     strcpy(s->categories[s->category_count].category_name,nCategory);
        s->categories[foundCategory].product_count = 0;
        s->category_count++;
        SetColor(10);
        printf("Category %s added.\n\n", nCategory);
        SetColor(15);
    }
    else
    {SetColor(28);
        printf("Cannot add more categories.\n\n");
        SetColor(15);
    }
}

//removeCategory
void removeCategory(supermarket *s)
{
    if(s->category_count>0)
    {
        char cat_name[20];
        SetColor(9);
        printf("Enter Category you want to remove \n\n");
        SetColor(15);
        scanf("%s",cat_name);
        int foundCategoryIndex=-1;
        for(int i=0;i<s->category_count;i++)
            {
             if(strcmp(s->categories[i].category_name,cat_name)==0)
             {
               foundCategoryIndex=i;
               break;
             }
        }
       if(foundCategoryIndex!=-1)
        {
        for(int i=foundCategoryIndex;i<s->category_count;i++)
        {
          s->categories[i]=s->categories[i+1] ;
          s->category_count--;

        }
        SetColor(10);
    printf("category %s removed \n\n ",cat_name);
    SetColor(15);
       }
  else
    {
        SetColor(28);
    printf("No have anything to remove\n\n");
    SetColor(15);
    }

  }

}



void addProduct(supermarket *S){

    char catName[30];
    char pName[30];
    int p,q;
    int categoryIndex = -1;
    int proIndex=-1;

SetColor(9);
    printf("Enter name of category that you wont add product \n\n");
    SetColor(15);
    scanf("%s",catName);

    for(int i=0; i<S->category_count ; i++)
    {

       if(strcmp(S->categories[i].category_name, catName)==0)
          {
              categoryIndex=i;
              break;
          }
    }

   if(categoryIndex!=-1)
    {
SetColor(9);
        printf("Enter name of product \n\n");
        SetColor(15);
        scanf("%s",pName);

            for(int i=0; i<S->categories[categoryIndex].product_count ; i++)
            {

               if(strcmp(S->categories[categoryIndex].products[i].product_name, pName)==0)
              {
                  proIndex=i;
                  break;
              }
           }
       if(proIndex!= -1)
       {  SetColor(28);
          printf("(%s) there is already be here \n\n",pName);////
          SetColor(15);
       }
       else
       {
            if(S->categories[categoryIndex].product_count < 30)
                    {SetColor(9);
                        printf("Enter price of price \n\n");
                        SetColor(15);
                        scanf("%d",&p);

                    SetColor(9);
                          printf("Enter price of quantity \n\n");
                          SetColor(15);
                          scanf("%d",&q);

                       strcpy(S->categories[ categoryIndex].products[S->categories[ categoryIndex].product_count].product_name , pName);
                       S->categories[categoryIndex].products[S->categories[categoryIndex].product_count].product_price=p;
                       S->categories[categoryIndex].products[S->categories[categoryIndex].product_count].quantity=q;
                       S->categories[categoryIndex].product_count++;
                    }
                    SetColor(10);
              printf("your added this success\n\n");
              SetColor(15);


     }
    }
     else
          {
               SetColor(28);

              printf("(%s) there is not be here \n\n",catName);
               SetColor(15);

          }

}
//removeProduct


void removeProduct(supermarket *s)
{
    char nameCategory[30];
    char productName[30];
    int foundCategory = -1;
    SetColor(9);
    printf("please enter categoryName to remove product: \n");
    SetColor(15);
    scanf("%s",nameCategory);
    SetColor(9);
    printf("\n remove product name: \n");
    SetColor(15);
    scanf("%s", productName);
    for(int i=0; i<s->category_count; i++)
    {
        if(strcmp(s->categories[i].category_name,nameCategory)==0)
        {
            foundCategory=i;
            break;
        }

    }
    int productIndex=-1;
    if(foundCategory!=-1)
    {
        for(int i=0; i<s->categories[foundCategory].product_count; i++)
        {
            if(strcmp(s->categories[foundCategory].products[i].product_name,productName)==0)
            {
                productIndex=i;
                break;
            }
        }
    }
    if(productIndex!=-1)
    {
        for(int i=productIndex; i < s->categories[foundCategory].product_count; i++)
        {
            s->categories[foundCategory].products[i]=s->categories[foundCategory].products[i+1];
        }
        s->categories[foundCategory].product_count--;
        SetColor(10);
        printf("Product '%s' removed from category '%s'.\n", productName, nameCategory);
        SetColor(15);

    }



}

//move function
void moveProduct(supermarket*s){

    if(s->category_count > 1){

        char sourceName[10];
        int sourceIndex= -1 ;
SetColor(9);
        printf("enter name of category you wont move product from it \n\n");
        SetColor(15);
        scanf("%s",sourceName);

        for(int i=0 ; i<s->category_count; i++)
        {

            if(strcmp(s->categories[i].category_name ,sourceName)==0)
            {
                sourceIndex= i;
                break;
            }
        }
        if (sourceIndex != -1)
                {
//                    break;
                }
                else
                {
                    SetColor(12);
                    printf("Error: The source category \"%s\" was not found. Please enter a valid source name.\n", sourceName);
                    SetColor(15);
                     SetColor(9);
                    printf("Do you want to enter another source cat name? (Y|N)\n");
                     SetColor(15);
                    char key = getch();
                    if (key == 'n' || key == 'N')
                    {
                        return;
                    }
                }

       int productIndex = -1;

       char pName[10];
SetColor(9);
        printf("enter name of product you wont move it \n\n");
        SetColor(15);
        scanf("%s",pName);

        for(int i = 0 ; i< s->categories[sourceIndex].product_count; i++)
        {

            if(strcmp(s->categories[sourceIndex].products[i].product_name,pName)==0)
            {
                productIndex=i;
                break;
            }
        }

           int desIndex = -1;
           char desName[10];
SetColor(9);
         printf("enter name of destination category you wont move product to it \n \n");
         SetColor(15);
        scanf("%s",desName);

        for(int i = 0 ; i< s->category_count; i++)
        {

            if(strcmp(s->categories[i].category_name,desName)==0)
            {
                desIndex=i;
                break;
            }
        }


        int desProductIndex =-1;

        if (desIndex != -1)
        {

             for(int i=0 ; i< s->categories[desIndex].product_count; i++)
            {

                if(strcmp(s->categories[desIndex].products[i].product_name,pName)==0)
                {
                    desProductIndex = i;
                    break;
                }
            }
        }
        if(desProductIndex == -1)
        {
            s->categories[desIndex].products[s->categories[desIndex].product_count]=
            s->categories[sourceIndex].products[productIndex];
            s->categories[desIndex].product_count++;

            for(int i = productIndex ; i< s->categories[sourceIndex].product_count-1 ;i++ )
            {
                s->categories[sourceIndex].products[i]=
                s->categories[sourceIndex].products[i+1];

            }
                s->categories[sourceIndex].product_count --;
                SetColor(10);
                printf("move the %s from %s to %s accepted \n\n",pName,sourceName,desName);
                SetColor(15);
        }
    }
}

//sell function

void sellProduct(supermarket *s){

    float totalPrice=0;
    char pName[10];
    char cName[10];
    int quantity;
    float price;
    int categoryIndex;
    //gotoxy(5, 16);
SetColor(9);
    printf("Enter the category name that you wont sale from it \n\n");
    SetColor(15);
    scanf("%s",cName);

    for(int i =0 ; i< s->category_count ; i++)
    {
        if(strcmp(s->categories[i].category_name,cName)==0)
        {
            categoryIndex = i;
            break;
        }
    }

    int productIndex=-1;

    if(categoryIndex != -1)
    {SetColor(9);
        printf("enter name of product wont to sale it \n \n");
        SetColor(15);
        scanf("%s",pName);

        for(int i =0 ; i< s->categories[categoryIndex].product_count ; i++)
        {
            if(strcmp(s->categories[categoryIndex].products[i].product_name,pName)==0)
            {
                productIndex=i;
                break;
            }
        }
    }

    if(s->categories[categoryIndex].products[productIndex].quantity>0)
    {SetColor(9);
        printf("Enter quantity of product you wont sale it : \n\n");
        SetColor(15);

        do
        {
            if(scanf("%d", &quantity) == 1 && quantity > 0)
               {
                    break;
               }
               else
               {    SetColor(28);
                    printf("ERORR...\n\n");
               }

        }while(1);

       if(quantity <= s->categories[categoryIndex].products[productIndex].quantity)
       {
            s->categories[categoryIndex].products[productIndex].quantity -= quantity;
            totalPrice+=quantity*s->categories[categoryIndex].products[productIndex].product_price;
            SetColor(10);
            printf(" \n you sale the %s from category %s his quantity %d with total price is %2.f \n\n",pName,cName,quantity,totalPrice);
            SetColor(15);

       }
    }
}

void menu(){
    printf(" choose number: \n\n");
    printf("1- Add Category Name: \n\n");
    printf("2- Remove Category Name: \n\n");
    printf("3- Add product Name : \n\n");
    printf("4- Remove product Name: \n\n");
    printf("5- Move product : \n\n");
    printf("6- Sell product: \n\n");
    printf("7- Display Category: \n\n");
    printf("8-Exit: \n\n");

}
void SetColor(int ForgC)
 {
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

int main()
{
    int col = 60, row = 3;
    int current_item = 0;
    char Menu[8][45] = {"Display supermarket", "Add category", "Remove category","Add product ", "Remove product", "Move product to category", "Sell product", "Exit"};
    char c;
    supermarket supermarket;
     intialSupermarket(&supermarket);
     do
    {
        DrawMenu(Menu, 8, col, row, current_item);

        c = getch();
        switch (c)
        {
            case -32:
            {
                c = getch();
                switch (c)
                {
                    case 72:
                    {
                        if (current_item > 0)
                            current_item--;
                        else
                            current_item = 7;
                        break;
                    }
                    case 80:
                    {
                        if (current_item < 7)
                            current_item++;
                        else
                            current_item = 0;
                        break;
                    }
                    case 73:
                    {
                        current_item = 0;
                        break;
                    }
                    case 81:
                    {
                        current_item = 7;
                        break;
                    }
                }
                break;
            }
            case 13:
            {
                system("cls");
                switch (current_item)
                {
                    case 0:
                        gotoxy(col, row);
                        printf("<< Super Market >> \n");
                        DisplaySupermarket(&supermarket);
                        break;
                    case 1:
                        gotoxy(col, row);
                        printf("<< Super Market >> \n");
                        DisplaySupermarket(&supermarket);
                          addCategory(&supermarket);
                        break;
                     case 2:
                        gotoxy(col, row);
                        printf("<< Super Market >> \n");
                        DisplaySupermarket(&supermarket);
                          removeCategory(&supermarket);
                        break;
                     case 3:
                        gotoxy(col, row);
                        printf("<< Super Market >> \n");
                        DisplaySupermarket(&supermarket);
                          addProduct(&supermarket);
                        break;
                     case 4:
                        gotoxy(col, row);

                        printf("<< Super Market >> \n");
                        DisplaySupermarket(&supermarket);
                          removeProduct(&supermarket);
                        break;
                     case 5:
                        gotoxy(col, row);
                        printf("moveProduct \n");
                        DisplaySupermarket(&supermarket);
                          moveProduct(&supermarket);
                        break;
                     case 6:
                        gotoxy(col, row);
                        printf("sell\n");
                        DisplaySupermarket(&supermarket);
                         sellProduct(&supermarket);
                        break;
                    case 7:
                        gotoxy(col, row);
                        printf("Exit\n");
                        c = 27;
                        break;
                }
                getch();
                break;
            }
        }
    } while (c != 27);

    return 0;
}
