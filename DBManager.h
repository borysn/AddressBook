#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <WinSock.h>
#include <mysql.h>
#include <stdlib.h>
#include <stdio.h> 

#define SIZE 64

struct MysqlConnectInfo {
	char *host;
	char *user;
	char *pass;
	char *db;
	char *tables; //only one table so far
};

class DBManager {
protected:
	MysqlConnectInfo info;
	MYSQL *conn;
	MYSQL_RES *result;

	//checks
	bool DBExists();
	bool DBTableExists(char *table);
	bool createDB(); 
	bool clearDB(); 

	bool setupConnection();
	//this function will setup the connection then return a pointer to it
	void setConnectionInfo(MysqlConnectInfo *dbInfo);
	//this function will set the connect info
	void doQuery(char *query); 
	//this function will perform an sql query, and return a pointer to the result
	// sets results to NULL if query is not succesful
	char **getNextRow(); 
	//returns result as row (char**)
	//return null if result is empty 
	MYSQL *getConnection();
	//return conn
public:
	//[con/destructor]
	DBManager();
	DBManager(MysqlConnectInfo *dbInfo);
	~DBManager();
};

#endif