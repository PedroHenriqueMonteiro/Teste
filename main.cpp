#include <iostream>
#include <stdio.h>
#include <math.h>


using namespace std;
double exp(double x);


int main(){

    int TAMANHO = 200;
    double Ez[TAMANHO] = {0.};
    double Hy[TAMANHO] = {0.};
    double N0 = 377.0;
    int Tempo; // Intervalo de tempo
    int TempoMaX = 250; // Número total de etapas da simulação
    int mm;

    for (Tempo = 0; Tempo< TempoMaX; Tempo++){

        // Atualização do Campo Magnético
        for (mm = 0; mm< TAMANHO-1; mm++)
            Hy[mm] = Hy[mm] + ((Ez[mm+1]-Ez[mm])/N0);

       // Atualização do Campo Elétrico
            for (mm=1; mm< TAMANHO;mm++)
                Ez[mm] = Ez[mm] +((Hy[mm+1]-Hy[mm])*N0);

            Ez[0] = exp(-(Tempo-30)*(Tempo-30)/100);

              cout << Ez[50]; cout <<  endl;

              }
return 0;
}

