/*
Date: 9.23.26
Author: Ana Gonzalez Yuil
Lab: 4
Sources:N/A
Description: Temperature Conversion
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char userTemp[20];
    char userScale[20];
    char userConversion[20];

    float newTemp;
    float newTempC; //for use in temperature categorization
    char category[20] = "default";
    char advisory[20] = "default"; 


    printf("Enter a temperature:\n");
    // scanf("%d", &userTemp);
    fgets(userTemp, 20, stdin);
    int INTuserTemp = atoi(userTemp);

    printf("Enter the original scale (C,F, or K): \n");
    // scanf("%c", &userScale);
    fgets(userScale, 20, stdin);


    printf("Enter the scale to convert to (C, F, or K): \n");
    // scanf("%c", &userConversion);
    fgets(userConversion, 20, stdin);

    //temperature conversion
    if (userScale[0] == 'C')
    {
        newTempC = INTuserTemp;
        if (userConversion == 'K') // c to k
        {
            newTemp = INTuserTemp + 273.15;
        }
        else if (userConversion == 'F') // c to f
        {
            newTemp = (INTuserTemp * (9/5)) + 32;
        }
    } 
    else if (userScale == 'K')
    {
        if (userConversion == 'C')// k to c
        {
            newTemp = INTuserTemp - 273.15;
            newTempC = newTemp;
        }
        else if (userConversion == 'F') // k to f
        {
            newTemp = ((INTuserTemp - 273.15) * (9/5)) + 32;
        }
    }
    else if (userScale == 'F')
    {
        if (userConversion == 'C')// f to c
        {
            newTemp = (INTuserTemp - 32) * (5/9);
            newTempC = newTemp;
        }
        else if (userConversion == 'K')// f to k
        {
            newTemp = ((INTuserTemp - 32) * (5/9)) + 273.15;
        }
    } 

    //temperature categorization
    if (newTempC > -INFINITY && newTempC < 0)
    {
        strncpy(category, "Freezing", 20);
        strncpy(advisory, "Stay inside", 20);
    }
    else if (newTempC >= 0 && newTempC < 10)
    {
        strncpy(category, "Cold", 20);
        strncpy(advisory, "Wear a coat.", 20);
    }
    else if (newTempC >= 10 && newTempC < 25)
    {
        strncpy(category, "Comfortable", 20);
        strncpy(advisory, "Take a walk.", 20);
    }
    else if (newTempC >= 20 && newTempC < 35)
    {
        strncpy(category, "Hot", 20);
        strncpy(advisory, "Drink water.", 20);
    }
    else if (newTempC >= 35 && newTempC < INFINITY)
    {
        strncpy(category, "Extreme Heat", 20);
        strncpy(advisory, "Stay inside", 20);
    }
    
    if (userConversion == 'C')
    {
        printf("Converted temperature: %f C\nTemperature Category: %s\nWeather Advisory: %s\n", newTemp,category,advisory);
    }
    else if (userConversion == 'F')
    {
        printf("Converted temperature: %f F\nTemperature Category: %s\nWeather Advisory: %s\n", newTemp,category,advisory);
    }
    else if (userConversion == 'K')
    {
        printf("Converted temperature: %f K\nTemperature Category: %s\nWeather Advisory: %s\n", newTemp,category,advisory);
    }
    
    


}