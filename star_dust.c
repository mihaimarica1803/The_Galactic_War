#include <stdio.h>
#include <stdlib.h>

// Calculul mediei aritmetice a octeților de pe conturul hărții.
double task1(int x, int *v, int **w)
{
	int i, j;
	double m_a, n = 0, p = 0;
	for (i = 0; i < v[0]; i++) {
		for (j = 0; j < 4; j++) {
			n += *((char *)&w[0][i] + j);
			p++;
		}
	}
	for (i = 0; i < v[x - 1]; i++) {
		for (j = 0; j < 4; j++) {
			n += *((char *)&w[x - 1][i] + j);
			p++;
		}
	}
	for (i = 1; i < x - 1; i++) {
		n += *((char *)&w[i][0]);
		n += *((char *)&w[i][v[i] - 1] + 3);
		p += 2;
	}
	m_a = n / p;
	return m_a;
}

// Modificarea blocurilor de date de tip char.
void mc(int **w, int *v, int c, int d, int e)
{
	int i, nr;
	if (d % 4 == 0)
		nr = d / 4;
	else
		nr = (d / 4) + 1;
	if (v[c] < nr) {
		w[c] = realloc(w[c], sizeof(int) * (d + 1) / 2);
		for (i = v[c]; i <= nr - 2; i++)
			w[c][i] = 0;
		if (d % 4 == 1)
			*((char *)&w[c][nr - 1]) = *((char *)&e);
		if (d % 4 == 2)
			*((char *)&w[c][nr - 1] + 1) = *((char *)&e);
		if (d % 4 == 3)
			*((char *)&w[c][nr - 1] + 2) = *((char *)&e);
		if (d % 4 == 0)
			*((char *)&w[c][nr - 1] + 3) = *((char *)&e);
		v[c] = nr;
	} else {
		if (d % 4 == 1)
			*((char *)&w[c][nr - 1]) = *((char *)&e);
		if (d % 4 == 2)
			*((char *)&w[c][nr - 1] + 1) = *((char *)&e);
		if (d % 4 == 3)
			*((char *)&w[c][nr - 1] + 2) = *((char *)&e);
		if (d % 4 == 0)
			*((char *)&w[c][nr - 1] + 3) = *((char *)&e);
	}
}

// Modificarea blocurilor de date de tip short int.
void ms(int **w, int *v, int c, int d, int e)
{
	int i, nr;
	if (d % 2 == 0)
		nr = d / 2;
	else
		nr = (d / 2) + 1;
	if (v[c] < nr) {
		w[c] = realloc(w[c], sizeof(int) * nr);
		for (i = v[c]; i <= nr - 2; i++)
			w[c][i] = 0;
		if (d % 2 == 0)
			*((short *)&w[c][nr - 1] + 1) = *((short *)&e);
		if (d % 2 == 1)
			*((short *)&w[c][nr - 1]) = *((short *)&e);
		v[c] = nr;
	} else {
		if (d % 2 == 0)
			*((short *)&w[c][nr - 1] + 1) = *((short *)&e);
		if (d % 2 == 1)
			*((short *)&w[c][nr - 1]) = *((short *)&e);
	}
}

// Modificarea blocurilor de date de tip int.
void mi(int **w, int *v, int c, int d, int e)
{
	int i;
	if (v[c] < d) {
		w[c] = realloc(w[c], sizeof(int) * d);
		for (i = v[c]; i <= d - 2; i++)
			w[c][i] = 0;
		w[c][d - 1] = e;
		v[c] = d;
	} else {
		w[c][d - 1] = e;
	}
}

// Inversarea ordinii octeților blocurilor de date cu dimensiunea short int.
void ss(int **w, int c, int d)
{
	int nr = d / 2;
	if (d % 2 == 0) {
		int var = *((char *)&w[c][nr]);
		*((char *)&w[c][nr]) = *((char *)&w[c][nr] + 1);
		*((char *)&w[c][nr] + 1) = var;
	} else {
		int var = *((char *)&w[c][nr] + 2);
		*((char *)&w[c][nr] + 2) = *((char *)&w[c][nr] + 3);
		*((char *)&w[c][nr] + 3) = var;
	}
}

// Inversarea ordinii octeților blocurilor de date cu dimensiunea int.
void si(int **w, int c, int d)
{
	int var1 = *((char *)&w[c][d]);
	*((char *)&w[c][d]) = *((char *)&w[c][d] + 3);
	*((char *)&w[c][d] + 3) = var1;
	int var2 = *((char *)&w[c][d] + 1);
	*((char *)&w[c][d] + 1) = *((char *)&w[c][d] + 2);
	*((char *)&w[c][d] + 2) = var2;
}

// Modificarea matricei.
void task2(int a, int b, int c, int d, int *v, int **w)
{
	int e;
	if (a == 'M') {
		scanf("%X", &e);
		if (b == 'C')
			mc(w, v, c, d, e);
		if (b == 'S')
			ms(w, v, c, d, e);
		if (b == 'I')
			mi(w, v, c, d, e);
	}
	if (a == 'D') {
		if (b == 'C')
			// Ștergerea blocurilor de date cu dimensiunea char.
			*((char *)&w[c][(d + 3) / 4 - 1] + ((d + 3) % 4)) = 0;
		if (b == 'S')
			// Ștergerea blocurilor de date cu dimensiunea short int.
			*((short *)&w[c][(d + 1) / 2 - 1] + 1 - (d % 2)) = 0;
		if (b == 'I')
			// Ștergerea blocurilor de date cu dimensiunea int.
			w[c][d - 1] = 0;
	}
	if (a == 'S') {
		if (b == 'S')
			ss(w, c, d);
		if (b == 'I')
			si(w, c, d);
	}
}

