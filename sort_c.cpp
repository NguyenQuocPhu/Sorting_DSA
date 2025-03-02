#include <bits/stdc++.h>
using namespace std;
vector <int> a;
int SIZE = 1e6;
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // Lấy liên tiếp 10 test để kiểm tra
    for(int test = 1 ; test <= 10 ; test++){
        string filename = "test_" + to_string(test) + ".txt";
        freopen(filename.c_str(), "r", stdin);
        // Lấy dữ liệu từ trong file
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 1 ; i <= SIZE; i++){
            int x; cin>>x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        // Sử dụng hàm sort có sẵn của C++
        auto end = std::chrono::high_resolution_clock::now();
        a.clear();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        // Tính thời gian chạy của mỗi file 
        std::cout << "Runtime "<<test<<": "<< elapsed.count() << " ms" << std::endl;
    }
    return 0;
}
