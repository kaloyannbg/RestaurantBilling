#include <stdio.h>
#include <stdlib.h>

#define ROWS 9
#define COLUMNS 10
#define SAVED_PRODUCTS 100 //cAN SAVE 50 ids and 50 products like key = id [0], value = Pieces [1] ...

char foods[ROWS][COLUMNS] = {"x", "Pizza", "Pasta", "Salad", "Meat", "Eggs", "Fish", "Fries", "Tiramisu"};

float foodsPrices[ROWS] = { 0.00, 5.50, 4.80, 3.20, 6.50, 3.00, 5.80, 2.80, 5.85 };

int productCount = 0;

int foodSavedID[SAVED_PRODUCTS]; // GET THE PRODUCTS WITH THEIR ID-S

void printMenu(void) {

    printf(" *** -- Menu -- Restaurant Software -- ***\n\n");
    printf(" ** 1. Print Foods and Prices \n");
    printf(" ** 2. Create new bill \n");
    printf(" ** 0. Quit from program \n");
    printf("\n");

}

void printFoodsAndPrices(void) {

    int i = 1;

    int j = 0;

    printf("** Food ID ** Food.    **Price \n\n");

    for(i; i < ROWS; i++) {
        printf("**   %d.       ", i);

        for(j; j < COLUMNS; j++) {
            printf("%c", foods[i][j]);
        }
        printf("$ %.2f ", foodsPrices[i]);
        printf("\n");

        //printf("** %d. %s      %.2f\n",i, foods[i], foodsPrices[i]);
    j = 0;

    }

}

void printHorizontalFoodMenuAndPrices(void) {

    int j;

    for(int i = 1; i < ROWS; i++) {

                 printf(" ID %d. ", i);

                for(j = 0; j < COLUMNS; j++) {
                    printf("%c", foods[i][j]);
                }

                printf("$ %.2f |", foodsPrices[i]);

                if( (i % 4) == 0 ) {
                    printf("\n");
                }

            }

}

void createBillMenu(void) {
    printf(" *** -- Bill Menu -- Restaurant Software -- ***\n\n");

    printf(" ** 1. Add food \n");
    printf(" ** 2. Show the bill \n");
    printf(" ** 0. Quit from bill \n");
    printf("\n");

}

void printTheBill() {

    float piecesTotalAmount;

    float totalAmount;

    totalAmount = 0;

    printf("\n\n");

    if(productCount < 1) {

        printf("Dont have bill for showing!");

    } else {
        printf(" ******** bill *********\n\n");
        printf(" **ID**  **Foods**   **Price**    **Pieces**  **Total Price**\n\n");

        int counter = 1;

        for(int i = 0; i < productCount; i++) {


        if( (i % 2) == 0 ) {
            //even nums is food id
            //printf("food id = %d  ", foodSavedID[i]);

            printf("   %d.     ", counter++);

            for(int j = 0; j < COLUMNS; j++ ) {
            printf("%c", foods[foodSavedID[i]][j] );
            }

            printf("   $ %.2f", foodsPrices[foodSavedID[i]] );         //foodSavedID[0] return saved food ID and search in foods array


        } else {
            //odd nums is pieces id
            //printf("pieces = %d || ", foodSavedID[i]);
            //float IDofPrice
            piecesTotalAmount = foodsPrices[foodSavedID[i-1]] * foodSavedID[i];
            printf("          %d            %.2f\n", foodSavedID[i], piecesTotalAmount  );    //foodSavedID[1] return saved pieces of food
            printf(" *************************************************************\n");

            totalAmount = totalAmount + piecesTotalAmount;

        }

    }

        printf("\n *************************************************************\n");

        printf(" *                 Total amount: $ %.2f                    ", totalAmount);

        printf("\n *************************************************************\n\n");

    }

    printf("\n\n");
}

int main()
{
    int menuChoice;

    int billMenuChoice;

    int foodID;

    do {

        printMenu();

        printf("Enter your choice: ");

        scanf("%d", &menuChoice);

        printf("\n\n");

        if(menuChoice == 1) {

            printFoodsAndPrices();

        } else if (menuChoice == 2) {

            createBillMenu();

            printf("Enter Bill Menu Choice: ");

            scanf("%d", &billMenuChoice);

            while(billMenuChoice != 0) {

            printf("\n");

            if(billMenuChoice == 1) {

            printHorizontalFoodMenuAndPrices();

            printf("\n\n");

            printf("Food ID: ");

            scanf("%d", &foodID);
            printf("\n");
            if(foodID < 1 || foodID > ROWS) {

                printf("That food id don\'t exist! Try again!");

            } else {

            printf("Enter how much pieces of %s: ", foods[foodID]);

            int pieces;

            scanf("%d", &pieces);

            printf("\n\n");

            foodSavedID[productCount] = foodID;

            productCount++;

            foodSavedID[productCount] = pieces;

            productCount++;

            }

            } else if (billMenuChoice == 2) {
                printTheBill();
            }

            createBillMenu();

            printf("Enter Bill Menu Choice: ");

            scanf("%d", &billMenuChoice);

            }

       } else if (menuChoice == 0) {

        printf("Okay! Bye bye!");

        } else {
        printf("Invalid choice! Try again!");
        }

        printf("\n\n");

    } while(menuChoice != 0);

    return 0;
}
