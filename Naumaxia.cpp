
#include "Naumaxia.h"

#include <cstring>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>


using namespace std;



char name [10];




int main(){

								BattleShip player;
								BattleShip computer;


                                int a,x,y,a2,x2,y2;

                                int hits=0; //player stats
                                int misses=0;
                                int repeat=0;
                                int hits2=0; // computer stats
                                int misses2=0;
                                int repeat2=0;

                                int tries = 10; //tries left
								int m_iShipCounter = 9; // number of ships each player has
								int m_iShipCounter2 = 9;
								int shipcheck = 0; // checks ship type

								player.clear_board(); // this clears the grid at the beginning for player
                                computer.clear_board(); // this will clear the grid for the computer


                               cout << " please enter your name" << endl; //player name input
                               cin >> name;



								player.start_game(shipcheck); // call player set ship location to deploy player ships


								computer.comp_start_game(shipcheck); //  call comp set ship location to deploy computer ships







                                player.Player_Draw_board(a2,x2,y2); // print player board


								do {

																m_iShipCounter = computer.player_turn(m_iShipCounter,hits,misses,repeat);


																m_iShipCounter2 = player.computer_turn(m_iShipCounter2,hits2,misses2,repeat2);



                                                                tries--;
																cout << "\ntries left:" << tries << "\n" << endl;












                               } while (m_iShipCounter != 0 && m_iShipCounter2 !=0 && tries > 0 ); // this will check for an end condition
                                //stats----------------
                                cout << name << "stats:" << "\n tries:" << 10 - tries  <<"\n hits:" << hits << "\n misses:" << misses <<"\n already picked:" << repeat << endl;
                                cout << "Computer" << "stats:" << "\n tries:" << 10 - tries  <<"\n hits:" << hits2 << "\n misses:" << misses2 <<"\n already picked:" << repeat2 << endl;


                                 // prints if player won or lost
                                 cout << "game over" << endl;
                                 if (m_iShipCounter == 0) { cout << "You lost" << endl;

                                                   }
                                 else if (m_iShipCounter2 == 0)
                                    {cout << "You won" << endl;
                                                            }
                                 else { cout << "Exceeded number of tries" << endl;}







								return (0);
}


/*-----------------------------------------------------------------------------------------------------*/






/*-------------------------------------/
   / this functions clear the playing board/
   / to all empty water                   /
   /-------------------------------------*/

void BattleShip::clear_board(){
								for (int i = 0; i < GRID_SIZE; i++)
																for(int j = 0; j < GRID_SIZE; j++)
																								m_cBattleShipGrid_ShipLocations [i][j] = '~';


								for (int i = 0; i < GRID_SIZE; i++)
																for(int j = 0; j < GRID_SIZE; j++)
																								m_cBattleShipGrid_HitMissLocations [i][j] = '~';
}


/*-------------------------------------/
   / this functions prints the playing    /
   / board                               /
   /-------------------------------------*/


void BattleShip::Player_Draw_board(int a2,int x2,int y2)
{
								cout << name << "\n 0 1 2 3 4 5 " << endl;

								for (int i = 0; i < GRID_SIZE; i++)
								{

																cout << i;

																for(int j = 0; j < GRID_SIZE; j++)

                                                                cout << m_cBattleShipGrid_ShipLocations[i][j]<< " ";


																cout << endl;

								}
								if (a2==0) {m_cBattleShipGrid_ShipLocations[x2][y2] = 'h';}
                                else if (a2==1) {m_cBattleShipGrid_ShipLocations[x2][y2] = 'm';}

}


void BattleShip::Computer_Draw_board(int a,int x, int y)
{
								cout << "Computer \n 0 1 2 3 4 5 " << endl;


								for (int i = 0; i < GRID_SIZE; i++)
								{

                                                                cout << i;

																for(int j = 0; j < GRID_SIZE; j++)



                                                                cout << m_cBattleShipGrid_HitMissLocations[i][j]<< " ";
																cout << endl;

								}
							    if (a==0) {m_cBattleShipGrid_ShipLocations[x][y] = 'h';}
                                else if (a==1) {m_cBattleShipGrid_ShipLocations[x][y] = 'm';}



}



