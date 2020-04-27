#include "reconos.h"
#include "reconos_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>





int main(int argc, char **argv) {

	reconos_init();
	reconos_app_init();

	int clk = reconos_clock_threads_set(100000);





	while(1) sleep(1);





	reconos_app_cleanup();
	reconos_cleanup();

	return clk;
}