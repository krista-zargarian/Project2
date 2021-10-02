#include <stdio.h>
#include "fees_and_expenses.c"

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
   printf("How many days spent on the trip?");
   TotalDaysOnTrip = ValidateInput_days();
   float subtractedParking = companyParking(TotalDaysOnTrip);
   float subtractedTaxi = companyTaxi(TotalDaysOnTrip);
   float subtractedHotel = companyHotel(TotalDaysOnTrip);
   printf("%.2f", subtractedHotel+subtractedParking+subtractedTaxi);
   return 0;
}