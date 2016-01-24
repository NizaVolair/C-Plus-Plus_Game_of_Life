/****************************************************************************************
 **Program Filename: Life 
 **Author: Niza Volair
 **Date: 04-05-2015
 **Description: This is the client code for the game of life which uses the game class
 **Input: Ingers representing x and y coordinates
 **Output: 40x20 arrays displaying 3 sequences from the game of life 
 ***************************************************************************************/
#include <iostream>
#include <iomanip>
#include "Game.hpp"

using namespace std;

int main()
{
   //declare a game object and choice, x and y coordinate integers initialized to 1;
   Game game;
   int choice, xCoord, yCoord;
   choice = xCoord = yCoord = 1;
   
   //display menu and options in a do while loop
   cout << endl << "~~~~~~Welcome to the Game of Life~~~\n" << endl;
   do
   {
      do
      {	 //loop menu until a correct selection is made
	 cout << "~Select Game~\n";
	 cout << "1) Blinker\n";
	 cout << "2) Glider\n";
	 cout << "3) Cannon\n";
	 cout << "4) Clear Games\n";
	 cout << "5) Death\n";
	 cout << endl << "Selection: ";
	 cin >> choice;
	 
	 //vallidate choice
         if((choice < 1) || (choice > 5))
	 {  cout << endl << "That's just not a game we can play!";
	    cout << " Try again in the Game of Life." << endl << endl;
	 }

      }while((choice < 1) || (choice > 5));
   
      //get x and y coordiates for the first two designs
      if((choice == 1) || (choice == 2))
      {
	 cout << endl << "~~Select Coordinates~~\n";   
         cout << "X Coordinate 1 to 40: ";
         cin >> xCoord;
	 cout << "Y Coordinate 1 to 20: ";
         cin >> yCoord;
      }
      
      //get only coordinate for the third design and limit from 1 to 10 for full display
      else if(choice == 3)
      {
      	 cout << endl << "~Select Cannon Position~\n";
	 cout << "Y Coordinate 1 to 10: ";
         cin >> yCoord;
      }

      //validate coordiates and call correct funtions
      switch (choice)
      {
	    case 1:  if(game.validate(yCoord, xCoord))
			game.oscillator(yCoord, xCoord);
		     break;
	    case 2:  if(game.validate(yCoord, xCoord))
			game.glider(yCoord, xCoord);
		     break;
	    case 3:  if((yCoord > 0) && (yCoord < 11))
			game.cannon(yCoord);
		     else
		     {	cout << endl << "What!? That's not a proper Y Coordinate!";
		     	cout << " Try again in the Game of Life." << endl << endl;
		     }
		     break;		
	    case 4:  cout << endl;
		     game.clear();
		     break;
	    case 5:  cout << endl << "Goodbye!!" << endl << endl;
		     break;
      }

   }while((choice > 0) && (choice < 5));
   
   return 0;
}
