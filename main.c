#include <stdio.h>

int open_account(float a[],int len,float dep){
  for(int i = 0;i < len;i++){
    if(a[i] == -1){
      if (dep >= 100){
        a[i] = dep;
        printf("\n\tAccount: %d\n",(i+100));
        break;
      }
      else {
        printf("\tAmount must be greater than 100\n");
        break;
      }
    }
    else if(i==49)
        printf("\tAll accounts are taken\n");
  }
}

int balance_inquiry(float a[],int len,int acc){
    int i = acc - 100;
    if(a[i] != -1){
        printf("\n\tAccount Number:%d\n\tBalance:$%.2f\n",acc,a[i]);
    }
    else{
        printf("\n\tThis Account is not open\n");
    }
}

int deposit(float a[],int len,int acc,float am){
    printf("\n\tAccount: %d\n",acc);
    int i = acc - 100;
    if(a[i] != -1){
        a[i] += am;
        printf("\tBalance:$%.2f\n",a[i]);
    }
    else
        printf("\n\tThis Account is not open\n");
}

int withdrawal(float a[],int len,int acc, float am){
    printf("\n\tAccount: %d\n",acc);
    int i = acc - 100;
    if(a[i] != -1){
        if((a[i] - am) >= 0){
            a[i] -= am;
            printf("\tBalance:$%.2f\n",a[i]);
        }
        else
            printf("\tInsufficient Funds Available\n");
    }
    else
        printf("\n\tThis Account is not open\n");
}

int close_account(float a[],int len,int acc){
    int i = acc - 100;
    if(a[i] != -1){
        a[i] = -1;
        printf("\n\tAccount Closed\n");
    }
    else
        printf("\n\tAccount is already Closed\n");
}
int compute_interest(float a[],int len,float rate){
    for(int i;i < len;i++){
        if(a[i] != -1)
            a[i] += (rate * a[i]);
    }
}

int print_all(float a[],int len){
    printf("\tAccount:\tAmount:\n");
    for(int i;i < len; i++){
        int acc = i + 100;
        if(a[i] != -1)
            printf("\t%d\t\t$%.2f\n",acc,a[i]);
        else
            printf("\t%d\t\tCLOSED\n",acc);
    }
}

int close_all(float a[],int len){
    for(int i;i < len;i++){
        a[i] = -1;
    }
    printf("\tExiting Program\n");
}

int main(void) {

  float array[50];
  for(int i = 0;i < 50;i++){
    array[i] = -1;
  }

  float amount;
  int account;
  float interest_rate;

  char trans_type;

  while(1){

    printf("\nTransaction Type? ");
    scanf(" %c",&trans_type);

    if((trans_type == 'o') || (trans_type == 'O')){
        printf("Initial Deposit? ");
        scanf("%f",&amount);
        open_account(array,50,amount);
    }
    else if((trans_type == 'b') || (trans_type == 'B')){
        printf("Account Number? ");
        scanf("%d",&account);
        balance_inquiry(array,50,account);
    }
    else if((trans_type == 'd') || (trans_type == 'D')){
        printf("Account Number? ");
        scanf("%d",&account);
        printf("Amount? ");
        scanf("%f",&amount);
        deposit(array,50,account,amount);
    }
    else if((trans_type == 'w') || (trans_type == 'W')){
        printf("Account Number? ");
        scanf("%d",&account);
        printf("Amount? ");
        scanf("%f",&amount);
        withdrawal(array,50,account, amount);
    }
    else if((trans_type == 'c') || (trans_type == 'C')){
        printf("Account Number? ");
        scanf("%d",&account);
        close_account(array,50,account);
    }
    else if((trans_type == 'i') || (trans_type == 'I')){
        printf("Interest Rate? ");
        scanf("%f",&interest_rate);
        compute_interest(array,50,interest_rate);
    }
    else if((trans_type == 'P') || (trans_type == 'p')){
        print_all(array,50);
    }
    else if((trans_type == 'e') || (trans_type == 'E')){
        close_all(array,50);
        break;
    }
    else
        printf("Invalid Input\n");
    }

  return 0;
}
