#include <iostream>
#include <climits>


using namespace std;

class Stack {
private:
    int* arr_;          // указатель на массив
    int size_;          // текущий размер стека
    int capacity_;      // вместимость стека
    int min_;           // минимальное значение в стеке
    int max_;           // максимальное значение в стеке

public:
    Stack(int capacity) {
        arr_ = new int[capacity];
        size_ = 0;
        capacity_ = capacity;
        min_ = INT_MAX;
        max_ = INT_MIN;
    }

    ~Stack() {
        delete[] arr_;
    }

    bool empty() const {
        return size_ == 0;
    }

    void push(int val) {
        if (size_ == capacity_) {
            // бросаем исключение, если стек уже заполнен
            throw overflow_error("Stack overflow");
        }
        arr_[size_] = val;
        size_++;
        // обновляем минимальное и максимальное значения
        if (val < min_) {
            min_ = val;
        }
        if (val > max_) {
            max_ = val;
        }
    }

    void pop() {
        if (empty()) {
            // бросаем исключение, если стек уже пуст
            throw underflow_error("Stack underflow");
        }
        size_--;
        // если удаляем минимальное или максимальное значение,
        // нужно обновить соответствующую переменную
        if (arr_[size_] == min_) {
            min_ = INT_MAX;
            for (int i = 0; i < size_; i++) {
                if (arr_[i] < min_) {
                    min_ = arr_[i];
                }
            }
        }
        if (arr_[size_] == max_) {
            max_ = INT_MIN;
            for (int i = 0; i < size_; i++) {
                if (arr_[i] > max_) {
                    max_ = arr_[i];
                }
            }
        }
    }

    void top() const {
        if (empty()) {
            // бросаем исключение, если стек уже пуст
            throw underflow_error("Stack underflow");
        }
        cout << arr_[size_ - 1] << endl;
    }

    void pop_min() {
        if (empty()) {
            // бросаем исключение, если стек уже пуст
            throw underflow_error("Stack underflow");
        }
        int* temp_arr = new int[size_];
        int temp_size = 0;
        // копируем все элементы, кроме минимального
        for (int i = 0; i < size_; i++) {
            if (arr_[i] != min_) {
                temp_arr[temp_size] = arr_[i];
                temp_size++;
            }
        }
        // если удаляется минимальное значение,
        // нужно обновить соответствующую переменную

        min_ = INT_MAX;
        for (int i = 0; i < temp_size; i++) {
            if (temp_arr[i] < min_) {
                min_ = temp_arr[i];
            }
        }

        // обновляем массив и размер стека
        delete[] arr_;
        arr_ = temp_arr;
        size_ = temp_size;
    }

    void pop_max() {
        if (empty()) {
            // бросаем исключение, если стек уже пуст
            throw underflow_error("Stack underflow");
        }
        int* temp_arr = new int[size_];
        int temp_size = 0;
        // копируем все элементы, кроме максимального
        for (int i = 0; i < size_; i++) {
            if (arr_[i] != max_) {
                temp_arr[temp_size] = arr_[i];
                temp_size++;
            }
        }
        // если удаляется максимальное значение,
        // нужно обновить соответствующую переменную

        max_ = INT_MIN;
        for (int i = 0; i < temp_size; i++) {
            if (temp_arr[i] > max_) {
                max_ = temp_arr[i];
            }
        }

        // обновляем массив и размер стека
        delete[] arr_;
        arr_ = temp_arr;
        size_ = temp_size;
    }

    void sh_min() const {
        if (empty()) {
            // бросаем исключение, если стек уже пуст
            throw underflow_error("Stack underflow");
        }
        cout << min_ << endl;
    }

    void sh_max() const {
        if (empty()) {
            // бросаем исключение, если стек уже пуст
            throw underflow_error("Stack underflow");
        }
        cout << max_ << endl;
    }
};


int main() {
    int stack_size = 10;
    Stack s1(stack_size);
    
    s1.push(1);
    s1.push(2);
    s1.push(38);
    s1.push(5);
    s1.push(0);
    s1.push(1);
    cout << "Check empty:" << endl;
    cout << s1.empty() << endl;

    cout << "Show max\min" << endl;
    s1.sh_max();
    s1.sh_min();

    s1.pop_max();
    s1.pop_min();

    cout << "Show max\min after pop max\min" << endl;
    s1.sh_max();
    s1.sh_min();


    cout << "Show stack top" << endl;
    s1.top();
    s1.pop();
    cout << "Show stack top after pop" << endl;
    s1.top();
};

