Как собрать mosquitto 2.0 под stretch

 1. Потребуется devenv с исправлениями (feature/39308-mosquitto-2.0.11-1-build-devenv).
 2. Потребуются бэкпортированные пакеты из bullseye (все они сейчас добавлены в репозиторий dev-tools):
   - libcjson1 и libcjson-dev
   - libdlt2 и libdlt-dev
   - uthash-dev (>= 2.1.0)
 3. Собираем libwebsockets 4.0.20 (приложен в contrib), добавляем собранные пакеты в репозиторий.
 4. Собираем mosqutto 2.0.11 (приложен в contrib) с репозиторием, где есть упомянутые пакеты и libwebsockets.
 
