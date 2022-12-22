#!/bin/bash

R CMD SHLIB question.c
R -e 'dyn.load("question.so")'
