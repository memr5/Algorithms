#include <iostream>

using namespace std;

void BinaryInsertion(int *v, int n)
{
    int i,j,temp,medio,izq,der;
    for (j = 1; j < n; j++)
    {   
        //Se declaran las variables de comparacion y la auxiliar para desplazar los valores ordenados
        temp=v[j];
        izq=0;
        der = j-1;
        //Se busca la posición de la inserción de forma binaria
        while (izq <= der)
        {
            medio = (int) ((izq + der)/2);
                if (temp <= v[medio])
                    der = medio-1;
                else
                    izq = medio+1;
        }
        //Los elementos ya ordenados de desplazan a la derecha(final)
        for (i = j-1; i>= izq; i--)
            v[i+1] = v[i];
        v[izq] = temp;  
    }
}

void mostrarDatos(int v[],int lim){//Se muestran los datos del vector
    int contador=1;
    for (int i = 0; i < lim; i++){
        cout<<"Valor del elemento No."<<contador<<": "<<v[i]<<endl;
        contador++;
    }
    
}

int main(){
    int n,x;
    //Apartado para ingresar el total de numeros del vector 
    cout<<"Ingresa el numero de elementos: ";
    cin>>n;
    /*Declaración del vector a ordenar*/
    int v[n];

    //Rellenado de vector
    for (int i = 0; i < n; i++){
        cout<<"Ingrese el elemento: ";
        cin>>x;
        v[i]=x;
    }


    cout<<"Valores no ordenados"<<endl;
    mostrarDatos(v,n);
    BinaryInsertion(v,n);
    cout<<"Valores ordenados"<<endl;
    mostrarDatos(v,n);
    return 0;
}
