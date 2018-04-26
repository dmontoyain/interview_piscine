#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	printf("%d\n", tankPop(tank));
	printf("%d\n", tankPop(tank));
	printf("%d\n", tankPop(tank));
	tankPush(tank, 10);
	printf("total energy: %d\n", tank->stacks[tank->n - 1]->sum);
	tankPush(tank, 50);
	printf("total energy: %d\n", tank->stacks[tank->n - 1]->sum);
	tankPush(tank,40);
	tankPush(tank,520);
	tankPush(tank, 600);
	printf("total energy 1: %d\n", tank->stacks[tank->n - 2]->sum);
	printf("total energy 2: %d\n", tank->stacks[tank->n - 1]->sum);
	printf("tanks: %d\n", tank->n);
	printf("%d\n", tankPop(tank));
	return (0);
}



// Function used for the test
// Don't go further :)
