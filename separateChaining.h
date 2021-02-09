#ifndef __SEPARATECHAINING_H_
#define __SEPARATECHAINING_H_

#define HASH_SIZE 10


struct node;

void init();
int hashSC(int);
void addValue(int);
void print();
int findValue(int);
void deleteValue(int);

#endif
