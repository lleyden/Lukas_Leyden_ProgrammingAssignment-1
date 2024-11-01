/*  Lukas Leyden
    CS 33211
    Programming Assignment #1
    */


#include "../header/src.hpp"
#include "../header/memorybuff.hpp"

int main(int argc, char* argv[]) {
    struct shMem* consumeMem;
    int fwd;
    char* shmpath;

    shmpath = argv[1];
    fwd = shm_open(shmpath, O_RDWR, 0);

    ftruncate(fwd, sizeof(*consumeMem));
    consumeMem = static_cast<shMem*>(mmap(NULL, sizeof(*consumeMem), PROT_READ | PROT_WRITE, MAP_SHARED, fwd, 0));

    for (int i = 4; i >= 0; --i) {
        sem_wait(&(consumeMem->full));
        sem_wait(&(consumeMem->mutex));

        int cons_item;
        cons_item = consumeMem->table[consumeMem->out];
        std::cout << "Consumed: " << cons_item << std::endl;

        consumeMem->out = (consumeMem->out + 1) % TABLE_SIZE;
        sem_post(&(consumeMem->mutex));
        sem_post(&(consumeMem->empty));

        sleep(rand() % 10);
    }

    shm_unlink(shmpath);
    return 0;

}
