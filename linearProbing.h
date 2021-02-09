#ifndef __LINEARPROBING_H_
#define __LINEARPROBING_H_

struct element;
unsigned char elementCount;

#define SIZE 20
#define oneDigitNumb 10

void initLP(void);
int hash(int);
int rehash(int);
int getValueLP(int);
void addValueLP(int);
void printLP(void);
void deleteLP(int);

#endif
