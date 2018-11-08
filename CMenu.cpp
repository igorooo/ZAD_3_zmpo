//
// Created by qivi on 10/20/18.
//

#include "CMenu.h"


int CMenu::check_for_command(string COMMAND) {

    int POSITION = 0,BOUND = this->VECTOR.size();

    for(POSITION ; POSITION < BOUND ; POSITION ++){
        if(VECTOR[POSITION]->s_command().compare(COMMAND) == 0)
            return POSITION;
    }

    return -1; //failed
}

int CMenu::check_for_name(string NAME) {

    int POSITION = 0,BOUND = this->VECTOR.size();

    for(POSITION ; POSITION < BOUND ; POSITION ++){
        if(VECTOR[POSITION]->s_name() == NAME)
            return POSITION;
    }

    return -1; //failed
}

string CMenu::name_helper(string NAME) {

    string S_NAME = NAME;

    while(check_for_name(S_NAME) != -1){

        cout<<"Given name already exist on current menu, try again: ";
        cin>>S_NAME;

    }

    return S_NAME;

}

string CMenu::command_helper(string COMMAND) {

    string S_COMMAND = COMMAND;

    while(check_for_command(S_COMMAND) != -1){

        cout<<"Given command already exist on current menu, try again: ";
        cin>>S_COMMAND;

    }

    return S_COMMAND;

}

int CMenu::delete_command_helper(string COMMAND) {

    string S_COMMAND = COMMAND;
    int POSITION = check_for_command(S_COMMAND);

    while(POSITION == -1 || S_COMMAND == this->S_COMMAND){

        cout<<"Cant find given command, try again: ";
        cin>>S_COMMAND;
        POSITION = check_for_command(S_COMMAND);
    }

    return POSITION;

}





void CMenu::run(CMenuItem *MAIN_MENU) {

    string OPTION_COMMAND; // = "";
    int BOUND,COMMAND_POSITION;


    while(OPTION_COMMAND != BACK){

       // system("clear");

        BOUND = this->VECTOR.size();

        cout<<"\n\n";
        cout<<"To add positions in menu enter: (edit), to remove positions enter: (delete)"<<endl<<endl;


        for(int i = 0 ; i < BOUND ; i++){

            if(i == 0) cout<<"current menu: ";
            VECTOR[i]->show();

            if(i < BOUND-1) cout<<i+1<<". ";

        }

        cin>>OPTION_COMMAND;

        COMMAND_POSITION = check_for_command(OPTION_COMMAND);

        if(COMMAND_POSITION != -1){

            this->VECTOR[COMMAND_POSITION]->run(MAIN_MENU);

        }

        if(COMMAND_POSITION == -1 && OPTION_COMMAND != BACK){

            if(OPTION_COMMAND == EDIT_MENU){
                this->edit_menu();
            }

            else if(OPTION_COMMAND == DELETE_ITEM){
                this->delete_menu();
            }

            else if(OPTION_COMMAND == HELP_COM){
                this->help();
            }

            else if(OPTION_COMMAND == SEARCH){
                this->search_(MAIN_MENU);
            }

            else if(OPTION_COMMAND == SAVE){
                this->save(MAIN_MENU);
            }

            else{
                cout<<"There is no such a position!"<<endl;
            }

        }
    }
}



void CMenu::add_CMenuItem(CMenuItem *ITEM) {

    this->VECTOR.push_back(ITEM);
}

void CMenu::edit_menu() {

  //  system("clear");
    cout<<"1. To add new menu here enter (menu)\n2. To add new command here enter (command)\n";

    string OPTION,S_NAME,S_COMMAND;

    cin>>OPTION;

    if(OPTION == "menu"){


        cout<<"Enter new menu name: ";
        cin>>S_NAME;
        S_NAME = this->name_helper(S_NAME);


        cout<<"Enter new menu command: ";
        cin>>S_COMMAND;
        S_COMMAND = this->command_helper(S_COMMAND);

        this->add_CMenuItem(new CMenu(S_NAME,S_COMMAND));

    }

    if(OPTION == "command"){

        string OPTION_2,MESSAGE;

        cout<<"Enter new command name: ";
        cin>>S_NAME;

        cout<<"Enter command for this function: ";
        cin>>S_COMMAND;

        cout<<"Do you want to add CCommand for this function? if yes enter (yes): ";
        cin>>OPTION_2;

        if( OPTION_2 == "yes"){

            cout<<"Enter message for CCommand"<<endl;
            cin>>MESSAGE;

            this->add_CMenuItem(new CMenuCommand( S_NAME, S_COMMAND,   new CCommand(MESSAGE)  ));

        }

        else{
            this->add_CMenuItem(new CMenuCommand(S_NAME , S_COMMAND));
        }
    }
}



