#!/bin/sh

clang++ test.cpp -fPIC -shared -o libtest.dylib -g

clang++ test_dylib.cpp -L. -ltest -g
