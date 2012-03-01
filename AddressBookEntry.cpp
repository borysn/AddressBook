#include "AddressBookEntry.h"

//con/destructors
AddressBookEntry::AddressBookEntry() {
	setup("\0", "\0", "\0", "\0", "\0", UNKNOWN);
}

AddressBookEntry::AddressBookEntry(char *first, char *last, char *mid, char *addr, 
	                               char *phone, RelationShipType type) {	
	setup(first, last, mid, addr, phone, type);
}

AddressBookEntry::~AddressBookEntry() {
	//delete firstName;
	//delete lastName;
	//delete middleName;
	//delete address;
}

void AddressBookEntry::setup(char *first, char *last, char *mid, char *addr, 
		             char *phone, RelationShipType type) {
	strcpy_s(firstName, 64, first);
	strcpy_s(lastName, 64, last);
	strcpy_s(middleName, 64, mid);
	strcpy_s(address, 64, addr);
	strcpy_s(phoneNumber, 64, phone);
	relation = type;
}

//retrive stuff
char *AddressBookEntry::getFirstName() {
	if (firstName == NULL)
		return NULL;
	return firstName;
}

char *AddressBookEntry::getLastName() {
	
	if (lastName == NULL)
		return NULL;
	return lastName;
}

char *AddressBookEntry::getMidName() {
	if (middleName == NULL)
		return NULL;
	return middleName;
}

char *AddressBookEntry::getAddress() {
	if (address == NULL)
		return NULL;
	return address;
}

char *AddressBookEntry::getPhoneNum() {
	if (phoneNumber == NULL)
		return NULL;
	return phoneNumber;
}

RelationShipType AddressBookEntry::getRelationShipType() {
	//dont have to do NULL check. will just return unkown
	return relation;
}

char *AddressBookEntry::getEntryAsKey() {
	int SIZE = 128;
	char *key = new char[SIZE];
	strcpy_s(key, SIZE, " firstname = '");
	strcat_s(key, SIZE, firstName); 
	strcat_s(key, SIZE, "' AND ");

	strcat_s(key, SIZE, " lastname = '");
	strcat_s(key, SIZE, lastName); 
	strcat_s(key, SIZE, "' AND");
	
	strcat_s(key, SIZE, " phonenumber = '");
	strcat_s(key, SIZE, phoneNumber); 
	strcat_s(key, SIZE, "'");
	return key;
}

char *AddressBookEntry::getEntryAsQuery() {
	char *query = new char[256]; 
	//let the cat game begin ^_^
	strcpy_s(query, 256, " (firstname, lastname, middlename, address, phonenumber, relationshiptype) VALUES('");
	strcat_s(query, 256, firstName); 
	strcat_s(query, 256, "','"); 
	strcat_s(query, 256, lastName);
	strcat_s(query, 256, "','");
	strcat_s(query, 256, middleName);
	strcat_s(query, 256, "','"); 
	strcat_s(query, 256, address);
	strcat_s(query, 256, "','");
	strcat_s(query, 256, phoneNumber);
	strcat_s(query, 256, "', ");
	//convert into to string
	//10 = our numberbase
	char *tmp = new char[1];
	_itoa_s(relation, tmp, 256, 10);
	strcat_s(query, 256, tmp);
	strcat_s(query, 256, ")");
	delete tmp;
	return query;
}

RelationShipType AddressBookEntry::intToRelation(int i) {
	RelationShipType type;
	switch (i) {
	case 1: 
		type = UNKNOWN;
	break;
	case 2: 
		type = BUSINESS; 
	break;
	case 3: 
		type = FAMILY; 
	break;
	case 4: 
		type = PLEASURE; 
	break;
	case 5: 
		type = INFO;
	break;
	case 6: 
		type = WORK;
	break;
	default: 
		type = UNKNOWN;
	break;
	}
	return type;
}