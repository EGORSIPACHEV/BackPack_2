//
//  main.cpp
//  BackPack_2
//
//  Created by Егор Сипачев on 20.04.2022.
//

#include <iostream>

using namespace std;
namespace fs = filesystem;

int solve(int n, vector<int> values, vector<int> weights, int W) {
    vector<int> memo1(W+1, 0); //буфер 1
    vector<int> memo2(W+1, 0); // буфер 2
    for (int i = 1; i <= n; i++) { //первый итерационный цикл
        vector<int> temp = memo1;
        memo1 = memo2;
        memo2 = temp;//темпорари переменная для сортировки
        for (int j = 0; j <= W; j++) {
            memo2[j] = memo1[j];
            if (j - weights[i - 1] >= 0) {
                memo2[j] = max(memo2[j], memo1[j - weights[i-1]] + values[i-1]); //выбираем максимальные из полседующих
            }
        }
    }
    int result = 0; //задаем результат минимальным
    for (int i = W; i >= 0; i--) { //цикл уменьшаем, так как нужно идти в обратную сторону
        if(memo2[i] != 0) {
            result = memo2[i]; //находим результирующую, это будет максимальный элемент из последующих
            break;
        }
    }
    return result;
}


int main(int argc, const char * argv[]) {
    string path = "";
           auto it = fs::directory_iterator(path);
    vector<path> array_path;
    copy_if(fs::begin(it), fs::end(it), std::back_inserter(array_path),[](const auto& entry) { //копируем из файла в буфер программы
                   return fs::is_regular_file(entry);
           });
    for (auto& p : array_path) { //инициализация типа ссылки в итерации
            ifstream fin;
            fin.open(p.string());
            cout << p.string() << endl;
            int n, W;
            fin >> n >> W;
            vector<int> values;
            vector<int> weights;
            for (int i = 0; i < n; i++) {
                int value, weight;
                fin >> value >> weight;//считываем из файла
                values.push_back(value);
                weights.push_back(weight);
            } //составление матрицы
            int max_value = solve(n, values, weights, W);
            cout << max_value << endl;
        }
    return 0;
}
