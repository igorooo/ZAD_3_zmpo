//
// Created by qivi on 11/8/18.
//

#include "ReadFile.h"

CMenu* ReadFile::readfile() {

    string FILE_NAME,FILE;

    cout<<"Enter file name (also PATH if not in the same directory for e.g ../SAVES/main.txt ) : ";
    cin>>FILE_NAME;

    this->READER.open(FILE_NAME.c_str());

    while(! READER.good() ){

        cout<<"wrong path or file name, try again!"<<endl;
        cout<<"Enter file name (also PATH if not in the same directory for e.g ../SAVES/main.txt ) : ";
        cin>>FILE_NAME;
        this->READER.open(FILE_NAME.c_str());

        if(FILE_NAME == "stop"){
            cout<<"aborted"<<endl;
            return new CMenu();
        }
    }

    getline(this->READER,FILE);

    CMenu *RESULT = new CMenu();

    int POS = 0;

    RESULT->get(FILE,POS);

    if(POS == FILE.length() + 2){
        delete RESULT;
        return new CMenu();
    }


    return RESULT;
}
