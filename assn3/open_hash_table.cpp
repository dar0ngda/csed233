#include <iostream>
#include <fstream>
#include <string>
#include "open_hash_function.h"
#include "open_hash_table.h"

using namespace std;

OpenHashTable::OpenHashTable(int table_size, OpenHashFunction *hf) : table_size(table_size) {
    this->hf = hf;
    table = new HashNode*[this->table_size];
    for(int i = 0; i < this->table_size; i++){
        table[i] = NULL;
    }
    this->states = new OpenTableState[this->table_size];

    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    
    /*  Write your codes if you need  */
    for (int i = 0; i < this->table_size; i++) {
        this->states[i] = OPEN_EMPTY;
    }

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

OpenHashTable::~OpenHashTable() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    
    /*  Write your codes if you need  */
    for (int i = 0; i < table_size; i++) {
        while (table[i] != NULL) {
            HashNode* cur = table[i];
            table[i] = table[i]->next;
            delete cur;
        }
    }

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////

    delete[] table;
    delete[] this->states;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
void OpenHashTable::print_table(ostream &out) {
    for (int i=0; i < this->table_size; i++) {
        out << i << ": ";
        if (this->states[i] == OPEN_EMPTY){
            out << "empty" << endl;
        }else if (this->states[i] == OPEN_OCCUPIED){
          HashNode* cur;
          cur = table[i];
          while(cur->next != NULL){
              out << cur->key ;
              out << ", ";
              cur = cur->next;
          }
            out << cur->key << endl;
        }else{
            out << "unknown state" << endl;
        }
    }
}

void OpenHashTable::insert(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int idx = hf->openhashing(key);
    HashNode * newnode = new HashNode(key);
    if (states[idx] == OPEN_OCCUPIED) {
        HashNode* cur = table[idx];
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newnode;
    }
    else {
        table[idx] = newnode;
        states[idx] = OPEN_OCCUPIED;
    }
    return;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

void OpenHashTable::erase(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int idx = hf->openhashing(key);
    HashNode* cur = table[idx];

    if (table[idx]->key == key) {
        table[idx] = table[idx]->next;
        delete cur;
    }
    else {
        while (cur->next->key != key) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        delete cur->next;
    }
    if (table[idx] == NULL) {
        states[idx] = OPEN_EMPTY;
    }
    return;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
