#include<stdio.h>
#include "myBank.h"
#define TRUE 1
#define FALSE 0
int main()
{
    int flag=FALSE;
    while (flag==FALSE)
    {
    printf("\nPlease choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
    char input;
    scanf(" %c" ,&input);
    switch (input)
    {
    case 'O':{
        double deposit;
        double q;
        q=getNumberOfOpenAccounts();
        if(q<49){
        printf("Please enter amount for deposit: ");
        if(scanf(" %lf" ,&deposit)){//check if the input is a number
          if(deposit>=0){//deposit can't be negative 
          deposit=((double)((int)(deposit*100))/100);
          	O(deposit);
          }
          else printf("Invalid Amount\n");
        }
        else{
          printf("Failed to read the amount\n");
        }
     }
     else printf("there is no place for new account\n");
     break;
    }
      case 'B': {
        int account_number;
        printf("Please enter account number: ");
        if(scanf(" %d",&account_number))
        {
          if(isInRange(account_number)){//check if account number is in range
          	if(isopen(account_number))
            		B(account_number);
            	else printf("This account is closed\n");	
          }
        }
        else{
          printf("Failed to read the account number\n");
        }
        break;

        }
     case 'D' :{
       int account_number;
        printf("Please enter account number: ");
        if(scanf(" %d",&account_number))
        {
         if(isInRange(account_number)){//check if account number is in range
            if(isopen(account_number)){//check if the account is open
              printf("Please enter the amount to deposit: ");
              double deposit;
              if(scanf(" %lf", &deposit)){
                 deposit=((double)((int)(deposit*100))/100);
                 if(deposit>=0)
                     D(account_number,deposit);
                     else printf("Cannot deposit a negative amount\n");
              }
              else
              {
                printf("Failed to read the amount\n");
              }
              
          }
            else printf("This account is closed\n");	
        }
          else printf("Invalid account number\n");
        }
        else{
        printf("Failed to read the account number\n");
        }
        break;
     }
      case 'W':{
        int account_number;
        printf("Please enter account number: ");
        if(scanf(" %d",&account_number))
        {
          if(isInRange(account_number)){//check if account number is in range
            if(isopen(account_number)){//check if the account is open
              double withdrawal;
              printf("Please enter the amount to withdraw: ");
              if(scanf(" %lf", &withdrawal)){
              withdrawal=((double)((int)(withdrawal*100))/100);
              			W(account_number,withdrawal);
              }
              else
              {
                printf("faild to read withdrow\n");
              }
              
          }
          else printf("This account is closed\n");	
        }
        }
        else{
           printf("Failed to read the account number\n");
        }

      break;
    
      }
     case 'C':{
        int account_number;
        printf("Please enter account number: ");
        if(scanf(" %d",&account_number))
        {
          if(isInRange(account_number)){//check if account number is in range
            if(isopen(account_number)){//check if the account is open
             C(account_number);
             printf("Closed account number %d\n", account_number);
             
          }
            	else printf("This account is already closed\n");
            	}	
          }
        else{
        printf("Failed to read the account number\n");
    }
    break;
     }
      case 'I':{
        int interest;
        printf("Please enter interest rate: ");
        if(scanf(" %d",&interest)==1){
		 if(interest>=0)//interest can't negative    	
          		I(interest);
          	else printf("Invalid interest rate\n");		
        }
        else
        {
         printf("Failed to read the interest rate\n");
        }
          break;
    }
      case 'P':{
           P();
           break;
    }
    case 'E':{
      E();
      flag=TRUE;
      break;
    }
    default:
        printf("Invalid transaction type\n");
    }
    }
}
    
