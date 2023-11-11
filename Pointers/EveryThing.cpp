#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    int *addressStore;
    addressStore = &n;

    string test = "Awadesh";
    string *testPtr = &test;

    char check = 'a';
    char *checkPtr = &check;

    vector<string> ListOfPeople = {"Liza", "john", "Carly", "christina", "Taylor", "Awadesh"};

    vector<string> *storeAddressPtr1 = &ListOfPeople;

    string *storeAddressPtr2 = &ListOfPeople[0];

    ListOfPeople.push_back("Nancy");          // ListOfPeople->push_back("Nancy"); is wrong
    storeAddressPtr1->push_back("x2324klsd"); //  storeAddress.push_back("x2324klsd"); is wrong in case of Pointer arrary

    string arrStr[] = {"Liza", "john", "Carly", "christina", "Taylor", "Awadesh"};
    string *ptrStr = arrStr;
}
