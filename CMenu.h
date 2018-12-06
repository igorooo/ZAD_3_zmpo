//
// Created by qivi on 10/19/18.
//

#ifndef ZAD_2_ZMPO_CMENU_H
#define ZAD_2_ZMPO_CMENU_H

#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include "CMenuItem.h"
#include "CMenuCommand.h"
#include "CTABLE/CTable.h"
#include <stack>
#include <queue>
#define CMENU_ID 1
#define BACK "back"
#define EDIT_MENU "edit"
#define DELETE_ITEM "delete"
#define HELP_COM "help"
#define SEARCH "search"
#define SAVE "save"
#define MAX_LEVEL 10

#define FORBIDDEN_SYMBOLS_FOR_MENU { ']' , 'NUL'}
#define L_OF_FORB_M 5



using namespace std;

class CMenu : public CMenuItem{

private:

    vector <CMenuItem*> VECTOR;
    vector <CTable*> *TABLE;

    string name_helper(string NAME);
    string command_helper(string COMMAND);

public:

    void run(CMenuItem *MAIN_MENU);
    int check_for_command(string COMMAND);
    int check_for_name(string NAME);
    void add_CMenuItem(CMenuItem *ITEM);
    void edit_menu();
    void remove();
    void delete_item(int POSITION);
    void delete_menu();
    int delete_command_helper(string COMMAND);
    int class_id();
    void show_leafs();
    void help();
    void search_(CMenuItem *MAIN_MENU);
    void search(vector<string> STACK,string COMMAND);
    void save(CMenuItem *MAIN_MENU);
    void save_current(ofstream &FSTREAM);
    void get(string FILE,int &POS);
    bool condition(char A);
    void show_levels(CMenuItem *MAIN_MENU);
    void show_levels_(vector<queue<CMenuItem* > > &QUEUE, int LEVEL);

    CMenu();
    CMenu(string S_NAME, string S_COMMAND,vector <CTable*> &TABLE);
    CMenu(string S_NAME, string S_COMMAND);
    ~CMenu();


};


#endif //ZAD_2_ZMPO_CMENU_H
