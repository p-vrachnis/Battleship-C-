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
