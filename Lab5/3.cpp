//Iniciar programa.
//Para poder realizar el ordenamiento de los 4 digitos haremos 1 funcion  que pida el numero al usuario y que  separe cada digito de el 
//numero.
//Despues haremos 2 funciones que nos analicen todos los digitos para verificar cada caso posible con tal que quede ordenado 
//de mayor a menor y de menor a mayor ( 1 funcion de mayor a menor y otra de menor a mayor).
//Llamaremos las 2 funciones de orden dentro de la funcion que separo los numeros.
//Dentro de la funcion principal main llamaremos a la funcion que separo.
//Finalizar programa.
//


#include <stdio.h>
  


 int separar(){
	 int num, a, b, c, d;
		printf("Ingrese un numero entero de 4 digitos: ");
		scanf("%d", &num);
		if (num>=1000){
			if (num<=9999){
			a=num / 1000;
			b=(num % 1000) / 100;
			c=(num % 1000) % 100 / 10;
			d=((num % 1000) % 100) % 10 / 1;
		}
	}
	menor(a, b, c, d);
	mayor(a, b, c, d);
	return 1;
}


  
  
int mayor(int a, int b, int c, int d){
	
	if (a>=b && b>=c && c>=d){									
	printf("El numero mayor sera %d %d %d %d\n", a,b,c,d);
	}
	else if (a>=b && b>=d && d>=c){								
	printf("El numero mayor sera %d %d %d %d\n", a,b,d,c);
	}
	else if (a>=c && c>=d && b>=d){
	printf("El numero mayor sera %d %d %d %d\n", a,c,b,d);		
	}
	else if (a>=d && d>=b && b>=c){
	printf("El numero mayor sera %d %d %d %d\n", a,d,b,c);	
	}
	else if (a>=c && c>=d && d>=b){
	printf("El numero mayor sera %d %d %d %d\n", a,c,d,b);	
	}
	else if (a>=d && d>=c && c>=b){
	printf("El numero mayor sera %d %d %d %d\n", a,d,c,b);	
	}
	else if (b>=a && a>=c && c>=d){
	printf("El numero mayor sera %d %d %d %d\n", b,a,c,d);	
	}
	else if (b>=a && a>=d && d>=c){
	printf("El numero mayor sera %d %d %d %d\n", b,a,d,c);	
	}
	else if (c>=a && a>=b && b>=d){
	printf("El numero mayor sera %d %d %d %d\n", c,a,b,d);	
	}
	else if (d>=a && a>=b && b>=c){
	printf("El numero mayor sera %d %d %d %d\n", d,a,b,c);	
	}
	else if (c>=a && a>=d && d>=b){
	printf("El numero mayor sera %d %d %d %d\n", c,a,d,b);	
	}
	else if (d>=a && a>=c && c>=b){
	printf("El numero mayor sera %d %d %d %d\n", d,a,c,b); 	
	}
	else if (b>=c && c>=a && a>=d){
	printf("El numero mayor sera %d %d %d %d\n", b,c,a,d);	
	}
	else if (b>=d && d>=a && a>=c){
	printf("El numero mayor sera %d %d %d %d\n", b,d,a,c);	
	}
	else if (c>=b && b>=a && a>=d){
	printf("El numero mayor sera %d %d %d %d\n", c,b,a,d);	
	}
	else if (d>=b && b>=a && a>=c){
	printf("El numero mayor sera %d %d %d %d\n", d,b,a,c);	
	}
	else if (c>=d && d>=a && a>=b){
	printf("El numero mayor sera %d %d %d %d\n", c,d,a,b);	
	}
	else if (d>=c && c>=a && a>=b){
	printf("El numero mayor sera %d %d %d %d\n", d,c,a,b);	
	}
	else if (b>=c && c>=d && d>=a){
	printf("El numero mayor sera %d %d %d %d\n", b,c,d,a);	
	}
	else if (b>=d && d>=c && c>=a){
	printf("El numero mayor sera %d %d %d %d\n", b,d,c,a);	
	}
	else if (d>=b && b>=c && c>=a){
	printf("El numero mayor sera %d %d %d %d\n", d,b,c,a);	
	}
	else if (c>=b && b>=d && d>=a){
	printf("El numero mayor sera %d %d %d %d\n", c,b,d,a);	
	}
	else if (c>=d && d>=b && b>=a){
	printf("El numero mayor sera %d %d %d %d\n", c,d,b,a);	
	}
	else if (d>=c && c>=b && b>=a){
	printf("El numero mayor sera %d %d %d %d\n", d,c,b,a);	
	}
	else{
	printf("Error\n");
	}
return 1;
}

