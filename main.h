/*
 *  This is a test of my AddressBook class
 *  this test will be adapted into a display addressbook class
 *
 *  Borys H.N. (last update) 3/5/12
 * 
 */
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
void setupSearch();
//menu stuff
void printMenu();
void processInput(int option);

#endif