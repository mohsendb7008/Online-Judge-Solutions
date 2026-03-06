#include <iostream>
#include "FlowNetwork.cpp"

using namespace std;

int adjX[6]{0, 0, 0, 0, 1, -1};
int adjY[6]{0, 0, 1, -1, 0, 0};
int adjZ[6]{1, -1, 0, 0, 0, 0};

bool defective[10][10][10];

int main() {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            for (int z = 0; z < 10; z++) {
                defective[x][y][z] = false;
            }
        }
    }
    int n;
    cin >> n;
    while (n--) {
        int x, y, z;
        cin >> x >> y >> z;
        defective[x][y][z] = true;
    }
    FlowNetwork<> network(1002);
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            for (int z = 0; z < 10; z++) {
                if (defective[x][y][z]) {
                    network.addCapacity(0, 100 * x + 10 * y + z + 1, numeric_limits<int>::max());
                }
                for (int t = 0; t < 6; t++) {
                    const int i = x + adjX[t];
                    const int j = y + adjY[t];
                    const int k = z + adjZ[t];
                    if (i >= 0 && i < 10 && j >= 0 && j < 10 && k >= 0 && k < 10) {
                        network.addCapacity(100 * x + 10 * y + z + 1, 100 * i + 10 * j + k + 1, 1);
                    } else {
                        network.addCapacity(100 * x + 10 * y + z + 1, 1001, 1);
                    }
                }
            }
        }
    }
    cout << network.maxFlow(Node(0), Node(1001)) << endl;
}