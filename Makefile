####################################################
#
#	Producer-consumer problem Makefile
#	Using G++ compiler
#
#	Author: Lukas Leyden
#	Date : 10 / 28 / 2024
#
#
####################################################

#Menu

msg :
@echo 'Targets are: '
@echo ' producer'
@echo ' consumer'
@echo ' run'
@echo  ' clean'


consumer: ./source/consumer.cpp
g++ "./source/consumer.cpp" - pthread - lrt - o ./out/consumer

producer : ./source/producer.cpp
g++ "./source/producer.cpp" - pthread - lrt - o ./out/producer


run : ./source

make producer
make consumer
clear
./out/producer shmfile & ./out/consumer shmfile

clean :
rm -f ./out/consumer
rm -f ./out/producer
