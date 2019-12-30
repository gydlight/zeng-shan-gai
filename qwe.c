#include <stdio.h>


typedef struct {
                char name[23];
                int age ;
                int sex;

        }user;

int add(int *i,user *u  )
{
	 printf("请输入名字\n"); 
	 scanf("%s",u->name);
         printf("请输入年龄\n");
         scanf("%d",&(u->age));
   	 printf("请输入性别\n");
	 scanf("%d",&(u->sex));
	// printf("%s\n",u->name);
	// printf("%d\n",*i);
	 *i=*i+1;

return 0;
}

int show (int i,user *u )
{	printf( "编号:%d\n",i);
	printf("名字:%s\n",u->name);
	printf("年龄:%d\n",u->age);
	printf("性别:%d\n=============\n",u->sex);

return 0;
	
}


int update(int i,user *u)(int i,user *u)

{
	printf("请输入名字\n");
	scanf("%s",u->name );
	printf("请输入年龄\n");

	scanf("%d",&u->age );
	printf("请输性别\n");

	scanf("%d",&u->sex );

return 0;
}




int change(user* i,user *u)

{
	*i=*u;
return 0;
}


		
int main()
{
	int num2;
	int y;
	int num3;
	int flag3;
        int j;
	int flag2;
	user u[50];
	int i=0;//计数
	int flag=1;//控制while循环的条件
	int num;//控制switch 分支
	while(flag){
		printf("1:新增会员\n");
                printf("2:删除会员\n");
                printf("3:修改会员\n");
                printf("4:查找会员\n");
                printf("5:退出\n");
                scanf("%d",&num);
		switch(num){
                        case 1:
				flag2=1;
				while(flag2){
					printf("1:新增\n2:返回\n");
					scanf("%d",&num2);
					switch(num2){
						case 1:add(&i,&u[i]);break;
						case 2:flag2=0;break;
						default: printf("请输入正确序号\n");
					}
				};break;
			case 4:

				printf("1:查询所有\n2:单个查询\n");
                                scanf("%d",&num3);
				switch(num3){
					case 1:
					j=0;
					for(;j<i;j++){
						show(j,&u[j]);
					};break;
					case 2:
					for(int x=0 ;x<i;x++ ){
					printf("编号:%d,名字:%s\n",x,u[x].name);
					};
					printf("输入编号\n");
					scanf("%d",&y);
					if(y>i-1){
						printf("请输入正确序号\n");break;

					
					}else{
						show(y,&u[y]);break;
					};
					default :printf("请输入正确序号\n");

				};break;
		


			case 3:
				for(int z=0 ;z<i;z++ ){
                                        printf("编号:%d,名字:%s\n",z,u[z].name);
                                        };
                                        printf("输入编号\n");
					scanf("%d",&y);

                                        update(y,&u[y]);break;


			case 2:
				for(int z=0 ;z<i;z++ ){
                                        printf("编号:%d,名字:%s\n",z,u[z].name);
                                        };
                                        printf("输入删除编号\n");
                                        scanf("%d",&y);
					for(;y<i;y++){
						change(&u[y],&u[y+1]);
					
					};
					i--;
					break;
			case 5:
					flag=0;break;
			default:printf("请输入正确序号\n");
		
		
		}

	}
	return 0;
}
