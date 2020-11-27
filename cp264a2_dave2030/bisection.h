#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float horner(float *p, int n, float x)
{
   float r=0;
   int i;
   for (i=0;i<n;i++){
	   r=r*x+ (*p+i);
   }
   return r;
}

//your bisection method implementation
float bisection(float *p, int n, float a, float b)
{
  float c,p1,p2;
  while ((b-a)>1e-6){ //tolerance measure
	  c=(a+b)/2.0;
	  p1=horner(p,n,a);
	  p2=horner(p,n,c);
	  if (fabs(p2)<1e-6)return c;
	  else{
		  if (p2<1e-6 && (c-a)<1e-6){
			  break;
		  }else if (p1*p2>0)a=c;
		  else b=c;
	  }		  
}
return c;
}