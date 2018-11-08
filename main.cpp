#include <iostream>
#include <cstdlib>
#include <fstream>
#include "CMenu.h"
#include "CCommand.h"
#include "CMenuCommand.h"
#include "CTABLE/AddObject.h"
#include "CTABLE/ArrayLength.h"
#include "CTABLE/RmObject.h"
#include "CTABLE/RmAll.h"
#include "CTABLE/SetObjName.h"
#include "CTABLE/AddClone.h"
#include "CTABLE/GetInfo.h"
#include "CTABLE/SetVal.h"
#include "CTABLE/Zad1.h"
#include "ReadFile.h"

int main() {

    ReadFile READ;

    CMenu *MENU;

    MENU = READ.readfile();

    MENU->run(MENU);


    return 0;
}

    //Zad1 *ZAD_1 = new Zad1();

    //ZAD_1->run();

    /*
    ifstream op;
    op.open("../SAVES/main.txt");

    string A;


    getline(op,A);

 */

/*

    CMenu *MAIN = new CMenu("Menu glowne","main");
    CMenu *MENU1 = new CMenu("Podmenu1","menu1");
    CMenu *MENU2 = new CMenu("Podmenu2","menu2");
    CMenu *MENU11 = new CMenu("Podmenu11","menu1");
    CMenu *MENU111 = new CMenu("Podmenu11","menu1");


    CCommand *COM = new CCommand("Ala ma kota");
    CCommand *COM2 = new CCommand("test");
    CCommand *COM3 = new CCommand();

    CMenuCommand *CMCOM1 = new CMenuCommand("Napisz Ala ma kota","ala",COM);
    CMenuCommand *CMCOM2 = new CMenuCommand("Uruchom przegladarke","internet");
    CMenuCommand *CMCOM3 = new CMenuCommand("Test","test",COM2);
    CMenuCommand *CMCOM4 = new CMenuCommand("Default command2","defcom",COM3);

    CMCOM1->add_help("Command writes that ala has cat");

    MAIN->add_CMenuItem(MENU1);
    MAIN->add_CMenuItem(MENU2);
    MAIN->add_CMenuItem(CMCOM1);
    MENU1->add_CMenuItem(CMCOM2);
    MENU1->add_CMenuItem(MENU11);
    MENU2->add_CMenuItem(CMCOM3);
    MENU2->add_CMenuItem(CMCOM4);
    MENU2->add_CMenuItem(MENU111);

 */

    //MAIN->show_leafs();

   // MAIN->run(MAIN);

    //MAIN->save(MAIN);

    /*

    string T = "('Menu glowne','main';('Podmenu1','menu1';['Uruchom przegladarke',',internet','no help added'],('Podmenu11','menu1';)),('Podmenu2','menu2';['Test','test','no help added'],['Default command2','defcom','no help added'],('Podmenu11','menu1';)),['Napisz Ala ma kota','ala','Command writes that ala has cat'])";
    string TT = "('Menu glowne','main';)";
    int POS = 0,POS1=0;

    string TTTT = "'Uruchom przegladarke','internet','no help added'";

     */

    //CMenu *MMENU = new CMenu();
    //cout<<MMENU->get_string(TTTT,POS1)<<endl;
   // cout<<POS<<endl<<T[POS-1]<<endl;


    //CMenuCommand *CMCOM5 = new CMenuCommand();


    /*
     string TTT = "['Uruchom przegladarke','internet','no help added']";

    CMCOM5->get(TTT,POS);
    CMCOM5->show();
    cout<<CMCOM5->s_help();

    */

    /*

    CMenu *TEST_MENU = new CMenu();
    TEST_MENU->get(A,POS);
    cout<<A.length()<<" "<<POS<<endl;


    TEST_MENU->run(TEST_MENU);




   // delete MAIN;


    return 0;
}

     */