//
// Created by qivi on 10/22/18.
//

#ifndef ZAD_2_ZMPO_ARRAYLENGTH_H
#define ZAD_2_ZMPO_ARRAYLENGTH_H

#include <vector>
#include "CTable.h"
#include "../CCommand.h"

using namespace std;

class ArrayLength: public CCommand {

private:
    string S_NAME;
    int ARRAY_SIZE,AMOUNT;
    vector <CTable*> *TABLE;

public:
    virtual void run_command();

    ArrayLength(vector <CTable*> &TABLE);




};


#endif //ZAD_2_ZMPO_ARRAYLENGTH_H
