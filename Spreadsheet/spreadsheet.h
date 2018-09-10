#ifndef spreadSheet_H
#define spreadSheet_H


typedef struct spreadSheet spreadSheet_t;
struct spreadSheet;

spreadSheet_t *spreadSheet_create(int numberOfRows, int numberOfCoulumns);
int spreadSheet_put(spreadSheet_t *spreadSheet, int x, int y, char *formula);
int spreadSheet_clear(spreadSheet_t *spreadSheet, int x, int y);
int spreadSheet_getCell(spreadSheet_t *spreadSheet, int x, int y);
void spreadSheet_draw(spreadSheet_t *spreadSheet);

#endif
