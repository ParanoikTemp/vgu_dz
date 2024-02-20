#!/bin/bash
mkdir usr
mkdir usr/bin
mkdir usr/lib
mkdir usr/share
mkdir usr/share/doc
mkdir usr/share/doc/фамилия
mv install1 usr/bin/install1
mv install2.lib usr/lib/install2.lib
mv install3.doc usr/share/doc/фамилия/install3.doc
sudo chgrp user usr/bin/install1
chmod g+x usr/bin/install1

#  В 11 строке я запутался, так как надо выдать права группе user
#  Тут не совсем понятно, так как у меня пользователь называется НЕ user и группа тоже НЕ user
#  Так что я создал у себя искуственно группу user, но чтобы установить ей права, надо эту группу привязать к файлу
#  Чтобы привязать нужны права суперпользователя, то есть прописывать sudo
#  Так что, либо хуево прописано тз, либо я чет не понял
