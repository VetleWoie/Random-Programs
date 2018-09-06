#include <stdio.h>
#include <stdlib.h>

#include "spreadsheet.h"

#define USAGEERR "Error: Usage: %s numberOfCoulumns numberOfRows", argv[0]

struct spreadSheet{
    cell **cells;
    int numberOfCoulumns;
    int numberOfRows;
}

typedef struct cell cell_t;
struct cell{
    cell_t *affectedCells;
    int value;
    char *formula;
};

spreadsheet_t *spreadsheet_create(int numberOfRows, int numberOfCoulumns){
    //Create new spreadsheet
    spreadsheet_t new = (spreadSheet_t *) malloc(sizeof(spreadSheet_t));
    new->numberOfCoulumns = numberOfCoulumns;
    new->numberOfRows = numberOfRows;

    //Allocate memory for each row
    new->cells = (cell_t**) malloc(sizeof(cell_t *) * numberOfRows);
    
    //Allocate memory for each coulumn
    int i;
    for(i = 0; i < numberOfRows; i++){
        new->cells[i] = (cell_t *) malloc(sizeof(cell_t) * numberOfCoulumns);
        new->cells[i]->affectedCells = NULL;
        new->cells[i]->value = 0;
        new->cells[i]->formula = NULL;
    }
}

int spreadsheet_put(spreadsheet_t *spreadsheet, int x, int y, char *formula);
int spreadsheet_clear(spreadsheet_t *spreadsheet, int x, int y);
int spreadsheet_getCell(spreadsheet_t *spreadsheet, int x, int y);
void spreadsheet_draw(spreadsheet_t *spreadsheet);

A1 = 87;
B3 = A1 * B4 + 5;
C7 = A1 + B3;