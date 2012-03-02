#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include "AddressBookManager.h"

//global vars
AddressBookEntry entry;
AddressBookEntry key;
AddressBookManager *ABman;

//get inputs from keyboard
AddressBookEntry MakeEntry();
AddressBookEntry MakeSearchKey();
void printMenu();
void processInput(int option);
void setupSearch();

#endif