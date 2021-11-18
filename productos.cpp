//Emilio Jacob Rivas Monroy A01368205

#include <stdio.h>
#include <conio.h>
#include <String.h>
#include <fstream>
using namespace std;

char nom[21],fam[21],udm[21], falso[2];

int clave, pu, in, ac, minn, maxx;

//------------------------------------------//
bool existe_clave(){
	int busca_clv;
	ifstream arch;
	arch.open("productos.txt",ios::in);
	while (!arch.eof()){
		arch >> busca_clv;
		if (busca_clv==clave){
			arch.close();
			return(true);
		}
	}
	arch.close();
	return(false);
}
//------------------------------------------//
class Graba{
	public:
		char  ag_nom[21], ag_fam[21],ag_udm[21];
		int ag_clave,ag_in,ag_ac,ag_min,ag_max,ag_pu;
	public:
		Graba(int par_clave, char par_nom[21], char par_fam[21], char par_udm[21], int par_pu ,int par_in, int par_ac, int par_min, int par_max){
			ag_clave=par_clave;
            strcpy(ag_nom,par_nom);
			strcpy(ag_fam,par_fam);
			strcpy(ag_udm,par_udm);
            ag_pu= par_pu;
            ag_in = par_in;
            ag_ac = par_ac;
            ag_min= par_min;
            ag_max= par_max;	
		}
		
		void grabar(){
			ofstream arch;
			arch.open("productos.txt",ios::app);
			arch <<ag_clave << " "<< ag_nom << " "<< ag_fam <<" " <<ag_udm <<" " <<ag_pu <<" " << ag_in<<" "<<ag_ac <<" "<<ag_min<<" "<< ag_max <<"\n";
			arch.close();
            printf("dato guardado en el archivo txt.\n");
            printf("Presiona [ENTER] para continuar...");    
		}
};
//------------------------------------------//
void pide_datos(){
    system("cls");
    do {
        printf("Indica la clave del producto: ");scanf("%d",&clave);gets(falso);
        if ((clave < 0) || (clave > 99999 )){
            printf("ERROR, la clave solo puede tener entre 1 y 99,999.\n");
            printf("Presiona [ENTER] para ingresar de nuevo el n%cmero...\n",163);
            getche();
            system("cls");
     }
    } while ((clave < 0) || (clave > 99999));
        if(existe_clave()){
            printf("ERROR, la clave se duplica en el archivo.\n");
            printf("Presiona [ENTER] para regresar al men%c...\n",163);
            getche();
        }else{
            do {
            printf("Indica el nombre del producto   : "); gets(nom);
            if ((strlen(nom)<1) || (strlen(nom)>20)){
                printf("Error, el nombre debe tener entre 1 y 20 caracteres ...\n");
                getche();
                }
            } while ((strlen(nom)<1) || (strlen(nom)>20));
        
            do {
                printf("Indica la famlia del producto: "); gets(fam);
                if ((strlen(fam)<1) || (strlen(fam)>20)){
                    printf("Error, la familia debe tener entre 1 y 20 caracteres ...\n");
                    getche();
                    }
                } while ((strlen(fam)<1) || (strlen(fam)>999999));

            do {
                printf("Indica la unidad de medida del producto : "); gets(udm);
                if ((strlen(udm)<1) || (strlen(udm)>999999)){
                    printf("Error, la unidad de medida debe tener entre 1 y 20 caracteres ...\n");
                    getche();
                    }
                } while ((strlen(udm)<1) || (strlen(udm)>999999));

            do {
                printf("Indica el Precio Unitario por cada porducto : ");scanf("%d",&pu);gets(falso);
                if ((pu < 1) || (pu > 999999 )){
                    printf("ERROR, el Precio Unitario solo puede tener entre 1 y 99,999.\n");
                    printf("Presiona [ENTER] para ingresar de nuevo el n%cmero...\n",163);
                    getche();
                    }
                } while ((pu < 1) || (pu > 999999));
        
            do {
                printf("Indica la Existencia Inicial del producto : ");scanf("%d",&in);gets(falso);
                if ((in < 1) || (in > 999999 )){
                    printf("ERROR, la Existencia solo puede tener entre 1 y 99,999.\n");
                    printf("Presiona [ENTER] para ingresar de nuevo el n%cmero...\n",163);
                    getche();
                    }
                } while ((in < 1) || (in > 999999   ));

            do {   
                printf("Indica la Existencia Actual del producto : ");scanf("%d",&ac);gets(falso);
                if ((ac < 1) || (ac > 999999 )){   
                    printf("ERROR, la clave solo puede tener entre 1 y 99,999.\n");
                    printf("Presiona [ENTER] para ingresar de nuevo el n%cmero...\n",163);
                    getche();
                 }
                } while ((ac < 1) || (ac > 999999));


            do {
                printf("Indica el Stock Minimo : ");scanf("%d",&minn);gets(falso);
            if ((minn < 1) || (minn > 999999 )){
                printf("ERROR, el Stock Mimimo solo puede tener entre 1 y 99,999.\n");
                printf("Presiona [ENTER] para ingresar de nuevo el n%cmero...\n",163);
                getche();
                    }
                } while ((minn < 1) || (minn > 999999));

            do {
                printf("Indica el Stock M%cximo: ",181);scanf("%d",&maxx);gets(falso);
            if ((maxx < 1) || (maxx > 999999 )){
                printf("ERROR, el Stock M%cximo solo puede tener entre 1 y 99,999.\n",181);
                printf("Presiona [ENTER] para ingresar de nuevo el n%cmero...\n",163);
                getche();
                    }
                } while ((maxx < 1) || (maxx > 999999));

        for (int i=0;i<strlen(nom);i++) if (nom[i]==' ') nom[i]='_';
	    for (int i=0;i<strlen(fam);i++) if (fam[i]==' ') fam[i]='_';
        for (int i=0;i<strlen(udm);i++) if (udm[i]==' ') udm[i]='_';
        Graba objeto_graba(clave, nom, fam, udm, pu, in, ac, minn, maxx);
        objeto_graba.grabar();   
    }
}
//------------------------------------------//  
void menu(){
    int op = -1;
    while(op !=0){
        system("cls");
        printf("---------------------------------------\n");
        printf("-------MENU ARCHIVOS DE PRODUCTOS------\n");
        printf("1) Alta de productos\n"); 
        printf("2) Baja productos obsoletos\n");
        printf("3) Consulta productos por clave\n");
        printf("4) Consulta productos por familia\n");
        printf("0) terminar\n");
        printf("---------------------------------------\n");
        printf("Indica la opci%cn deseada : ",162);scanf("%d",&op);gets(falso);
        if ((op < 0)||(op > 4)){
			printf("Error, opci%cn fuera de rango entre 0 y 4 ...\n",162);
			getche();    
        }else{
            switch(op){
                case 0:
                    system("cls");
                    printf("Programa Finalizado...\n");
                    break;
                case 1:
                    system("cls");
                    pide_datos();
                    break;
                case 2:
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    break;
 
            }
        }
    }


}


main(){
    menu();
}