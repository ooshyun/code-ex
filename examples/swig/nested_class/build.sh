#!/bin/bash
python3-config --cflags --ldflags > compile_flags.txt
swig -c++ -python x.i
g++ -fPIC -c x.cc x_wrap.cxx $(cat compile_flags.txt)
g++ -shared x.o x_wrap.o -o _nested_class.so $(cat compile_flags.txt)
python3 test.py 