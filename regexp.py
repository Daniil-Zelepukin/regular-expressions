#Поиск всех email

import re

text = "Контактная информация: daniil48@mail.ru, daniil_zelepukin@example.com, zelepukin_d@gmail.com"
emails = re.findall(r'[\w\.-]+@[\w\.-]+', text)
print(emails)

print("----------------------------")

#Поиск всех хэштегов

import re

tweet = "Вчера проходила конференция #ProfIT, а сегодня проводился мастер-класс #РЕЛЭКС"
hashtags = re.findall(r'#\w+', tweet)
print(hashtags)

print("----------------------------")

#Замена всех ссылок на текст  

import re

text = "Ссылка на сайт ВГТУ: https://cchgeu.ru/, ссылка на сайт INOBITEC: https://inobitec.com/"
clean_text = re.sub(r'https?://\S+', 'Ссылка заменена данным текстом', text)
print(clean_text)

print("----------------------------")

#Поиск всех дат

import re

text = "Конференция пройдет 10.11.2023 в 14:00 , а мастер класс 14.10.2023 в 18:30"
dates = re.findall(r'\d{2}-\d{2}-\d{4}', text)
print(dates)

print("----------------------------")

#Поиск всех слов начинающихся на букву a или b

import re

text = "Компания apple - крупнейшая по производству гаджетов , bmw - марка автомобилей"
words = re.findall(r'\b[ab]\w+', text, re.IGNORECASE)
print(words)

print("----------------------------")

#Валидация формата телефонных номеров 

import re

def validate_phone_number(phone_number):
    pattern = re.compile(r'^\+?\d{1,3}[-.\s]?\(?\d{3}\)?[-.\s]?\d{3}[-.\s]?\d{4}$')
    return bool(pattern.match(phone_number))

phone1 = "+7-900-777-7777"
phone2 = "8-980-688-0880"
phone3 = "+999 333 777"
print(validate_phone_number(phone1))  
print(validate_phone_number(phone2))  
print(validate_phone_number(phone3))  