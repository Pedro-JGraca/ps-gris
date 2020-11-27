#!/bin/sh

#clean dst
rm -rf build/client/*
rm -rf build/server/*
rm -rf build/admin/*


#builds client
cd client
make clean
make
mv client ../build/client/
cd ..

#build server
cd server-backend/
cp -r * ../build/server/
cd ..

#build admin
cd server-frontend
make clean
make
cp front.py ../build/admin/
cp botnet ../build/admin/
make clean

cd ..

