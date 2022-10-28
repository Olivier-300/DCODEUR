cmake_minimum_required(VERSION 3.23)
project(DCODEUR C)

set(CMAKE_C_STANDARD 99)

add_executable(DCODEUR main.c ARBRES_VERBE.c ARBRES_VERBE.h crea_phrases.c crea_phrases.h conjugue_phrases.c conjugue_phrases.h ARBRES_NOMS.c ARBRES_NOMS.h ARBRES_ADV.c ARBRES_ADV.h ARBRES_ADJ.c ARBRES_ADJ.h)
