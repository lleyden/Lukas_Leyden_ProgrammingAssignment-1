# Programming Assignment #1

<br>

### Author: Lukas Leyden
### CS-33211: Operating Systems
### Dr. Qiang Guan
### Kent State University

<br><br>


### Implementation

Both the producer and consumer have their own processes, with a thread in each created and pointed to a function of the same name (i.e. consumer and producer respectively). With each thread running their own functions, a shared memory buffer with a capacity to hold two items is shared between the producer and consumer. To help prevent deadlock and other data hazards when it comes to a shared buffer, a semaphore is used to indicate use of the buffer. The number '1' indicates the buffer is currently in use, while the number '0' indicates the buffer is available for use.s


<br><br>

### Compilation
Both the producer and consumer are septate files and meant to be septate processes. There are three options within the make file. The first two being consumer and producer respectively. These compiler the producer and consumer. The last option is clean, which cleans any object (.o) files as well as the compiled program files to be executed. 

Running the consumer and/or producer separately will not be of benefit as each relies on each other to run concurrently.

<br>

#### Consumer:
Will compile files to execute consumer
```
    make consumer
```

### Producer:
Will compile files to execute producer
```
    make producer
```

### Run:
The make command will compile all files needed and run the program
```
    make run
```


### Clean:
Will reset and remove all files to execute cleanly
```
    make clean
```

<br><br>

### Run Instructions-


#### 1.) Manually/Command
```
    ./out/consumer shmfile & ./out/producer shmfile
```

### 2.) Using Make (Preferred)
Using the ```make run``` command will compile and run both the producer and consumer.
This is the preferred method of compilation and running the project.



<br><br>

### Libraries & Tech Stack
* C++
* Make
* G++
* PThread Library
* SharedMem 3 Library
