//
// Created by qivi on 10/24/18.
//

#ifndef ZAD_2_ZMPO_ADDCLONE_H
#define ZAD_2_ZMPO_ADDCLONE_H


#include <vector>
#include "CTable.h"
#include "../CCommand.h"

using namespace std;

class AddClone: public CCommand {

private:
    string S_NAME;
    int ARRAY_SIZE,AMOUNT;
    vector <CTable*> *TABLE;

public:
    virtual void run_command();

    AddClone(vector <CTable*> &TABLE);



};


#endif //ZAD_2_ZMPO_ADDCLONE_H
