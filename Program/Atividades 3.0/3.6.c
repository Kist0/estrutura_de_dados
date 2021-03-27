#include <stdio.h>

float areatriangulo(float b, float h){
	float a;
	
	a = b*h/2;
	return a;
}

float circunferencia(float r){

	return 2*3.14*r;
}

float areatrapezio(float bma, float bme, float h){
	float a;
	
	a = ((bma+bme)*h)/2;
	printf("Tendo por bases X e Z, Y como altura, a area do trapezio eh: %.2f\n", a);
}

float arearetangulo(float b, float h){
	float a;
	
	a = b*h;
	printf("A area do triangulo sendo base Y e altura Z eh: %.2f", a);
}

void main(){
	float x, y, z;
	
	printf("Digite 3 valores reais: ");
	scanf("%f %f %f", &x, &y, &z);
	printf("A area do triangulo de X e Y eh: %.2f\n", areatriangulo(x, y));
	printf("A circunferencia de Z eh: %.2f\n", circunferencia(z));
	areatrapezio(x, z, y);
	arearetangulo(y, z);
}
