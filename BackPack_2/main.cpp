//
//  main.cpp
//  BackPack_2
//
//  Created by Егор Сипачев on 20.04.2022.
//

#include <iostream>

using namespace std;
//Жадный алгоритм, один внутри другого, нужно отсортировать по весу и соответствующему индексу
/*
Arrays.sort(tasks); //сортируем по убыванию стоимости
TreeSet<Integer> time = new TreeSet<Integer>();
for (int i = 1; i <= n; ++i) {
  time.add(i);
}
int ans = 0;
for (int i = 0; i < n; ++i) {
  Integer tmp = time.floor(tasks[i].time);
  if (tmp == null) { // если нет свободного места в расписании, то в конец
  time.remove(time.last());
  } else { //иначе можно выполнить задание, добавляем в расписание
    time.remove(tmp);
    ans += tasks[i].cost;
  }
}
 */
/*Алгоритм:
 - Задать два массива, с индексами и весами
 - Пустить цикл внутри цикла, передавая соответствующий индекс
 - Найти результат посредствам сравнения
 */

int solve(int n, vector<int> values, vector<int> weights, int W) {
    vector<int>; memo1(W+1, 0); //буфер 1
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
    // insert code here...
    std::cout << "Hello, World!\n";
    //jkjk
    
    string path = "";
           auto it = fs::directory_iterator(path);
           vector<fs::path> array_path;
           copy_if(fs::begin(it), fs::end(it), std::back_inserter(array_path),           [](const auto& entry) { //копируем из файла в буфер программы
                   return fs::is_regular_file(entry);
           });
    
    return 0;
}
