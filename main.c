#include<stdio.h>
#include "myBank.h"
#define TRUE 1
#define FALSE 0
int main()
{
    int flag=FALSE;
    //run until the user init E 
    while (flag==FALSE)
    {
    printf("\nPlease choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
    char input;
    scanf(" %c" ,&input);
    switch (input)
    {
    case 'O':{//if the input is o get in.
        double deposit;
        double q;
        q=getNumberOfOpenAccounts();
        if(q<49){//check if there is less then 50 acounts 
        printf("Please enter amount for deposit: ");
        if(scanf(" %lf" ,&deposit)){//check if the input is a number.
          if(deposit>=0){//deposit can't be negative 
          deposit=((double)((int)(deposit*100))/100);//take deposit number until 2 numbers after the point.
          	O(deposit);
          }
          else printf("Invalid Amount\n");//if deposite is negative number.
        }
        else{
          printf("Failed to read the amount\n");//if if the input isn't a number.
        }
     }
     else printf("there is no place for new account\n");//if there is 50 acounts
     break;
    }
      case 'B': {//if the input is B get in.
        int account_number;
        printf("Please enter account number: ");
        if(scanf(" %d",&account_number))//check if the new input is a number. 
        {
          if(isInRange(account_number)){//check if account number is in range.
          	if(isopen(account_number))//if the acount is open.
            		B(account_number);
            	else printf("This account is closed\n");//if the acount isn't already open.	
          }
        }
        else{//if the input isn't a number
          printf("Failed to read the account number\n");
        }
        break;

        }
     case 'D' :{//if the input is D get in.
       int account_number;
        printf("Please enter account number: ");
        if(scanf(" %d",&account_number))//check if the new input is a number.
        {
         if(isInRange(account_number)){//check if account number is in range
            if(isopen(account_number)){//check if the account is open
              printf("Please enter the amount to deposit: ");
              double deposit;
              if(scanf(" %lf", &deposit)){//check if the new deposite is number.
                 deposit=((double)((int)(deposit*100))/100);//take the deposite until 2 numbers after the point.
                 if(deposit>=0)
                     D(account_number,deposit);
                     else printf("Cannot deposit a negative amount\n");//if negative.
              }
              else//if the deposite isn't a number.
              {
                printf("Failed to read the amount\n");
              }
              
          }
            else printf("This account is closed\n");	//if the acount is close.
        }
          else printf("Invalid account number\n");//if the acount number isn't in the range.
        }
        else{//if the input isn't a number.
        printf("Failed to read the account number\n");
        }
        break;
     }
      case 'W':{//if the input is W get in.
        int account_number;
        printf("Please enter account number: ");
        if(scanf(" %d",&account_number))//if the new input is a number get in.
        {
          if(isInRange(account_number)){//check if account number is in range
            if(isopen(account_number)){//check if the account is open
              double withdrawal;
              printf("Please enter the amount to withdraw: ");
              if(scanf(" %lf", &withdrawal)){//cheak if the input is number
              withdrawal=((double)((int)(withdrawal*100))/100);//take until 2 number after the point.
              			W(account_number,withdrawal);
              }
              else//if the input isn't a number.
              {
                printf("faild to read withdrow\n");
              }
              
          }//if the acount isn't open.
          else printf("This account is closed\n");	
        }//TODO
         else printf("Invalid account number\n");//if the acount number isn't in the range.
        }
        else{//if the account_number isn't number.
           printf("Failed to read the account number\n");
        }

      break;
    
      }
     case 'C':{//if the input is C get in.
        int account_number;
        printf("Please enter account number: ");
        if(scanf(" %d",&account_number))//if the new input is number.
        {
          if(isInRange(account_number)){//check if account number is in range
            if(isopen(account_number)){//check if the account is open
             C(account_number);
             printf("Closed account number %d\n", account_number);
             
          }
            	else printf("This account is already closed\n");//if the acount isn't already open.
            	}//todo
            	 else printf("Invalid account number\n");//if the acount number isn't in the range.	
          }
        else{//if the new input isn't a number.
        printf("Failed to read the account number\n");
    }
    break;
     }
      case 'I':{//if the input is I get in.
        int interest;
        printf("Please enter interest rate: ");
        if(scanf(" %d",&interest)==1){//check if the net input is number.
		 if(interest>=0)//interest can't negative    	
          		I(interest);
          	else printf("Invalid interest rate\n");		
        }
        else//the new input isn't a number.
        {
         printf("Failed to read the interest rate\n");
        }
          break;
    }
      case 'P':{//if the input is P get in.
           P();
           break;
    }
    case 'E':{//if the input is E.
      E();
      flag=TRUE;//this line break thw while.
      break;
    }
    default://else
        printf("Invalid transaction type\n");
    }
    }
}
    
