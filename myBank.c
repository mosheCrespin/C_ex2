#include<stdio.h>
#include "myBank.h"
#define ACCOUNTS 50
#define SITUATIONS 2
#define STARTER 901
#define END 950
double matrix_2d [ACCOUNTS][SITUATIONS]={0};
int i=0;
void O(double deposit){
    int j=0;
    while(matrix_2d[j][1]==1){j++;}
    matrix_2d[j][0]=deposit;
    matrix_2d[j][1]=1;
    printf( "New account number is: %d\n", (STARTER+j) );
    i++;
}
void B(int account_number){
        if(matrix_2d[account_number-STARTER][1]==1){
        printf( "The balance of account number %d is: %.2lf\n", account_number, matrix_2d[account_number-STARTER][0]);
        }
        else{
            printf("This account is closed\n");
        }
    }
void D (int account_number,double deposit){
        matrix_2d[account_number-STARTER][0]+=deposit;
        printf("The new balance is: %.2lf\n" , matrix_2d[account_number-STARTER][0]);
        }
void W(int account_number,double withdrawal){
    if(matrix_2d[account_number-STARTER][0]>=withdrawal){
        matrix_2d[account_number-STARTER][0]-=withdrawal;
    }
    else printf("There is not enough balance\n");
    printf("The new balance is: %.2lf\n" , matrix_2d[account_number-STARTER][0]);
}
void C(int account_number){
     matrix_2d[account_number-STARTER][1]=0;
     i--;
}
void I(int interest){
    int j;
    for(j=0;j<ACCOUNTS;j++)
        if(matrix_2d[j][1]==1)
            matrix_2d[j][0]=(matrix_2d[j][0]+matrix_2d[j][0]*interest/100);
}
void P(){
    int j=0;
    for(j=0; j<ACCOUNTS;j++){
        if(matrix_2d[j][1]==1)
            printf("The balance of account number %d is: %.2lf\n" , (STARTER+j), matrix_2d[j][0]);
    }
}
void E(){
    int j=0;
    for(j=0; j<ACCOUNTS;j++){
        if(matrix_2d[j][1]==1)
             matrix_2d[i][1]=0;
    }
}
int isopen(int account_number){
    return matrix_2d[account_number-STARTER][1];
}
int isInRange(int account_number){
    if(account_number>STARTER-1&&account_number<END)
        return 1;
    else return 0;    
}
int getNumberOfOpenAccounts(){
    return i;
}
