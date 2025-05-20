#!/bin/bash
# filepath: c:\Users\jgsei\OneDrive\Documentos\GitHub\Graph_Theory\Bellman-Ford\Bath\gerar_sp.sh

bellman=./Bellman-Ford.bin

mkdir -p sp

for arq in instances/*.dat
do
    nome=$(basename "$arq")
    $bellman -f "$arq" > "sp/$nome"
done