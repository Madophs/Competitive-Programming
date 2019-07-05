#!/bin/bash
read character
if [[ $character == "y" || $character == "Y" ]];
then
    echo "YES"
else
    echo "NO"
fi