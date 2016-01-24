/****************************************************************************************
 **Program Filename: Game
 **Author: Niza Volair
 **Date: 04-05-2015
 **Description: This is the implimentation file for the game class
 **Output: 40x20 arrays displaying 3 sequences from the game of life and error messages
 ***************************************************************************************/
#include <iostream>
#include "Game.hpp"

using namespace std;


//define default constructor
Game::Game()
{
   //set both arrays full of (.) dead spaces to initializes game
   for(int i = 0; i < 27; i++)
   {  for(int j = 0; j < 47; j++)
      {	 table[i][j] = '.';	 
      }
   }
   for(int i = 0; i < 27; i++)
   {  for(int j = 0; j < 47; j++)
      {	 tableCopy[i][j] = '.';	 
      }
   }
}


/****************************************************************************************
 Function: Print Game Board
 Description: This method prints the board to diplay the current state of life
 Parameters: None
 Pre-Conditions: Must be initialized by default constructor and called 
 Post-Conditions: Must display the current state of the board
 ***************************************************************************************/
void Game::print()
{
   //print row numbers
   cout << "  1 2 3 4 5 6 7 8 91011121314151617181920"; 
   cout << "2122232425262728293031323334353637383940" << endl;
   
   //uses for loop to print array with 4 character buffer on all sides for edge cases
   for(int i = 4; i < 24; i++)
   {  //print column numbers accounting for buffer
      cout << (i-3);
      if (i < 13)
	 cout << " ";
      for(int j = 4; j < 44; j++)
      {	 cout << table[i][j] << " ";	 
      }
      cout << endl;
   }
   cout << endl;
}


/****************************************************************************************
 Function: Rules
 Description: This method applies rules to the board to diplay the current state of life
 Parameters: None
 Pre-Conditions: Must be initialized by default constructor and called
 Post-Conditions: Must display the current state of the board
 ***************************************************************************************/
void Game::rules()
{  //initialize a count integer to add the live (x) spaces 
   int k = 0;

   //iterate through array with 1 character buffer on all sides to avoid going off array
   for(int i = 1; i < 26; i++)
   {  for(int j = 1; j < 46; j++)   
      {	 //set the k count equal to 0 and add to it for each live (x) neighbor 
	 k = 0;
	 if(table[i-1][j-1] == 'x')
	    k++;
	 if(table[i-1][j] == 'x')
	    k++;
	 if(table[i-1][j+1] == 'x')
	    k++;
	 if(table[i][j-1] == 'x')
	    k++;
	 if(table[i][j+1] == 'x')
	    k++;
	 if(table[i+1][j-1] == 'x')
	    k++;
	 if(table[i+1][j] == 'x')
	    k++;
	 if(table[i+1][j+1] == 'x')
	    k++;
   
	 //determine if the position should be alive (x) based on the k value
	 //change the value on the copy table and keep the origional intact 
	 if ((k == 2) && (table[i][j] == 'x'))
	    tableCopy[i][j] = 'x';
	 if (k == 3)
	    tableCopy[i][j] = 'x';
	 if ((k > 3) || (k < 2) || ((k == 2) && (table[i][j] == '.')))
	    tableCopy[i][j] = '.';
      }
   }

   //replace the actual table with the copy table
   for(int i = 0; i < 27; i++)
   {  for(int j = 0; j < 47; j++)
      {	 table[i][j] = tableCopy[i][j];	 
      }
   }

   //call print method to display table
   print();
   
   //clear the table copy so that it can be reused the next time the rules are called
   for(int i = 0; i < 27; i++)
   {  for(int j = 0; j < 47; j++)
      {	 tableCopy[i][j] = '.';	 
      }
   }
}


/****************************************************************************************
 Function: Clear 
 Description: This method clears the board and prints once
 Parameters: None
 Pre-Conditions: Must be initialized by default constructor and called 
 Post-Conditions: Must display an empty board
 ***************************************************************************************/
void Game::clear()
{  //set each place in array equal to dead ('.')
   for(int i = 0; i < 27; i++)
   {  for(int j = 0; j < 47; j++)
      {   table[i][j] = '.';	 
      }
   }

   //print screen to show results
   print();
}


/****************************************************************************************
 Function: Validate 
 Description: Checks if input is valid, i between 0 and 20, j between 0 and 40
 Parameters: x and y integer coordinates
 Pre-Conditions: Must be caled by method and passed parameters
 Post-Conditions: Must return true or false and output error if false
 ***************************************************************************************/
bool Game::validate(int i, int j)
{  //check that coordinates are within boundaries and display error message if not
   if((i >= 1) && (i <= 20) && (j >= 1) && (j <= 40))
      return true;
   else
   {  cout << endl << "Oh no! Invalid coordinates?!";
      cout << " Try again in the Game of Life.\n" << endl;
      return false;
   }

}


/****************************************************************************************
 Function: Oscillator
 Description: This method adds an oscillator to the game and displays 15 times
 Parameters: x and y integer coordinates
 Pre-Conditions: Must be called by user and passed parameters  
 Post-Conditions: Must display the board with an oscillator
 ***************************************************************************************/
void Game::oscillator(int i, int j)
{
   //set a oscillator in the array at the appropriate coordinates accounting for the buffer
   table[i+2][j+3] = table[i+3][j+3] = table[i+4][j+3] = 'x';
   
   //print initial array
   print();
   
   //call rulesi 15 times to display oscillator
   for(int k = 0; k < 15; k++)
   {  
      rules();
   }
}


/****************************************************************************************
 Function: Glider
 Description: This method adds a glider to the board and diplays 85 times
 Parameters: x and y coordinates
 Pre-Conditions: Must be called by user and passed parameters 
 Post-Conditions: Must display the board with a glider
 ***************************************************************************************/
void Game::glider(int i, int j)
{
   //set a glider in the array at the appropriate coordinates accounting for the buffer
   table[i+2][j+3] = table[i+3][j+4] =
   table [i+4][j+2] = table[i+4][j+3] = table[i+4][j+4] = 'x';
   
   //print initial array 
   print();

   //call rules 80 times to display glider exiting screen starting at extreme (1,1) edge
   for(int k = 0; k < 85; k++)
   {
      rules();
   }

}


/****************************************************************************************
 Function: Cannon
 Description: This method adds a cannon to the board and displays 80 times
 Parameters: y coordinate
 Pre-Conditions: Must be called by user and passed parameters
 Post-Conditions: Must display the board with a cannon
 ***************************************************************************************/
void Game::cannon(int i)
{
   //set cannon in the array at the appropriate coordinate accounting for the buffer
   table[i+3][29] = table[i+4][27] = table[i+4][29] = table[i+5][17] =
   table[i+5][18] = table[i+5][25] = table[i+5][26] = table[i+5][39] = 
   table[i+5][40] = table[i+6][16] = table[i+6][20] = table[i+6][25] = 
   table[i+6][26] = table[i+6][39] = table[i+6][40] = table[i+7][5] = 
   table[i+7][6] = table[i+7][15] = table[i+7][21] = table[i+7][25] = 
   table[i+7][26] = table[i+8][5] = table[i+8][6] = table[i+8][15] = 
   table[i+8][19] = table[i+8][21] = table[i+8][22] = table[i+8][27] =  
   table[i+8][29] = table[i+9][15] = table[i+9][21] = table[i+9][29] = 
   table[i+10][16] = table[i+10][20] = table[i+11][17] = table[i+11][18] = 'x';

   //print initial array ito avoid confusion and a lot of headache
   print();

   //call rules 80 times to display cannon firing multiple gliders 
   for(int k = 0; k < 80; k++)
   {
      rules();
   }
}
