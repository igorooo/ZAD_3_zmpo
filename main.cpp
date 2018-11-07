#include <iostream>
#include <cstdlib>
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

int main() {

    //Zad1 *ZAD_1 = new Zad1();

    //ZAD_1->run();



    CMenu *MAIN = new CMenu("Menu glowne","main");
    CMenu *MENU1 = new CMenu("Podmenu1","menu1");
    CMenu *MENU2 = new CMenu("Podmenu2","menu2");
    CMenu *MENU11 = new CMenu("Podmenu11","menu11");


    CCommand *COM = new CCommand("Ala ma kota");
    CCommand *COM2 = new CCommand("test");
    CCommand *COM3 = new CCommand();

    CMenuCommand *CMCOM1 = new CMenuCommand("Napisz Ala ma kota","ala",COM);
    CMenuCommand *CMCOM2 = new CMenuCommand("Uruchom przegladarke","internet");
    CMenuCommand *CMCOM3 = new CMenuCommand("Test","test",COM2);
    CMenuCommand *CMCOM4 = new CMenuCommand("Default command2","defcom",COM3);

    MAIN->add_CMenuItem(MENU1);
    MAIN->add_CMenuItem(MENU2);
    MAIN->add_CMenuItem(CMCOM1);
    MENU1->add_CMenuItem(CMCOM2);
    MENU1->add_CMenuItem(MENU11);
    MENU2->add_CMenuItem(CMCOM3);
    MENU2->add_CMenuItem(CMCOM4);


    MAIN->show_leafs();

    MAIN->run();


    return 0;
}