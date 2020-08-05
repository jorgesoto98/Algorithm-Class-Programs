/*
 Problema de la Mochila
 Tecnica: Backtracking
 Nombre: Jorge Soto
 Matricula: A01282936
 Clase: Analisis de algoritmos

 Error BadAccess
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct obj{
    int valor, peso, valpeso;
};

int PESO;
int vOptimo;
int n;

vector<obj> datos;
vector<bool> inc;
vector<bool> res;

bool my_cmp(const obj& a, const obj& b)
{
    return a.valpeso > b.valpeso;
}

void bt(int i, int va, int pa, int vp){
    if (i < n && pa <= PESO && vp>vOptimo)  {
        if (va > vOptimo) {
            vOptimo = va;
            res.clear();
            for (int j=0; i<n; j++) {
                res.push_back(inc[j]);
            }
        }
        // Si al siguente objeto
        inc[i+1] = true;
        bt(i+1, va+datos[i+1].valor, pa+datos[i+1].peso, vp);

        // No al siguente objeto
        inc[i+1] = false;
        int vpAux = va;
        int pesoAux = pa;
        int k = i+1;

        while (k<n && pesoAux + datos[k].peso <= PESO) {
            vpAux += datos[k].valor;
            pesoAux += datos[k].peso;
            k++;
        }

        if (k<n) {
            vpAux += ((PESO - pesoAux)*datos[k].valpeso);
        }

        bt(i+1, va, pa, vpAux);
    }
}

int main(){
    int v, p, vp;
    cin >> n >> PESO;
    for (int i=1; i<=n; i++){
        cin >> v >> p;
        vp = v/p;
        obj misDatos;
        misDatos.valor = v;
        misDatos.peso = p;
        misDatos.valpeso = vp;
        datos.push_back(misDatos);
        inc.push_back(false);
    }
    sort(datos.begin(), datos.end(), my_cmp);
    cout << endl << "Objetos Ordenados:"<<endl;
    for (int i=0; i<n; i++){
        cout << "Obj"<<(i+1)<<": "<<datos[i].valor<< " "<<datos[i].peso<<endl;
    }

    int vpAux = 0;
    int pesoAux = 0;
    int k = -1;
    while (k < n && pesoAux + datos[k+1].peso <= PESO){
        k++;
        vpAux += datos[k].valor;
        pesoAux += datos[k].peso;
    }
    k++;
    if (k < n){
        vpAux += ((PESO-pesoAux) * datos[k].valpeso);
    }

    bt(-1,0,0,vpAux);

    cout << endl << "Resultado: " << vOptimo << endl<<"Incluyendo los Obj: ";
    for (int i=0; i<n; i++){
        if (res[i]){
            cout << (i+1) << " ";
        }
    }
    cout << endl;
}

/*
 4 16
 10 5
 40 2
 50 10
 30 5
 */

/*
 4 10
 66 6
 50 5
 35 5
 18 3
 */
