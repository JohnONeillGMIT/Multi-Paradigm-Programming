#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
    int index;
};

struct Shop
{
    double cash;
    struct ProductStock stock[20];
};

/* The Method!*/


void printProduct(struct Product p)
{
    printf("PRODUCT NAME: %s \nPRODUCT PRICE: %.2F\n", p.name, p.price);
    printf("-------\n");
}

void printCustomer(struct Customer c)
{
    printf("CUSTOMER NAME: %s \nCUSTOMER BUDGET: %.2f\n", c.name, c.budget);
    printf("-------\n");
    for(int i=0; 1 < c.index; i++)
    {
        printProduct(c.ShoppingList[i].Product);
        printf("%s ORDERS %d OF ABOVE PRODUCT\n", c.name,c.ShoppingList[i].quantity);
    /* chaining of access using the index*/


        double cost = c.ShoppingList[i].quantity * c.ShoppingList[i].Product.price;
        printf("the cost to %s will be %.2f\n",c.name,cost);
        // keeping track of costs //
    }
}

struct Shop createAndStockShop()
{
	struct Shop shop = { 200 };
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("stock.csv", "r"); //reading in the stock file for the Shop//
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        // fp = file pointer //
        // printf("Retrieved line of length %zu:\n", read);
        printf("%s IS A LINE", line);
		char *n = strtok(line, ","); /* string tokeniser breaks out the line bu using the , */
		char *p = strtok(NULL, ","); /* NULL is a special char, meaning "nothing", line continues on from last , */
		char *q = strtok(NULL, ","); /* n=name, p=price, q=quantity */
		int quantity = atoi(q); /* atoi converts string to integer*/
		double price = atof(p); /* atof converts string to float*/
		char *name = malloc(sizeof(char) * 50);
		strcpy(name, n); /* string copy from a source to a destination (more low level stuff on pointers/memory) */
		struct Product product = { name, price };
		struct ProductStock stockItem = { product, quantity };
		shop.stock[shop.index++] = stockItem;
		//printf("NAME OF PRODUCT %s PRICE %.2f QUANTITY %d\n", name, price, quantity);
    }
	
	return shop;
}

void printShop(struct Shop s)
{
	printf("Shop has %.2f in cash\n", s.cash);
	for (int i = 0; i < s.index; i++)
	{
		printProduct(s.stock[i].product);
		printf("The shop has %d of the above\n", s.stock[i].quantity);
	}
}


int main(void)
{  
    struct Customer Dominic = {"Dominic", 100.0};
 
    struct Product Coke = {"Can of Coke", 1.10};
    struct Product Bread = {"Bread", 0.7};
    
    struct ProductStock CokeStock = { Coke, 20};
    struct ProductStock BreadStock = { Bread, 2};

    Dominic.ShoppingList[Dominic.index++] = CokeStock; /* recreating and index to step through array*/
    Dominic.ShoppingList[Dominic.index++] = BreadStock;
   
    printCustomer(Dominic); */

    struct Shop shop = createAndStockShop();
	printShop(shop);



    /*printf("The shop had %d of the product %s\n", CokeStock.quantity, CokeStock.Product.name);*/
    return 0;    
}