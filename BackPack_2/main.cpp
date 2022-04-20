//
//  main.cpp
//  BackPack_2
//
//  Created by Егор Сипачев on 20.04.2022.
//

#include <iostream>


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
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //jkjk
    return 0;
}
