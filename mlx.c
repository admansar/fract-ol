#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct complexe
{
	double	reel;
	double	imaginaire;
	struct complexe	*next;
}l_complexe;

l_complexe *creat_lst(double a, double b)
{
	l_complexe *ada;

	ada = malloc (sizeof(l_complexe));
	ada->reel = a;
	ada->imaginaire = b;
	ada->next = NULL;
	return (ada);
}


l_complexe *somme(l_complexe *a, l_complexe *b)
{
	return (creat_lst(a->reel + b->reel , b->imaginaire + a->imaginaire));
}

l_complexe *produit(l_complexe *a, l_complexe *b)
{
	double	a1;
	double	a2;
	double	b1;
	double	b2;

	a1 = a->reel;
	a2 = a->imaginaire;
	b2 = b->imaginaire;
	b1 = b->reel;
	return (creat_lst((a1 * b1) - (a2 * b2), (a1* b2) + (a2 * b1)));
}

l_complexe *khwi(l_complexe *a)
{
	a->reel = 0;
	a->imaginaire = 0;
	return (a);
}


int main()
{
	void *win;
	void *ptr;
	void *win2;
	double i = -500;
	double j = -500;
	l_complexe *z;
	l_complexe *c;
	l_complexe *pro;
	int	color;
	int n;
	int blasa;
	double reel;
	double imag;

	z = creat_lst(0, 0);
	ptr = mlx_init();
	win = mlx_new_window(ptr, 1000, 1000, "time_chamber");
	n = 0;
		while (i < 500)
		{
			j = -500;
			while (j < 500)
			{
				c = creat_lst((2 * i - 500 )/ 700 ,(2 * j)/ 700);
				z = khwi(z);
				reel = 0;
				imag = 0;
				blasa = 0;
				while (reel * imag <= 4 && blasa < 100)
				{
		//		printf("reel = %f ------- imag = %f\n", reel, imag);
					pro = produit(z, z);
					z = somme(pro, c);
					reel = z->reel;
					imag = z->imaginaire;
					blasa++;
				}
		//		printf("%d\n", blasa);
					color = 0xFFFFFF * (blasa);
				if (blasa == 100)
					color = 0;
				mlx_pixel_put(ptr, win, 500 + i, 500 - j, color);
				j++;
			}
			i++;
		}
	
	mlx_loop(ptr);
}
