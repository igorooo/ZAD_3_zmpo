//
// Created by qivi on 11/8/18.
//

#ifndef ZAD_3_ZMPO_READFILE_H
#define ZAD_3_ZMPO_READFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include "CMenu.h"

using namespace std;


class ReadFile {

private:
    ifstream READER;

public:
    CMenu* readfile();

};


#endif //ZAD_3_ZMPO_READFILE_H
