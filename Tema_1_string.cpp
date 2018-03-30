/// Alexandru Andrei Sorin
#include <iostream>
#include<fstream>
#include<string.h>
#include<vector>
using namespace std;

int main()
{
    ifstream fin("date.in");
    char a[100][2],b[100][100],v[100][100],finale[100],acum;
    int n,m,i,j,gasit;
    vector<char> finale2;
    /// cout<<"Cate muchii sunt: ";
    fin>>n;
    ///  cout<<"Creare automat incepand cu nodul start [nod,nod,muchie]:"<<endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<2; j++)
            fin>>a[i][j];
        fin.get();
        fin.get(b[i],100);
        fin.get();
    }
///   cout<<"Introduceti nodurile finale: ";
    fin.get(finale,100);
    ///cout<<"Introdu nr de cuv citite";
    fin>>m;
///   cout<<"Introdu cuvantul: "
    fin.get();
    for(i=0; i<m; i++)
    {
        fin.get(v[i],100);
        fin.get();
    }

    acum=a[0][0];
    for(i=0; i<m; i++)
    {
        gasit=0;
        for(j=0; j<n; j++)
        {
            if(acum == a[j][0])
                if(!strcmp(b[j],v[i]))
                {
                    acum=a[j][1];
                    gasit=1;
                    j=n;
                }

        }
        if(!gasit)
        {
            cout<<"EROARE";
            return 0;
        }
    }
    j=0;
    for(i=0; finale[i]!='\0'; i++)
    {
        j++;
        finale2.push_back(finale[i]);
    }
    for(i=0; i<j; i++)
        if(acum == finale2[i])
        {
            cout<<"ACCEPTAT";
            return 0;
        }
    cout<<"NEACCEPTAT";

}
