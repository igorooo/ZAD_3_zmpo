//
// Created by qivi on 10/22/18.
//

#include <iostream>
#include <cstring>
#include <sstream>
#include "CTable.h"

using namespace std;



string CTable::change_array_size(int NEW_SIZE){
    if( NEW_SIZE < 0){
        return "OnlyPositiveNumbers";
    }

    int *NEW_ARRAY = new int[NEW_SIZE];

    for( int i = 0; i < NEW_SIZE; i++){
        NEW_ARRAY[i] = this->ARRAY[i];
    }

    this->ARRAY = NEW_ARRAY;
    return "Success(changing array size)";
}

string CTable::set_array_pos(int POS, int VALUE){
    if( POS < 0 || POS >= this->ARRAY_SIZE){
        return "IndexOutOfBounds";
    }
    this->ARRAY[POS] = VALUE;
    return "Success";
}

int CTable::ret_array_pos(int POS){
    if( POS < 0 || POS >= this->ARRAY_SIZE){
        return -1;
    }
    return this->ARRAY[POS];
}

int* CTable::ret_array(){
    return this->ARRAY;
}

int CTable::ret_array_size(){
    return this->ARRAY_SIZE;
}

void CTable::clone(CTable &PATTERN){
    this->S_NAME = PATTERN.S_NAME + "_copy";
    int SIZE = PATTERN.ret_array_size();
    this->ARRAY = new int[SIZE];

    for( int i = 0; i < SIZE; i++){
        this->set_array_pos(i, PATTERN.ret_array_pos(i));
    }
    this->ARRAY_SIZE = PATTERN.ARRAY_SIZE;
    cout<<"kopiuj: '"<<this->S_NAME<<"'"<<endl;
}

string CTable::info(){
    string INFO = "(" + this->S_NAME + " len: ",TEMP;
    ostringstream SS;
    SS << this->ARRAY_SIZE;
    INFO += SS.str();
    INFO += " values:";

    for(int i = 0; i < this->ARRAY_SIZE; i++){

        SS.str("");
        SS.clear();
        SS << ARRAY[i];
        INFO += " ";
        INFO += SS.str();

        if(i < ARRAY_SIZE-1){
            INFO += ",";
        }
    }

    INFO += ")";
    return INFO;
}

void CTable::set_name(string S_NAME){
    this->S_NAME = S_NAME;
}


CTable::CTable(){
    this->ARRAY = new int[this->DEFAULT_ARRAY_SIZE];
    this->ARRAY_SIZE = this->DEFAULT_ARRAY_SIZE;
    this->S_NAME = DEFAULT_S_NAME;

    cout<<"bezp: '"<<this->S_NAME<<"'"<<endl;

}

CTable::CTable(string S_NAME,int ARRAY_SIZE){
    if(ARRAY_SIZE < 0){
        cout<<"NonPositiveIntegerDetected__Setting DEFAULT_ARRAY_SIZE"<<endl;
        ARRAY_SIZE = this->DEFAULT_ARRAY_SIZE;
    }

    this->ARRAY = new int[ARRAY_SIZE];
    this->ARRAY_SIZE = ARRAY_SIZE;
    this->S_NAME = S_NAME;

    cout<<"parametr: '"<<S_NAME<<"'"<<endl;

}

CTable::CTable(CTable &PATTERN){

    this->S_NAME = PATTERN.S_NAME + "_copy";
    int SIZE = PATTERN.ret_array_size();
    this->ARRAY = new int[SIZE];

    for( int i = 0; i < SIZE; i++){
        this->set_array_pos(i, PATTERN.ret_array_pos(i));
    }
    this->ARRAY_SIZE = PATTERN.ARRAY_SIZE;
    cout<<"kopiuj: '"<<this->S_NAME<<"'"<<endl;
}

CTable::~CTable(){
    cout<<"usuwam: "<<this->S_NAME<<endl;

    delete ARRAY;
}
