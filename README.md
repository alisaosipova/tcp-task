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
