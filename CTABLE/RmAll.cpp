//
// Created by qivi on 10/24/18.
//

#include "RmAll.h"


void RmAll::run_command() {


    //system("clear");

    for(int i = 0; i < this->TABLE->size(); i++){
        delete this->TABLE->at(i);
    }
    this->TABLE->clear();
    cout<<"Success"<<endl;
    //sleep(3);
}






RmAll::RmAll(vector<CTable *> &TABLE) {
    this->TABLE = &TABLE;
}