#include<iostream>
#include <fstream>
#include<iomanip>
using namespace std;

//Creo la funzione rimappatura dei numeri presenti nel file di input
double rimappatura (double num){
    double nuovo_numero=((3./4.)*(num-1))-1 ;  // 3 indica la lunghezza dell'intervallo di output e 4 la lunghezza di quello di input
    return nuovo_numero;
}


int main(){

    // Apertura e lettura del file data.csv
    string nameFileI="data.csv";
    ifstream ifs("data.csv");
    if(ifs.fail()){ // Verifico se il file esiste
        cerr<<"Il file non esiste"<<endl;
        return 1;
    }
    int contatore=0;

    //Apertura e scrittura del file result.csv
    string nameFileO="result.csv";
    ofstream ofs("result.csv");
    if (ofs.is_open()){ // Verifico se il file è correttamente aperto
        ofs<<"# N Mean"<<endl;   // Intestazione del file in scrittura
        double somma=0;
        double media=0;
        while (!ifs.eof()){
            double num;
            ifs>>num;
            //cout<<"Il numero presente nel file e': "<<num<<" e il numero rimappato e': "<<rimappatura(num)<<endl;

            // Calcoliamo la media e la stampiamo nel file result.csv
            contatore++;
            somma+=rimappatura(num); // ossia somma=somma+rimappatura(num)
            media=somma/contatore;
            //cout<<contatore <<"   "<<scientific<<media<<endl;
            ofs<<contatore <<"  "<<setprecision(16)<<scientific<<media<<endl;
        }
        ifs.close();
        ofs.close();
    }

    return 0;
}





