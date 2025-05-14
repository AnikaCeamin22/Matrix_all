#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> matrix;
    int mod=1e9+7;

matrix multi(matrix& a, matrix& b)
{
        matrix c(2,vector<int>(2,0));

        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                for(int k=0; k<2; k++){
                    c[i][j]= (c[i][j]+(1LL*a[i][k]*b[k][j])%mod) % mod;
                }
            }
        }
        return c;
}

matrix power(matrix& a, int b)
{
        if(b==0)
        {
            matrix I(2,vector<int>(2,0));
            for(int i=0; i<2; i++) I[i][i]=1;
            return I;
        }

        matrix half=power(a,b/2);
        matrix ans=multi(half,half);
        if(b%2==1)  ans=multi(ans,a);
        return ans;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n == 0) {
        cout << "Fibonacci(" << n << ") = 0" << endl;
        return 0;
    }

    matrix T = {{1, 1}, {1, 0}};
    matrix mat = {{1}, {0}}; // Base case matrix: F(1) = 1, F(0) = 0

    //n=T^(n-1)*base

    matrix Tn = power(T, n - 1);
    matrix result = multi(Tn, mat);

    cout << "Fibonacci(" << n << ") = " << result[0][0] << endl;
    return 0;
}
