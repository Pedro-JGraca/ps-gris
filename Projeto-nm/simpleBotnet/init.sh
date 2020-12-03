#!/bin/sh

#builds client
cd src/client
make
mv client ../../build/client/
make clean
cp link.py ../../build/client/
cd ..

#build server
cd server-backend/
cp -r * ../../build/server/
cd ..

#build admin
cd server-frontend
cp * ../../build/admin/
cd ../..

