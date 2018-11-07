//
// Created by qivi on 10/23/18.
//

#ifndef ZAD_2_ZMPO_RMOBJECT_H
#define ZAD_2_ZMPO_RMOBJECT_H


#include <vector>
#include "CTable.h"
#include "../CCommand.h"

using namespace std;

class RmObject: public CCommand {

private:
    string S_NAME;
    int ARRAY_SIZE,AMOUNT;
    vector <CTable*> *TABLE;

public:
    virtual void run_command();

    RmObject(vector <CTable*> &TABLE);




};

#endif //ZAD_2_ZMPO_RMOBJECT_H
