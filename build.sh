#!/bin/bash

g++ main.cpp grid.cpp position.cpp blocks.cpp colors.cpp block.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -g
