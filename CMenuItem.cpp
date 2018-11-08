//
// Created by qivi on 10/20/18.
//

#include <sstream>
#include "CMenuItem.h"


string CMenuItem::s_command() {
    return this->S_COMMAND;
}

string CMenuItem::s_name() {
    return this->S_NAME;
}

string CMenuItem::s_help(){
    return this->S_HELP;
}

void CMenuItem::add_help(string HELP) {
    this->S_HELP = HELP;
}

void CMenuItem::show(){
    cout<<this->s_name()<<"("<<this->s_command()<<")"<<endl;
}

void CMenuItem::set_s_help(string S_HELP) {
    this->S_HELP = S_HELP;
}

void CMenuItem::set_s_command(string S_COMMAND) {
    this->S_COMMAND=S_COMMAND;
}

void CMenuItem::set_s_name(string S_NAME) {
    this->S_NAME=S_NAME;
}

string CMenuItem::get_string(string FILE, int &POS) {

    int START_POS = POS;
    string RESULT;

    stringstream SS;


    if(FILE[POS] != 39){
        RESULT += STATEMENT_1;
        POS = FILE.length() + 2;  // sth like flag
        return RESULT;
    }

    POS++;

    while(FILE[POS] != 39){  // 39 is ' in ASCII

        if( condition( FILE[POS] ) ){
            RESULT += FILE[POS];
        }

        if( !condition( FILE[POS] ) ){  //fail

            this->print_file(FILE,POS);
            cout<<STATEMENT_1<<endl;
            POS = FILE.length() + 2;

            return RESULT;
        }

        if( ! (POS < FILE.length()) ){  //fail

            this->print_file(FILE,POS);
            cout<<STATEMENT_2;

            POS = FILE.length() + 2;

            return RESULT;
        }

        if( POS < FILE.length() ){
            POS++;
        }

    }

    POS++;
    return RESULT;

}

void CMenuItem::print_file(string FILE, int POS) {
    for(int i = 0; i <= POS; i++)
        cout<<FILE[i];
}


bool CMenuItem::condition(char A) {

    char ARR[] = FORBIDDEN_SYMBOLS_FOR_STRING;
    int LENGTH = L_OF_FORB;

    for(int i = 0; i < LENGTH; i++){

        if(A == ARR[i])
            return false;
    }

    return true;
}

CMenuItem::~CMenuItem() {}




