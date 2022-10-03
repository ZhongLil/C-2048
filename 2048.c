# include "stdlib.h"
# include "stdio.h"
# include "conio.h"
# include "time.h"
# define N 4

int main(void)
{
	int a[N][N] = {0}, x, y, l, t, sum, random; //�洢��ܣ��ж�����
	char c; //�洢�����ж�����

	random = ((int)time(0)); //time������������
	srand (random);
	for( y = 0; y < N; y++)
	{
		for( x = 0; x < N; x++)  //�������
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
	//������������ʼ2��λ��
	system("cls");
	for( y = 0; y < N; y++)
	{
		for( x = 0; x < N; x++)
		{
			printf("%5d", a[y][x]);
		}
		printf("\n");
	}
	//�����ʼ����Ϸ����
	do
	{
		sum = 0;
	c = getch();
	//scanf("%s", &c); //������Ϸ�ߵķ��������ַ�c
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
	  ������Ϸ��������ַ�������Ϸ������б仯

	*/
	for( ; a[y][x] != 0;)
	{
		x = rand() % 5;
		y = rand() % 5;
	}
	a[y][x] = 2; //����Ϸδ����ʱ���ѡ��һ��λ�ô��2
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
	  �˲��������Ƿ���� 2048��������� sum = 2;
	  �˲��������Ƿ��� 0��������� sum = 1;
	*/
	system("cls"); //�������̨
	for( y = 0; y < N; y++)
	{
		for(x = 0; x < N; x++)
		{
			printf("%5d", a[y][x]); //����仯����Ϸ�Ľ���
		}
		printf("\n");
	}
	if(sum == 0)
		break;
	else if( sum == 2)
		break;
	    /*
		  �� sum = 0ʱ����ѭ��;
		  �� sum = 2ʱ����ѭ��;
		  �� sum = 1ʱ����ѭ��;
		*/
	}while(1);
	if(sum == 0)
	{
		printf("You Lose!\n"); //�� sum = 0ʱ��Ϸ��������� You Lose��
	}
	else if(sum == 2)
	{
		printf("You Win!\n"); //�� sum = 2ʱ��Ϸ��������� You Win��
	}

	return 0;
}