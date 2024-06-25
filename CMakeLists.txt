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
        LinkedList/leecode-19.h
        LinkedList/leecode-0207.h
        LinkedList/leecode-142.h
        HashTable/leecode-242.h
        HashTable/leecode-349.h
        HashTable/leecode-202.h
        HashTable/leecode-1.h
        HashTable/leecode-454.h
        HashTable/leecode-383.h
        HashTable/leecode-15.h
        HashTable/leecode-18.h
        string/leecode-344.h
        string/leecode-541.h
        string/leecode-151.h
        string/right.h)
