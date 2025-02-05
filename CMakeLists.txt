cmake_minimum_required(VERSION 3.26)
project(estrutura_de_dados C)

set(CMAKE_C_STANDARD 99)

add_executable(estrutura_de_dados
        singly-linked-list/singly-liked-list.c
        singly-linked-list/singly-linked-list.h
        doubly-linked-list/doubly-linked-list.c
        doubly-linked-list/doubly-linked-list.h
)
