#include<iostream>  
#include<conio.h>
#include<math.h>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include <iomanip>
#include <cstring>

using namespace std;



struct Fiestas
{
    string FechaFiesta;
    string FMTipomenu1;
    string FMTipomenu2;
    string Fiestas;
    int cantidad;
    int menu;
    int MaxPersonasMenu1;
    int MaxPersonasMenu2;
    int Cantidadc;
    int cantidads;
    int cantidadO;
};


/*
Ejercicio 9:
Una Empresa dedicada a realizar servicios para fiestas, nos pide la confección
de un programa que les permita obtener algunos datos estadísticos procesando
la información que tienen de las fiestas que se van a realizar.
Para ello ingresan la siguiente información ya validada:
- Fecha de la fiesta (string)
- Tipo de fiesta (.C., .S., .O.)
- Cantidad de personas (Entero)
- Nro de menú elegido (1, ó 2)
Se pide:
a) Informar cuantas fiestas hay de cada tipo.
b) Para cada tipo de menú, la fecha para la cuál se realizará la fiesta con mayor
cantidad de personas (suponer único máximo)
c) El promedio de personas de todas las fiestas.
d) Considerar como debería venir la información si se pidiese informar la
Cantidad total de personas y de fiestas por cada día. (Por Ejemplo:)
Para el día 03/05/2006 se contabilizaron un total de 560 personas en 4 fiestas.
Para el día 04/05/2006 se contabilizaron un total de 305 personas en 2 fiestas.
*/



void PedirFecha(string &Fecha){
    fflush(stdin); //vacia memoria 
    cout<<"Ingrese fecha de fiesta: "<<endl;
	getline(cin, Fecha);
}

void PedirDato(string &fiesta,int &cantidadPersonas,int &Nmenu){
    fflush(stdin); //vacia memoria 
    bool Tfiesta = true;
        cout<<"Ingresar tipo de fiesta las opciones son c,s,o"<<endl;
        cin>>fiesta;
        if (fiesta == "c" || fiesta == "s" || fiesta == "o")
        {
            //No hace nada, esta bien 
        }else{
            while (Tfiesta)
            {
                cout<<"Ingreso un valor invalido"<<endl;
                cout<<"Ingresar tipo de fiesta las opciones son c,s,o"<<endl;
                cin>>fiesta;
                if (fiesta == "c" || fiesta == "s" || fiesta == "o")
                {
                    Tfiesta = false;
                }
                
            }
            
        }
        
        cout<<"Cantidad de personas: "<<endl;
        cin>>cantidadPersonas;
        cout<<"Elija el numero del menu (1 o 2): "<<endl;
        cin>>Nmenu;
        while (1>Nmenu || Nmenu>2)
        {
            cout<<"Ingreso un valor invalido de menu. "<<endl;
            cout<<"Elija el numero del menu (1 o 2): "<<endl;
            cin>>Nmenu;
        }

    
}

void ComparaMax(string &Tfiesta, int &CantTfiestaC,int &CantTfiestaS,int &CantTfiestaO,int &Tmenu,string &Infecha, string &OutFecha1,string &OutFecha2,int &cantidadPersonas,int &OutMax1, int &OutMax2){
    if (Tfiesta == "c")
    {
        CantTfiestaC++;
    }else if (Tfiesta == "s")       
    {
        CantTfiestaS++;
    }else{
        CantTfiestaO++;
    }
    
if (Tmenu == 1)
{
    if (OutMax1<cantidadPersonas)
    {
        OutMax1 = cantidadPersonas;
        OutFecha1 = Infecha;
    }
    
}else
{
    if (OutMax2<cantidadPersonas)
    {
        OutMax2 = cantidadPersonas;
        OutFecha2 = Infecha;
    }
    
}

}

int main(int argc, char const *argv[])
{
    Fiestas fiesta;
    //variables
    fiesta.FechaFiesta= " ";
    fiesta.FMTipomenu1 = " ";
    fiesta.FMTipomenu2 = " ";
    string FechaActual=" ";
    fiesta.Fiestas=" ";
    fiesta.cantidad = 0;
    fiesta.menu;
    int Iterador = 0,CantidadXfecha,CantFiestas,cantTotalPersonas = 0;
    float Promedio = 0;
    fiesta.MaxPersonasMenu1 = 0;
    fiesta.MaxPersonasMenu2  = 0;
    fiesta.Cantidadc= 0;
    fiesta.Cantidads = 0;
    fiesta.cantidadO = 0;
    //variables
    PedirFecha(fiesta.FechaFiesta);

    while (fiesta.FechaFiesta != "f")
    {
        if (Iterador != 0)
        {
            cout<<"Para el dia: "<<FechaActual<<" Se contabilizaron un total de "<<CantidadXfecha<<" personas en "<<CantFiestas<<" Fiestas"<<endl;
        }
        CantidadXfecha = 0;
        CantFiestas = 0;
        FechaActual = fiesta.FechaFiesta;
        while (FechaActual == fiesta.FechaFiesta)
        {
            PedirDato(fiesta.Fiestas,fiesta.cantidad,fiesta.menu);
            CantFiestas++;
            CantidadXfecha += fiesta.cantidad;
            cantTotalPersonas += fiesta.cantidad;
            Iterador++;
            ComparaMax(fiesta);
            PedirFecha(fiesta.FechaFiesta);
        }
      

    }
        Promedio = (float)cantTotalPersonas/Iterador;
        cout<<"Fiestas de cada tipo"<<endl<<"Tipo fiesta C: "<<fiesta.Cantidadc<<" de fiestas"<<endl;
        cout<<"Tipo fiesta S: "<<fiesta.cantidads<<" de fiestas"<<endl;
        cout<<"Tipo fiesta S: "<<fiesta.cantidadO<<" de fiestas"<<endl;
        cout<<"La vez que vinieron mas personas con el menu 1 fueron: "<<fiesta.MaxPersonasMenu1<<" La fecha: "<<fiesta.FMTipomenu1<<endl;
        cout<<"La vez que vinieron mas personas con el menu 2 fueron: "<<fiesta.MaxPersonasMenu2<<" La fecha: "<<fiesta.FMTipomenu2<<endl;
        cout<<"El promedio de personas que participaron en todas las fechas fueron de: "<<Promedio<<endl;

    return 0;
}
