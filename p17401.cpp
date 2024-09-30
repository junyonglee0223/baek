#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int>> matrix;

const int MOD = 1000000007;

matrix mat_multi(matrix a, matrix b){
    int n = a.size();
    matrix ret(n, vector<int>(n, 0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++){
                ret[i][j] = (ret[i][j] + 1LL*a[i][k]*b[k][j])%MOD;
            }
        }
    }
    return ret;
}


matrix mat_pow(matrix x, int s){
    int n = x.size();
    matrix ret(n, vector<int>(n, 0));
    for(int i = 0; i<n; i++)
        ret[i][i] = 1;

    matrix tmp = x;

    while(s > 0){
        if(s%2 == 1){
            ret = mat_multi(ret, tmp);
        }
        tmp = mat_multi(tmp, tmp);
        s/=2;
    }
    return ret;
}


int main(){
    int T, N, D;
    cin>>T>>N>>D;
    vector<matrix>graph_time;
    
    for(int i = 0; i<T; i++){
        matrix tmp(N, vector<int>(N, 0));
        int m; cin>>m;
        for(int j = 0; j<m; j++){
            int a, b, c; cin>>a>>b>>c;
            a--, b--;
            tmp[a][b] = c;
        }
        graph_time.push_back(tmp);
    }

    matrix ret(N, vector<int>(N, 0));
    for(int i = 0; i<N; i++)
        ret[i][i] = 1;

    int route = D / T;
    int rest = D % T;

    matrix part = graph_time[0];
    for(int i = 1; i<T; i++){
        part = mat_multi(part, graph_time[i]);
    }
    ret = mat_multi(ret, mat_pow(part, route));


    for(int i = 0; i<rest; i++){
        ret = mat_multi(ret, graph_time[i]);
    }
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }

}