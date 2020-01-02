#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

typedef struct {
        char *title;
        char *content;
        char *cre;

}news;


int insert(sqlite3 *db, news new) {
    char *err;
    char sql[100];

    sprintf(sql, "INSERT INTO news (title,content,created_at) VALUES ('%s','%s','%s')", new.title,new.content,new.cre);

    if (0 != sqlite3_exec(db, sql, NULL, NULL, &err)) {
        printf("%s\n", err);
        exit(-1);
    }

    return 0;
}





int callback(void *para, int col_count, char **col_value, char **col_name) {

    for (int i = 0; i < col_count; i++) {
        printf("%s: %s \n", col_name[i], col_value[i]);
    }

//    printf("%s: %s \n", col_name[1], col_value[2]);

    printf("********************\n");

    return 0;
}



int show(sqlite3 *db)
{

	char *err;
    	char sql[100];

    	sprintf(sql, "SELECT * FROM news");

    	if (0 != sqlite3_exec(db, sql, callback, NULL, &err)) {
        	printf("%s\n", err);
        	exit(-1);
   	 }
	return 0;

}





int del(sqlite3 *db,int x)
{
	char *err;
        char sql[100];
	sprintf(sql, "DELETE FROM news WHERE id='%d'",x);
	if (0 != sqlite3_exec(db, sql, NULL, NULL, &err)) {
                printf("%s\n", err);
                exit(-1);
         }
        return 0;


}



int modify(sqlite3 *db,news new,int x)
{
	char *err;
        char sql[100];
        sprintf(sql, "UPDATE news SET title='%s',content='%s',created_at='%s' WHERE id='%d'",new.title,new.content,new.cre,x);
        if (0 != sqlite3_exec(db, sql, NULL, NULL, &err)) {
                printf("%s\n", err);
                exit(-1);
         }


return 0;
}








int main()

{
	sqlite3 *db = NULL;	
	int flag=1;
	int x;
	int res = sqlite3_open("cms.db", &db);
    	if (res != 0) {
        	printf("open db fail\n");
        	return -1;
   	 }

	while(flag){
		int y;
		printf("1:增加\n2删除\n:3修改\n:4查看\n:5退出\n");
		scanf("%d",&y);
		
		switch(y){
			case 1:{
				news new;
				printf("输入标题\n");
				new.title=malloc(sizeof(char));
				new.content=malloc(sizeof(char));
				new.cre=malloc(sizeof(char));

				scanf("%s",new.title);
				printf("输入内容\n");
				scanf("%s",new.content);
				printf("输入日期\n");
				scanf("%s",new.cre);
			//	printf("%s",new->title);
				insert(db,new);
				};break;


			case 2:show(db);
			       printf("输入要删除的编号\n");
			       scanf("%d",&x);
			       del(db,x);break;

			case 3:
			       {
			       news n;
			       show(db);
			       printf("输入要修改的编号\n");
                               scanf("%d",&x);
                               printf("输入标题\n");
                               n.title=malloc(sizeof(char));
                               n.content=malloc(sizeof(char));
                               n.cre=malloc(sizeof(char));
                               scanf("%s",n.title);
                               printf("输入内容\n");
                               scanf("%s",n.content);
                               printf("输入日期\n");
                               scanf("%s",n.cre);
			       modify(db,n,x);
			       };break;
			       
			case 4:
			       show(db);break;

			case 5: 
			       flag=0;
		
			       break;


			default :
			       printf("请输入正确序号1-5\n");

		}




	
	
	}
	sqlite3_close(db);
	return 0;
}
