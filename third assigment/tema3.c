//POPESCU ANDREI GABRIEL 313CA
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
  char nume_jucarie[30];
  int nr_jucarie;
} jucarie;

typedef struct
{
  char oras[30];
  jucarie j[20];
  char directie;
} fabrica;

void
verficare (int *i, int *j, char directie)
{

  if (directie == 'U')
    {
      *i = *i - 1;
      return;
    }
  else if (directie == 'D')
    {
      *i = *i + 1;
      return;
    }
  else if (directie == 'R')
    {
      *j = *j + 1;
      return;
    }
  else if (directie == 'L')
    {
      *j = *j - 1;
      return;
    }

}

fabrica *
sortare_lexicografica (fabrica * sac, int k)
{
  int l;
  int x;

  fabrica tmp;


  for (l = 0; l < k - 1; l++)
    {
      for (x = l + 1; x < k; x++)
	{
	  if (strcmp (sac[l].oras, sac[x].oras) > 0)
	    {
	      tmp = sac[l];
	      sac[l] = sac[x];
	      sac[x] = tmp;
	    }
	}
    }
  return sac;
}


void
afisarea_sac (fabrica * sac, int k)
{
  int l;
  int x;
  int y = 0;
  int total = 0;


  //1.cresteam numarul la cele cu aparitii multiple
  int m;
  for (l = 0; l < k; l++)
    {

      m = sac[l].j[0].nr_jucarie;
      //memoram numarul maxim de jucarii
      //pentru ca acesta

      sac[l].j[0].nr_jucarie = 1;

      for (x = l + 1; x < k; x++)
	{

	  if (strcmp (sac[l].oras, sac[x].oras) == 0
	      && strcmp (sac[l].j[0].nume_jucarie,
			 sac[x].j[0].nume_jucarie) == 0)
	    {
	      sac[l].j[0].nr_jucarie++;
	      sac[x] = (fabrica)
	      {
	      };

	    }

	  if (sac[l].j[0].nr_jucarie > m)
	    {
	      sac[l].j[0].nr_jucarie = m;
	    }

	}

      total += sac[l].j[0].nr_jucarie;

    }

  //2.adugam in vectorul de jucarii

  for (l = 0; l < k; l++)
    {
      y = 0;


      for (x = l + 1; x < k; x++)
	{

	  if (strcmp (sac[l].oras, sac[x].oras) == 0
	      && strcmp (sac[l].j[0].nume_jucarie,
			 sac[x].j[0].nume_jucarie) != 0)
	    {
	      y++;

	      if (sac[x].j[0].nr_jucarie != 0)
		{
		  strcpy (sac[l].j[y].nume_jucarie, sac[x].j[0].nume_jucarie);
		  sac[l].j[y].nr_jucarie = sac[x].j[0].nr_jucarie;
		  sac[x] = (fabrica){};
		}
	      else
		{

		  sac[x] = (fabrica)
		  {
		  };

		}

	    }
	}
    }


  printf ("%d\n", total);


  for (l = 0; l < k; l++)
    {
      int t = 0;


//verificam daca nu sunt spatii nule in vector
      if (memcmp (&sac[l], &(fabrica){}
		  , sizeof (fabrica)) != 0)
	    {

	  if (strcmp (sac[l].oras, ""))
	    printf ("%s:\n", sac[l].oras);

//numarul de jucarii al fiecrui oras in parte
	  while (strcmp (sac[l].j[t].nume_jucarie, ""))
	    {
	      t++;
	    }


	  char aux[30];
	  int n, a, b;

	  //ordonarea descrescatore a sacului
	  for (a = 0; a < t; a++)
	    {
	      for (b = a + 1; b < t; b++)
		{

		  if (sac[l].j[a].nr_jucarie < sac[l].j[b].nr_jucarie)
		    {

		      strcpy (aux, sac[l].j[a].nume_jucarie);
		      strcpy (sac[l].j[a].nume_jucarie,
			      sac[l].j[b].nume_jucarie);
		      strcpy (sac[l].j[b].nume_jucarie, aux);

		      n = sac[l].j[a].nr_jucarie;
		      sac[l].j[a].nr_jucarie = sac[l].j[b].nr_jucarie;
		      sac[l].j[b].nr_jucarie = n;

		    }


		}
	    }


        //ordonarea lexicografica
	  for (a = 0; a < t; a++)
	    {
	      for (b = a + 1; b < t; b++)
		{

		  if ((sac[l].j[a].nr_jucarie == sac[l].j[b].nr_jucarie)
		      && strcmp (sac[l].j[a].nume_jucarie,
				 sac[l].j[b].nume_jucarie) > 0)
		    {

		      strcpy (aux, sac[l].j[a].nume_jucarie);
		      strcpy (sac[l].j[a].nume_jucarie,
			      sac[l].j[b].nume_jucarie);
		      strcpy (sac[l].j[b].nume_jucarie, aux);

		      n = sac[l].j[a].nr_jucarie;
		      sac[l].j[a].nr_jucarie = sac[l].j[b].nr_jucarie;
		      sac[l].j[b].nr_jucarie = n;


		    }


		}
	    }

	}
      
      int z = 0;
      for (z = 0; z < t; z++)
	{
	  printf ("  %d", sac[l].j[z].nr_jucarie);
	  printf (" %s\n", sac[l].j[z].nume_jucarie);
	}
    }


}


int
main ()
{
  int N, M;
  fabrica **laponia;
  fabrica *sac;

  int i, j;
  int startl, startc;
  int nr_pasi_maxim;


  scanf ("%d %d", &N, &M);
  scanf ("%d %d", &startl, &startc);
  scanf ("%d", &nr_pasi_maxim);



  laponia = (fabrica **) malloc (N * sizeof (fabrica *));
  for (i = 0; i < N; i++)
    {
      laponia[i] = malloc (M * sizeof (fabrica));

    }

  sac = malloc (100 * sizeof (fabrica));


  for (i = 0; i < N; i++)
    {
      for (j = 0; j < M; j++)
	{
	  scanf ("%s", laponia[i][j].oras);
	  scanf ("%s", laponia[i][j].j[0].nume_jucarie);
	  scanf ("%d", &laponia[i][j].j[0].nr_jucarie);
	  scanf (" %c", &laponia[i][j].directie);

	}
    }


  i = startl;
  j = startc;
  int k = 0;
  int nr_pasi_facuti = 0;



  int ok;//verfica daac este depasita harta pentru ca se contorizeaza si pasul de iesire

  while (nr_pasi_facuti <= nr_pasi_maxim)
    {

      memcpy (&sac[k], &laponia[i][j], sizeof (fabrica));

      verficare (&i, &j, sac[k].directie);//apelam functia de inaintare 

      if (sac[k].j[0].nr_jucarie == 0)
	{
	  sac[k] = (fabrica){};
	//eliminam elemetele fara jucarii
	//nu pot aparea pe harta ca avand 0 jucarii 
	}
      else
	{
	  k++;
	}

      if (i < 0 || i >= N || j < 0 || j >= M)
	{
	  printf ("TOO MUCH SNOW!\n");
	  ok = 0;
	  break;

	}
      else
	{
	  ok = 1;
	  nr_pasi_facuti++;
	}



    }

  *sac = *sortare_lexicografica (sac, k);
  printf ("%d\n", nr_pasi_facuti - ok);

  afisarea_sac (sac, k);


//eliberarea memoriei folosite 
  for (i = 0; i < N; i++)
    {
      free (laponia[i]);
    }
  free (laponia);
  free (sac);

  return 0;

}