void BattleShip::start_game(int shipcheck)
{



								player_place_ship(shipcheck);
								shipcheck++;

								player_place_ship( shipcheck);
								shipcheck++;

								player_place_ship( shipcheck);


}


void BattleShip::comp_start_game(int shipcheck)
{
								comp_place_ship(shipcheck);
								shipcheck++;

								comp_place_ship(shipcheck);
								shipcheck++;

								comp_place_ship(shipcheck);
}

// GENERATORS--------------------------------------

int BattleShip:: getRandInput()
{
								srand(time (NULL) ); // seed number
								int num = rand() % 6; // generator of the random number
								                     // checking the printout of the number
								return (num);

}

int BattleShip:: getRandInput2()
{

                                int num2 = rand() % 6;


                                return (num2);
}

int BattleShip::num_generatorstart1()
{
								srand(time (NULL) ); // seed number
								int num3 = rand() % 6; // generator of the random number
								  // checking the printout of the number
								return (num3);

}

int BattleShip::num_generatorstart2()
{
								 // seed number
								int num4 = rand() % 6; // generator of the random number
								cout << "Deploying ships random please wait" << endl;  // checking the printout of the number
								return (num4);

}

int BattleShip::getOrientation()
{
                                 srand(time (NULL) );
								int num5 = rand() % 2 ;// generator of the random number
                                                     // checking the printout of the number
								return (num5);

}

//Deploy ships for players------------------------------------------------------------

