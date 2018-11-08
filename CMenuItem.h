//
// Created by qivi on 10/19/18.
//

#ifndef ZAD_2_ZMPO_CMENUITEM_H
#define ZAD_2_ZMPO_CMENUITEM_H


#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#define FORBIDDEN_SYMBOLS_FOR_STRING { '(' , ')' , '[' , ']' , ',' , ';' , 'NUL'}
#define L_OF_FORB 7
#define STATEMENT_1 "<-|MISMATCH here, <'> expected|"
#define STATEMENT_2 "<-|MISMATCH here, <'> expected - out of bounds|"
#define STATEMENT_3 "<-|MISMATCH here, <,> expected|"
#define STATEMENT_4 "<-|MISMATCH here, <]> expected|"
#define STATEMENT_5 "<-|MISMATCH here, <;> expected|"
#define STATEMENT_6 "<-|MISMATCH here, <)> expected|"
#define STATEMENT_7 "<-|MISMATCH here, <(> expected|"


using namespace std;

class CMenuItem{

protected:
    string S_COMMAND;
    string S_NAME;
    string S_HELP;

public:
    virtual void run(CMenuItem *MAIN_MENU) = 0;
    virtual int class_id() = 0;
    virtual void remove() = 0;
    virtual void show_leafs() = 0;
    virtual void search(vector<string> STACK,string COMMAND) = 0;
    virtual void save_current(ofstream &FSTREAM) = 0;
    virtual void get(string FILE,int &POS) = 0;
    void set_s_command(string S_COMMAND);
    void set_s_name(string S_NAME);
    void set_s_help(string (S_HELP));
    string s_command();
    string s_name();
    string s_help();
    void add_help(string HELP);
    void show();
    string get_string(string FILE, int &POS);
    void print_file(string FILE, int POS);
    virtual bool condition(char A);

    virtual ~CMenuItem();



};

#endif //ZAD_2_ZMPO_CMENUITEM_H
