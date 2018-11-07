//
// Created by qivi on 10/24/18.
//

#include "AddClone.h"


void AddClone::run_command() {

    //system("clear");

    cout<<"Please enter object's position: ";

    int POS;
    cin>>POS;

    if( POS >= this->TABLE->size() || POS < 0){
        cout<<"Wrong posiotion!"<<endl;
        //sleep(2);
    }

    else{
        this->TABLE->push_back( new CTable( *(this->TABLE->at(POS)) ) );
        cout<<"Success"<<endl;
        //sleep(3);
    }

}




AddClone::AddClone(vector<CTable *> &TABLE) {
    this->TABLE = &TABLE;
}