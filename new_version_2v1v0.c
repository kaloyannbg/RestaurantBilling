#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



#define ROWS 7
#define FOOD_LENGTH 15


    char foods[ROWS][FOOD_LENGTH] = {
                                        {'F', 'i', 's', 'h', '\0' },
                                        {'M', 'e', 'a', 't', '\0' },
                                        {'P', 'e', 'p', 'p', 'e', 'r','s', '\0' },
                                        {'P', 'i', 'z', 'z', 'a', '\0' },
                                        {'T', 'i', 'r', 'a', 'm', 'i','s','u', '\0' },
                                        {'A', 'p', 'p', 'l', 'e', 's', '\0' },
                                        {'E', 'g', 'g', 's', '\0' },

                                    };

    double foodsPrices[ROWS] = { 2.22, 5.55, 5.85, 9.48, 6.52, 2.55, 3.25  };

    int foodIDandFoodPieces[50];



    int foodID;

    int pieces;

    int foodsCounter = 0;

    double foodPriceTotal = 0.00;

    double fullTotalPrice = 0.00;

    int tempSquares;

    int tempSquaress;

int main() {


    int i, j, z;

    int menuChoice;

        char tempFood[FOOD_LENGTH];

        for(i = 0; i < ROWS; i++) {

        for(j = i + 1; j < ROWS; j++) {

            if(foods[i][0] > foods[j][0]) {

                strcpy(tempFood, foods[i]);

                strcpy(foods[i], foods[j]);

                strcpy(foods[j], tempFood);

            }

        }

    }

    do {

        printf("\n\n -- Billing Restaurant New Version 2.1.0 -- "); //Kaloyan Angelov - kaloyannbg github
        printf("\n __________________________________________");

        printf("\n\n -- Enter 1 for food menu --");
        printf("\n\n -- Enter 2 for choose food ID --");
        printf("\n\n -- Enter 3 for view the bill --");

        printf("\n\n -- Enter your choice: ");
        scanf("%d", &menuChoice);

        if(menuChoice == 1) {

    printf("\n -- FOODS --      -- PRICES --\n\n");

    for(i = 0; i < ROWS; i++) {

        printf("    ");

        for(j = 0; foods[i][j] != '\0'; j++) { // foods[i][j] != '\0' like j < atrlen(foods[i])

            printf("%c", foods[i][j]);


        }

        tempSquares = FOOD_LENGTH - strlen(foods[i]);

            for(int z = 0; z < tempSquares + 2; z++) {
                printf(" ");
            }

        printf("$ %.2f", foodsPrices[i]);

        printf("\n");
    }

        } else if(menuChoice == 2) {

            printf("\n oo Enter your food ID: ");

            scanf("%d", &foodID);

            foodID = abs(foodID);

            if(foodID > ROWS) {
                printf("\n\n !! Food ID don\'t exist! View again food menu! !! ");
            } else {

                printf("\n\n -- You choose: %s , the price is: $ %.2f -- ", foods[foodID], foodsPrices[foodID]);

                printf("\n\n -- Enter how much pieces from %s you want: ", foods[foodID]);

                scanf("%d",&pieces);

                pieces = abs(pieces);

                if(pieces < 1 ) {

                    printf("\n\n !! You dont choose piece. !! ");

                } else if(pieces > 99) {

                    printf("\n\n !! You can\'t buy more than 99 pieces");

                }

                 else {

                    foodIDandFoodPieces[foodsCounter] = foodID;

                    foodsCounter++;

                    foodIDandFoodPieces[foodsCounter] = pieces;

                    foodsCounter++;

                }
            }



        } else if( menuChoice == 3 ) {

            if(foodsCounter < 1) {
                printf("\n\n -- You don\'t have bill. -- ");
            } else {

                printf("\n\n========================================================================\n\n");

                printf(" -- FOOD --      -- PRICE --      -- PIECES --     -- TOTAL PRICE -- \n\n");

                for(i = 0; i < foodsCounter; i++) {

                    if( (i % 2) == 0 ) {

                        foodID = foodIDandFoodPieces[i];

                        foodPriceTotal = foodsPrices[foodID] * foodIDandFoodPieces[i+1];

                        fullTotalPrice = fullTotalPrice + foodPriceTotal;

                        //printf("\nFood: %s : $ %.2f", foods[foodID], foodsPrices[foodID]);

                        printf("    ");
                        for(j = 0; foods[foodID][j] != '\0'; j++) {

                            printf("%c", foods[foodID][j]);

                        }

                        tempSquares = FOOD_LENGTH - strlen(foods[foodID]);

                         for(z = 0; z < tempSquares; z++) {

                            printf(" ");

                        }


                        printf("$ %.2f ", foodsPrices[foodID]);


                    } else {

                        printf("             %d", foodIDandFoodPieces[i]);

                        int tempFoodPiece = foodIDandFoodPieces[i];

                        int tempFoodPieceCounter = 0;

                        while(tempFoodPiece > 0) {

                            tempFoodPiece = tempFoodPiece / 10;

                            tempFoodPieceCounter++;
                        }

                        if(tempFoodPieceCounter == 1) {
                            printf("  ");
                        } else if (tempFoodPieceCounter == 2) {
                            printf(" ");
                        }

                        printf("              $ %.2f", foodPriceTotal);

                        printf("\n");

                    }

                }

                    printf("\n========================================================================");

                    printf("\n     ---- ---- ---- Total Price of all: $ %.2f ---- ---- ----", fullTotalPrice);

                    printf("\n========================================================================\n\n");

                    fullTotalPrice = 0;


            }

        }


    } while(menuChoice != 0);




    return 0;
}