int menor(int a, int b, int c, int d){
	
	if (a<=b && b<=c && c<=d){									
	printf("El numero menor sera %d %d %d %d\n", a,b,c,d);
	}
	else if (a<=b && b<=d && d<=c){								
	printf("El numero menor sera %d %d %d %d\n", a,b,d,c);
	}
	else if (a<=c && c<=d && b<=d){
	printf("El numero menor sera %d %d %d %d\n", a,c,b,d);	
	}
	else if (a<=d && d<=b && b<=c){
	printf("El numero menor sera %d %d %d %d\n", a,d,b,c);	
	}
	else if (a<=c && c<=d && d<=b){
	printf("El numero menor sera %d %d %d %d\n", a,c,d,b);
	}
	else if (a<=d && d<=c && c<=b){
	printf("El numero menor sera %d %d %d %d\n", a,d,c,b);
	}
	else if (b<=a && a<=c && c<=d){
	printf("El numero menor sera %d %d %d %d\n", b,a,c,d);	
	}
	else if (b<=a && a<=d && d<=c){
	printf("El numero menor sera %d %d %d %d\n", b,a,d,c);	
	}
	else if (c<=a && a<=b && b<=d){
	printf("El numero menor sera %d %d %d %d\n", c,a,b,d);	
	}
	else if (d<=a && a<=b && b<=c){
	printf("El numero menor sera %d %d %d %d\n", d,a,b,c);	
	}
	else if (c<=a && a<=d && d<=b){
	printf("El numero menor sera %d %d %d %d\n", c,a,d,b);	
	}
	else if (d<=a && a<=c && c<=b){
	printf("El numero menor sera %d %d %d %d\n", d,a,c,b); 	
	}
	else if (b<=c && c<=a && a<=d){
	printf("El numero menor sera %d %d %d %d\n", b,c,a,d);	
	}
	else if (b<=d && d<=a && a<=c){
	printf("El numero menor sera %d %d %d %d\n", b,d,a,c);	
	}
	else if (c<=b && b<=a && a<=d){
	printf("El numero menor sera %d %d %d %d\n", c,b,a,d);	
	}
	else if (d<=b && b<=a && a<=c){
	printf("El numero menor sera %d %d %d %d\n", d,b,a,c);	
	}
	else if (c<=d && d<=a && a<=b){
	printf("El numero menor sera %d %d %d %d\n", c,d,a,b);	
	}
	else if (d<=c && c<=a && a<=b){
	printf("El numero menor sera %d %d %d %d\n", d,c,a,b);	
	}
	else if (b<=c && c<=d && d<=a){
	printf("El numero menor sera %d %d %d %d\n", b,c,d,a);
	}
	else if (b<=d && d<=c && c<=a){
	printf("El numero menor sera %d %d %d %d\n", b,d,c,a);
	}
	else if (d<=b && b<=c && c<=a){
	printf("El numero menor sera %d %d %d %d\n", d,b,c,a);	
	}
	else if (c<=b && b<=d && d<=a){
	printf("El numero menor sera %d %d %d %d\n", c,b,d,a);	
	}
	else if (c<=d && d<=b && b<=a){
	printf("El numero menor sera %d %d %d %d\n", c,d,b,a);	
	}
	else if (d<=c && c<=b && b<=a){
	printf("El numero menor sera %d %d %d %d\n", d,c,b,a);	
	}
	else{
	printf("Error\n");
	}
return 1;
}
 
int main(){
	separar();

	return 0;
}
