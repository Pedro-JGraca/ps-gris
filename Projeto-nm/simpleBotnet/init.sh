#!/bin/sh

rm -rf build/client/*
rm -rf build/server/*
rm -rf build/admin/*

#builds client
cd src/client
make
mv client ../../build/client/
make clean
cp link.py ../../build/client/
cp serverLink.txt ../../build/client/
cd ..

#build server
cd server-backend/
cp -r * ../../build/server/
cd ..

#build admin
cd server-frontend
cp * ../../build/admin/
cd ../..

