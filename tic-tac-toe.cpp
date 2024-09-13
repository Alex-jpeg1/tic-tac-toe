#include<iostream>
#include<cstring>

using namespace std;

    char board[3][3];

    bool check(int poz)

    {

        int i=(poz-1)/3;

        int j=poz-3*i-1;

        if((poz>=10 || poz<=0) || board[i][j]!=(poz+'0'))

        return false;

        return true;

    }

    void update(char caracter,int poz)

    {

        int i=(poz-1)/3;

        int j=poz-3*i-1;

        board[i][j]=caracter;

    }

    bool check_winner(bool jucator,int dreapta[2][6],int stanga[2][6],int col[2][3],int rand[2][3],int poz)

    {

        int i=(poz-1)/3;

        int j=poz-3*i-1;

        dreapta[jucator][i+j]++;

        stanga[jucator][3+j-i]++;

        col[jucator][j]++;

        rand[jucator][i]++;

        if(dreapta[jucator][i+j]==3 || stanga[jucator][3+j-i]==3 || col[jucator][j]==3 || rand[jucator][i]==3)

            return true;

        else 

            return false;

    }
    void afis()
    {
        for(int i=0;i<3;i++)

            {

                cout<<'|'<<" ";

                for(int j=0;j<3;j++)

                    {

                        cout<<board[i][j]<<" | ";

                    }

            cout<<"\n--   --   --\n";

            }
    }
    void reset()
    {
         for(int i=0;i<3;i++)

            for(int j=0;j<3;j++)

            board[i][j]=3*i+j+'0'+1;

    }
int main()
{
    bool joc=true;

    bool jucator=true;

    char caracter='X';

    cout<<"X si 0\n";
    
    while(joc)
    {   
        reset();

        afis();
        int dreapta[2][6];

        int stanga[2][6];

        int col[2][3];

        int rand[2][3];

        memset(dreapta,0,sizeof(dreapta));

        memset(stanga,0,sizeof(stanga));

        memset(col,0,sizeof(col));

        memset(rand,0,sizeof(rand));

        bool continuati=true;

        int numar_mutari=1;

        while(numar_mutari<=9 && continuati)
        {
           if(jucator)

           cout<<"jucator 1\n";

           else cout<<"jucator 2\n";

            if(jucator)

            caracter='X';

            else caracter='0';

            int poz;

            cin>>poz;

            while(!check(poz))
            {
                cout<<"Pozitie invalida ,alegeti una diferita va rog\n";

                cin>>poz;
            }

            update(caracter,poz);

            afis();

            if(check_winner(jucator,dreapta,stanga,col,rand,poz))
            {
                cout<<"A castigat "<<(jucator?"jucatorul 1\n":"jucatorul 2\n");

                continuati=false;
            }

            jucator=1-jucator;

            numar_mutari++;
        }
        if(numar_mutari==10 && continuati)

            cout<<"Egalitate\n";

        cout<<"Jucati din nou? y/n\n";

        char c;

        cin>>c;

        joc=(c=='y')?1:0;

    }

    return 0;

}