/*
 *  This is a test of my AddressBook class
 *  this test will be adapted into a display addressbook class
 *
 *  Borys H.N. 2/25/12
 * 
 */
#include "main.h"

int main() {
	/*test 1 is a test of the AddressBookManager class and the
	  AddressBookEntry class */
	printf_s("[=================StartTest1=================]\n\n");

	ABman = new AddressBookManager();
	entry = AddressBookEntry();
	key = AddressBookEntry();
	
	int i = 0; 

	do {
		printMenu(); 
		printf("//:> ");
		scanf_s("%d", &i);
		processInput(i); 
	} while (i != 8);
	
	printf_s("\n[==================EndTest1==================]\n");

	delete ABman;

	return 0;
}

void printMenu() { 
	printf_s("[______Menu Options______]\n");
	printf_s(" 1 : Setup an entry   (*)\n");
	printf_s(" 2 : Setup a search   (^)\n");
	printf_s(" 3 : Que an entry     (*)\n");
	printf_s(" 4 : Que a search     (^)\n");
	printf_s(" 5 : Edit an entry    (^)\n");
	printf_s(" 6 : Delete an entry  (^)\n");
	printf_s(" 7 : Retrieve Entries \n");
	printf_s(" 8 : Exit Application \n");
}

void processInput(int option) {
	switch (option) {
	//setup an entry
	case 1:	
		printf_s("\n[Setting Up An Entry]...\n");
		entry = MakeEntry();
		break;
	//setup a search
	case 2:
		printf_s("\n[Setting Up A Search]...\n");
		key = MakeSearchKey();
		break;
	case 3:
	//que an entry
		printf_s("\n[Queing An Entry]...\n");
		//lets see if entry is empty first
		if (strcmp(entry.getFirstName(), "\0") == 0) {
			printf_s("\nERROR: NO ENTRY DEFINED!\n\n");
			break;
		}
		printf_s("\nChecking to see if entry exists using query...\n");
		printf_s("%s\n", entry.getEntryAsKey()); //works
		if (!ABman->entryExists(entry)) {
			printf("\n\n[Entry not found...]\n[Adding Entry...]\n\n");
			ABman->addNewEntry(entry); //works 
		} else {
			printf("\n\n[Entry already exists!]\n\n");
		}
		break;
	//que a search
	case 4:
		printf_s("\n[Queing A Search]...\n");
		//lets see if key is empty first
		if (strcmp(key.getFirstName(), "\0") == 0) {
			printf_s("\nERROR: NO SEARCH DEFINED!\n\n");
			break;
		}
		printf_s("\nChecking to see if entry exists using key...\n");
		printf_s("%s\n", key.getEntryAsKey()); //works
		if (!ABman->entryExists(key)) {
			printf("\n\n[Entry not found...]\n\n");
		} else {
			printf("\n\n[Entry found!]\n\n");
		}
		break;
	//edit an entry
	case 5:
		printf_s("\n[Editing an entry]\n\n");
		//lets see if key is empty first
		if (strcmp(key.getFirstName(), "\0") == 0) {
			printf_s("\nERROR: NO SEARCH DEFINED!\n\n");
			break; 
		}
		printf_s("\nChecking to see if entry exists using key...\n");
		printf_s("%s\n", key.getEntryAsKey()); //works
		if (!ABman->entryExists(key)) { 
			printf_s("\n\n[Entry not found. Cannot edit...]\n\n");
		} else { 
			printf_s("\n\n[Entry found! Beginning Editing Process]\n\n");
			printf_s("first create the new entry\n");
			entry = MakeEntry();
			ABman->editOldEntry(key, entry); 
			printf_s("\n\n[Finished with editing]\n\n");
		} 
		break;
	//Remove an entry
	case 6:
		printf_s("\n[Removing an entry]\n\n");		
		//lets see if key is empty first
		if (strcmp(key.getFirstName(), "\0") == 0) {
			printf_s("\nERROR: NO SEARCH DEFINED!\n\n");
			break;
		}
		printf_s("\nChecking to see if entry exists using key...\n");
		printf_s("%s\n", key.getEntryAsKey()); //works
		if (!ABman->entryExists(key)) {
			printf_s("\n\n[Entry not found. Cannot delete...]\n\n");
		} else { 
			//make sure i want to delete the entry
			printf_s("\n\n[Entry found!]\n");
			printf_s("Are you sure you want to delete this entry?(y/n)\n");
			printf_s("//:> "); 
			char *c = new char[2];
			scanf_s("%s", c); 
			switch (c[0]) {
			case 'y':
				printf("[Entry Deleted!]\n\n");
				ABman->removeEntry(key);
				break;
			case 'n':
				printf("[Entry not deleted!]\n\n");
				break;
			default:
				printf("[Entry not deleted!]\n\n");
				break;
			}
			delete c;
		}
		break;
	//Look at address book
	case 7:
		printf("\n\n[Retrieving Entries]\n\n"); 
		setupSearch(); 
		break;
	//Exit 
	case 8:
		printf("\n\n[Exiting the application]\n");
		break;
	//Just print menu
	default:
		printMenu();
		break;
	}
}

