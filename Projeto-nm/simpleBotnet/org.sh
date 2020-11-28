#!/bin/sh

#builds client
cd src/client
make
mv client ../../build/client/
make clean
cd ..

#build server
cd server-backend/
cp -r * ../../build/server/
cd ..

#build admin
cd server-frontend
cp *.py ../../build/admin/
cd ../..