// Afișarea matricei.
void afisare(int x, int *v, int **w)
{
	int i, j;
	for (i = 0; i < x; i++) {
		for (j = 0; j < v[i]; j++)
			printf("%08X ", w[i][j]);
	printf("\n");
	}
}

// Verificare apartenență matrice alocată.
int ver(int i, int j, int k, int x, int *v, int **w)
{
	if (i >= 0 && j >= 0 && i < x && j < v[i])
		if (*((char *)&w[i][j] + k) == 0)
			return 1;
	return 0;
}

// Algoritmul fill.
void fill(int i, int j, int k, int x, int *v, int **w, int f, int *s, int *t)
{
	int l, i1, j1, k1;
	*((char *)&w[i][j] + k) = 1;
	t[f - 1]++;
	for (l = 0; l < 4; l++) {
		if (l == 0 || l == 2) {
			i1 = i + s[l];
			j1 = j;
			k1 = k;
			if (ver(i1, j1, k1, x, v, w) == 1)
				fill(i1, j1, k1, x, v, w, f, s, t);
		} else {
			i1 = i + s[l];
			if (k == 1) {
				j1 = j;
				k1 = 0;
				if (ver(i1, j1, k1, x, v, w) == 1)
					fill(i1, j1, k1, x, v, w, f, s, t);
				k1 = 2;
				if (ver(i1, j1, k1, x, v, w) == 1)
					fill(i1, j1, k1, x, v, w, f, s, t);
			}
			if (k == 2) {
				j1 = j;
				k1 = 1;
				if (ver(i1, j1, k1, x, v, w) == 1)
					fill(i1, j1, k1, x, v, w, f, s, t);
				k1 = 3;
				if (ver(i1, j1, k1, x, v, w) == 1)
					fill(i1, j1, k1, x, v, w, f, s, t);
			}
			if (k == 0) {
				j1 = j;
				k1 = 1;
				if (ver(i1, j1, k1, x, v, w) == 1)
					fill(i1, j1, k1, x, v, w, f, s, t);
				j1 = j - 1;
				k1 = 3;
				if (ver(i1, j1, k1, x, v, w) == 1)
					fill(i1, j1, k1, x, v, w, f, s, t);
			}
			if (k == 3) {
				j1 = j;
				k1 = 2;
				if (ver(i1, j1, k1, x, v, w) == 1)
					fill(i1, j1, k1, x, v, w, f, s, t);
				j1 = j + 1;
				k1 = 0;
				if (ver(i1, j1, k1, x, v, w) == 1)
					fill(i1, j1, k1, x, v, w, f, s, t);
			}
		}
	}
}

int main(void)
{
	// Declararea, citirea si alocarea dinamică!

	char a, b;
	int c, d, f = 0, g = 0, r = 0, q = 0, x, y, i, j, k;
	double m_a;
	int s[4] = {-1, 0, 1, 0};
	scanf("%d", &x);
	int *v = (int *)malloc(sizeof(int) * x);
	if (!v) {
		fprintf(stderr, "malloc() failed\n");
		return -1;
	}
	int **w = (int **)malloc(sizeof(int *) * x);
	if (!w) {
		fprintf(stderr, "malloc() failed\n");
		return -1;
	}
	for (i = 0; i < x; i++) {
		scanf("%d", &v[i]);
		w[i] = (int *)malloc(sizeof(int) * v[i]);
		if (!w[i]) {
			fprintf(stderr, "malloc() failed\n");
			return -1;
		}
		for (j = 0; j < v[i]; j++)
			scanf("%X", &w[i][j]);
	}

	// Task 1!

	m_a = task1(x, v, w);
	printf("task 1\n%.8lf\n", m_a);

	// Task 2!

	printf("task 2\n");
	scanf("%d", &y);
	for (i = 0; i < y; i++) {
		scanf(" %c %c %d %d", &a, &b, &c, &d);
		task2(a, b, c, d, v, w);
	}
	afisare(x, v, w);

	// Task 3!

	int *t = (int *)malloc(sizeof(int) * 0);
	if (!t) {
		fprintf(stderr, "malloc() failed\n");
		return -1;
	}
	for (i = 0; i < x; i++) {
		for (j = 0; j < v[i]; j++) {
			for (k = 0; k < 4; k++)
				if (*((char *)&w[i][j] + k) == 0) {
					f++;
					t = realloc(t, sizeof(int) * f);
					t[f - 1] = 0;
					fill(i, j, k, x, v, w, f, s, t);
					if (g < t[f - 1]) {
						r = i;
						q = j * 4 + k;
						g = t[f - 1];
					}
				}
		}
	}
	printf("task 3\n%d %d %d\n", r, q, g);

	// Eliberarea memoriei!

	for (i = 0; i < x; i++)
		free(w[i]);
	free(w);
	free(v);
	free(t);
	return 0;
}