void BattleShip::player_place_ship(int shipcheck)
{
                                start:

                                int h,x2,x3,x4,y2,y3,y4; // h vertical or horizontal all x and y variables are coordinates

								x1 = num_generatorstart1(); // generate the x location for the ship

								//------------------hecks for errors with input of the x value---------//

								while ((x1 != 0) && (x1!= 1) && (x1 != 2) && (x1 != 3) && (x1 != 4) && (x1!= 5)
															) // it will loop until the input is valid
								{
																x1 = num_generatorstart1();

								}
								//---------------------------------------------------------------------------//



								y1 = num_generatorstart2(); // generate the y location for the ship

								//------------------ checks for errors with input of the y value---------//

								while ((y1!= 0) && (y1 != 1) && (y1 != 2) && (y1 != 3) && (y1!= 4) && (y1 != 5)
															) // it will loop until the input is valid
								{
																y1 = num_generatorstart2();

								}

								if (shipcheck == 0) {  // battleship

                                    h = getOrientation(); // 0 is vertical , 1 is horizontal

                                    // checks if it can be deployed.If it can go the starting point one position back until it can
                                    if ( h ==0 ) { while  (x1+ 3 > 5 ){x1--;}
                                                    x2 = x1 + 1;
                                                    y2 = y1   ;
                                                    x3 = x1+ 2;
                                                    y3 = y1    ;
                                                    x4 = x1 + 3;
                                                    y4 = y1    ;

                                    }
                                    else { while  (y1 + 3 > 5 ){y1--;}
                                                    x2 =x1   ;
                                                    y2 = y1+ 1;
                                                    x3 = x1   ;
                                                    y3 = y1+ 2;
                                                    x4 = x1   ;
                                                    y4 = y1+ 3;

                                    }







								//----------------------------------------------------------------------------------------//


								//------------------checks to see if the spot is already taken----------//


								if ((m_cBattleShipGrid_ShipLocations[x1] [y1] == '~') && (m_cBattleShipGrid_ShipLocations[x2] [y2] == '~')
                                    && (m_cBattleShipGrid_ShipLocations[x3] [y3] == '~') && (m_cBattleShipGrid_ShipLocations[x4] [y4] == '~') ) // check to make sure the space is unused
								{
																m_cBattleShipGrid_ShipLocations[x1] [y1] = 's';
																m_cBattleShipGrid_ShipLocations[x2] [y2] = 's';  // a computer ship
                                                                m_cBattleShipGrid_ShipLocations[x3] [y3] = 's';
                                                                m_cBattleShipGrid_ShipLocations[x4] [y4] = 's';
								}

								else
								{
																goto start; // go at the start if ship cannot be deployed
								}
								//-------------------------------------------------------------------------//






								}

								else if (shipcheck == 1) {// cruiser ship

                                    h =getOrientation();


                                    if ( h ==0 ) { while  (x1 + 2 > 5 ){x1--;}
                                                    x2 = x1 + 1;
                                                    y2 = y1    ;
                                                    x3 = x1 + 2;
                                                    y3 = y1    ;

                                   if ((m_cBattleShipGrid_ShipLocations[x1-1] [y1] != 's')&& (m_cBattleShipGrid_ShipLocations[x1] [y1+1] != 's')&&
                                      (m_cBattleShipGrid_ShipLocations[x2] [y1+1] != 's')&& (m_cBattleShipGrid_ShipLocations[x3] [y1+1] != 's') &&
                                      (m_cBattleShipGrid_ShipLocations[x3+1] [y1] != 's')&& (m_cBattleShipGrid_ShipLocations[x1] [y1-1] != 's')&&
                                      (m_cBattleShipGrid_ShipLocations[x2] [y1-1] != 's')&& (m_cBattleShipGrid_ShipLocations[x3] [y1-1] != 's')
                                       ) goto v1;
                                   else {goto start;}


                                    }
                                    else { while  (y1 + 2 > 5 )
                                        {y1--;}
                                                    x2 = x1   ;
                                                    y2 = y1 +1;
                                                    x3 = x1   ;
                                                    y3 = y1 +2;
                                    //check if there is adjacent cell horizontal and vertical

                                     if ((m_cBattleShipGrid_ShipLocations[x1] [y1-1] != 's')&& (m_cBattleShipGrid_ShipLocations[x1+1] [y1] != 's')&&
                                      (m_cBattleShipGrid_ShipLocations[x1+1] [y2] != 's')&& (m_cBattleShipGrid_ShipLocations[x1+1] [y3] != 's') &&
                                      (m_cBattleShipGrid_ShipLocations[x1] [y3+1] != 's')&& (m_cBattleShipGrid_ShipLocations[x1-1] [y1] != 's')&&
                                      (m_cBattleShipGrid_ShipLocations[x1-1] [y2] != 's')&& (m_cBattleShipGrid_ShipLocations[x1-1] [y3] != 's')
                                       ) goto v1;
                                   else {goto start;}


                                    }
                                    v1:
                                    if ((m_cBattleShipGrid_ShipLocations[x1] [y1] == '~') && (m_cBattleShipGrid_ShipLocations[x2] [y2] == '~')
                                    && (m_cBattleShipGrid_ShipLocations[x3] [y3] == '~')   ) // check to make sure the space is unused
								{
																m_cBattleShipGrid_ShipLocations[x1] [y1] = 's';
																m_cBattleShipGrid_ShipLocations[x2] [y2] = 's';  // a computer ship
                                                                m_cBattleShipGrid_ShipLocations[x3] [y3] = 's';


								}

								else
								{
																goto start; // go at the start if ship cannot be deployed
								}



}

                              else if (shipcheck == 2) {   // destroyer ship

                                    h = getOrientation();


                                    if ( h ==0 ) { while  (x1 + 1 > 5 )
                                                    {x1--;}
                                                    x2 = x1+ 1;
                                                    y2 = y1   ;

                                       if ((m_cBattleShipGrid_ShipLocations[x1-1] [y1] != 's')&& (m_cBattleShipGrid_ShipLocations[x1] [y1+1] != 's')&&
                                        (m_cBattleShipGrid_ShipLocations[x2] [y1+1] != 's')&& (m_cBattleShipGrid_ShipLocations[x1] [y1-1] != 's')&&
                                        (m_cBattleShipGrid_ShipLocations[x2] [y1-1] != 's') && (m_cBattleShipGrid_ShipLocations[x2+1] [y1] != 's')
                                       ) {goto v2;}
                                   else {goto start;}



                                    }
                                    else { while  (y1 + 1 > 5 )
                                                    {y1--;}
                                                    x2 = x1   ;
                                                    y2 = y1 + 1;


                                        if ((m_cBattleShipGrid_ShipLocations[x1] [y1-1] != 's')&& (m_cBattleShipGrid_ShipLocations[x1+1] [y1] != 's')&&
                                      (m_cBattleShipGrid_ShipLocations[x1+1] [y2] != 's')&& (m_cBattleShipGrid_ShipLocations[x1] [y2+1] != 's')
                                            && (m_cBattleShipGrid_ShipLocations[x1-1] [y2] != 's')&&(m_cBattleShipGrid_ShipLocations[x1-1] [y1] != 's')
                                       ) goto v2;
                                   else {goto start;}



                                    }
                                    v2:
                                    if ((m_cBattleShipGrid_ShipLocations[x1] [y1] == '~') && (m_cBattleShipGrid_ShipLocations[x2] [y2] == '~')
                                      ) // check to make sure the space is unused
								{
																m_cBattleShipGrid_ShipLocations[x1] [y1] = 's';
																m_cBattleShipGrid_ShipLocations[x2] [y2] = 's';  // a computer ship



								}

								else
								{
																goto start; // go at the start if ship cannot be deployed
								}



}
}








