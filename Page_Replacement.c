#include<stdio.h>

int ref_string[100];
int frame_alloc[100];

void initialise(int frames);
void fifo(int r,int frames);
void optimal(int r,int frames);
void lru(int r,int frames);

void main()
{
	int r,frames;
	int i;

	printf("Enter the number of References : ");
	scanf("%d",&r);

	printf("Enter the Reference String : ");
	for(i=0;i<r;i++)
	{
		scanf("%d",&ref_string[i]);
	}

	printf("Enter the number of frames : ");
	scanf("%d",&frames);

	fifo(r,frames);
	optimal(r,frames);
	lru(r,frames);

}


void fifo(int r,int frames)
{
	int i,j,k;
	int flag,f_select;
	int page_hit;
	float hit_percent;

	f_select=0;
	page_hit=0;

	printf("\nFirst In First Out (FIFO) Page Replacement Policy :\n\n");

	initialise(frames);

	for(i=0;i<r;i++)
	{
		flag=0;

		for(j=0;j<frames;j++)
		{
			if(ref_string[i]==frame_alloc[j])
			{
				flag=1;
				break;
			}
		}

		if(flag==0)
		{

			if(f_select==frames)
			{
				f_select=0;
			}

			frame_alloc[f_select]=ref_string[i];
			f_select=f_select+1;

			for(k=0;k<frames;k++)
			{

				if(frame_alloc[k]==-1)
				{
					printf("-\t");
				}
				else
				{
					printf("%d\t",frame_alloc[k]);
				}

			}

			printf("\n");

			}
		else
		{
			printf("No Page Fault\n");
			page_hit=page_hit+1;
		}

	}

	hit_percent=((float)page_hit/r)*100;

	printf("\nAnalysis of First In First Out (FIFO) Page Replacement Policy for the given Reference String and Number of Frames : \n\n");
	printf("No of Total References : %d\n",r);
	printf("No of Page Hits : %d\n",page_hit);
	printf("No of Page Faults : %d\n",r-page_hit);
	printf("Hit Percentage : %f\n",hit_percent);

}


void optimal(int r,int frames)
{

	int finder[100];

	int i,j,k;
	int a,b,n,max;
	int flag,f_select;
	int flag1,flag2;
	int page_hit;
	float hit_percent;

	page_hit=0;

	printf("\nOptimal Page Replacement Policy :\n\n");

	initialise(frames);

	for(i=0;i<r;i++)
	{
		flag=0;

		for(j=0;j<frames;j++)
		{
			if(ref_string[i]==frame_alloc[j])
			{
				flag=1;
				break;
			}
		}

		if(flag==0)
		{

			flag2=0;

			for(n=0;n<frames;n++)
			{
				if(frame_alloc[n]==-1)
				{
					flag2=1;
					break;
				}
			}

			if(flag2)
			{

				f_select=n;

				frame_alloc[f_select]=ref_string[i];

			}
			else
			{

				for(a=0;a<frames;a++)
				{
					flag1=0;
					for(b=i+1;b<r;b++)
					{
						if(ref_string[b]==frame_alloc[a])
						{
							flag1=1;
							finder[a]=b;
							break;
						}
					}
					if(flag1==0)
					{
						finder[a]=r;
					}
				}

				max=0;
				f_select=0;

				for(a=0;a<frames;a++)
				{
					if(max<finder[a])
					{
						max=finder[a];
						f_select=a;
					}
				}

				frame_alloc[f_select]=ref_string[i];

			}


			for(k=0;k<frames;k++)
			{

				if(frame_alloc[k]==-1)
				{
					printf("-\t");
				}
				else
				{
					printf("%d\t",frame_alloc[k]);
				}

			}

			printf("\n");

		}
		else
		{
			printf("No Page Fault\n");
			page_hit=page_hit+1;
		}

	}

	hit_percent=((float)page_hit/r)*100;

	printf("\nAnalysis of Optimal Page Replacement Policy for the given Reference String and Number of Frames : \n\n");
	printf("No of Total References : %d\n",r);
	printf("No of Page Hits : %d\n",page_hit);
	printf("No of Page Faults : %d\n",r-page_hit);
	printf("Hit Percentage : %f\n",hit_percent);

}


void lru(int r,int frames)
{

	int finder[100];

	int i,j,k;
	int a,b,n,min;
	int flag,f_select;
	int flag1,flag2;
	int page_hit;
	float hit_percent;

	page_hit=0;

	printf("\nLeast Recently Used (LRU) Page Replacement Policy :\n\n");

	initialise(frames);

	for(i=0;i<r;i++)
	{
		flag=0;

		for(j=0;j<frames;j++)
		{
			if(ref_string[i]==frame_alloc[j])
			{
				flag=1;
				break;
			}
		}

		if(flag==0)
		{

			flag2=0;

			for(n=0;n<frames;n++)
			{
				if(frame_alloc[n]==-1)
				{
					flag2=1;
					break;
				}
			}

			if(flag2)
			{

				f_select=n;

				frame_alloc[f_select]=ref_string[i];

			}
			else
			{

				for(a=0;a<frames;a++)
				{
					flag1=0;
					for(b=i-1;b>=0;b--)
					{
						if(ref_string[b]==frame_alloc[a])
						{
							flag1=1;
							finder[a]=b;
							break;
						}
					}
					if(flag1==0)
					{
						finder[a]=-2;
					}
				}

				min=r;
				f_select=0;

				for(a=0;a<frames;a++)
				{
					if(min>finder[a])
					{
						min=finder[a];
						f_select=a;
					}
				}

				frame_alloc[f_select]=ref_string[i];

			}


			for(k=0;k<frames;k++)
			{

				if(frame_alloc[k]==-1)
				{
					printf("-\t");
				}
				else
				{
					printf("%d\t",frame_alloc[k]);
				}

			}

			printf("\n");

		}
		else
		{
			printf("No Page Fault\n");
			page_hit=page_hit+1;
		}

	}

	hit_percent=((float)page_hit/r)*100;

	printf("\nAnalysis of Least Recently Used (LRU) Page Replacement Policy for the given Reference String and Number of Frames : \n\n");
	printf("No of Total References : %d\n",r);
	printf("No of Page Hits : %d\n",page_hit);
	printf("No of Page Faults : %d\n",r-page_hit);
	printf("Hit Percentage : %f\n",hit_percent);

}


void initialise(int frames)
{
	int i;

	for(i=0;i<frames;i++)
	{
		frame_alloc[i]=-1;
	}

}
