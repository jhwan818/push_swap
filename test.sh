#!/bin/bash

ARG=$(cat output.txt);
./push_swap $ARG | wc -l;
./push_swap $ARG | ./checker_MAC $ARG
