//
// Created by qivi on 10/22/18.
//

#include "AddObject.h"


void AddObject::run_command() {

    cout<<"How many objects you want to add?: ";
    cin>>AMOUNT;

    if(AMOUNT < 0){
        cout<<"Only positive integers!"<<endl;;
        //sleep(1);
    }

    else{

        for( int i = 0; i < AMOUNT; i++){
            //system("clear");

            cout<<"Object no. "<<i<<": "<<endl;
            cout<<"Please enter new object's name: ";
            cin>>S_NAME;

            cout<<"Please enter new object's array length: ";
            cin>>ARRAY_SIZE;

            if(ARRAY_SIZE < 0){
                cout<<"Only positive integers!"<<endl;;
               // sleep(1);
            }



            else{
                this->TABLE->push_back(new CTable(S_NAME,ARRAY_SIZE));
                cout<<"Sucess"<<endl;
                //sleep(1);
            }
        }
    }

}

AddObject::AddObject(vector<CTable *> &TABLE) {
    this->TABLE = &TABLE;
}