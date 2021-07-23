#include<stdlib.h>

struct Food{
    int id;
    char name[20];
    int price;
    // struct Node *next;
};

// struct Node *head = NULL;


struct Food menu[3];


struct Stack{
  int id;
  char name[20];
  int price;
  struct Stack *next;
};
struct Stack *top = NULL;

int sum = 0;

void push(int id,int price){
    struct Stack *temp;
    temp = (struct Stack*)malloc(sizeof(struct Stack));
    temp->id = id;
    temp->price = price;
    temp->next = NULL;
  

    if(top == NULL){
        top = temp;
    }else{
        struct Stack *temp2 = top;
        top = temp;
        top->next = temp2;
    }


}


void printNodes(){
    if(top == NULL){
        printf("Your Cart is Empty");
    }else{
        struct Stack *curr = top;
        while(curr != NULL){
            printf("You ordered %s that will cost you $%d \n", menu[curr->id].name, curr->price);
            // printf("%d \n", curr->price);
            // sum = sum + curr->price;
            curr = curr ->next;

        }
      
    }
}
void pop(){
    struct Stack *temp = top;

    if(top == NULL){
      printf("Nothing to remove your cart in empty. \n");
    }else{
    temp = top;
    top = top->next;
    printf("%s is no longer in your cart.\n ", menu[temp->id].name);
     //sum = sum - menu[temp->id].price;
    free(temp);
}
}
void newPop(){
    struct Stack *temp = top;

    if(top == NULL){
      printf("Nothing to remove your cart in empty. \n");
    }else{
    temp = top;
    top = top->next;
    //printf("%s is no longer in your cart.\n ", menu[temp->id].name);
     //sum = sum - menu[temp->id].price;
    free(temp);
}
}
void generateBill(){
    if(top == NULL){
        printf("Your Cart is Empty");
    }else{
        struct Stack *curr = top;
        while(curr != NULL){
            sum = sum + menu[curr->id].price;
            newPop();
            curr = curr ->next;
        }
        printf("\t\t---------------Your Total Bill is $%d-----------------", sum);
      
    }
}

void main(){

int choice = 99;
printf("\t\tCreate Menu ");
for(int i = 0; i < 3; i++){
  printf("%d Item \n",i+1);
    menu[i].id = i;
    printf("\nEnter Item Name: ");
    scanf("%s", &menu[i].name);
    printf("\nEnter Item Price:$ ");
    scanf("%d", &menu[i].price);
    
};


  

while(choice != -1){
  printf("\n\nHere is The Menu\n\n");
  // Print Menu
  for(int i = 0; i < 3; i++){
    printf("Product Name: %s\n", menu[i].name);
    printf("Price: $%d\n", menu[i].price);
    printf("Press : %d to Buy this \n", menu[i].id);
    printf("\n");
  };
  printf("Select What you want to buy: (-1 to exit)\n Enter 10 to remove last added item \n Press 11 to view your cart\n Press 12 to confirm your order and generate Bill\n");
  scanf("%d", &choice);
  if(choice == 0){
    push(menu[choice].id,menu[choice].price);
    printf("-----------%s Is added to your cart----------", menu[choice].name);
  } 
  else if(choice == 1){
    push(menu[choice].id,menu[choice].price);
    printf("------------%s Is added to your cart----------", menu[choice].name);
  } 
  else if(choice == 2){
    push(menu[choice].id,menu[choice].price);
    printf("----------%s Is added to your cart---------", menu[choice].name);
  }else if(choice == 10){
    pop();
    printf("Your Current Cart : ");
    printNodes();

  }else if(choice == 11){
    printf("Your Current Cart : ");
    printNodes();
  }else if(choice == 12){
    printNodes(); 
    generateBill();
    break;
  }
}

// printf("\nEnter the Food Item you want to buy\n");




    


}