#!/bin/bash

# Определяем переменные
TARGET_USER="arethdag" # Имя пользователя на целевой машине
TARGET_HOST="10.10.0.1" # IP-адрес целевой машины
TARGET_DIR="/usr/local/bin" # Директория на целевой машине, куда будут скопированы файлы
TEMP_DIR="/tmp" # Временная директория для копирования

# Копируем файлы на целевую машину во временную директорию
echo "Копирование s21_cat на $TARGET_HOST:$TEMP_DIR"
scp cat/s21_cat "$TARGET_USER@$TARGET_HOST:$TEMP_DIR"
if [ $? -ne 0 ]; then
echo "Ошибка при копировании s21_cat"
exit 1
fi

echo "Копирование s21_grep на $TARGET_HOST:$TEMP_DIR"
scp grep/s21_grep "$TARGET_USER@$TARGET_HOST:$TEMP_DIR"
if [ $? -ne 0 ]; then
echo "Ошибка при копировании s21_grep"
exit 1
fi

# Перемещение файлов в /usr/local/bin
echo "Перемещение файлов в $TARGET_DIR"
ssh "$TARGET_USER@$TARGET_HOST" "sudo mv $TEMP_DIR/s21_cat $TARGET_DIR && sudo mv $TEMP_DIR/s21_grep $TARGET_DIR"
if [ $? -ne 0 ]; then
echo "Ошибка при перемещении файлов в $TARGET_DIR"
exit 1
fi

echo "Деплой завершен успешно!"