AddressBookEntry MakeEntry() {
	char entryInfo[5][SIZE];
	int relation = 1;

	//read in all requirements for an "entry"
	//and echo the input after each "return" key is pressed
	printf_s("First Name:> ");
	scanf_s("%s", entryInfo[0]);
	printf_s("First = %s\n", entryInfo[0]);

	printf_s("Last Name:> ");
	scanf_s("%s", entryInfo[1]);
	printf_s("Last = %s\n", entryInfo[1]);

	printf_s("Middle Name:> ");
	scanf_s("%s", entryInfo[2]);
	printf_s("Middle = %s\n", entryInfo[2]); 

	printf_s("Address(\"Address City, State, Zipecode\")\n:> ");
	//have alot of trouble with this, i ended up solving the line issue
	//by using the file method, but just using stdin stream instead of
	//a file stream 
	fflush(stdin); //flush stream first
	fgets(entryInfo[3], SIZE, stdin); //get whole line
	char *newline = strchr(entryInfo[3], '\n'); //set pointer to end of line char
	*newline = '\0'; //replace newline with null terminator
	printf_s("Address = %s\n", entryInfo[3]);

	printf_s("Phone Number(x-xxx-xxx-xxx)\n:> ");
	scanf_s("%s", entryInfo[4]);
	printf_s("Phone Number = %s\n", entryInfo[4]);

	printf_s("RelationShipType (1, 2, 3, 4, 5, 6)\n (UNKOWN, BUSINESS, FAMILY, PLEASURE, INFO, WORK)\n:> ");
	scanf_s("%d", &relation);
	printf_s("Relation = %d\n\n", relation);

	RelationShipType type = AddressBookEntry::intToRelation(relation); 
	AddressBookEntry entry = AddressBookEntry(entryInfo[0], entryInfo[1], entryInfo[2], entryInfo[3], 
		                     entryInfo[4], type); 
	return entry;
}

AddressBookEntry MakeSearchKey() {
	char entryInfo[3][SIZE];

	//read in all requirements for a "key"
	//and echo the input after each "return" key is pressed
	printf_s("First Name:> ");
	scanf_s("%s", entryInfo[0]);
	printf_s("First = %s\n", entryInfo[0]);

	printf_s("Last Name:> ");
	scanf_s("%s", entryInfo[1]);
	printf_s("Last = %s\n", entryInfo[1]);
	
	printf_s("Phone Number(x-xxx-xxx-xxx)\n:> ");
	scanf_s("%s", entryInfo[2]);
	printf_s("Phone Number = %s\n\n", entryInfo[2]);

	//only paramters for first and last names, and phonenumber matter here
	AddressBookEntry entry = AddressBookEntry(entryInfo[0], entryInfo[1], " ", " ", 
		                     entryInfo[2], UNKNOWN); 
	return entry;
}

void setupSearch() {
	int size = 64;
	AddressBookEntry *entries;
	char *search = new char[size];
	char *column = new char[size];

	printf_s("Enter search string...\ni.e. \"A\" or \"1-800\" or type \"null\" for nothing\n");
	printf_s("//:> ");
	scanf_s("%s", search); 
	printf_s("Enter column which applies to search string...\n");
	printf_s("i.e. if search string = \"A\" then column = \"firstname\" or type \"null\" for nothing");
	printf_s("//:> ");
	scanf_s("%s", column); 

	entries = ABman->getEntries(search, column);
	
	delete search;
	delete column;
}