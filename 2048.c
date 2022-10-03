# include "stdlib.h"
# include "stdio.h"
# include "conio.h"
# include "time.h"
# define N 4

int main(void)
{
	int a[N][N] = {0}, x, y, l, t, sum, random; //存储框架，判定变量
	char c; //存储方向判定变量

	random = ((int)time(0)); //time函数输入种子
	srand (random);
	for( y = 0; y < N; y++)
	{
		for( x = 0; x < N; x++)  //框架清零
		{
			a[y][x] = 0;
		}
	}
	for( l = 0; l < 2; l++)
	{
		//scanf("%d", &random);
		random = getch();
		for( ;a[y][x] != 0;)
		{
			x = rand() % 5;
			y = rand() % 5;
		}
		a[y][x] = 2;
	}
	//随机存放两个初始2的位置
	system("cls");
	for( y = 0; y < N; y++)
	{
		for( x = 0; x < N; x++)
		{
			printf("%5d", a[y][x]);
		}
		printf("\n");
	}
	//输出初始化游戏界面
	do
	{
		sum = 0;
	c = getch();
	//scanf("%s", &c); //输入游戏者的方向存放在字符c
    switch(c)
	{
		case 'a':
	    {
			for( y = 0; y < N; y++)
			{
				for( x = 0; x < N; x++)
				{
					if(a[y][x] == 0)
						{
							continue;
					}
					else
					{
						for( l = x; l > 0; l--)
						{
							if(a[y][l-1] == 0)
							{
								a[y][l-1] = a[y][l];
								a[y][l] = 0;
							}
							else if(a[y][l-1] == a[y][l])
							{
								a[y][l-1] *= 2;
								a[y][l] = 0;
							}
						}
					}
				}
			}
	    };break;
		case 'w':
			{
				for( x = 0; x < N; x++)
				{
					for( y = 0; y < N; y++)
					{
						if(a[y][x] == 0)
							continue;
					else
					{
						for( l = y; l > 0; l--)
						{
							if(a[l-1][x] == 0)
							{
								a[l-1][x] = a[l][x];
								a[l][x] = 0;
							}
							else if(a[l-1][x] == a[l][x])
							{
								a[l-1][x] *= 2;
								a[l][x] = 0;
							}
						}
						}
					}
				}
			};break;
		case 's':
			{
				for( x = N-1; x >= 0; x--)
				{
					for( y = N-1; y >= 0; y--)
					{
						if(a[y][x] == 0)
							continue;
						else
						{
							for( l = y; l < N-1; l++)
							{
								if(a[l+1][x] == 0)
								{
									a[l+1][x] = a[l][x];
									a[l][x] = 0;
								}
								else if(a[l+1][x] == a[l][x])
								{
									a[l+1][x] *= 2;
									a[l][x] = 0 ;
								}
							}
						}
					}
				}
			};break;
		case 'd':
			{
				for( y = N-1; y >= 0; y--)
				{
					for( x = N-1; x >= 0; x--)
					{
						if(a[y][x] == 0)
							continue;
						else
						{
							for( l = x; l < N-1; l++)
							{
								if(a[y][l+1] == 0)
								{
									a[y][l+1] = a[y][l];
									a[y][l] = 0;
								}
								else if(a[y][l+1] == a[y][l])
								{
									a[y][l+1] *= 2;
									a[y][l] = 0;
								}
							}
						}
					}
				}
			};

	}
	/*
	  根据游戏者输入的字符依据游戏规则进行变化

	*/
	for( ; a[y][x] != 0;)
	{
		x = rand() % 5;
		y = rand() % 5;
	}
	a[y][x] = 2; //当游戏未结束时随机选择一个位置存放2
	for( x = 0 ; x < N; x++)
	{
		for( y = 0; y < N; y++)
		{
			if(a[y][x] == 0)
			{
				sum = 1;
			}
			if(a[y][x] == 2048)
			{
				sum = 2;
			}
		}
	}
	/*
	  核查数组内是否出现 2048，如出现则 sum = 2;
	  核查数组内是否还有 0，如果有则 sum = 1;
	*/
	system("cls"); //清理控制台
	for( y = 0; y < N; y++)
	{
		for(x = 0; x < N; x++)
		{
			printf("%5d", a[y][x]); //输出变化后游戏的界面
		}
		printf("\n");
	}
	if(sum == 0)
		break;
	else if( sum == 2)
		break;
	    /*
		  当 sum = 0时结束循环;
		  当 sum = 2时结束循环;
		  当 sum = 1时继续循环;
		*/
	}while(1);
	if(sum == 0)
	{
		printf("You Lose!\n"); //当 sum = 0时游戏结束，输出 You Lose！
	}
	else if(sum == 2)
	{
		printf("You Win!\n"); //当 sum = 2时游戏结束，输出 You Win！
	}

	return 0;
}