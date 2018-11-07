//
// Created by qivi on 10/22/18.
//

#ifndef ZAD_2_ZMPO_ADDOBJECT_H
#define ZAD_2_ZMPO_ADDOBJECT_H


#include "../CCommand.h"
#include "../CMenuItem.h"
#include "CTable.h"
#include <vector>

class AddObject: public CCommand {

private:
    string S_NAME;
    int ARRAY_SIZE,AMOUNT;
    vector <CTable*> *TABLE;

public:
    virtual void run_command();

    AddObject(vector <CTable*> &TABLE);



};


#endif //ZAD_2_ZMPO_ADDOBJECT_H
