#!/bin/bash

for (( i=1 ; i<=${1:-"10"} ; i++));
do
	./Hello_world $RANDOM > ./outputs/output_"$i".txt &
done
