# tcp-task by alisaosipova
### Задание для "ООО PBF group"

#### How to install and build:
```bash
git clone https://github.com/alisaosipova/tcp-task.git
cd tcp-task
./build.sh
cd build
```
#### How to run
Порт может быть любой, я буду использовать 8080 как дефолтный divert порт

Клиент получает из командной строки 3 параметра: \
    1. Текстовое имя клиента \
    2. Номер порта сервера \
    3. Период подключения к серверу в секундах
```bash
First terminal:
./server 8080

Second terminal:
./client Client1 8080 5

Third terminal:
./client Client2 8080 2

etc...
```
#### Result

[2024-09-20 18:54:38.267] Client1 \
[2024-09-20 18:54:43.268] Client1 \ 
[2024-09-20 18:54:48.286] Client1 \ 
[2024-09-20 18:54:53.287] Client1 \ 
[2024-09-20 18:54:58.299] Client1 \ 
[2024-09-20 18:55:03.202] Client2 \ 
[2024-09-20 18:55:03.301] Client1 \ 
[2024-09-20 18:55:05.203] Client2 \ 
[2024-09-20 18:55:07.210] Client2 \ 
[2024-09-20 18:55:08.303] Client1 \ 
[2024-09-20 18:55:09.210] Client2
