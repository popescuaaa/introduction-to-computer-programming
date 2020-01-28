//Popescu Andrei-Gabriel 313CA

#include<stdio.h>
#include<math.h>
//Transformarea valorilor R,G,B in H,S,V
//Incepem prin implementare functiilor min si max
float
max (float a, float b)
{
  if (a > b)
    return a;
  return b;

}

float
min (float a, float b)
{
  if (a < b)
    return a;
  return b;

}

int
main ()
{
  //Datorita necesitatii obtinerii unor valori normate, tripletul (r,g,b)
  //citit initial va fi declarat cu tipul de date float, pentru a evita truncherea
  //pe care o face tipul int la impartire

  float r, g, b, h, s, v,r1,g1,b1,h1,s1,v1;
  float cmax, cmin, x, delta;
  char  c;
  int i, n, m;//variabila contor, n=latimea respectiv m=lungimea "matricei"
  int p;

  scanf ("%d%d", &n, &m);
  scanf(" %c ",&c);

  scanf ("%f", &x);

  //Pentru a evita folosirea de tablouri bidimensionale, vom folosi o instructiune "for"
  //in care vom citi toate valorile r,g,b ale pixelilor, le vom norma si vom efectua
  //toate transformarile necesare, apoi, in accelasi "for" vom afisa rezultatul
  //tripletul (h1,s1,v1), valorile modificate comform datelor de intrare

  p = n * m;
  for (i = 1; i <= p; i++)
    {
      scanf ("%f%f%f", &r, &g, &b);

      //normam la intervalul [0,1]

      r1 = r / 255;
      g1 = g / 255;
      b1 = b / 255;
      cmin = min (min (r1, g1), b1);
      cmax = max (max (r1, g1), b1);
      delta = cmax - cmin;

      //v este  mereu maximul tripletului de intrare normat

      v = cmax;
  if (cmax == cmin)
	{

    //matematic, cazul in care minimul a trei numere este identic cu minimul lor
    //implica in mod direct egalitatea lor, iar comform formulelor date in enuntul temei
    // h = 0, iar s = delta/cmax = 0/cmax = 0, pentru orice valoare diferita de 0 a cmax

    	h = 0;
	s = 0;
}else if(cmax == 0)
 {

  //in cazul in care maximul a trei numere pozitive este 0, v = 0, prin definitia problemei
  //dar si s = 0

     s= 0;
   }

   //cazul cmax = 0, presupune ecident ca unul dintre (r1,g1,b1) este 0
   //deci tratm separat comform indicatiilor din formula

  else if(cmax!=cmin){

    s= delta/cmax;

    if(cmax == r1){
      h = 60*fmod((g1-b1)/delta,6);
    }

    if(cmax == g1){
      h = 60*(2+(b1-r1)/delta);
    }
    if(cmax == b1){
      h = 60*(4+(r1-g1)/delta);
    }

}

  //numarul h astfel obtinut poate fi negativ, caz in care il adunam cu 360
  //urmand sa-l normam apoi la intervalul [0,1](si daca este pozitiv)

  if(h<0){ h = (h+360)/360;}
  else { h = h/360;}

  //tripletul de iesire primeste valorile formate anterior (h,s,v)

  h1 = h;
  v1 = v;
  s1 = s;
  switch (c) {
    case 'h': h1 = h+x;

              //pentru un numar h<0, pentru a ramane in [0,1] il vom considera 0
              //practic este : max(h1,0) = 0, pentru h<0

              if(h1<0){ h1 =max(0,h1);}

              //in caz contrar, pentru o valoare mai mare decat 1, h devine 1

              if(h1>1){ h1=min(h1,1);}

              break;
    case 's': s1 =min(s*x,1);

              break;
    case 'v': v1 =min(v*x,1);

              break;
  }

//pentru precizia de 5 zecimale impusa de problema, folosim "%.5f"
//specifica tipului float

      printf ("%.5f %.5f %.5f\n", h1, s1, v1);
  }
return 0;

}
