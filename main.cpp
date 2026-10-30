bool f(const Grafo& g, int x){
    int n=g.n();
    bool x_ha_almeno_1_entrante=false;
    for (int i=0; i<n; i++){
        if (g(i, x)){
            x_ha_almeno_1_entrante=true;
            break;
        }
    }
    if (x_ha_almeno_1_entrante){
        vector<int> visitati(n, 0);
        queue<int> coda;
        visitati[x]=1;
        coda.push(x);
        while (!coda.empty()){
            int primo=coda.front();
            coda.pop();
            if (g(primo, x) && primo!=x) return true;
            for (int v=0; v<n; v++){
                if (g(primo, v) && visitati[v]==0){
                    visitati[v]=visitati[primo]+1;
                    coda.push(v);
                }
            }
        }
    }
    return false;
}