void BattleShip::comp_place_ship(int shipcheck)
{
             start:
                               int h,x2,x3,x4,y2,y3,y4; // h vertical or horizontal all x and y variables are coordinates

								x1 = num_generatorstart1(); // generate the x location for the ship

								//------------------ checks for errors with input of the x value---------//

								while ((x1!= 0) && (x1!= 1) && (x1!= 2) && (x1!= 3) && (x1!= 4) && (x1!= 5)
															) // it will loop until the input is valid
								{
																x1 = num_generatorstart1();

								}
								//---------------------------------------------------------------------------//



								y1 = num_generatorstart2(); // generate the y location for the ship

								//------------------checks for errors with input of the y value---------//

								while ((y1 != 0) && (y1 != 1) && (y1 != 2) && (y1!= 3) && (y1 != 4) && (y1!= 5)
															) // it will loop until the input is valid
								{
																y1 = num_generatorstart2();

								}

								if (shipcheck == 0) { // battleship

                                    h =getOrientation();  // 0 is vertical , 1 is horizontal

                                     //checks if it can be deployed.If it cant go the starting point one position back until it can
                                    if ( h ==0 ) { while  (x1+ 3 > 5 ){x1--;}
                                                    x2 = x1 + 1;
                                                    y2 = y1   ;
                                                    x3 = x1 + 2;
                                                    y3 = y1   ;
                                                    x4 = x1 + 3;
                                                    y4 = y1   ;

                                    }
                                    else { while  (y1+ 3 > 5 ){y1--;}
                                                    x2 = x1   ;
                                                    y2 = y1+ 1;
                                                    x3 = x1    ;
                                                    y3 = y1 + 2;
                                                    x4 = x1   ;
                                                    y4 = y1 + 3;

                                    }






								//----------------------------------------------------------------------------------------//


								//------------------checks to see if the spot is already taken----------//


								if ((m_cBattleShipGrid_ShipLocations[x1] [y1] == '~') && (m_cBattleShipGrid_ShipLocations[x2] [y2] == '~')
                                    && (m_cBattleShipGrid_ShipLocations[x3] [y3] == '~') && (m_cBattleShipGrid_ShipLocations[x4] [y4] == '~') ) // check to make sure the space is unused
								{
																m_cBattleShipGrid_ShipLocations[x1] [y1] = 's';  // computers ship
																m_cBattleShipGrid_ShipLocations[x2] [y2] = 's';
                                                                m_cBattleShipGrid_ShipLocations[x3] [y3] = 's';
                                                                m_cBattleShipGrid_ShipLocations[x4] [y4] = 's';
								}

								else
								{
																goto start; // go at the start if ship cannot be deployed
								}
								//-------------------------------------------------------------------------//






								}
								else if (shipcheck == 1) { // cruiser

                                    h = getOrientation();


                                    if ( h ==0 ) { while  (x1+ 2 > 5 ){x1--;}
                                                    x2 = x1 + 1;
                                                    y2 = y1   ;
                                                    x3 = x1 + 2;
                                                    y3 = y1    ;

                                          if ((m_cBattleShipGrid_ShipLocations[x1-1] [y1] != 's')&& (m_cBattleShipGrid_ShipLocations[x1] [y1+1] != 's')&&
                                      (m_cBattleShipGrid_ShipLocations[x2] [y1+1] != 's')&& (m_cBattleShipGrid_ShipLocations[x3] [y1+1] != 's') &&
                                      (m_cBattleShipGrid_ShipLocations[x3+1] [y1] != 's')&& (m_cBattleShipGrid_ShipLocations[x1] [y1-1] != 's')&&
                                      (m_cBattleShipGrid_ShipLocations[x2] [y1-1] != 's')&& (m_cBattleShipGrid_ShipLocations[x3] [y1-1] != 's')
                                       ) {goto v3;}
                                   else {goto start;}


                                    }
                                    else { while  (y1 + 2 > 5 ){y1--;}
                                                    x2 = x1   ;
                                                    y2 = y1 + 1;
                                                    x3 = x1   ;
                                                    y3 = y1+ 2;

                                        if ((m_cBattleShipGrid_ShipLocations[x1] [y1-1] != 's')&& (m_cBattleShipGrid_ShipLocations[x1+1] [y1] != 's')&&
                                      (m_cBattleShipGrid_ShipLocations[x1+1] [y2] != 's')&& (m_cBattleShipGrid_ShipLocations[x1+1] [y3] != 's') &&
                                      (m_cBattleShipGrid_ShipLocations[x1] [y3+1] != 's')&& (m_cBattleShipGrid_ShipLocations[x1-1] [y1] != 's')&&
                                      (m_cBattleShipGrid_ShipLocations[x1-1] [y2] != 's')&& (m_cBattleShipGrid_ShipLocations[x1-1] [y3] != 's')
                                       ) goto v3;
                                   else {goto start;}

                                    }
                                    v3:
                                    if ((m_cBattleShipGrid_ShipLocations[x1] [y1] == '~') && (m_cBattleShipGrid_ShipLocations[x2] [y2] == '~')
                                    && (m_cBattleShipGrid_ShipLocations[x3] [y3] == '~')  ) // check to make sure the space is unused
								{
																m_cBattleShipGrid_ShipLocations[x1] [y1] = 's';
																m_cBattleShipGrid_ShipLocations[x2] [y2] = 's';  // a computer ship
                                                                m_cBattleShipGrid_ShipLocations[x3] [y3] = 's';


								}

								else
								{
																goto start; // go at the start if ship cannot be deployed
								}



}

                              else if (shipcheck == 2) { // destroyer

                                    h =getOrientation();


                                    if ( h ==0 ) { while  (x1+ 1 > 5 ){x1--;}
                                                    x2 = x1 + 1;
                                                    y2 = y1    ;


                                       if ((m_cBattleShipGrid_ShipLocations[x1-1] [y1] != 's')&& (m_cBattleShipGrid_ShipLocations[x1] [y1+1] != 's')&&
                                        (m_cBattleShipGrid_ShipLocations[x2] [y1+1] != 's')&& (m_cBattleShipGrid_ShipLocations[x1] [y1-1] != 's')&&
                                        (m_cBattleShipGrid_ShipLocations[x2] [y1-1] != 's') && (m_cBattleShipGrid_ShipLocations[x2+1] [y1] != 's')
                                       ) {goto v4;}
                                   else {goto start;}


                                    }
                                    else { while  (y1 + 1 > 5 ){y1--;}
                                                    x2 = x1    ;
                                                    y2 = y1 + 1;


                                        if ((m_cBattleShipGrid_ShipLocations[x1] [y1-1] != 's')&& (m_cBattleShipGrid_ShipLocations[x1+1] [y1] != 's')&&
                                      (m_cBattleShipGrid_ShipLocations[x1+1] [y2] != 's')&& (m_cBattleShipGrid_ShipLocations[x1] [y2+1] != 's')
                                            && (m_cBattleShipGrid_ShipLocations[x1-1] [y2] != 's')&&(m_cBattleShipGrid_ShipLocations[x1-1] [y1] != 's')
                                       ) goto v4;
                                   else {goto start;}



                                    }
                                    v4:
                                    if ((m_cBattleShipGrid_ShipLocations[x1] [y1] == '~') && (m_cBattleShipGrid_ShipLocations[x2] [y2] == '~')
                                      ) // check to make sure the space is unused
								{
																m_cBattleShipGrid_ShipLocations[x1] [y1] = 's';
																m_cBattleShipGrid_ShipLocations[x2] [y2] = 's';  // a computer ship



								}

								else
								{
																goto start; // go at the start if ship cannot be deployed
								}



}
}




