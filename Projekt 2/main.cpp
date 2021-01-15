#include <iostream>
#include <time.h>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

int generator_Liczb(int tablica[],int n)//Funkcja generująca pseudolosowe liczby
{
    ofstream plik("dane.txt"); //Otwarcie pliku "dane.txt" do zapisu
//Generator liczb pseudolosowych
    srand(time(NULL));

    for(int i=0; i<n; i++)
    {
        tablica[i]=rand()%101;
        plik<<tablica[i]<<" "; //Zapis wygenerej tablicy do pliku
    }
    return tablica[n]; //Zwrócenie tablicy
}

void wczytanie_z_pliku(int tablica[],int n) //Funkcja wczytująca dane  zpliku
{
    fstream plik; //zadeklarowanie pliku do odczytu
    plik.open("dane.txt");
    if(plik.good()==false) //Sprawdzenie czy plik istnieje
    {
        cout<<"Plik dane.txt nie istnieje"<<endl;
    }
    for(int i=0; i<n; i++) //Zapis tablicy do pliku
    {
        plik>>tablica[i];
    }
}

void zapis_do_pliku(int tab[],int tab_przedsort[],int n) //Funkcja zapisująca dane do pliku
{
    ofstream zapis; //Otwarcie pliku zapis "wynik.txt"
    zapis.open("wynik.txt");
    zapis<<"Po sortowaniu: ";
    for(int i=0;i<n;i++) //Wypisanie tablicy po posortowaniu
    {
        zapis<<tab[i];
        zapis<<" ";
    }
    zapis<<endl;
    zapis<<"Przed sortowaniem: ";
    for(int j=0;j<n;j++) //Wypisanie tablicy przed sortowaniem
        zapis<<tab_przedsort[j]<<" ";
   

}

void sortowanie_babelkowe(int tab[],int p) //Funkcja sortująca metoda bąbelkową
{
	for(int i=0;i<p;i++)    //Pętla zewnętrzna
		for(int j=1;j<p-i;j++) //Pętla wewnętrzna
		if(tab[j-1]>tab[j])
        swap(tab[j-1], tab[j]);  //Zamiana miejscami
        for(int i=0; i<p; i++) //Wypisanie tablicy na ekranie
        cout<<tab[i]<<" ";
}
void sortowanie_grzebieniowe( int tab[], int n ) //Funkcja sortująca grzebieniowo
{
    int gap = n; //Ustalam odstęp pomiędzy pierwszyn a ostatnim wyrazem
    bool replace = true;
    while( gap > 1 || replace ) //Jeśli odstęp jest większy niż jeden albo replace=true
    {
        gap = gap * 10 / 13; //Mnożymy gap przez 1.3
        if( gap == 0 )
             gap = 1;
        replace = false;
        for( int i = 0; i + gap < n; i++ )
        {
            if( tab[ i + gap ] < tab[ i ] ) //zamienia miejscami elementy o mniejszej wartosci
            {
                swap( tab[ i ], tab[ i + gap ] );
                replace = true;
            }
        }
    }
    for(int i=0; i<n; i++) //wypisujemy tablice
        cout<<tab[i]<<" ";
}


int main()
{
    int n, *tablica, i,k; //Deklaracja zmiennych

    cout<<"ile liczb chcesz posortowac ?"<<endl;
    cin>>n;
    tablica= new int [n];
    cout<<"1.Wczytaj liczby z pliku dane.txt"<<endl;
    cout<<"2.Wygenerowanie liczb i zapisanie do dane.txt"<<endl;
    cin>>k;
    //Wybor jaka metoda chcesz posortowac
    if(k==1)
    {
        wczytanie_z_pliku(tablica,n); //Wywołanie funkcji wczytanie_z_pliku
    }
    else if(k==2)
    {
        generator_Liczb(tablica,n); //Wyowołanie funkcji generator_Liczb
    }
    int tablica_przedsort[n];
    for(int j=0;j<=n;j++)
    {
        tablica_przedsort[j]=tablica[j]; //Stoworzenie tablicy z wartosciami tablicy przed posortowaniem
    }
    cout<<"Liczby to :"<<endl; //Wypisanie ciagu
    for(int l=0;l<n;l++)
        {
            cout<<tablica[l]<<" ";
        }
        //Wybor rodzaju sorotwoania
    cout<<endl<<endl;
    cout<<"-----Ktora metoda chcesz posortowac----"<<endl;
    cout<<"1.Babelkowa"<<endl;
    cout<<"2.Grzebieniowa"<<endl;
    cout<<endl<<endl;
    int wybor;
    cin>>wybor;
    if(wybor==1)
    {
    cout<<"Po posortowaniu babelkowym :"<<endl;
        sortowanie_babelkowe(tablica,n); // Wywołanie funkcji sortującej bąbelkowo
    }
    if(wybor==2)
    {
        cout<<"Po posortowaniu grzebieniowym :"<<endl;
        sortowanie_grzebieniowe(tablica,n); //Wywołąnie funkcji sortującej grzbietowo
    }
    zapis_do_pliku(tablica,tablica_przedsort,n); //Wywołanie funkcji zapisującej dane do pliku

    return 0;
}
