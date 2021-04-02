#include <bits/stdc++.h>
using namespace std;

const int max_dimension = 300;

int n, m, number_of_rotations;
long matrix[max_dimension][max_dimension];

// Helper arrays to make iterating edge of an sub-matrix easier:
int adjR[4]{1, 0, -1, 0}; // Down, Right, Up, Left
int adjC[4]{0, 1, 0, -1};

// There are independent solutions for layers of the matrix!
// Solving sub-problem with sub-matrix of matrix[ln:rn][lm:rm]:
void solve(int ln, int rn, int lm, int rm){
    if(ln >= rn || lm >= rm)
        return;
    // Number of effective (non-redundant) rotations of a layer is bounded to number of cells in that layer: (bounded to O(n + m))
    int number_of_effective_rotations = number_of_rotations % (2 * (rn - ln + 1) + 2 * (rm - lm + 1) - 4);
    while(number_of_effective_rotations--){
        int iterator_i = ln, iterator_j = lm, iterator_dir = 0;
        long buffer = matrix[iterator_i][iterator_j];
        while(true){
            int next_i = iterator_i+adjR[iterator_dir], next_j = iterator_j+adjC[iterator_dir];
            // Boundary checking:
            if(next_i >= ln && next_i <= rn && next_j >= lm && next_j <= rm){
                // Shifting:
                long temporary = matrix[next_i][next_j];
                matrix[next_i][next_j] = buffer;
                buffer = temporary;
                iterator_i = next_i, iterator_j = next_j;
            }
            else if(iterator_dir < 3) // Let's take a turn
                iterator_dir++;
            else // We're all done!
                break;
        }
    }
    // Let's solve the nearest inner layer:
    solve(ln+1, rn-1, lm+1, rm-1);
}

int main(){
    cin >> n >> m >> number_of_rotations;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];
    // O(n * m * (n + m)) is ok for n, m <= 300
    solve(0, n-1, 0, m-1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}