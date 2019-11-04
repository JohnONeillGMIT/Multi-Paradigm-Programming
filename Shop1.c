#include <stdio.h>
#include <string.h>


struct Product
{
    char* name;
    double price;
};

/* A struct can contain a struct*/

struct ProductStock
{
    struct Product Product;
    int quantity;
};

struct Customer
{
    char* name;
    double budget;
    struct ProductStock ShoppingList[10];
};

struct Shop
{
    double cash;
    struct ProductStock stock[20];
};

/* The Method!*/

void printCustomer(struct Customer c)
{
    printf("-------\n");
    printf("CUSTOMER NAME: %s \nCUSTOMER BUDGET: %.2F\n", c.name, c.budget);
    printf("-------\n");
}
void printProduct(struct Product p)
{
    printf("-------\n");
    printf("PRODUCT NAME: %s \nPRODUCT PRICE: %.2F\n", p.name, p.price);
    printf("-------\n");
}


int main(void)
{   struct Customer Dominic = {"Dominic", 100.0};
    /* printf("Customer name is %s\n", Dominic.name); */
    printCustomer(Dominic);
    
    struct Product Coke = {"Can of Coke", 1.10};
    /* printf("The %s costs %.2f\n", Coke.name, Coke.price);*/
    printProduct(Coke);
    
    struct ProductStock CokeStock = { Coke, 20};
    printf("The shop had %d of the product %s\n", CokeStock.quantity, CokeStock.Product.name);
    return 0;    
}