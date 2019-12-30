#include <stdio.h>
 struct users{
                char name[30];
                int age;
                int sex;
        };
int show();
struct users u[50];
int add(int *y )
{	
	int i=*y;
	int flag1=1;
	int num_2;
	if(i<=0){
		i=0;
		printf("请输入名字\n");
		scanf("%s",u[i].name);
		printf("请输入年龄\n");
		scanf("%d",&u[i].age);
		printf("请输入性别\n");
		scanf("%d",&u[i].sex);
		i++;
		*y=i;
	}	
	while(flag1){
		printf("1:继续新增\n2:查看\n3:结束\n");
		scanf("%d",&num_2);
		switch(num_2){
			case 1:
				
			     	printf("请输入名字\n");
       			        scanf("%s",u[i].name);
       			        printf("请输入年龄\n");
       			        scanf("%d",&u[i].age);
       			        printf("请输入性别\n");
       			        scanf("%d",&u[i].sex);
				i++;
				*y=i;
			        break;
			case 2:show(y);break;
			case 3:flag1=0;
			       break;
	
			default:printf(" 输入正确的选项\n");break;
		}
	}
	 
	return 0;
}

int show(int *y )
{	
	int i=*y;
	int  flag2=1;
	int num_3;
	int id;
	while(flag2){
		int j=0;
		printf("1:查询所有数据\n2:个人查询\n3:返回\n");
                scanf("%d",&num_3);
		switch(num_3){
			case 1:	
				for(;j<i;j++){
					printf("名字：%s,年龄：%d,性别：%d\n",u[j].name,u[j].age,u[j].sex );		
			        };break;
			
			case 2:
				printf("你想查询谁：\n" );
				for(;j<i;j++){
                                        printf("%d,%s\n",j,u[j].name);
                                };
				printf("输入编号\n");
				scanf("%d",&id);
				printf("名字：%s,年龄：%d,性别：%d\n",u[id].name,u[id].age,u[id].sex );
				break;
			case 3:flag2=0;break;
		}
	}
	return 0;
}	
int modify( int*y )
{	
	int i=*y;
	int id;
	int n=0;
	int falg3=1;
	while(falg3){
		printf("你想修改谁：\n" );
        	for(;n<i;n++){
			printf("%d,%s\n",n,u[n].name);
        	};
		printf("输入编号\n");
		scanf("%d",&id);
		if(id>=0&&id<i ){
			printf("请输入%d号的名字\n",id);
       			scanf("%s",u[id].name);
        		printf("请输入%d号的年龄\n",id);
        		scanf("%d",&u[id].age);
			printf("请输入%d号的性别\n",id); 
			scanf("%d",&u[id].sex);falg3=0;
		}else{
			printf("别闹好好输入\n");
	
		};
	return 0;
	}
}

int del (int *y )
{	
	int i=*y;
	int n=0;
	int id;
	if(i==0){
		printf("无数据可以删除\n" );
		return 1;

	}
	else{	
	printf("你想删除谁：\n" );
        for(;n<i;n++){
                printf("%d,%s\n",n,u[n].name);
        };
	scanf("%d",&id);
	for( ;id<i-1;id++ ){
		u[id]=u[id+1];
	
	};
	i--;
	*y=i;

	return 0;
	}
}



int main()
{	
	int i=0;
	int flag=1;
	int  num;
	while(flag){
		printf("1:新增会员\n");
		printf("2:删除会员\n");
		printf("3:修改会员\n");
		printf("4:查找会员\n");
		printf("5:退出\n");
		scanf("%d",&num);
		switch(num){
			case 1:add(&i);break;
			case 2:del ( &i);break;
			case 3:modify(&i);break;
			case 4:show(&i);break;
			case 5:flag=0;break;
			default:printf( "请输入正确的选项\n" );
		}
	}
return 0;	
}
