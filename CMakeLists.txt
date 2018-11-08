cmake_minimum_required(VERSION 3.12)
project(ZAD_3_zmpo)

set(CMAKE_CXX_STANDARD 98)

include_directories(.)
include_directories(CTABLE)

add_executable(ZAD_3_zmpo
        CTABLE/AddClone.cpp
        CTABLE/AddClone.h
        CTABLE/AddObject.cpp
        CTABLE/AddObject.h
        CTABLE/ArrayLength.cpp
        CTABLE/ArrayLength.h
        CTABLE/CTable.cpp
        CTABLE/CTable.h
        CTABLE/GetInfo.cpp
        CTABLE/GetInfo.h
        CTABLE/RmAll.cpp
        CTABLE/RmAll.h
        CTABLE/RmObject.cpp
        CTABLE/RmObject.h
        CTABLE/SetObjName.cpp
        CTABLE/SetObjName.h
        CTABLE/SetVal.cpp
        CTABLE/SetVal.h
        CTABLE/Zad1.cpp
        CTABLE/Zad1.h
        CCommand.cpp
        CCommand.h
        CMenu.cpp
        CMenu.h
        CMenuCommand.cpp
        CMenuCommand.h
        CMenuItem.cpp
        CMenuItem.h
        main.cpp ReadFile.cpp ReadFile.h)
