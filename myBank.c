#include<stdio.h>
#include "myBank.h"
#define ACCOUNTS 50
#define SITUATIONS 2
#define STARTER 901
#define END 950
double matrix_2d [ACCOUNTS][SITUATIONS]={0};
int i=0;
void O(double deposit){//this function is to open a new acount.
    int j=0;
    while(matrix_2d[j][1]==1)//run until find acount that is close.
    {j++;}
    matrix_2d[j][0]=deposit;//init the deposite in the acount.
    matrix_2d[j][1]=1;//init this acount to open.
    printf( "New account number is: %d \n", (STARTER+j) );
    i++;//count the numbers of acounts.
}

void B(int account_number){//this function is to know the acount balance. 
        if(matrix_2d[account_number-STARTER][1]==1){//check if this acount is open
        printf( "The balance of account number %d is: %.2lf\n", account_number, matrix_2d[account_number-STARTER][0]);
        }
        else{//if this acount is close.
            printf("This account is closed\n");
        }
    }
void D (int account_number,double deposit){//this function is to cash deposite in the acount.
        matrix_2d[account_number-STARTER][0]+=deposit;//add the deposite to the acount.
        printf("The new balance is: %.2lf\n" , matrix_2d[account_number-STARTER][0]);
        }
void W(int account_number,double withdrawal){//this function is to cash withdrawal from the acount.
    if(matrix_2d[account_number-STARTER][0]>=withdrawal){//if the money the user want to withdrawal is less than what he have in the acount.
        matrix_2d[account_number-STARTER][0]-=withdrawal;//init the acount.
        printf("The new balance is: %.2lf\n" , matrix_2d[account_number-STARTER][0]);
    }//if the money the user want to withdrawal is bigger than what he have in the acount.
    else printf("Cannot withdraw more than the balance\n");

}
void C(int account_number){//this function is to close acount.
     matrix_2d[account_number-STARTER][1]=0;//close the acount.
     i--;//update the number of acounts.
}
void I(int interest){//this function is to add interest to all the acounts.
    int j;
    for(j=0;j<ACCOUNTS;j++)//run over the acounts
        if(matrix_2d[j][1]==1)//if the acount is open,do.
            matrix_2d[j][0]=(matrix_2d[j][0]+matrix_2d[j][0]*interest/100);//update the acount after the interest.
}
void P(){//this function is to print all the open acounts.
    int j=0;
    if(i>0){
    for(j=0; j<ACCOUNTS;j++){//run over the acounts.
        if(matrix_2d[j][1]==1)//if the acount is open,print.
            printf("The balance of account number %d is: %.2lf\n" , (STARTER+j), matrix_2d[j][0]);
    }
    }
}
void E(){//close all the acounts and get out from this plan.
    int j=0;
    for(j=0; j<ACCOUNTS;j++){//run over all the acounts.
        if(matrix_2d[j][1]==1)//if this acount is open,close him.
             matrix_2d[i][1]=0;
    }
}
int isopen(int account_number){//function that check if acount is open.
    return matrix_2d[account_number-STARTER][1];
}
int isInRange(int account_number){//function that check if the acount is in the range.
    if(account_number>STARTER-1&&account_number<END)
        return 1;
    else return 0;    
}
int getNumberOfOpenAccounts(){//function that return the numbers of the open acount in the bank.
    return i;
}
