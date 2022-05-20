//Victor Krieger Almeida

#include <iostream>
#include <string>

using namespace std;
const unsigned int MAXNOS = 100;

struct arco{
    bool une_no;
    float peso;
};

class GrafoComPeso
{
    private:
    arco adj[MAXNOS][MAXNOS];
    int N;
    
    public:
    GrafoComPeso(int num_nos);
    void une(int a, int b, float c);
    void remv(int a ,int b);
    bool adjacente(int a, int b);
    void imprime();
};

GrafoComPeso::GrafoComPeso(int num_nos){
    
    N = num_nos;
    int i , j;
    
    for(i=0; i <num_nos; i++)
        for(j = 0; j < num_nos; j++)
            adj[i][j].une_no = false;
            adj[i][j].peso = 0;
}

void GrafoComPeso::une(int a, int b, float c)
{
    if(a>= 0 && a < N && b >= 0 && b < N){
        adj[a][b].une_no = true;
        adj[a][b].peso = c;
    }
    else
        cout << endl << "pelo menos 1 no eh invalido!" << endl;
}

void GrafoComPeso::remv(int a, int b){
     if(a>= 0 && a < N && b >= 0 && b < N)
        adj[a][b].une_no = false;
    else
        cout << endl << "pelo menos 1 no eh invalido!" << endl;
}

bool GrafoComPeso::adjacente(int a, int b){
      if(a>= 0 && a < N && b >= 0 && b < N)
        return adj[a][b].une_no;
    else
        cout << endl << "pelo menos 1 no eh invalido!" << endl;
}

void GrafoComPeso::imprime()
{
    int i , j;
    cout<< endl << "-=-=-=-=-=-=-=MATRIZES-=-=-=-=-=-=-=-=" << endl;
    cout << "| |";
    
    for( i = 0; i < N; i++)
        cout << i << " ";
        
    for(i = 0; i < N; i++){
        cout<<endl << i << " ";
        for(j=0;j<N;j++)
            cout << adj[i][j].une_no << " ";
    }        
    cout<< endl << "-=-=-=-=-=-=-=-PESOS=-=-=-=-=-=-=-=" << endl;
    cout << "| |";
    
    for( i = 0; i < N; i++)
        cout << i << " ";
        
    for(i = 0; i < N; i++){
        cout<<endl << i << " ";
        for(j=0;j<N;j++)
            cout << adj[i][j].peso << " ";
    }
    cout << endl;
}
    
int main()
{
    string msg[] = {"N", "S"};
   GrafoComPeso meuGrafo(4);
    
    meuGrafo.imprime();
    meuGrafo.une(0,3,2);
    meuGrafo.une(1,2,3);
    meuGrafo.imprime();
    
    return 0;
    
    
}