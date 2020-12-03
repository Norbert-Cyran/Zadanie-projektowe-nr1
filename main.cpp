#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int Szukaj(int n, int t[], int k)//Funkcja szukajaca od poczatku tablicy 0 ktore po zastapieniu jedynka da najdluzszy ciag
{
    int max_licznik=0;//max_licznik bedzie okreslal najdluzszy ciag jedynek

    for(int i=0; i<n; i++) //przechodzimy przez wszystkie warianty tablic
    {
        int t1[n]; //tworzymy nowa tablice taka sama jak t[]
        for(int p=0; p<n; p++)
            t1[p]=t[p];
        t1[i]=1;  //w nowej tablicy wstawiamy 1 w i-te miejsce

        int licznik = 0;

        for(int j=0; j<n; j++) //sprawdza od poczatku który ciag jedynek jest najwiekszy w tej tablicy ktora aktualnie analizujemy
        {
            if(t1[j] == 1)
            {
                licznik++;
                if(licznik > max_licznik)
                {
                    max_licznik = licznik;
                    k=i;
                }


            }
            else if(t1[j] == 0)
            {
                licznik = 0;

            }
        }
    }
    return k;
}
int Szukaj2(int n, int t[], int k)//Funkcja szukajaca od konca tablicy 0 ktore po zastapieniu jedynka da najdluzszy ciag
{
    int max_licznik=0;//max_licznik bedzie okreslal najdluzszy ciag jedynek

    for(int i=0; i<n; i++) //przechodzimy przez wszystkie warianty tablic
    {
        int t1[n]; //tworzymy nowa tablice taka sama jak t[]
        for(int p=0; p<n; p++)
            t1[p]=t[p];
        t1[i]=1;  //w nowej tablicy wstawiamy 1 w i-te miejsce

        int licznik = 0;

        for(int j=n; j>0; j--) //sprawdza od konca który ciag jedynek jest najwiekszy w tej tablicy ktora aktualnie analizujemy
        {
            if(t1[j] == 1)
            {
                licznik++;
                if(licznik > max_licznik)
                {
                    max_licznik = licznik;
                    k=i;

                }


            }
            else if(t1[j] == 0)
            {
                licznik = 0;

            }
        }
    }
    return k;

}
int main()
{
    fstream out;
    out.open("wyniki.txt",ios::out);//Wyniki beda zapisywac sie w pliku tekstowym "wyniki"
    int *t, i, n;
    int k=0;//k bedzie okreslalo w ktore miejsce trzeba wstawic 1 by ciag jedynek byl najdluzszy
    int odpowiedz;
    cout<<"Czy chcesz wprowadzic recznie elementy tablicy? W przeciwnym razie program wylosuje je za Ciebie (tak/nie)"<<endl;
    cout<<"Wpisz 1 aby wybrac reczne wprowadzanie."<<endl;
    cout<<"Wpisz 2 aby wybrac losowanie zawartosci tablicy."<<endl;
    cout<<"Wpisz 3 aby wczytac dane z pliku tekstowego. Plik powinien zawierac wartosci oddzielone ENTEREM."<<endl;
    cin>>odpowiedz;
    switch(odpowiedz)
    {
    case 1:
    {
        cout<<"Podaj liczbe elementow tablicy: ";
        cin>>n;
        t=new int[n];
        for(int i=0; i<n; i++)//Petla pozwalajaca na wpisanie wartosci do tabeli
        {
            cout<<"Podaj "<<i+1<<" element tablicy (tylko 0 i 1): ";
            cin>>t[i];
        }
        for(int i=0; i<n; i++)//Petla wypisujaca tabele
        {
            cout<<t[i]<<" ";
            out<< t[i]<<" ";
        }
        cout<<endl<<"Aby ciag jedynek byl najdluzszy nalezy zastapic 0 pod indeksem: "<< Szukaj(n,t,k);//Wywolanie funkcji Szukaj
        out<<endl<<"Aby ciag jedynek byl najdluzszy nalezy zastapic 0 pod indeksem: "<< Szukaj(n,t,k);//Zapisanie wynikow do pliku
        if(Szukaj2(n,t,k)!= Szukaj(n,t,k))//Warunek sprawdzajacy czy sa 2 mozliwosci utworzenia najdluzszego ciagu
        {
            cout<<" albo: " <<Szukaj2(n,t,k)<<endl;
            out<<" albo: " <<Szukaj2(n,t,k)<<endl;
        }
        break;
    }
    case 2:
    {
        cout<<"Podaj liczbe elementow tablicy: ";
        cin>>n;
        srand(time(NULL));
        t=new int[n];
        for (int i=0; i<n; i++)
            t[i]=rand()%2;//Funkcja losujaca w zakresie od 0 do 1
        for(int i=0; i<n; i++)
        {
            cout<< t[i]<<" ";
            out<< t[i]<<" ";
        }
        cout<<endl<<"Aby ciag jedynek byl najdluzszy nalezy zastapic 0 pod indeksem: "<< Szukaj(n,t,k);//Wywolanie funkcji Szukaj
        out<<endl<<"Aby ciag jedynek byl najdluzszy nalezy zastapic 0 pod indeksem: "<< Szukaj(n,t,k);//Zapisanie wynikow do pliku
        if(Szukaj2(n,t,k)!= Szukaj(n,t,k))//Warunek sprawdzajacy czy sa 2 mozliwosci utworzenia najdluzszego ciagu
        {
            cout<<" albo: " <<Szukaj2(n,t,k)<<endl;
            out<<" albo: " <<Szukaj2(n,t,k)<<endl;
        }
        break;
    }
    case 3:
    {
        int t[500] = {0};//Deklaracja tablicy o wielkosci 500 i wyzerowanie jej
        int tmp = 0;//Tmp to dodatkowa zmienna ktora pomaga wpisac wartosci z pliku do tablicy
        fstream in;
        string plik;
        cout<<"Podaj nazwe pliku lub jego sciezke: ";
        cin>>plik;
        in.open(plik,ios::in);//Otwarcie pliku
        if(in.good()==false)
        {
            cout<<"Nie mozna znalezc pliku.";
        }
        else
        {
            while (!in.eof())//Petla while wykonuje sie dopoki nie dotrze do konca pliku
                in >> t[tmp++];

            in.close();

            for (int i=0; i<tmp; i++)
            {
                cout << t[i]<<" ";
                out << t[i]<<" ";
            }
            cout<<endl<<"Aby ciag jedynek byl najdluzszy nalezy zastapic 0 pod indeksem: "<< Szukaj(10,t,k);//Wywolanie funkcji Szukaj
            out<<endl<<"Aby ciag jedynek byl najdluzszy nalezy zastapic 0 pod indeksem: "<< Szukaj(10,t,k);//Zapisanie wynikow do pliku
            if(Szukaj2(10,t,k)!= Szukaj(10,t,k))//Warunek sprawdzajacy czy sa 2 mozliwosci utworzenia najdluzszego ciagu
            {
                cout<<" albo: " <<Szukaj2(10,t,k)<<endl;
                out<<" albo: " <<Szukaj2(10,t,k)<<endl;
            }
        }

    }
    break;
    default:
    {
        cout<<"Niepoprawna odpowiedz"<<endl;
        break;
    }


    out.close();
    delete [] t;
    getchar();
    return 0;
    }
}
