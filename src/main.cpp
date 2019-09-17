#include <iostream>
#include <thread>
#include <chrono>
#include <curses.h>
#include <ncurses.h>

#include "Elevator.h"


// WINDOW *create_newwin(int height, int width, int starty, int startx);
// void destroy_win(WINDOW *local_win);

int main() 
{
  /** Basic NCurses Drawing **/
  // initscr();      // start ncurses
  // noecho();       // do not print input values
  // cbreak();       // terminate ncurses on ctrl + c
  // start_color();  // enable color

  // int x_max{getmaxx(stdscr)};
  // WINDOW* building_window = newwin(15, x_max - 1, 0, 0);  
  // WINDOW* in_window = newwin(9, x_max - 1, 16, 0);  
  

  // while(1){
  //     box(building_window, 0, 0);
  //     box(cout_window, 0, 0);
  //     wrefresh(building_window);
  //     wrefresh(cout_window);
  //     refresh();
  //     std::this_thread::sleep_for(std::chrono::milliseconds(100));
  // }
  // endwin(); /* End curses mode		  */
	// return 0;

  // Init an elevator
  Elevator e;
  e.operate();


}