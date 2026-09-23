/*
Date: 9.23.26
Author: Ana Gonzalez Yuil
Lab: 4
Sources:N/A
Description: Football Score Calculator
*/

#include <stdio.h>

//global variables
int score;
int TD = 6;
int FG = 3;
int safety = 2;
int TD_2PtConversion = 8;
int TD_1PtFG = 7;

int calculate(int score, int TDC, int FGC, int safetyC, int TD2C, int TD1C)
// takes amount of times to multiply each score
{
    while (score > 0)
    {
        // printf("score in function is %d", score);
        if (TDC == 0) //tdc is incremented outside of function
        {
            score = score - (FG * FGC) - (safety * safetyC);
        }
        else
        {
            score = score - (TD * TDC) - (FG * FGC) - (safety * safetyC) - (TD_2PtConversion * TD2C) - (TD_1PtFG * TD1C);
        }

        FGC++;
        safetyC++;
        TD2C++;
        TD1C++;

        // printf("%d", safetyC);
    }

    return FGC, safetyC, TD2C, TD1C;
}

int main()
{
    int TDCount = 0;
    int FGCount = 0;
    int safetyCount = 0;
    int TD_2PtConversionCount = 0;
    int TD_1PtFGCount = 0;
    // if no TD, cant get other TD related pts

    printf("Enter the NFL score (Enter 1 to stop): ");
    scanf("%d",&score);

    while (score < 0)
    {
      printf("Invalid Score, enter again: ");
      scanf("%d",&score);  
    }

    while (score != 1)
    {
        for (int i = 0; i < 30; i++)
        {
            FGCount, safetyCount, TD_2PtConversionCount, TD_1PtFGCount = calculate(score, TDCount, FGCount, safetyCount, TD_2PtConversionCount, TD_1PtFGCount);
            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",TD_2PtConversionCount, TD_1PtFGCount, TDCount, FGCount, safetyCount);
            TDCount++;
        }

        printf("Enter the NFL score (Enter 1 to stop): ");
        scanf("%d",&score);
    }

    printf("program ended\n");
    return 0; 
}