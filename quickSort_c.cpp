#include <bits/stdc++.h>
using namespace std;
// Hàm random: Chọn một số ngẫu nhiên trong đoạn [l, r]
long long random(int l, int r) {
    return l + 1LL * rand() * rand() % (r - l + 1);
}

// Hàm quickSort: Sắp xếp mảng bằng thuật toán Quick Sort
void quickSort(vector<int>& a, int l, int r) {
    // Chọn phần tử pivot (điểm chốt) ngẫu nhiên trong khoảng [l, r]
    int p = a[random(l, r)];

    // Khai báo hai con trỏ i (bên trái) và j (bên phải)
    int i = l, j = r;

    // Phân đoạn mảng theo pivot
    while (i < j) {
        while (a[i] < p) {  // Duyệt từ trái, tìm phần tử >= pivot
            i++;
        }
        while (a[j] > p) {  // Duyệt từ phải, tìm phần tử <= pivot
            j--;
        }
        if (i <= j) {  // Nếu i và j chưa vượt qua nhau, hoán đổi phần tử
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    // Gọi đệ quy cho hai phần còn lại của mảng
    if (i < r) quickSort(a, i, r);  // Sắp xếp nửa bên phải
    if (l < j) quickSort(a, l, j);  // Sắp xếp nửa bên trái
}
vector <int> a;
int SIZE = 1e6;
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // Lấy liên tiếp 10 test để kiểm tra
    for(int test = 1 ; test <= 10 ; test++){
        // Lấy dữ liệu từ trong file
        string filename = "test_" + to_string(test) + ".txt";
        freopen(filename.c_str(), "r", stdin);
        auto start = chrono::high_resolution_clock::now();
        for (int i = 1 ; i <= SIZE; i++){
            int x; cin>>x;
            a.push_back(x);
        }
        quickSort(a, 0, a.size() -1 );
        auto end = chrono::high_resolution_clock::now();
        a.clear();
        // Tính thời gian chạy của mỗi file 
        chrono::duration<double, milli> elapsed = end - start;
        cout << "Runtime "<<test<<": "<< elapsed.count() << " ms" << endl;
    }
    return 0;
}
