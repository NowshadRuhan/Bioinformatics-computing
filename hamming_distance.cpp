#include<bits/stdc++.h>

using namespace std;

int hamming_distence(string str[], int n, int tt)
{
    int hamming = 0;
    for(int i=0; i<n; i++){

        int a=0, t=0, c=0, g=0;

        for(int j=0; j<tt; j++){


            if(str[j][i] == 'a'){
                a++;
            }
            else if(str[j][i] == 't'){
                t++;
            }
            else if(str[j][i] == 'c'){
                c++;
            }
            else if(str[j][i] == 'g'){
                g++;
            }
        }
        hamming+= (tt-max(a,max(t,max(c,g))));


    }

    cout<<"Hamming Distence : "<<hamming;

}



int main()
{
    int n, tt;
    cin>>n>>tt;
    string str[tt];
    for(int i=0; i<tt; i++)
    {
        cin>>str[i];
    }

    hamming_distence(str, n, tt);

}

/*
3 5
cag
aag
caa
caa
caa
*/
