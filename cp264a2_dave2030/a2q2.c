#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
float horner(float p[], int n, float x)
{
	int res= 0;
	for (int k = 0; k<n ;k++) {
		res+= (pow(x,(n-k-1)))*p[k];
	}
	return res;
}
 
int main(int argc, char* args[])
{   
    //get polynomial efficients from command line arguments
    
	if (argc <= 1) {
        printf("Need more than one arguments, e.g.: 1 2 3 4\n");
        return 0;
    }
    
    int n = argc-1;
    
    float c[n];
	for (int i = 0;i<n;i++) {
		c[i] = atof(args[i + 1]);
	}
    // read command line arguments convert them to floating numbers atof(args[i+1]);

    
    // repetitive polynomial evaluation for user input of x value
    float x = 0.0, ans;
    do {
        //get x value from keyboard
        do {
            printf("Please enter x value (Ctrl+C or 999 to quit):\n");
            if (scanf("%f", &x) != 1) {
                printf("Invalid input\n");
            } else {
                break;
            }
            // flush the input buffer 
            while(getchar() !='\n'); 
		} while (1);
		
		if (x!=999){
			for (int k=0;k<n;k++){
				printf("%.1f*%.1f^%d",c[k],x,(n-k-1));
				if (k+1<n)printf(" + ");
			
		}
		float ans=horner(c,n,x);
		printf(" = %.1f\n",ans);
		}
		else break;
        // write your code
        // escape when input 999
        // print the polynomial expression
        // use x^n to denote x raised to the n-th power
        // use %.1f format for floating number
        // get polynomial's value by calling horner(p, n, x)
    
    } while (1);

    return 0;
}