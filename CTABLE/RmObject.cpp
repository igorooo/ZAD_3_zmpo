//
// Created by qivi on 10/23/18.
//

#include "RmObject.h"

void RmObject::run_command() {

    cout<<"Please enter object's position: ";

    int POS;
    cin>>POS;

    if( POS >= this->TABLE->size() || POS < 0){
        cout<<"Wrong posiotion!"<<endl;
        //sleep(2);
    }

    else{
        delete this->TABLE->at(POS);
        this->TABLE->erase( TABLE->begin() + POS);
        cout<<"Success"<<endl;
        //sleep(3);
    }

}




RmObject::RmObject(vector<CTable *> &TABLE) {
    this->TABLE = &TABLE;
}