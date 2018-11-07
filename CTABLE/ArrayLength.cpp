//
// Created by qivi on 10/22/18.
//

#include "ArrayLength.h"

void ArrayLength::run_command() {

    cout<<"Please enter object's position: ";

    int POS;
    cin>>POS;

    if( POS >= this->TABLE->size() || POS < 0){
        cout<<"Wrong posiotion!"<<endl;
        //sleep(2);
    }



    else{
        cout<<"Objest's array length is: "<<this->TABLE->at(POS)->ret_array_size()<<endl;
        //sleep(3);
    }
}





ArrayLength::ArrayLength(vector<CTable *> &TABLE) {
    this->TABLE = &TABLE;
}