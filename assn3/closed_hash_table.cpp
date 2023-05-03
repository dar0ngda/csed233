#include <iostream>
#include <fstream>
#include <string>
#include "closed_hash_function.h"
#include "closed_hash_table.h"

using namespace std;

ClosedHashTable::ClosedHashTable(int table_size, ClosedHashFunction *hf) : table_size(table_size) {
    this->hf = hf;
    this->table = new int[this->table_size];
    this->states = new ClosedTableState[this->table_size];

    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    
    /*  Write your codes if you need  */
    for (int i = 0; i < this->table_size; i++) {
        this->states[i] = CLOSED_EMPTY;
    }
    
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

ClosedHashTable::~ClosedHashTable() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    
    /*  Write your codes if you need  */
    
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////

    delete[] this->table;
    delete[] this->states;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
void ClosedHashTable::print_table(ostream &out) {
    for (int i=0; i < this->table_size; i++) {
        out << i << ": ";
        if (this->states[i] == CLOSED_EMPTY)
            out << "empty" << endl;
        else if (this->states[i] == CLOSED_DELETED)
            out << "deleted" << endl;
        else if (this->states[i] == CLOSED_OCCUPIED)
            out << this->table[i] << endl;
        else
            out << "unknown state" << endl;
    }
}

void ClosedHashTable::insert(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int h_k = key * key;
    h_k = h_k >> ((2 * (hf->getkeysize()) - hf->getindexsize()) / 2);
    h_k = h_k % table_size;

    int idx = h_k;

    int colcount = 0;
    int p_i;
    while (states[idx] != CLOSED_EMPTY) {
        if (states[idx] == CLOSED_DELETED) break;
        colcount++;
        p_i = colcount * colcount + colcount + 1;
        idx = (h_k + p_i) % table_size;
    }
    if (states[idx] == CLOSED_EMPTY) {
        table[idx] = key;
        states[idx] = CLOSED_OCCUPIED;
    }
    
    return;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

void ClosedHashTable::erase(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    for (int i = 0; i < table_size; i++) {
        if (table[i] == key) {
            states[i] = CLOSED_DELETED;
            break;
        }
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
