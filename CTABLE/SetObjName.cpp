//
// Created by qivi on 10/24/18.
//

#include "SetObjName.h"


void SetObjName::run_command() {


    //system("clear");

    cout<<"Please enter object's position: ";

    int POS;
    cin>>POS;

    if( POS >= this->TABLE->size() || POS < 0){
        cout<<"Wrong posiotion!"<<endl;
        //sleep(2);
    }

    else{
        string S_NAME;
        cout<<"Please enter new object's name: ";
        cin>>S_NAME;
        this->TABLE->at(POS)->set_name(S_NAME);
        cout<<"Success"<<endl;

        //sleep(3);
    }

}




SetObjName::SetObjName(vector<CTable *> &TABLE) {
    this->TABLE = &TABLE;
}