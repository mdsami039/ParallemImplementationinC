#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<ctype.h>
struct PizzaOrder //creating a structure for order which have different elements to be store
{
    char SIZE[10];
    double price;
    char cust_name[50];
    char address[50];
    char toppings;
    int no;
    char typeOforder[50];
    char* typeOftoppings[50];
    char phoneNo[5];
    char addr[10];
    int numToppings;
    int order;
    int choice;
    int var;
} p;

int main()
{

    int repeat;
     int s;
         int r=1;
         int z=1;
   do              //Creating a do while loop to show the menu to the user for selection of size of pizza
   {
    char c;
    int choice;
    int i;
    int selection;
    p.price=0.0;
    double charge=0;
    printf("\n----------Welcome to the Pizza Hut---------\n");
    printf("\n1. Small Pizza");
    printf("\n2. Medium Pizza");
    printf("\n3. Large Pizza");
    printf("\n");
    int check=1;
    while(check==1)//This loop executes until user entered the proper type of pizza from the above menu
    {
    printf("\nPlease select your pizza size\n");fflush(stdin);
    scanf("%c",&c);
    if(c<'1'||c>'3')//check the condition whether entered character is less then 1 or greater than 2
    {
        printf("Please enter a valid selection");
    }
    else if(!isdigit(c))//check whether the given input is digit or char
    {
        printf("Please  enter only 1 or 2 or 3 only\n");
    }
    else{
    check=0;
    }
    }
    switch(c)//creating a switch case to save the type of pizza into the structure
    {
        case '1':strcpy(p.SIZE,"SmallSize");
                    charge=5;
                    break;

        case '2':strcpy(p.SIZE,"MediumSize");
                    charge=8;
                    break;

        case '3':strcpy(p.SIZE,"LargeSize");
                   charge=12;
                     break;

    }

     int tcharge,checking=1;
     int ans;
     int t=toppings();
     int type;
     int order=1;
     p.price=charge;
     p.price+=t;
     while(order)//This loop to ask whether to have pizza eat in or delivery, prompts continuously until he press proper number 1 or 2
     {
     printf("\nPlease enter 1 for Order Collected or 2 for Delivery\n");fflush(stdin);
      scanf("%d",&type);
      p.order=type;
      if(type<1||type>2)
      {
          printf("Enter a valid selection");
      }
      else if(isdigit(type))
      {
          printf("Invalid selection\n");
      }
      else
      {
          order=0;
      }
     }
       switch(type)
          {
              case 1:strcpy(p.typeOforder,"Collected");//this method copy the type of order into structure
                      if(p.var==0)//Satisfied when the order for the first time to be taken
                      {
                        validateDel();
                      }
                      recordDel();
                    break;

              case 2:strcpy(p.typeOforder,"Delivered");
                 if(p.price<30)
                   {
                     p.price+=8.0;
                     printf("additional delivery cost is $8\n");
                   }
                   if(p.var==0)
                   {
                    validateDel();
                   }
                   recordDel();
                      break;
          }
            //After completion first order it ask user to continue to buy the pizza or to exit.
          printf("Do you want additional pizza\n");
          printf("0-Exit or 1-Continue\n");
          scanf("%d",&z);fflush(stdin);
          int d=1;
          while(d==1)//Goes on prompting the user until he entered correct input
          {
          if(r<1||r>2)
          {
              printf("Enter 1 or 2 only");fflush(stdin);
          }
          else if(isdigit(r))
          {
              printf("Sorry...invalid input\n");fflush(stdin);
          }
          else{
            d=0;
          }
          }
 }while(r==z);fflush(stdin);
   return 0;
}
 int toppings()//this method evaluates based on user selection for the toppings
{
    int sel;
    int b=1;
    int c=1;
    int tcharge=0;
    int s;

    s=1;
    while(s==1)//Continue to execute until user entered proper input
    {
    printf("Do you want toppings 1-Yes or 2-No\n");fflush(stdin);//Ask the user does he required toppings or not
    scanf("%d",&sel);
    p.choice=sel;
    if(sel<1||sel>2)
    {
        printf("Enter 1 or 2 only\n");
    }
    else if(isdigit(sel))
    {
        printf("Sorry...invalid selection \n");
    }
    else{
        s=0;
    }
    }


    char dec;
    int toppins=0;
    char* top[]={"Bacon","Olives","Mushrooms","Pineapple","Salami","Apple"};//Creating a pointer array to shoe the list of toppings
    int i,j;
    int index;
    p.numToppings=0;
    //sel=1;
    while(sel==1&&tcharge<=4)
    {
    for(i=0;i<6;i++)//this loop to show the toppings
     {
             printf(" %d  %s\n",i,top[i]);

     }
     int c=1;
      while(c==1)
     {
      printf("Please enter the type of toppings u want\n");fflush(stdin);
      scanf("%d",&index);
     if(isdigit(index))
     {
        printf("The entered %d is not digits\n",index);
     }
     else if(index<0||index>5)
     {
         printf("Please enter integers between 1 to 5 only\n");
     }
     else{
        c=0;
     }
     }

     p.typeOftoppings[p.numToppings]=top[index];/*this statement to select the toppings based on the index shown in the loop
                          and stored into the structure                        */
     index++;//increment for every successive toppings charge
     tcharge++;//increment the charge of the toppings
     p.numToppings++;
     p.price=tcharge;//save toe cost of the toppings
     int a=1;
     int choose;
     while(a)
     {
     printf("Do you want additional toppings 1-Yes or 2-No\n");
     scanf("%d",&choose);
     if(choose<1||choose>2)
     {
         printf("Please enter 1 or 2 only\n");
     }
     else if(isdigit(choose))
     {
         printf("Sorry...invalid selection\n");

     }
     if(choose==1)
     {
         a=0;
         s=1;

     }
     if(choose==2)
     {
         return 0;
     }
        }

     }



}
validateDel()//This method to save the details of the customer and pizza details
{

    char number[5],ch=1;
    char cname[6];
    char addr[10];
    int i;
    int n=1;
    int n2=2;
    while(n==1)//prompt the user until he entered proper name of the customer
    {
    printf("Enter Customer Name\n");
    scanf("%s",&cname);fflush(stdin);
    printf("%d",strlen(cname));
      for(i=0;i<strlen(cname);i++)fflush(stdin);//validating the customer name by having mentioning six letters name
    {
     if(isdigit(cname[i]))
    {
        printf("Enter a proper Name\n",cname[i]);

    }
    else if(isalpha(cname[i]))
    {
        printf("Enter a  proper Name\n",cname[i]);
    }

    }

    if(strlen(cname)==6)
    {
      n=0;
      }
    if(strlen(cname)!=6)
    printf("Enter minimum 6 letters name\n");fflush(stdin);
    strcpy(p.cust_name,cname);
    }

    while(ch==1)
   {
    printf("Enter Customer phone number\n");//validating phone number by having at least minimum 5 numbers digit
    scanf("%s",&number);
    for(i=0;i<strlen(number);i++)fflush(stdin);
    {
      if(isdigit(number))
     {
         printf("Invalid digits\n",number[i]);
     }
     else if(isalpha(number))
     {
         printf("%Invalid digits\n",number[i]);
     }
     }
         if(strlen(number)!=5)
     {
         printf("Please enter 5 digit phone number only\n");fflush(stdin);
     }
    else{
        ch=0;
        }
 strcpy(p.phoneNo,number);
   }

    if(p.order==2)
    {
    printf("Please enter the address\n");//if the type of order is delivered then this decision take place
    scanf("%s",&addr);
    int a2=1;
    while(a2==1)
    {
    if(strlen(addr)!=10)//validate the address if user entered up to length 10
    {
        printf("Enter a valid 10 length address\n");

    }
    else{
        a2=0;
    }
    }
    }
    p.var++;
}

void recordDel(int n)/*This method to display the summary of the order includes customer name phone no, if it is delivered then it show the address
                       of the customer with the pizza details    */
{
    int i,i2;
    printf("---------------Summary of the Order---------------\n");
    printf("Customer Name is %s\n\n",p.cust_name);
    printf("Phone number is %s\n\n",p.phoneNo);
    if(p.choice==1)
    {
     printf("Type of Toppings are\n");
     for(i=0;i<p.numToppings;i++)
     {
        printf("%s\n",p.typeOftoppings[i]);
     }
    }
    printf("Type of the Pizza is %s\n",p.SIZE);
    printf("\nType of the order is %s\n",p.typeOforder);
    printf("\nTotal cost  of the order is $%.2f\n",p.price);
    if(p.order==2)
    {
     printf("\nThe address of the customer is %s",p.addr);
    }
    printf("\nThanks for buying the pizzas\n");
}

