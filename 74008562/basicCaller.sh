#!/bin/bash

for i in {0..2..1}; do
    for j in {1..2..1}; do
        ./basicScript.R file-type${i}-sector${j}.tsv
    done
done
