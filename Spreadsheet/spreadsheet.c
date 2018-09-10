#include <stdio.h>
#include <stdlib.h>

#include "spreadsheet.h"

#define USAGEERR "Error: Usage: %s numberOfCoulumns numberOfRows", argv[0]

typedef struct cell cell_t;

struct spreadSheet{
    cell_t **cells;
    int numberOfCoulumns;
    int numberOfRows;
};


struct cell{
    cell_t *affectedCells;
    int value;
    char *formula;
};

spreadSheet_t *spreadSheet_create(int numberOfRows, int numberOfCoulumns){
    //Create new spreadSheet
    spreadSheet_t *new = (spreadSheet_t *) malloc(sizeof(spreadSheet_t));
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

int spreadSheet_put(spreadSheet_t *spreadSheet, int x, int y, char *formula){
    int value = atoi(formula);
    spreadSheet->cells[x][y].formula = formula;
    spreadSheet->cells[x][y].value = value;
    //Temporary;
    spreadSheet->cells[x][y].affectedCells = NULL;
    return 1;
}
int spreadSheet_clearCell(spreadSheet_t *spreadSheet, int x, int y){
    spreadSheet->cells[x][y].value = 0;
    spreadSheet->cells[x][y].formula = NULL;
    //Temporary
    spreadSheet->cells[x][y].affectedCells = NULL;
    return 1;
}
int spreadSheet_getCell(spreadSheet_t *spreadSheet, int x, int y){
    return spreadSheet->cells[x][y].value;
}
void spreadSheet_draw(spreadSheet_t *spreadSheet){

    int i;
    int j;

    printf("\n\n\n\n\n");

    for(i = 0; i < spreadSheet->numberOfCoulumns; i++){
        for(j = 0; j < spreadSheet->numberOfRows; j++){
            printf("|  %d  ", spreadSheet->cells[i][j].value);
        }
        printf("|\n");
        for( j = 0; j < spreadSheet->numberOfRows * 7; j++){
            printf("_");
        }
        printf("\n");
    }
}

