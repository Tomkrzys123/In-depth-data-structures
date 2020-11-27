#include "mystring.h"

int letter_count(char *s) 
{
if (s == NULL)return  -1;
int counter = 0;
char *p = s; 
while (*p){ 
	if ((*p>='a' && *p<='z') || (*p>='A' && *p<='Z'))counter++;   
	p++;                
	}
	return counter;
}

void lower_case(char *s) {
if (s == NULL)return;
char *p = s; 
while (*p){ 
	if (*p>='A' && *p<='Z')*p+=32;    
	p++;
	}
}	


int word_count(char *s) {
if (s == NULL)return  -1;
int counter = 0;
char *p = s;
char *d=s;
while (*p){ 
	d++;
	if (*p==' ' && *(d)!=' ' && *(d)!='\0')counter++;
	p++;
	}
	return counter; 
}

void trim(char *s) {
	if(s==NULL||*s=='\0')return;
	char *p=s,*dp=s;
	while(*p){
		if(*p!=' ' || (p>s && *(p-1)!=' ')){
			*dp++=*p;
		}
		p++;
	}
	if(*(p-1)==' ') *(dp-1)='\0';
	else *dp= '\0';
}