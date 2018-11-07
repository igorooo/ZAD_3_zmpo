//
// Created by qivi on 10/22/18.
//

#ifndef ZAD_2_ZMPO_CTABLE_H
#define ZAD_2_ZMPO_CTABLE_H
#define DEFAULT_S_NAME "object"

#include <iostream>



using namespace std;

class CTable{

private:
    //const string DEFAULT_S_NAME = "object";
    string S_NAME;
    int *ARRAY;
    static const int DEFAULT_ARRAY_SIZE = 10;
    int ARRAY_SIZE;

public:

    string change_array_size(int NEW_SIZE);
    string set_array_pos(int POS, int VALUE);
    int ret_array_pos(int POS);
    int* ret_array();
    int ret_array_size();
    void clone(CTable &PATTERN);
    string info();
    void set_name(string S_NAME);

    CTable();
    CTable(string S_NAME, int ARRAY_SIZE);
    CTable(CTable &PATTERN);

    ~CTable();


};

#endif //ZAD_2_ZMPO_CTABLE_H
