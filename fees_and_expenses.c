#include <stdio.h>
#include <stdlib.h>

float airfare () {
    float input;
    int inputValidated = 0;
    while (inputValidated == 0) {
        printf("Please enter the amount spent on airfare.\n");
        scanf("%f", &input);
        if (input < 0) {
            printf("Please enter a positive number or zero.\n");
         }
         else {
             inputValidated = 1;
         }
    }
    return input;
}

float carRentals () {
    float input;
    int inputValidated = 0;
    while (inputValidated == 0) {
        printf("Please enter the amount spent on car rentals.\n");
        scanf("%f", &input);
        if (input < 0) {
            printf("Please enter a positive number or zero.\n");
         }
         else {
             inputValidated = 1;
         }
    }
    return input;
}

float privateVehicle () {
    float input;
    int inputValidated = 0;
    while (inputValidated == 0) {
        printf("Please enter the miles driven with your private car.\n");
        scanf("%f", &input);
        if (input < 0) {
            printf("Please enter a positive number or zero.\n");
         }
         else {
             inputValidated = 1;
         }
    }
    return (input*0.27);
}

float totalParking () {
    float input;
    int inputValidated = 0;
    while (inputValidated == 0) {
        printf("Please enter the amount spent on parking.\n");
        scanf("%f", &input);
        if (input < 0) {
            printf("Please enter a positive number or zero.\n");
         }
         else {
             inputValidated = 1;
         }
    }
    return input;
}

float companyParking (int days) {
    float coveredParking = 6.00;
    return (coveredParking*days);
}

float totalTaxi () {
    float input;
    int inputValidated = 0;
    while (inputValidated == 0) {
        printf("Please enter the amount spent on taxis.\n");
        scanf("%f", &input);
        if (input < 0) {
            printf("Please enter a positive number or zero.\n");
         }
         else {
             inputValidated = 1;
         }
    }
    return input;
}

float companyTaxi (int days) {
    float coveredTaxi = 10.00;
    return (coveredTaxi*days);
}

float registrationFees () {
    float input;
    int inputValidated = 0;
    while (inputValidated == 0) {
        printf("Please enter the amount spent on conference or seminar registration fees.\n");
        scanf("%f", &input);
        if (input < 0) {
            printf("Please enter a positive number or zero.\n");
         }
         else {
             inputValidated = 1;
         }
    }
    return input;
}

float totalHotel () {
    float input;
    int inputValidated = 0;
    while (inputValidated == 0) {
        printf("Please enter the amount spent on hotels and lodging.\n");
        scanf("%f", &input);
        if (input < 0) {
            printf("Please enter a positive number or zero.\n");
         }
         else {
             inputValidated = 1;
         }
    }
    return input;
}

float companyHotel (int days) {
    float coveredLodging = 90.00;
    return (coveredLodging*days);
}