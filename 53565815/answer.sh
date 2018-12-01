#!/bin/bash

(echo "Hello,World";echo "Bye,Bye") | r -e 'X <- readLines(stdin());print(X)' -

(echo "X,Y"; echo "Hello,World"; echo "Bye,Bye") | r -d -e 'print(X)' -
