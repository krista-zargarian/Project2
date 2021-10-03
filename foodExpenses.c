#include <stdio.h>
#include <string.h>
/*
contact me if any variable names need changes or anything does not work
also sorry for the messiness
*/

float mealFeesFirstDay();
float mealFeesLastDay();
float normalMealFees(int days);
float getMealFees(int days);
float getExcessMealFees(int days);
float getCoveredCosts(int days);
static float totalCost;
static float totalSpent;

//returns the total spending of meals on the trip
float getMealFees(int days)
{
    return totalCost;
}

//the user is asked about their meal expenses when this is called
//calculates and returns the excess fees 
float getExcessMealFees(int days)
{
    float total = mealFeesFirstDay() + normalMealFees(days) + mealFeesLastDay();
    totalSpent = total;
    return total;
}

//this should return how much the company covered
float getCoveredCosts(int days)
{
    return totalCost - totalSpent;
}

//calculates meal costs on the first day based on the departure hour
//if the user enters the departure hour 7 am, 12 pm, or 6 pm
//they will be told they could not purchase a meal
//Not sure if hours after midnight should be included or not (1-6am) still counts as breakfast
//midnight is not included
float mealFeesFirstDay()
{
    float brkfst, lunch, dinner, total;
    int departure;
    char period[3];

    printf("Enter hour of departure [1-12] on your first day: ");
    scanf(" %d", &departure);
    while(departure < 1 || departure > 12)
    {
        printf("Please enter a valid hour [1-12]: \n");
        printf("(If your flight is at 11:30 am, enter 11)\n");
        scanf(" %d", &departure);
    }
    printf("Enter am or pm: ");
    scanf(" %s", period);
    while (strcmp(period, "am") != 0 && strcmp(period, "pm") != 0)
    {
        printf("Please enter a valid time period [am/pm]: \n");
        printf("In lowercase, not AM/PM/Pm/Am/aM/pM\n");
        scanf(" %s", period);
    }
    

    if(departure < 7 && strcmp(period, "am") == 0)
    {
        printf("How much did you pay for breakfast?\nEnter amount: ");
        scanf(" %f", &brkfst);
        totalCost+=brkfst;
    } else if (departure < 12 && departure > 7 && strcmp(period, "am") == 0)
    {
        printf("How much did you pay for lunch?\nEnter amount: ");
        scanf(" %f", &lunch);
        totalCost+=lunch;
    } else if(((departure < 6 && departure >= 1) && strcmp(period, "pm") == 0))
    {
        printf("How much did you pay for dinner?\nEnter amount: ");
        scanf(" %f", &dinner);
        totalCost+=dinner;
    } else{
        printf("You did not get the chance to eat. You have not been charged.\n");
        return 0;
    }

    if(brkfst <= 9 && lunch <= 12 && dinner <= 16)
    {
        printf("Your costs for the last day are within the spending limit!\n");
        return 0;
    } else{
        printf("You've gone over the limit for the last day.\n");
        total = (((brkfst-9) > 0) ? (brkfst-9):0) + (((lunch-12) > 0) ? (lunch-12):0) + (((dinner-16) > 0) ? (dinner-16):0);
        return total;
    }
}

//calculates meal costs on the last day based on the arrival hour
//12-7 am not considered
float mealFeesLastDay()
{
    float brkfst, lunch, dinner, total;
    int arrival;
    char period[3];

    printf("Enter hour of arrival [1-12] on the last day: ");
    scanf(" %d", &arrival);
    while(arrival < 1 || arrival > 12)
    {
        printf("Please enter a valid hour [1-12]: \n");
        printf("(If your arrival is at 11:30 am, enter 11)\n");
        scanf(" %d", &arrival);
    }
    printf("Enter am or pm: ");
    scanf(" %s", period);
    while (strcmp(period, "am") != 0 && strcmp(period, "pm") != 0)
    {
        printf("Please enter a valid time period [am/pm]: \n");
        printf("In lowercase, not AM/PM/Pm/Am/aM/pM\n");
        scanf(" %s", period);
    }

    if((arrival >= 8 && strcmp(period, "am") == 0) || (arrival == 12 && strcmp(period, "pm") == 0))
    {
        printf("How much did you pay for breakfast?\nEnter amount: ");
        scanf(" %f", &brkfst);
        totalCost+=brkfst;
    } else if (arrival >= 1 && arrival < 7 && strcmp(period, "pm") == 0) 
    {
        printf("How much did you pay for lunch?\nEnter amount: ");
        scanf(" %f", &lunch);
        totalCost+=lunch;
    } else if(arrival >= 7 && arrival < 12 && strcmp(period, "pm") == 0)
    {
        printf("How much did you pay for dinner?\nEnter amount: ");
        scanf(" %f", &dinner);
        totalCost+=dinner;
    } else{
        printf("You did not get the chance to eat. You have not been charged.\n");
        return 0;
    }

    if(brkfst <= 9 && lunch <= 12 && dinner <= 16)
    {
        printf("Your costs for the last day are within the spending limit!\n");
        return 0;
    } else{
        printf("You've gone over the limit for the last day.\n");
        total = (((brkfst-9) > 0) ? (brkfst-9):0) + (((lunch-12) > 0) ? (lunch-12):0) + (((dinner-16) > 0) ? (dinner-16):0);
        return total;
    }
}

//calcutes total costs of meals on trip days that are not the first and last day
//Will notify the user if they went over or were within the spending limit for each day
float normalMealFees(int days)
{
    float brkfst, lunch, dinner, total;
    total = 0;
    days-=2;
    while (days > 0)
    {
        printf("How much did you spend on breakfast for day %d?\n", (days+1));
        scanf(" %f", &brkfst);
        totalCost+=brkfst;
        brkfst-=9;
        printf("How much did you spend on lunch for day %d?\n", (days+1));
        scanf(" %f", &lunch);
        totalCost+=lunch;
        lunch-=12;
        printf("How much did you spend on dinner for day %d?\n", (days+1));
        scanf(" %f", &dinner);
        totalCost+=dinner;
        dinner-=16;

        if(brkfst <= 0 && lunch <= 0 && dinner <= 0)
        {
            printf("Your costs for that day are within the spending limit!\n");
        } else{
            printf("You went over the limit for that day.\n");
            total+=((brkfst > 0) ? brkfst:0) + ((lunch > 0) ? lunch:0) + ((dinner > 0) ? dinner:0);
        }
        days--;
    }
    
    return total;
}