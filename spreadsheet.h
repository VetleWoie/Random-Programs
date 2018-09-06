#ifndef SPREADSHEET_H
#define SPREADSHEET_H


typedef struct spreadsheet spreadsheet_t;
struct spreadsheet;

spreadsheet_t *spreadsheet_create(int numberOfRows, int numberOfCoulumns);
int spreadsheet_put(spreadsheet_t *spreadsheet, int x, int y, char *formula);
int spreadsheet_clear(spreadsheet_t *spreadsheet, int x, int y);
int spreadsheet_getCell(spreadsheet_t *spreadsheet, int x, int y);
void spreadsheet_draw(spreadsheet_t *spreadsheet);

#endif