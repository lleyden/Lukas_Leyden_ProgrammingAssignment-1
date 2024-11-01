/*  Lukas Leyden
    CS 33211
    Programming Assignment #1
    */

#include "../header/src.hpp"
#include "../header/memorybuff.hpp"

int main(int argc, char* argv[]) {
    struct shMem* produceMem;
    int fwd;
    char* shmpath;

    shmpath = argv[1];
    fwd = shm_open(shmpath, O_CREAT | O_EXCL | O_RDWR, 0600);

    ftruncate(fwd, sizeof(*producerMem));
    produceMem = static_cast<shMem*>(mmap(NULL, sizeof(*produceMem), PROT_READ | PROT_WRITE, MAP_SHARED, fwd, 0));

    sem_init(&(produceMem->mutex), 1, 1);
    sem_init(&(produceMem->full), 1, 0);
    sem_init(&(produceMem->empty), 1, TABLE_SIZE);

    produceMem->in, produceMem->out = 0;

    for (int i = 4; i >= 0; --i) {
        sem_wait(&produceMem->empty);
        sem_wait(&produceMem->mutex);

        int prod_val = rand();

        std::cout << "Produced: " << prod_val << std::endl;
        produceMem->table[produceMem->in] = prod_val;
        produceMem->in = (produceMem->in + 1) % TABLE_SIZE;

        sem_post(&produceMem->mutex);
        sem_post(&produceMem->full);

        sleep(rand() % 10);
    }

    shm_unlink(shmpath);
    return 0;
}
