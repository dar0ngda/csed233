#include "open_hash_function.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


int OpenHashFunction::openhashing(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int idx = 0;
    int tmp = key;
    while (tmp) {
        idx += tmp;
        tmp /= 10;
    }
    idx %= index_size;
    return idx;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
