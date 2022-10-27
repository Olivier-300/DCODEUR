cmake_minimum_required(VERSION 3.23)
project(DCODEUR C)

set(CMAKE_C_STANDARD 99)

add_executable(DCODEUR main.c ARBRES_N_AIRES.c ARBRES_N_AIRES.h crea_phrases.c crea_phrases.h conjugue_phrases.c conjugue_phrases.h)
