#!/bin/sh


#!/bin/sh
curl    "http://localhost:8080/register"

curl    --header "Content-Type: application/json" \
        --request POST \
        --data '{"username":"admin","password":"pass"}' \
        http://localhost:8080/login

curl    -H "X-Auth-Token: eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJ1c2VybmFtZSI6ImFkbWluIiwicGFzc3dvcmQiOiJwYXNzIiwiY3JlYXRlZEF0IjoxNjA1MDM2MDExLCJ2YWxpZFVudGlsIjoxNjA3NjI4MDExfQ.WsboAiOuh58Aoia2fg3lWFZZ_o1KsKOosBj52G16Owk"\
        http://localhost:8080/getTests?testNumber=1



curl    -H "X-Auth-Token: eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJ1c2VybmFtZSI6ImFkbWluIiwicGFzc3dvcmQiOiJwYXNzIiwiY3JlYXRlZEF0IjoxNjA1MDM2MDExLCJ2YWxpZFVudGlsIjoxNjA3NjI4MDExfQ.WsboAiOuh58Aoia2fg3lWFZZ_o1KsKOosBj52G16Owk"\
        "http://localhost:8080/getTests?testNumber=1&requestIndex=1"