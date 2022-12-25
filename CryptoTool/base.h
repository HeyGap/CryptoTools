#pragma once
#include<iostream>
#include<cstring>
#define Size 501
using namespace std;

void base64manager();

void base64encode(char* M,const char* base64_table);

void base64decode(char* C,const char* base64_table);