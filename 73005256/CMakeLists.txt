cmake_minimum_required(VERSION 3.0) # optional line, but prevents a warning

project(MyProject)

add_executable(myapp
    main.cpp
    miscClass1.cpp
    miscClass1.h # technically we don't need to list headers
)
