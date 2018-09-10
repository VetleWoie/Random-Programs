#include "spreadsheet.h"
#include <stdlib.h>

int main(int argc, char **argv){

	int i = atoi(argv[1]);
	int y = atoi(argv[0]);

	spreadSheet_t *spreadsheet = spreadSheet_create(i,y);

	spreadSheet_draw(spreadsheet);
}