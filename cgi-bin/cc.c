#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

//gcc hellocgi.c -o hellocgi.cgi
int main(){
	

    	printf("Content-Type: text/html\n\n"); 

    	printf("<!DOCTYPE html>\
	<html lang='en'>\
	<head>\
    	<meta charset='UTF-8'>\
    	<title>Document</title>\
	<style>\
	ul,li,body{padding:0;margin:0;}\
	li{list-style:none;}\
	#big{background: #cff;\
	font-size: 18px;\
	width:1200px;\
	text-align: center;\
	height: 60px;\
	line-height: 60px;\
	margin-bottom: 10px;\
	margin:0 auto 10px;}\
	#tle{width: 1200px;\
            margin: 0 auto;\
            font-size:16px;\
            text-align: center;\
            background: #dde6ed;\
	    height:50px;\
		line-height:50px;}\
	#content{width: 1200px;\
            margin: 0 auto;\
            font-size:14px;\
            background: #dde6ed;}\
	#create{width:1200px;overflow: hidden;margin:0 auto;}\
	#cre{width:400px;float:right;font-size:14px;background: #dde6ed;}\
	</style>\
	</head>\
	<body>");
    	printf("<div id='big'>我是大标题</div>");
  
   	int callback(void *para, int col_count, char **col_value, char **col_name) 
	{

        	printf("<div id='tle'><h3>%s</h3></div><div id='content'>%s</div><div id='create'><div id='cre'>%s</div></div>",col_value[1],col_value[2],col_value[3]);
    	

    		return 0;
	};


	sqlite3 *db = NULL;	
	int res = sqlite3_open("cms.db", &db);
    	if (res != 0) {
        	printf("open db fail\n");
        	return -1;
   	 }
	char *err;
    	char sql[100];
	char *id = getenv("QUERY_STRING");
    	sprintf(sql, "SELECT * FROM news where id=%d",atoi(id));

    	if (0 != sqlite3_exec(db, sql, callback, NULL, &err)) {
        	printf("%s\n", err);
        	exit(-1);
   	 };

	

    	printf("</body>");
    	

    



    	printf("</html>");
	sqlite3_close(db);
    	return 0;
}