void CMenu::remove() {

    CMenuItem *TEMP;

    while(this->VECTOR.size() > 1){

        TEMP = this->VECTOR.back();
        this->VECTOR.pop_back();

        if(TEMP->class_id() == 1){

            TEMP->remove();
        }

        delete TEMP;
    }
}



void CMenu::delete_item(int POSITION) {

    CMenuItem *TEMP = this->VECTOR[POSITION];

    this->VECTOR.erase(this->VECTOR.begin()+POSITION);

    if(TEMP->class_id() == 1){
        TEMP->remove();
    }

    delete TEMP;
}

void CMenu::delete_menu() {

    string COMMAND;

    cout<<"Enter command of item u want to remove: ";

    cin>>COMMAND;


    delete_item(delete_command_helper(COMMAND));

}



int CMenu::class_id() {
    return CMENU_ID;
}

void CMenu::show_leafs() {

    CMenuItem *TEMP;

   // cout<<"entered: "<<this->S_NAME<<endl;

    if(this->VECTOR.size() > 1){

        for(int ITER = 1; ITER < this->VECTOR.size(); ITER++){

            TEMP = this->VECTOR[ITER];

            if(TEMP->class_id() == 2){
                cout<<"Leaf: ";
                TEMP->show();
            }

            if(TEMP->class_id() == 1){
                TEMP->show_leafs();
            }

            //cout<<"-->Cur. TEMP:";
            //TEMP->show();
        }

       // cout<<"end of: "<<this->S_NAME<<endl;
    }

    else{
        cout<<"Leaf: ";
        this->show();
    }

}


void CMenu::help() {

    string COMMAND;
    cin>>COMMAND;

    int COMMAND_POSITION = check_for_command(COMMAND);

    if(COMMAND_POSITION == -1){

        cout<<"command doesnt exist in this menu"<<endl;
    }

    else{

        if(VECTOR[COMMAND_POSITION]->class_id() == 2){
            cout<<VECTOR[COMMAND_POSITION]->s_help()<<endl;
        }

        else{
            cout<<"command doesnt exist in this menu"<<endl;
        }
    }
}

void CMenu::search_(CMenuItem *MAIN_MENU){

    string COMMAND;
    cin>>COMMAND;
    vector<string> STACK;
    MAIN_MENU->search(STACK,COMMAND);
}

void CMenu::search(vector<string> STACK,string COMMAND) {

    CMenuItem *TEMP;

    if(this->s_command() == COMMAND){

        for(int i = 0; i < STACK.size() ; i++){
            cout<<STACK[i]<<"/";
        }
        cout<<this->s_command()<<endl;

    }

    STACK.push_back(this->s_name());


    if(this->VECTOR.size() > 1){

        for(int ITER = 1; ITER < this->VECTOR.size(); ITER++){

            TEMP = this->VECTOR[ITER];

            if(TEMP->class_id() == 2){

                if(TEMP->s_command() == COMMAND){
                    for(int i = 0; i < STACK.size() ; i++){
                        cout<<STACK[i]<<"/";
                    }
                    cout<<TEMP->s_command()<<endl;
                }
            }
            if(TEMP->class_id() == 1){
                TEMP->search(STACK,COMMAND);
            }
        }
    }


    STACK.pop_back();

}

