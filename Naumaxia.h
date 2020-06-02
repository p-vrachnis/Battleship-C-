#ifndef _NAUMAXIA_H_
#define _NAUMAXIA_H_
#include <iostream>

const int GRID_SIZE = 6;





class BattleShip
{

public:


	void clear_board();	// this function with initialize the board to all water '~' spaces
	void Player_Draw_board(int,int,int);	// this function will print the board with ship locations
	void Computer_Draw_board(int,int,int);	// this function will print the board hits and misses
	void start_game(int);

	void player_place_ship(int);	// this will set the initial ship locations for the player
	void comp_place_ship(int); // this will set the initial ship locations for the computer player
    int  getRandInput(); // this will generate the number
    int  getRandInput2();
    int num_generatorstart1();
    int num_generatorstart2();
    int getOrientation();

	void comp_start_game(int);
	int player_turn(int,int&,int&,int& ); //player turn
	int computer_turn(int,int&,int&,int&); // this is the computers turn









private:


	char m_cBattleShipGrid_ShipLocations[GRID_SIZE][GRID_SIZE];		// this is the array that will hold the grid for the ship locations
	char m_cBattleShipGrid_HitMissLocations[GRID_SIZE][GRID_SIZE];	// this is the array that will hold the grid for the ship hits and misses

	int x1;		// this holds the first x location (row)
	int y1;		// this holds the first y location (column)


};

#endif

