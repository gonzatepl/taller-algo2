#include <vector>
#include <set>
#include <map>
#include "algobot.h"

using namespace std;

//Funciones Auxiliares

int cantidadApariciones(vector<int> s, int a){
    int res = 0;
    for (int i=0; i<s.size(); i++){
        if (s[i] == a){
            res++;
        }
    }
    return res;
}

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    vector<int> res;
    for (int i=0; i<s.size(); i++){
        if(cantidadApariciones(res, s[i])==0){
            res.push_back(s[i]);
        }
    }
    return vector<int>(res);
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> set_a;
    for (int i = 0; i < s.size(); i++) {
        set_a.insert(s[i]);
    }
    vector<int> res;
    for(int x: set_a){
        if(cantidadApariciones(res, x)==0){
            res.push_back(x);
        }
    }
    return vector<int>(res);
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> set_a;
    set<int> set_b;
    bool res= true;
    for (int i=0;i<a.size();i++){
        set_a.insert(a[i]);
    }
    for (int j=0;j<b.size();j++){
        set_b.insert(b[j]);
    }
    for(int x:set_b){
        if(!set_a.count(x)==1){
            res = false;
        }
    }
    for(int y:set_a){
        if(!set_b.count(y)==1){
            res = false;
        }
    }
    return res;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    return mismos_elementos(a, b);
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> m;
    for (int i=0; i<s.size();i++){
        if(m.count(s[i])>0){
            m[s[i]]++;
        }else{
            m[s[i]] = 1;
        }
    }
    return map<int, int>(m);
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res = vector<int>();
    for(int x:s){
        if(cantidadApariciones(s,x)==1){
            res.push_back(x);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res = set<int>();
    for(int x: a){
        if(b.count(x)==1){
            res.insert(x);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> m;
    for(int x:s){
        int digMenosSig=x%10;
        m[digMenosSig].insert(x);
    }
    return map<int, set<int>>(m);
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    map<char, char> m;
    //Paso tr a diccionario. Ver que forma produce mejor complejidad, entre esta y la de calcularlo así como está
    for(pair<char, char> x: tr){
        m[x.first]=x.second;
    }
    vector<char> res;
    for(int i=0;i<str.size();i++){
        if(m.count(str[i])){
            res.push_back(m[str[i]]);
        }else{
            res.push_back(str[i]);
        }
    }
    return vector<char>(res);
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    bool res = false;
    //La idea es ver si una misma libreta aparece en dos (o más) mails que tengan distinto conjunto de libretas.
    //Tomamos uno como base, y vamos comparando a partir de ese (como haciendo "recursion" sobre la secuencia 's' de mails)
    if(s.size()>0){
        int i=0;
        while(i<s.size()-1){
            set<LU> libretasMail = s[i].libretas();
            for(int j=i+1;j<s.size();j++){
                for (LU ls : s[j].libretas()){
                    if(libretasMail.count(ls)==1 && libretasMail != s[j].libretas()){
                        res = true;
                    }
                }
            }
            i++;
        }
    }
    return res;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    for(int i=0;i<s.size();i++){
        if(res[s[i].libretas()].fecha() < s[i].fecha() && s[i].adjunto()){
            res[s[i].libretas()] = s[i];
        }
    }
    return map<set<LU>, Mail>(res);
}
