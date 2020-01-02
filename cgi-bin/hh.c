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
	li{list-style: none;\
	background: rgba(0, 0, 0, 0.05);\
	text-align: center;\
	height:50px;\
	width:800px;\
	margin:0 auto;\
	border-bottom: solid 1px rgba(0, 0, 0, 0.1);\
	border-radius: 10px;}\
	li:hover{background: #ccf;}\
	a{text-decoration: none;color:rgb(0,0,0);display:block;line-height:50px;}\
	li{list-style:none}\
	#big{background: #cff;\
	font-size: 18px;\
	width:1200px;\
	text-align: center;\
	height: 60px;\
	line-height: 60px;\
	margin-bottom: 10px;\
	margin:0 auto 10px;}\
	</style>\
	</head>\
	<body>");
    	printf("<div id='big'>我是大标题</div>");
   
    	printf("<ul>");
	int callback(void *para, int col_count, char **col_value, char **col_name) 
	{ 

        	printf("<li calss='lis'><a href='cc.cgi?%s'>%s</a></li>",col_value[0],col_value[1]);
    	
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

    	sprintf(sql, "SELECT * FROM news");

    	if (0 != sqlite3_exec(db, sql, callback, NULL, &err)) {
        	printf("%s\n", err);
        	exit(-1);
   	 };

	
   
    	printf("</ul>");

    	printf("</body>");
    	

    



    	printf("</html>");
	sqlite3_close(db);
    	return 0;
}
