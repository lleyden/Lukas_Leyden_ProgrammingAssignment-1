/*  Lukas Leyden
    CS 33211
    Programming Assignment #1
    */


#ifndef MEMORYBUFF_HPP
#define  MEMORYBUFF_HPP

#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <semaphore.h>

#define TABLE_SIZE 2

struct shMem {
    int table[TABLE_SIZE];
    int in;
    int out;

    sem_t mutex;
    sem_t empty;
    sem_t full;
};

#endif
