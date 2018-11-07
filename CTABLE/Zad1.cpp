//
// Created by qivi on 10/24/18.
//

#include "Zad1.h"


void Zad1::run() {

    vector <CTable*> TABLE;

    CMenu *MENU = new CMenu("ZADANIE 1","zad1");

    AddObject *ADD_OBJ = new AddObject(TABLE);
    ArrayLength *ARRAY_LENGTH = new ArrayLength(TABLE);
    RmObject *REMOVE_OBJECT = new RmObject(TABLE);
    RmAll *REMOVE_ALL = new RmAll(TABLE);
    SetObjName *SET_OBJ_NAME = new SetObjName(TABLE);
    AddClone *ADD_CLONE = new AddClone(TABLE);
    GetInfo *GET_INFO = new GetInfo(TABLE);
    SetVal *SET_VAL = new SetVal(TABLE);



    //CMenuCommand *ADDOBJ = new CMenuCommand("add object","1",ADD_OBJ);
    // CMenuCommand *ARRAYLENGTH = new CMenuCommand("check length of array","2",ARRAY_LENGTH);

    vector <CMenuCommand*> CMENU_COMMAND_ARRAY;

    CMENU_COMMAND_ARRAY.push_back(new CMenuCommand("Add objects","1",ADD_OBJ));
    CMENU_COMMAND_ARRAY.push_back(new CMenuCommand("Check object's array length","2",ARRAY_LENGTH));
    CMENU_COMMAND_ARRAY.push_back(new CMenuCommand("Remove object","3",REMOVE_OBJECT));
    CMENU_COMMAND_ARRAY.push_back(new CMenuCommand("Remove all","4",REMOVE_ALL));
    CMENU_COMMAND_ARRAY.push_back(new CMenuCommand("Set object name","5",SET_OBJ_NAME));
    CMENU_COMMAND_ARRAY.push_back(new CMenuCommand("Add clone","6",ADD_CLONE));
    CMENU_COMMAND_ARRAY.push_back(new CMenuCommand("Get info about object","7",GET_INFO));
    CMENU_COMMAND_ARRAY.push_back(new CMenuCommand("Set value in object's array","8",SET_VAL));


    for(int i = 0; i < CMENU_COMMAND_ARRAY.size(); i++) MENU->add_CMenuItem(CMENU_COMMAND_ARRAY[i]);

    MENU->run();

    REMOVE_ALL->run_command();


    //delete ADD_CLONE,ADD_OBJ,ARRAY_LENGTH,REMOVE_ALL,REMOVE_OBJECT,SET_OBJ_NAME,GET_INFO,SET_VAL;

    delete MENU;

    CMENU_COMMAND_ARRAY.clear();


}
