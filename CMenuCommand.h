//
// Created by qivi on 10/20/18.
//

#ifndef ZAD_2_ZMPO_CMENUCOMMAND_H
#define ZAD_2_ZMPO_CMENUCOMMAND_H

#include "CCommand.h"
#include "CMenuItem.h"
#include <iostream>
#include <stack>

#define EMPTY_COMMAND "empty command"
#define CMENUCOMMAND_ID 2
#define DEFAULT_HELP "no help added"
#define FORBIDDEN_SYMBOLS_FOR_COMMAND { '(' , ')' , '['  , ';' , 'NUL'}
#define L_OF_FORB_C 5


using namespace std;

class CMenuCommand : public CMenuItem{

private:
    CCommand *COMMAND;

public:

    void test();
    void run(CMenuItem *MAIN_MENU);
    int class_id();
    void remove();
    void show_leafs();
    void search(vector<string> STACK,string COMMAND);
    void save_current(ofstream &FSTREAM);
    void get(string FILE,int &POS);
    bool condition(char A);
    void show_levels_(vector<queue<CMenuItem* > > &QUEUE, int LEVEL);

    CMenuCommand(string S_NAME, string S_COMMAND ,CCommand *COMMAND);
    CMenuCommand(string S_NAME, string S_COMMAND);
    CMenuCommand();
    ~CMenuCommand();

};



#endif //ZAD_2_ZMPO_CMENUCOMMAND_H
