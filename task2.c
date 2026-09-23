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
    float newTempC =0; //for use in temperature categorization
    char category[20] = "default";
    char advisory[20] = "default"; 


    printf("Enter a temperature:\n");
    // scanf("%d", &userTemp);
    fgets(userTemp, 20, stdin);
    // int INTuserTemp = atoi(userTemp);
    float INTuserTemp = atof(userTemp); //it is named INT but it is actually a FLOAT

    printf("Enter the original scale (C,F, or K): \n");
    // scanf("%c", &userScale);
    fgets(userScale, 20, stdin);


    printf("Enter the scale to convert to (C, F, or K): \n");
    // scanf("%c", &userConversion);
    fgets(userConversion, 20, stdin);

    //temperature conversion
    if (userScale[0] == 'C') // userScale is C
    {
        newTempC = INTuserTemp; //save temp as C for category and advisory
        if (userConversion[0] == 'K') // c to k
        {
            newTemp = INTuserTemp + 273.15;
        }
        else if (userConversion[0] == 'F') // c to f
        {
            newTemp = (INTuserTemp * (9.0/5.0)) + 32.0;
        }
    } 
    else if (userScale[0] == 'K') // userScale is K
    {
        if (userConversion[0] == 'C')// k to c
        {
            newTemp = INTuserTemp - 273.15; 
            newTempC = newTemp; //save temp as C for category and advisory
        }
        else if (userConversion[0] == 'F') // k to f
        {
            newTemp = ((INTuserTemp - 273.15) * (9.0/5.0)) + 32.0;

            //convert to C for later use in category and advisory
            newTempC = INTuserTemp - 273.15;
        }
    }
    else if (userScale[0] == 'F') // userScale is F
    {
        if (userConversion[0] == 'C')// f to c
        {
            newTemp = (INTuserTemp - 32.0) * (5.0/9.0);
            newTempC = newTemp; //save temp as C for category and advisory
        }
        else if (userConversion[0] == 'K')// f to k
        {
            newTemp = ((INTuserTemp - 32.0) * (5.0/9.0)) + 273.15;
            //convert to C for later use in category and advisory
            newTempC = (INTuserTemp - 32.0) * (5.0/9.0);
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
    
    //output defined by user conversion
    if (userConversion[0] == 'C')
    {
        printf("Converted temperature: %f C\nTemperature Category: %s\nWeather Advisory: %s\n", newTemp,category,advisory);
    }
    else if (userConversion[0] == 'F')
    {
        printf("Converted temperature: %f F\nTemperature Category: %s\nWeather Advisory: %s\n", newTemp,category,advisory);
    }
    else if (userConversion[0] == 'K')
    {
        printf("Converted temperature: %f K\nTemperature Category: %s\nWeather Advisory: %s\n", newTemp,category,advisory);
    }
    
    


}