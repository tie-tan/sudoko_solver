#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<long long, long long>
#define no cout<<"NO"<<endl;
#define yes cout<<"YES"<<endl;
#define f(i,x,y); for(long long i=x;i<y;i++)
const double pi = 3.14159265358979323846;
const int MOD = 1e9 + 7;
#define N 9


int row[N], col[N], box[N];
bool seted = false;


int getBox(int i,int j)
{
    return i / 3 * 3 + j / 3;
}

bool isSafe(int i,int j,int number)
{
    return !((row[i] >> number) & 1)
        && !((col[j] >> number) & 1)
        && !((box[getBox(i,j)] >> number) & 1);
}


void setInitialValues(int grid[N][N])
{
    for (int i = 0; i < N;i++)
        for (int j = 0; j < N; j++)
                row[i] |= 1 << grid[i][j],
                col[j] |= 1 << grid[i][j],
                box[getBox(i, j)] |= 1 << grid[i][j];
}


bool SolveSudoku(int grid[N][N] ,int i, int j)
{
    // Set the initial values
    if(!seted)
        seted = true,
        setInitialValues(grid);

    if(i == N - 1 && j == N)
        return true;
    if(j == N)
        j = 0,
        i++;

    if(grid[i][j])
        return SolveSudoku(grid, i, j + 1);

    for (int nr = 1; nr <= N;nr++)
    {
        if(isSafe(i, j, nr))
        {
            
            
            grid[i][j] = nr;
            row[i] |= 1 << nr;
            col[j] |= 1 << nr;
            box[getBox(i, j)] |= 1 << nr;

            if(SolveSudoku(grid, i,j + 1))
                return true;

           
            row[i] &= ~(1 << nr);
            col[j] &= ~(1 << nr);
            box[getBox(i, j)] &= ~(1 << nr);
        }

        grid[i][j] = 0;
    }

    return false;
}

void print(int grid[N][N])
{
    for (int i = 0; i < N; i++, cout << '\n')
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << ' ';
}


void sol()
{
    
    int grid[N][N] ;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>grid[i][j];
        }
    }

    if (SolveSudoku(grid,0 ,0))
        print(grid);
    else
        cout << "No solution exists"<<endl;;

    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long Test=1;
    //cin>>Test;
    ll T=1;
    while(Test>=T)
    {
           // cout<<"Case #"<<T<<":"<<" ";
            sol();
            T++;
    }
    return 0;
}
