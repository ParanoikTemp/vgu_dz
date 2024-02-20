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
