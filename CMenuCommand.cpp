//
// Created by qivi on 10/21/18.
//

#include "CMenuCommand.h"


void CMenuCommand::run(CMenuItem *MAIN_MENU) {

    if(this->COMMAND == NULL){
        cout<<EMPTY_COMMAND<<endl;

    }

    else{
        this->COMMAND->run_command();
    }
}


int CMenuCommand::class_id() {
    return CMENUCOMMAND_ID;
}

void CMenuCommand::save_current(ofstream &FSTREAM) {
    FSTREAM<<"['"<<this->s_name()<<"','"<<this->s_command()<<"','"<<this->s_help()<<"']";
}


void CMenuCommand::get(string FILE, int &POS) {

    int START_POS = POS;

    POS++;
    // FIRST PART OF COMMAND PATTERN (S_NAME)

    string STR = this->get_string(FILE,POS);

    if(POS == FILE.length() + 2){
        return;
    }

    this->set_s_name(STR);

    // SECOND ... , (S_COMMAND)

    if(FILE[POS] != ','){

        this->print_file(FILE,POS);
        cout<<STATEMENT_3<<endl;
        POS = FILE.length() + 2;    //flag
        return;
    }
    POS++;

    STR = this->get_string(FILE,POS);

    if(POS == FILE.length() + 2){
        return;
    }

    this->set_s_command(STR);

    // THIRD ... , (S_HELP)

    if(FILE[POS] != ','){

        this->print_file(FILE,POS);
        cout<<STATEMENT_3<<endl;
        POS = FILE.length() + 2;    //flag
        return;
    }
    POS++;

    STR = this->get_string(FILE,POS);

    if(POS == FILE.length() + 2){
        return;
    }

    this->set_s_help(STR);

    // END OF COMMAND

    if(FILE[POS] != ']'){
        this->print_file(FILE,POS);
        cout<<STATEMENT_4<<endl;
        POS = FILE.length() + 2;    //flag
        return;
    }
    POS++;

}

bool CMenuCommand::condition(char A) {

    char ARR[] = FORBIDDEN_SYMBOLS_FOR_COMMAND;
    int LENGTH = L_OF_FORB_C;

    for(int i = 0; i < LENGTH; i++){

        if(A == ARR[i])
            return false;
    }

    return true;
}



CMenuCommand::CMenuCommand(string S_NAME, string S_COMMAND ,CCommand *COMMAND) {
    this->COMMAND = COMMAND;
    this->S_COMMAND = S_COMMAND;
    this->S_NAME = S_NAME;
    this->add_help(DEFAULT_HELP);
}

CMenuCommand::CMenuCommand(string S_NAME, string S_COMMAND) {
    this->COMMAND = COMMAND;
    this->S_COMMAND = S_COMMAND;
    this->S_NAME = S_NAME;
    this->add_help(DEFAULT_HELP);
}

CMenuCommand::~CMenuCommand() {
    delete COMMAND;
    cout<<"removing: "<<this->S_NAME<<endl;
}

CMenuCommand::CMenuCommand() {}

void CMenuCommand::remove() {}
void CMenuCommand::show_leafs() {}
void CMenuCommand::search(vector<string> STACK,string COMMAND) {}