void CMenu::save_current(ofstream &FSTREAM) {

    FSTREAM<<"('"<<this->s_name()<<"','"<<this->s_command()<<"';";
    CMenuItem *TEMP;

    if(this->VECTOR.size() > 1){

        for(int ITER = 1; ITER < this->VECTOR.size(); ITER++){

            this->VECTOR[ITER]->save_current(FSTREAM);

            if(ITER < this->VECTOR.size()-1){
                FSTREAM<<",";
            }
        }
    }

    FSTREAM<<")";
}

void CMenu::save(CMenuItem *MAIN_MENU) {

    ofstream FSTREAM;
    string PATH = "../SAVES/",FILE_NAME;

    cout<<"Enter file name (without .txt): ";
    cin>>FILE_NAME;
    PATH += FILE_NAME;
    PATH += ".txt";

    FSTREAM.open(PATH.c_str());

    MAIN_MENU->save_current(FSTREAM);

    FSTREAM.close();
}




void CMenu::get(string FILE, int &POS) {

    this->add_CMenuItem(this);

    int START_POS = POS;
    string STR;

    //BEGGINING of pattern

    if( FILE[POS] != '('){
        this->print_file(FILE,POS);
        cout<<STATEMENT_7<<endl;
        POS = FILE.length() + 2;    //flag
        return;
    }
    POS ++;

    //FIRST (S_NAME)

    STR = this->get_string(FILE,POS);

    if(POS == FILE.length() + 2){   // checking after every outside function call
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

    // THIRD - children  ---------------------------------


    if(FILE[POS] != ';'){

        this->print_file(FILE,POS);
        cout<<STATEMENT_5<<endl;
        POS = FILE.length() + 2;    //flag
        return;
    }
    POS++;

    if(FILE[POS] != ')' && FILE[POS] != '[' && FILE[POS] != '(' ){
        this->print_file(FILE,POS);
        cout<<STATEMENT_8<<endl;
        POS = FILE.length() + 2;    //flag
        return;
    }

    if(FILE[POS] == ')'){
        POS++;
        return;
    }



    while( FILE[POS] == '(' || FILE[POS] == '[' ){

        if(FILE[POS] == '('){

            CMenu *NEW_MENU = new CMenu();
            this->add_CMenuItem(NEW_MENU);
            NEW_MENU->get(FILE,POS);
           // cout<<this->s_name()<<"->->>"<<NEW_MENU->s_name()<<endl;

            if(POS == FILE.length() + 2){  //routine check
                return;
            }


            if(FILE[POS] != ',' && FILE[POS] != ')'){

                this->print_file(FILE,POS);
                cout<<STATEMENT_3<<endl;
                //cout<<this->s_name()<<" "<<NEW_MENU->s_name();
                POS = FILE.length() + 2;    //flag
                return;
            }
        }

        else if(FILE[POS] == '['){

            CMenuCommand *NEW_COMM = new CMenuCommand();
            this->add_CMenuItem(NEW_COMM);
            NEW_COMM->get(FILE,POS);
            //cout<<this->s_name()<<"->->>"<<NEW_COMM->s_name()<<endl;

            if(POS == FILE.length() + 2){  //routine check
                return;
            }

            if(FILE[POS] != ',' && FILE[POS] != ')'){

                this->print_file(FILE,POS);
                cout<<STATEMENT_3<<endl;
                POS = FILE.length() + 2;    //flag
                return;
            }
        }

        else{

            this->print_file(FILE,POS);
            cout<<STATEMENT_8<<endl;
            POS = FILE.length() + 2;    //flag
            return;
        }


        POS++;
    }


    //POS++; // ???




}

bool CMenu::condition(char A) {
    return CMenuItem::condition(A);
}



CMenu::CMenu(string S_NAME, string S_COMMAND) {
    this->S_NAME = S_NAME;
    this->S_COMMAND = S_COMMAND;
    this->VECTOR.push_back(this);
}

CMenu::CMenu(string S_NAME, string S_COMMAND, vector<CTable *> &TABLE) {
    this->S_NAME = S_NAME;
    this->S_COMMAND = S_COMMAND;
    this->VECTOR.push_back(this);
    this->TABLE = &TABLE;

}

CMenu::CMenu() {}

CMenu::~CMenu() {

    this->remove();
    cout<<"removing: "<<this->S_NAME<<endl;

}












