#!/bin/bash
mkdir -p var/log
touch var/log/фамилия.log
read -p "Введите название папки: " filepath
read -p "Расширение файлов: " ending
read -p "Введите строку поиска: " stroke
find ~ -type f -name "*.$ending" -exec grep -l $stroke {} + > var/log/фамилия.log

# В тз не указано куда пихать название папки, так что я его не использую
