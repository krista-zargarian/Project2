#include <stdio.h>
#include "fees_and_expenses.c"
#include "foodExpenses.c"
 
int ValidateInput_days(){
 int user_input;
 scanf("%d", &user_input);
 getchar(); // clears the buffer
 while( user_input < 1 ){
  ///Output an error and tell user to enter again
scanf("%d", &user_input);
  fflush(stdout);
 }
 return user_input;
}
 
int main()
{
  int TotalDaysOnTrip = 0;
  printf("How many days spent on the trip?\n");
  TotalDaysOnTrip = ValidateInput_days();
  float costAirfare = airfare();
  float costRentals = carRentals();
  float costPrivateVehicle = privateVehicle();
  float costTotalParking = totalParking();
  float costTotalTaxi = totalTaxi();
  float costFees = registrationFees();
  float costTotalHotel = totalHotel();
  float subtractedParking = companyParking(TotalDaysOnTrip);
  float subtractedTaxi = companyTaxi(TotalDaysOnTrip);
  float subtractedHotel = companyHotel(TotalDaysOnTrip);

  float costMeals = getMealFees(TotalDaysOnTrip);
  float normal = normalMealFees(TotalDaysOnTrip);
  float covered = getCoveredCosts(TotalDaysOnTrip);
  
  //Cost of items that the employee might have to pay for
  float debatedItems = costTotalParking + costTotalTaxi + costTotalHotel + costMeals + normal;
  //Amounts covered by company
  float coveredValue = subtractedParking + subtractedTaxi + subtractedHotel + costPrivateVehicle + covered;
  //Employee balance
  float employeeBalance = debatedItems-coveredValue;
  //Cost of rest of trip.
  float remainingTripCost = costAirfare + costRentals + costFees + costMeals;
  //Total Trip Cost
  float tripCost = remainingTripCost + debatedItems;
  //Allowable expenses
  float allowableExpenses = coveredValue + remainingTripCost;
 
  printf("The total expenses incurred are: $%.2f\nThe total allowable expenses allowed by the trip are $%.2f\n", tripCost, allowableExpenses);
 
  if (employeeBalance > 0) {
      printf("The employee owes the company $%.2f\n", employeeBalance);
  }
  else {
      printf("The employee saved the company $%.2f\n", employeeBalance*(-1.0));
  }
 
  return 0;
}
