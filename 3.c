#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 0.0001
 double f(double x);
double method_hord(double x1, double x2);
double method_half(double x1, double x2);
double method_isa(double x);

 double f(double x)
 {
     return 2*pow(x-4,3)+2*x;
 }


 double method_hord(double x1, double x2)
 {

    double xi;
    int n=1;

    do{
       xi = (f(x2)*x1-f(x1)*x2) / ( f(x2)-f(x1) );

       if ( f(xi)*f(x1) > 0 )
            x1 = xi;
       else
            x2 = xi;

       n++;
    }while( fabs(f(xi)) > EPS );
printf("Count:%d",n);

    return xi;
 }

double method_half(double x1, double x2){
    double xi;
    int i = 0;
    printf("X1 = %.4f \t X2 = %.4f\n",x1, x2);
    do {
    xi = (x1 + x2) / 2;
     if ( f(xi)*f(x1) > 0 )
            x1 = xi;
       else
            x2 = xi;
    i++;
  } while (fabs(f(xi)) > EPS );
    printf("Xi = %.4f\n",xi);
    return xi;
}


double method_isa(double x){
    double F;
    int i = 0;
    printf("X = %.4f \n",x);
    do{
        F = f(x);
        x = x - f(x)/x;
        i++;
    }while(fabs(F) > EPS);
    printf("resoult = %.4f\n",x);
    return x;
}


int main()
{
    double x1, x2, root;
int choice;
    do{
       system("cls");
       printf("x1=");
       scanf("%lf", &x1);
       printf("x2=");
       scanf("%lf", &x2);
    }while( f(x1) * f(x2) > 0);
printf("Choice method:\n1.Method Hord\n2.Method Half\n3.Method Isaak\nChoice: ");
scanf("%d", &choice);
switch(choice){
case 1:root = method_hord(x1,x2);
break;
case 2:root = method_half(x1,x2);
break;
//case 3: root = method_isa(x);
//break;
}

    printf("\n\nx=%lf   f(x)=%lf", root, f(root) );
getch();
}
}