/*----------------------------------------------------------*/

int BattleShip::player_turn(int m_iShipCounter,int& hits,int& misses,int& repeat)
{

                                start:
                                int a,x,y;





								cout << "Please select the row and the column you want to attack" << endl;

                                cin >> x1;//row

								cin >> y1;//column

								x = x1;
                                y = y1;



								if (m_cBattleShipGrid_ShipLocations[x1] [y1] == 's') // this checks to see if the location is a ship
								{

																cout << "\nHIT" << endl;
																m_cBattleShipGrid_HitMissLocations[x1] [y1] = 'h'; // this means you hit something
																m_iShipCounter--;
																a=0;
																hits++;

								}

								else if ((x1> 5) || (y1 > 5)) {
																cout << "Wrong input" << endl;
																player_turn(m_iShipCounter,hits,misses,repeat);
								}

								else if (m_cBattleShipGrid_ShipLocations[x1] [y1] == '~') // this checks to see if the location is empty water
								{
																cout << "\nMISS" << endl;
																m_cBattleShipGrid_HitMissLocations[x1] [y1] = 'm'; // this means you missed
																a=1;
																misses++;


								}

								else if (m_cBattleShipGrid_ShipLocations[x1] [y1] == 'h')
								{
								    cout << "ALREADY HIT" << endl;
                                    player_turn(m_iShipCounter,hits,misses,repeat);
                                    repeat++;
								}

                                else if (m_cBattleShipGrid_ShipLocations[x1] [y1] == 'm')
								{
								    cout << "ALREADY MISS" << endl;
                                    repeat++;
                                    system ("pause");

                                    goto start;
								}




                                cout << endl;
                               Computer_Draw_board(a,x,y); //this will print the grid to hold hit or misses

    return m_iShipCounter;


}


/*---------------------------------------------------------------*/

int BattleShip::computer_turn(int m_iShipCounter2,int& hits2,int& misses2,int& repeat2)
{
                                start:
                                int a2,x2,y2;

								x1 =  getRandInput();
								y1 =  getRandInput2();


								x2 = x1;
                                y2 = y1;



								if (m_cBattleShipGrid_ShipLocations[x1] [y1] == 's') // this checks to see if the location is a ship
								{

																m_cBattleShipGrid_ShipLocations[x1] [y1] = 'h';  // this means you hit something
																m_iShipCounter2--;
																hits2++;
																a2=0;
								}

								else if (m_cBattleShipGrid_ShipLocations[x1] [y1] == '~') // this checks to see if the location is empty water
								{

																m_cBattleShipGrid_ShipLocations[x1] [y1] = 'm'; // this means you missed
																misses2++;
																a2=1;

								}
								else {   cout << "Same space for computer wait while retrying" << endl;
                                          repeat2++;
                                          system ("pause");
                                          goto start;

                                         }





                                       Player_Draw_board(a2,x2,y2);


    return m_iShipCounter2;

}


