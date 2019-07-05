#!/bin/bash
read n
sum=0
for (( i=0; i < n; i++));
do
    read number
    let sum=sum+number
done
printf %.3f\\n "$((sum*(10**10)/n))e-10"