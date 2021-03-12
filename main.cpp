#include <iostream>
#include <fstream>





using namespace std;
int bledy;
int main()
{
    fstream plik;
    plik.open("dane_obrazki.txt", ios::in);

    int ile1 = 0;
    char poprawnyBit;
	int poprawny = 0;
	int naprawialny = 0;
	int nienaprawialny = 0;
	int zlakolumna, zlywiersz;
	
    while(!plik.eof()) 
	{

        string obraz[21];

        for(int i = 0; i < 21; i++) {
            plik >> obraz[i];
		}
		
		for(int i=0;i<20;i++)
	    {
	
	        for(int j=0;j<20;j++)
	        {
	            if(obraz[i][j]=='1') ile1++;
	            if(j == 19)
	            {
	
	                if(ile1 % 2 == 1)
	                {
	                    poprawnyBit = '1';
	                }
	                else
	                {
	                    poprawnyBit ='0';
	                }
	
	                if(poprawnyBit != obraz[i][20])
	                {
	                    zlywiersz++;
	                }
	
	                ile1=0;
	            }
	        }
	    }
	    
	    for(int i=0;i<20;i++)
	    {
	
	        for(int j=0;j<20;j++)
	        {
	
	            if(obraz[j][i] == '1') ile1++;
	            if(j == 19)
	            {
	                if(ile1 % 2 == 1)
	                {
	                    poprawnyBit ='1';
	                }
	                else
	                {
	                    poprawnyBit = '0';
	                }
	                if(poprawnyBit != obraz[20][i])
	                {
	                    zlakolumna++;
	                }
	                ile1=0;
	            }
	        }
	    }
	    
	    if(zlakolumna > 1 || zlywiersz > 1)
	    {
	        nienaprawialny++;
	    }
	    else if(zlakolumna > 0 || zlywiersz > 0)
	    {
	        naprawialny++;
	    }
	    else
	    {
	        poprawny++;
	    }
    }
	
    cout << "Znalezionio " << poprawny << " poprawnych\n";
    cout << "Znalezionio " << naprawialny << " naprawialnych\n";
	cout << "Znalezionio " << nienaprawialny << " nienaprawialnych\n";
    return 0;
}
