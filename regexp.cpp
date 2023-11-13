// Поиск всех email

#include <iostream>
#include <regex>
#include <string>

using namespace std;

void findEmails() {
    string text = "Контактная информация: daniil48@mail.ru, daniil_zelepukin@example.com, zelepukin_d@gmail.com";
    regex pattern(R"([\w\.-]+@[\w\.-]+)");
    smatch match;

    while (regex_search(text, match, pattern)) {
        cout << "Найден email: " << match.str() << endl;
        text = match.suffix().str();
    }

    cout << "--------------------------" << endl;
}

// Поиск всех хэштегов

void findHashtags() {
    string tweet = "Вчера проходила конференция #ProfIT, а сегодня проводился мастер-класс #РЕЛЭКС";
    regex pattern(R"(#\w+)");
    sregex_iterator words_begin(tweet.begin(), tweet.end(), pattern);
    sregex_iterator words_end;

    while (words_begin != words_end) {
        cout << "Найден хэштег: " << (words_begin++)->str() << endl;
    }

    cout << "--------------------------" << endl;
}

// Замена всех ссылок на текст

void replaceLinks() {
    string text = "Ссылка на сайт ВГТУ: https://cchgeu.ru/, ссылка на сайт INOBITEC: https://inobitec.com/";
    regex pattern(R"(https?://\S+)");
    string clean_text = regex_replace(text, pattern, "Ссылка заменена данным текстом");
    cout << clean_text << endl;

    cout << "--------------------------" << endl;
}

// Поиск всех дат

void findDates() {
    string text = "Конференция пройдет 10-11-2023 в 14:00 , а мастер класс 14-10-2023 в 18:30";
    regex pattern(R"(\d{2}-\d{2}-\d{4})");
    sregex_iterator dates_begin(text.begin(), text.end(), pattern);
    sregex_iterator dates_end;

    while (dates_begin != dates_end) {
        cout << "Найдена дата: " << (dates_begin++)->str() << endl;
    }

    cout << "--------------------------" << endl;
}

// Поиск всех слов начинающихся на букву a или b

void extractWordsAB() {
    string text = "Компания apple - крупнейшая по производству гаджетов , bmw - марка автомобилей";
    regex pattern(R"(\b[ab]\w+)");
    sregex_iterator words_begin(text.begin(), text.end(), pattern);
    sregex_iterator words_end;

    while (words_begin != words_end) {
        cout << "Найдено слово: " << (words_begin++)->str() << endl;
    }

    cout << "--------------------------" << endl;
}

// Валидация формата телефонных номеров 

bool validatePhoneNumber(const string& phone_number) {
    regex pattern(R"(^\+?\d{1,3}[-.\s]?\(?\d{3}\)?[-.\s]?\d{3}[-.\s]?\d{4}$)");
    return regex_match(phone_number, pattern);
}

int main() {
    findEmails();
    findHashtags();
    replaceLinks();
    findDates();
    extractWordsAB();

    string phone1 = "+7-900-777-7777";
    string phone2 = "8-980-688-0880";
    string phone3 = "999 333 777";

    cout << boolalpha;
    cout << validatePhoneNumber(phone1) << endl;  
    cout << validatePhoneNumber(phone2) << endl;  
    cout << validatePhoneNumber(phone3) << endl;  

    return 0;
}