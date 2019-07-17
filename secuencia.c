#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include "auxiliar.h"
#include <string.h>

int main(int argc, char *argv[]){
	double desde;
	double hasta;
	double paso;
	double i;
	double maximo= 100;
	argv0="secuencia";
	char *output;
	char *aux;
	output = getenv("MAX_OUTPUT");
	if(output!=NULL && strcmp(output,"\0")!=0){
		char *max;
		double maxout;
		maxout = strtol(output, &max,10);
		if(maxout==0){
			Error(EX_NOPERM, "Se intentó superar el límite de salida establecido por MAX OUTPUT.");
		}
		if(strcmp(max,"\0")==0 && maxout>0){
			maximo = maxout;
		}
	}
	switch(argc){
		case 1:
			i = 1;
			while (i<11){
				if(i>maximo){
					Error (EX_NOPERM, "Se intento superar el limite de salida establecido por MAX_OUTPUT.");
				}
				printf("\t%g\n", i);
				i++;
			} 
		break;
		case 2:
			if((strcmp(argv[1],"-h") == 0) || (strcmp(argv[1],"--help") == 0)){
				printf("secuencia: Uso: secuencia [ hasta [ desde [ paso ]]]\n");
 				printf("secuencia: Genera la secuencia de numeros en el intervalo y paso indicados \n");
				exit(EX_OK);
			}else{
				hasta=strtod(argv[1],&aux);
				i = 1;
				if(strcmp(aux,"\0")!=0 || hasta<1){
             				Error(EX_USAGE, "El parametro \"hasta\" no es un numero real valido.");
             		  	}
				while (i<=hasta){
					if(i>maximo){
						Error (EX_NOPERM, "Se intento superar el limite de salida establecido por MAX_OUTPUT.");
					}
					printf("\t%g\n", i);
					i++;
				} 
			}
		break;
		case 3:
			hasta=strtod(argv[1],&aux);
			if(strcmp(aux,"\0")!=0){
             			   Error(EX_USAGE, "El parametro \"hasta\" no es un numero real valido.");
             		}
			desde = strtod(argv[2],&aux);
			if(strcmp(aux,"\0")!=0){
             			   Error(EX_USAGE, "El parametro \"desde\" no es un numero real valido.");
             		}
			i = desde;
			if(desde<0){
				Error (EX_USAGE, "El parametro \"hasta\" no es un numero real valido.");
			}
			while (i<=hasta){
				if(i>maximo){
					Error (EX_NOPERM, "Se intento superar el limite de salida establecido por MAX_OUTPUT.");
				}
				printf("\t%g\n", i);
				i++;
			} 
		break;
		case 4:
			hasta=strtod(argv[1],&aux);
			if(strcmp(aux,"\0")!=0){
             			   Error(EX_USAGE, "El parametro \"hasta\" no es un numero real valido.");
             		}
			desde = strtod(argv[2],&aux);
			if(strcmp(aux,"\0")!=0){
             			   Error(EX_USAGE, "El parametro \"desde\" no es un numero real valido.");
             		}
			paso = strtod(argv[3],&aux);
			if(paso == 0){
				if(strcmp(argv[3],"0")==0){
					Error (EX_USAGE, "El parametro \"paso\" no puede valer 0.");
				}
				Error(EX_USAGE, "El parametro \"paso\" no es un numero real valido.");
			}
			i = desde;
			if(desde<hasta){
				if(paso<0){
					Error (EX_USAGE, "El signo de \"paso\" no permite recorrer el intervalo en el sentido \"desde\" a \"hasta\".");
				}
				while(i <= hasta){
					printf("\t%g\n", i);
					i = i + paso;
				}
			}
			if(hasta>maximo){
				while(i <= maximo){
					printf("\t%g\n", i);
					i = i + paso;
				}
				Error (EX_NOPERM, "Se intento superar el limite de salida establecido por MAX_OUTPUT.");
			} 
			if(hasta<desde){
				if(paso>0){
					Error (EX_USAGE, "El signo de \"paso\" no permite recorrer el intervalo en el sentido \"desde\" a \"hasta\".");
				}
				while(i>=hasta){
					printf("\t%g\n", i);	
					i = i + paso;
				}
			} 
		break;
		default: 
			Error (EX_USAGE, "El numero de argumentos no es correcto.");
	}
exit(EX_OK);
return 0;
}
