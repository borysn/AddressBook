#ifndef ADDRESSBOOKMANAGER_H
#define ADDRESSBOOKMANAGER_H

#include "DBManager.h" 
#include "AddressBookEntry.h" 
#include <stdio.h>

class AddressBookEntry; //using this class

class AddressBookManager : public DBManager {
private: 
	MysqlConnectInfo *info;  
public:
	//[con/destructors]
	AddressBookManager();
	~AddressBookManager(); 

	//checks 
	bool entryExists(AddressBookEntry entry); //key = phone #

	/*/creation/managment
	void order(bool byName);
	*/

	//entries (create "entry" class?)
	void addNewEntry(AddressBookEntry entry);
	void editOldEntry(AddressBookEntry oldEntry, AddressBookEntry newEntry); 
	void removeEntry(AddressBookEntry entry);

	//retrieval
	AddressBookEntry *getEntries(char *search, char *column);
	//return all entries relevant to search/column 
	//retunrs all entries if search is NULL
	//returns entries as AddressBookEntry array
};

#endif