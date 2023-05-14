/*******************************************************************
Name: Alyana Barrera
Assignment: Project 1
Description: This project prompts the user to input how many rolls they would like to roll a pair of dice.
After the input, the program will roll both dice the number of times the user typed in and will add the 
the sum of the random dice numbers each roll. At the end of program, it will share the number of sums total 
respectively for 2-12. (I hope that makes sense)
********************************************************************/

//all includes
#include <iostream>
#include <stdlib.h>
#include <time.h>

//to prevent having to write std all the time
using namespace std;

//function declaration (function description below)
void findResults(int arr[], int userNum, int sumNum);

int main() {

    //local variables
    int userValue; //for input from user for number of rolls
    
    //ask user for how many dice rolls they want and label it as userValue
    cout << "How many rolls? ";
    cin >> userValue;
    cout << endl;
    cout << "Simulating " << userValue << " rolls..." << endl;

    //Note: starts random number sequence (so it is different each time) 
    //for random numbers
    srand(time(NULL));

    int randNumTotalArray[userValue]; //array for the two dice's sum

    //loop for dice 1 and 2 limited to the number of rolls from usr input
    for (int i = 0; i < userValue; i++) {
        //used rand() to generate random numbers from 1-6
        int randNumDice1 = (rand() % 6) + 1;
        int randNumDice2 = (rand() % 6) + 1;

        //adds random numbers from each dice to create the sum
        int randNumTotal = randNumDice1 + randNumDice2;
        
        /*
        //Just to check if random numbers and addition of both worked.
        cout << randNumDice1 << " " << " " << randNumDice2 << "  " << randNumTotal << endl;
        */
        
        //add the sum of both dice to an array
        randNumTotalArray[i] = randNumTotal;
    }

    //find the total number of repeats of a singular number with the function findResults
    //goes from 2 -12 which are all possible totals from the dice

  /*
    cout << "Results: " << endl;
    findResults(randNumTotalArray, userValue, 2);
    findResults(randNumTotalArray, userValue, 3);
    findResults(randNumTotalArray, userValue, 4);
    findResults(randNumTotalArray, userValue, 5);
    findResults(randNumTotalArray, userValue, 6);
    findResults(randNumTotalArray, userValue, 7);
    findResults(randNumTotalArray, userValue, 8);
    findResults(randNumTotalArray, userValue, 9);
    findResults(randNumTotalArray, userValue, 10);
    findResults(randNumTotalArray, userValue, 11);
    findResults(randNumTotalArray, userValue, 12);
 */
  
  cout << "Results: " << endl;
    for (int j = 2; j < 13; j++) {
        findResults(randNumTotalArray, userValue, j);
    }
    }

  

/*******************************************************************
findResults: finds the number of repeating numbers (based on what sumNum is) within an array.

   Returns: sentence of how many times it was rolled (void)
   Parameters:
        arr[] (int) - mainly the random number total array.
        userNum (int) - another word for userValue which is the number of rolls.
        sumNum (int) - the number with are looking for repeats of. 
********************************************************************/

void findResults(int arr[], int userNum, int sumNum){
    //set count to 0 so that it can count in the loop
    int count = 0;

    //for loop restricted to repeat userValue amount of times
    for (int k = 0; k < userNum; k++) {
      //if the number in array at index k equals the sum number entered, then add 1 to count
      if (arr[k] == sumNum) {
        count++;
      }
    }
    //output that the sum number entered was rolled the number of times we have found 
    cout << sumNum << " was rolled " << count << " times" << endl;
}


