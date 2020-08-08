#!/usr/bin/zsh


# Koraci za generisanje gcov izvestaja:
# 
# 1. potrebno je prevesti program opcijom --coverage, sto kreira instrumentalizovanu verziju originalnog programa koji broji i generise statistiku sta se desava prilikom izvrsavanja programa
#     -takodje je potrebno prevesti komandom za debagovanje -g
#     -i iskljuciti optimizacije -O0



clang-9 --coverage -g -O0 article-example.c

#2. da bi llvm-cov-10 gcov opcija izgenerisala izvestaj mora da postoji .gcda fajl na osnovu kog se izvestaj pravi..
#gcda se pravi svaki put kada se izvrsi program

./a.out

#opcijom gcov se generise izvestaj koliko se linija, blokova grana itd izvrsilo
# ovoj komandi je bitan fajl gcno
llvm-cov-10 gcov article-example.gcno --branch-probabilities --color --atomic-counter-update-promoted --dump -p --verify-region-info --rdf-dump

## U ovom trenutku imamo gcov fajl gde se u kome imamo human readable statistiku


##zadatak je automatizovati pricu u pythonu recimmo gde se dobija source kod i test input i treba vratiti procenat izvrsenih linija za taj test primer
## odnosno potrebno je dobiti tu vrednost interno u nekoj pythonovoj strukturi


# 2. STVAR

## uzimamo vrednosti [0,1] ili procente izvrsenih linija, 

## kao kriterijum kojim se ocenjuje kvalitet test primera moze se uzimati broj izvrsenih grana, linija blokova
## broj svega toga veci/manji od zadatog broja






