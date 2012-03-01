#include "DBManager.h"

DBManager::DBManager() {
	conn = mysql_init(NULL);
	result = NULL;
	info.host = NULL;
	info.user = NULL;
	info.pass = NULL;
	info.db = NULL;
	info.tables = NULL; 
}

DBManager::DBManager(MysqlConnectInfo *dbInfo) {
	info.db = dbInfo->db;
	info.host = dbInfo->host;
	info.pass = dbInfo->pass;
	info.tables = dbInfo->tables;
	info.user = dbInfo->user;

	conn = mysql_init(NULL);
	result = NULL;
}

DBManager::~DBManager() {
	//clean up
	mysql_free_result(result);
	mysql_close(conn);
	//delete info;
}

bool DBManager::DBExists(){
	//first setup query to search for specific db
	char query[SIZE] = "SHOW DATABASES LIKE '";
	strcat_s(query, SIZE, info.db);
	strcat_s(query, SIZE, "'");
	//run query amd save result
	doQuery(query);
	char tmp[SIZE];
	strcpy_s(tmp, SIZE, getNextRow()[0]);
	//if query returned result return true, 
	//else return false
	if (strcmp(tmp, info.db) == 0) 	
		return true;
	return false;
}

bool DBManager::DBTableExists(char *table){
	//first setup query to search for specific
	char query[SIZE] = "SHOW TABLES FROM ";
	strcat_s(query, SIZE, info.db);
	strcat_s(query, SIZE, " LIKE '");
	strcat_s(query, SIZE, table); 
	strcat_s(query, SIZE, "'"); 
	//run query amd save result
	doQuery(query);
	char tmp[SIZE];
	strcpy_s(tmp, SIZE, getNextRow()[0]);
	if (strcmp(tmp, table) == 0)
		return true;
	return false; 
}

bool DBManager::setupConnection() {
	if (!mysql_real_connect(conn, info.host, info.user, info.pass, info.db, 0, NULL, 0))
		return false;
	else 
		return true;
}

void DBManager::setConnectionInfo(MysqlConnectInfo *dbInfo) {
	info = *dbInfo;
}

void DBManager::doQuery(char *query) {
	mysql_free_result(result);
	if (mysql_query(conn, query)) {
		result = NULL;	
		exit(1); 
	}
	else {
		result = mysql_use_result(conn);
	}
}

char **DBManager::getNextRow() {
	if (!(result == NULL))
		return mysql_fetch_row(result);
	else
		return NULL;
} 

MYSQL *DBManager::getConnection() {
	return conn;
}

