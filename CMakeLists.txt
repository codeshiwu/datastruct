cmake_minimum_required(VERSION 3.28)
project(datastruct)

set(CMAKE_CXX_STANDARD 20)

add_executable(datastruct main.cpp
        LinkedList/ListNode.h
        LinkedList/List.cpp
        LinkedList/List.h
        LinkedList/leecode-707.h
        LinkedList/leecode-206.h
        LinkedList/leecode-24.h
        LinkedList/leecode-19.h)
