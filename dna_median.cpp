#include<bits/stdc++.h>


using namespace std;
char ch[]={'a', 't', 'c', 'g'};
string str[100];
string best_motif[100];
int mn = 100000;

string best_combination;

int hamming_distence(string str[],int length_of_str,int how_many_str)
{
    int hamming = 0;
    for(int i=0; i<length_of_str; i++){

        int a=0, t=0, c=0, g=0;

        for(int j=0; j<how_many_str; j++){


            if(str[j][i] == ch[0]){
                a++;
            }
            else if(str[j][i] == ch[1]){
                t++;
            }
            else if(str[j][i] == ch[2]){
                c++;
            }
            else if(str[j][i] == ch[3]){
                g++;
            }
        }
        hamming+= (how_many_str-max(a,max(t,max(c,g))));


    }

    //cout<<"Hamming Distence : "<<hamming;
    return hamming;
}

void kmer_check(string ptn,int k_mer_length,int how_many_str,int length_of_str)
{
    string motif[how_many_str];
    for(int i=0; i<how_many_str; i++)
    {
        int mx = 0;
        for(int j=0; j<=length_of_str-k_mer_length; j++)
        {
            int cont = 0;
            string gen_temp="";
            for(int x=j; x<j+k_mer_length; x++)
            {
                if(str[i][x]== ptn[x-j])
                {
                    cont++;
                }
                gen_temp.push_back(str[i][x]);
            }

            if(cont>mx)
            {
                mx=cont;
                motif[i]=gen_temp;
            }

        }
    }
    int hamming = hamming_distence(motif , length_of_str, how_many_str);
    if(hamming < mn )
    {
        mn = hamming;

        for(int i=0; i<how_many_str; i++)
        {

            best_motif[i]=motif[i];
            best_combination = ptn;
        }
    }


}

void gen_k_mer_combination( string gen , int length, int k_mer_length, int how_many_str,
                           int length_of_str )
{
    if(length == k_mer_length ){
        //pattern.push_back(gen);
        kmer_check(gen, k_mer_length, how_many_str, length_of_str);
        return ;
    }
    string gen_temp;

    gen_temp=gen;
    gen_temp.push_back(ch[0]);
    gen_k_mer_combination(gen_temp, length+1, k_mer_length ,how_many_str, length_of_str);

    gen_temp=gen;
    gen_temp.push_back(ch[1]);
    gen_k_mer_combination(gen_temp, length+1, k_mer_length , how_many_str, length_of_str);

    gen_temp=gen;
    gen_temp.push_back(ch[2]);
    gen_k_mer_combination(gen_temp, length+1, k_mer_length, how_many_str, length_of_str );

    gen_temp=gen;
    gen_temp.push_back(ch[3]);
    gen_k_mer_combination(gen_temp, length+1, k_mer_length , how_many_str, length_of_str);

}

int main()
{
    int length_of_str, how_many_str, k_mer_length;

    cin>>length_of_str>>how_many_str>>k_mer_length;

    for(int i=0; i<how_many_str; i++)
    {
        cin>>str[i];
    }
    gen_k_mer_combination("", 0, k_mer_length, how_many_str, length_of_str);
    //hamming_distence(str, length_of_str, how_many_str);
    cout<<endl;
    cout<<"Median String : "<<endl;
    for(int i=0; i<how_many_str; i++)
    {
        cout<<best_motif[i]<<endl;
    }

     cout<<endl;
     cout<<"Best Motif for the combination best is : "<< best_combination<<endl;
    return 0;
}

/*
5 3 3
ataga
aatcc
gatgc


7 4 4
atagatt
aatccgt
gatgcac
cgtcaac

10 6 4
atctactacg
aagccgttgc
catggaccgt
cgtccacagc
gatgcacgac
cgtcaaccgc
*/

