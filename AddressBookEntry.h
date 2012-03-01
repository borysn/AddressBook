#ifndef ADDRESSBOOKENTRY_H
#define ADDRESSBOOKENTRY_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

enum RelationShipType {
	UNKNOWN = 1,
	BUSINESS = 2,
	FAMILY = 3,
	PLEASURE = 4,
	INFO = 5,
	WORK = 6
};

//this class is meant to be a quick place holder for values
//and is to be used to make code look neater when passing
//values too and from the databse

//it is also meant to be an easy way to return data needed
//to complete a successful sql query regarding
//addressbook entries

class AddressBookEntry {
private:
	char firstName[64];
	char lastName[64];
	char middleName[64];
	char address[64];        // i.e. 4367 Avendale Ave.
	char phoneNumber[13]; //x-xxx-xxx-xxx
	RelationShipType relation;
public: 
	//con/destructors
	AddressBookEntry();
	AddressBookEntry(char *first, char *last, char *mid, char *addr, 
		             char *phone, RelationShipType type);
	~AddressBookEntry();

	//setup
	void setup(char *first, char *last, char *mid, char *addr, 
		             char *phone, RelationShipType type);

	//retrive stuff
	char *getFirstName(); 
	char *getLastName();
	char *getMidName();
	char *getAddress();
	char *getPhoneNum();
	RelationShipType getRelationShipType();

	//functional returns
	char **getEntryAsString(); //return entry as md array dno if this is useful hmm
	char *getEntryAsKey(); //return entry as SQL key data
	char *getEntryAsQuery(); //return entry mySQL query data

	//conversion for relationship type
	static RelationShipType intToRelation(int i);
};

#endif