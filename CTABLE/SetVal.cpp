//
// Created by qivi on 10/24/18.
//

#include "SetVal.h"


void SetVal::run_command() {

    //system("clear");

    cout<<"Please enter object's position: ";

    int POS;
    cin>>POS;

    if( POS >= this->TABLE->size() || POS < 0){
        cout<<"Wrong posiotion!"<<endl;
        //sleep(2);
    }

    else{
        int POS_, VAL;
        cout<<"Please enter position in array:";
        cin>>POS_;

        if(POS_ >= this->TABLE->at(POS)->ret_array_size() || POS_ < 0){
            cout<<"Wrong position!"<<endl;
            //sleep(2);
        }
        else{
            cout<<"Please enter value: ";
            cin>>VAL;
            this->TABLE->at(POS)->set_array_pos(POS_,VAL);
            cout<<"Success"<<endl;
            //sleep(3);
        }
    }

}




SetVal::SetVal(vector<CTable *> &TABLE) {
    this->TABLE = &TABLE;
}