#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
	typedef struct    s_stone {
  int               size;
  struct s_stone    *next;
  }                 t_s;
  typedef struct      s_newstone {
    int               size;
    t_s               *startStone;
    t_s               *lastStone;
    struct s_newstone *next;
  }                   t_ns;


/*--------------------------------
  :) function you must implement
  --------------------------------*/
//stone is a pointer to the first
void sortStones(struct s_stone **stone);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_stone *genRandomStoneList(int n);
void printStone(struct s_stone *stone);
struct s_stone *createStone(int size);
void exitWithMsg(char *msg);


/*--------------------------------
  &  your own other function
  --------------------------------*/

#endif