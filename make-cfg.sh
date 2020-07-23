#!/bin/zsh


echo "Creating CFG picture from source code for $1"



#TODO: parametrizovati nazive argumenata da bude konkretan za svaki kod

clang++ -O3 -emit-llvm $1 -c -o temp.bc

opt-10 --dot-cfg temp.bc -o temp.dot

dot -Tpng .main.dot -o temp.png

rm -rf temp.bc temp.dot


okular temp.png &


