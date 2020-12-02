#include <iostream>
#include <string>
#include <vector>
#include <fstream>
/*
 * Написать программу, которая заменяет слова из списка цензуры на *-ки
 */

using namespace std;

class Text{
public:
    vector<char*> text;
    vector<string> ban_words;

public:
    void input_ban(){
        ifstream fin(R"(C:\Users\anton\CLionProjects\strings\banwords)");
        auto *str = new string((char*)malloc(sizeof(char)*200));
        while(!fin.eof()) {
            fin >> *str;
            ban_words.push_back(*str);
        }
    }
//переполнение
    void input(){
        FILE* file = fopen(R"(C:\Users\anton\CLionProjects\strings\textfull)", "r");
        int count = 0;
        char ch;
        while((ch = fgetc(file)) != EOF) {
            char* ch_sent = (char*)calloc(sizeof(char), 100);
            count++;
            int i = 0;
            while (ch != '.' && ch != '!' && ch != '?') {
                ch = fgetc(file);
                ch_sent[i] = ch;
                i++;
            }
            if(i != 0) {
                text.push_back(ch_sent);
            }
        }
        fclose(file);
    }

    void print(){
        for(auto i: text){
            cout << i;
        }
    }

    void to_censor(){
        //обработка текста
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Text snt = Text();
    snt.input();
    snt.print();
    return 0;
}