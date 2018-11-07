//
// Created by qivi on 10/24/18.
//

#include "GetInfo.h"


void GetInfo::run_command() {

    //system("clear");

    cout<<"Please enter object's position: ";

    int POS;
    cin>>POS;

    if( POS >= this->TABLE->size() || POS < 0){
        cout<<"Wrong posiotion!"<<endl;
        //sleep(3);
    }

    else{
        cout<<this->TABLE->at(POS)->info()<<endl;
        //sleep(4);
    }


}




GetInfo::GetInfo(vector<CTable *> &TABLE) {
    this->TABLE = &TABLE;
}