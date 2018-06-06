#include "stdio.h"
#include "stdlib.h"
int k, k1;
int sum;
int coun = 1;
int maxsum = 0;
int ans1, ans2;
typedef int datatype;
typedef struct node
{
	datatype data;
	datatype time;
	struct node *next;
}Linknode, *Link;

Link Createlist(int isFromFile)
{
	if (isFromFile == 2)
	{
		int a;
		Link H, p, r;
		H = (Link)malloc(sizeof(Linknode));
		r = H;

		while (scanf("%d", &a) && a != '#')
		{
			p = (Link)malloc(sizeof(Linknode));
			p->data = a;
			p->time = coun;
			coun++;
			r->next = p;
			r = p;
		}
		r->next = NULL;
		return H;
	}
	else
	{
		FILE *fpRead = fopen("data.txt", "r");
		if (fpRead == NULL)
		{
			printf("文件不存在……");
		}
		int a;
		Link H, p, r;
		H = (Link)malloc(sizeof(Linknode));
		r = H;

		while (fscanf(fpRead,"%d", &a) && a != '#')
		{
			p = (Link)malloc(sizeof(Linknode));
			p->data = a;
			p->time = coun-1;
			coun++;
			r->next = p;
			r = p;
		}
		r->next = NULL;
		return H;
	}
}

void Adjmax(Link H)
{
	
	Link p, p1, q, r, s, t;
	p = H->next;
	if ((p == NULL) || (coun - 1<k))
		return;
	while (p)
	{
		k1 = k;
		sum = 0;
		p1 = p;
		while ((k1--) && (p1))
		{
			sum += p1->data;
			q = p1->next;
			p1 = q;
		}
		if (sum>maxsum)
		{
			ans1 = p->time;
			ans2 = p->data;
			maxsum = sum;
		}
		p = p->next;
	}
	printf("order:%d\ndata:%d\nmaxsum:%d",ans1, ans2, maxsum);
	maxsum = 0;
	ans1 = 0;
	ans2 = 0;
	coun = 1;
	return;
}
void main()
{
	Link p,q;
	int b;
	int isFromFile;
	printf("请选择输入方式：1.文件输入；2.键盘输入\n");
	scanf("%d", &isFromFile);
	if (isFromFile == 2)
	{
		do
		{
			printf("input k:\n");
			scanf("%d", &k);
			printf("Please input numbers:\n");
			p = Createlist(isFromFile);
			Adjmax(p);
			while (p->next)
			{
				q = p;
				p = p->next;
				free(q);
			}
			free(p);
			printf("\n是否继续？是：1；否：0\n");
			getchar();
			scanf("%d", &b);

		} while (b);
	}
	else
	{
		FILE *fpRead = fopen("data.txt", "r");
		fscanf(fpRead, "%d", &k);
		p = Createlist(isFromFile);
		Adjmax(p);
		while (p->next)
		{
			q = p;
			p = p->next;
			free(q);
		}
		free(p);
	}
	system("pause");
}
