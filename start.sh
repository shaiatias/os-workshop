
#! /bin/bash

rmmod hello.ko -f

make

bash -c "insmod hello.ko"

sleep 2

dmesg | tail -10

rmmod hello.ko

sleep 2

dmesg | tail -10

