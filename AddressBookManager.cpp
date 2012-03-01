#include "AddressBookManager.h"

AddressBookManager::AddressBookManager() { 
	info = new MysqlConnectInfo();
	info->host = "localhost";
	info->user = "";
	info->pass = "";
	info->db = "addressbook"; //connect to address book
	info->tables = "contacts"; //only 1 table so far. maybe do array if more
	//initialize parent class 
	DBManager();
	setConnectionInfo(info);
	if(!setupConnection()) {
		exit(1);
		printf_s("\nerror:: %s\n\n", mysql_error(conn));
	}
}

AddressBookManager::~AddressBookManager() {
	delete info;
}


bool AddressBookManager::entryExists(AddressBookEntry entry){
	char *query = new char[SIZE*2]; 
	strcpy_s(query, SIZE*2, "SELECT * FROM ");
	strcat_s(query, SIZE*2, info->tables);
	strcat_s(query, SIZE*2, " WHERE ");
	strcat_s(query, SIZE*2, entry.getEntryAsKey());
	printf_s("\n----\nquery = %s\n", query);

	doQuery(query); 
	char **tmp;
	if ((tmp = getNextRow()) != NULL) {
		printf("\ntmp[0] = %s\n", tmp[0]); 
		if (strcmp(tmp[0], entry.getFirstName()) == 0 &&
			strcmp(tmp[1], entry.getLastName()) == 0 &&
			strcmp(tmp[4], entry.getPhoneNum()) == 0) 
			return true;
	} 
	delete tmp;
	delete query;
	return false;
}

/*
void AddressBookManager::order(bool byName){
}*/

void AddressBookManager::addNewEntry(AddressBookEntry entry) {
	//sample query was about 202 with my address and info
	//ill keep the size of query at 384 SIZE*6
	char query[SIZE*6] = "INSERT INTO ";
	strcat_s(query, SIZE*6, info->tables); 
	strcat_s(query, SIZE*6, entry.getEntryAsQuery());
	printf_s("\nquery = %s\n\n", query);
	doQuery(query); 
}

void AddressBookManager::editOldEntry(AddressBookEntry oldEntry, AddressBookEntry newEntry) {
	removeEntry(oldEntry);
	addNewEntry(newEntry);
}

void AddressBookManager::removeEntry(AddressBookEntry entry) {
	char query[SIZE*4];
	strcpy_s(query, SIZE*4, "DELETE FROM contacts WHERE ");
	strcat_s(query, SIZE*4, entry.getEntryAsKey());
	doQuery(query);
}

