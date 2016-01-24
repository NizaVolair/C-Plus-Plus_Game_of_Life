/****************************************************************************************
 **Program Filename: 
 **Author: Niza Volair
 **Date: 04-05-2015
 **Description: This is the header file for the game class
 ***************************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
using namespace std;


//Define the interface of the Board class
class Game
{
private:
   char table[27][47];
   char tableCopy[27][47];

public:
   Game();
   void print();
   bool validate(int, int);
   void rules();
   void clear();
   void oscillator(int, int);
   void glider(int, int);
   void cannon(int);
};
#endif


