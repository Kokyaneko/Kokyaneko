/*
This program is used for github auth instead of gh command.
Please set .github-Aauth.txt in your home directry.

This program is written by Arima Ryo, 2026.
This program is perfectly free.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(void){
    const char *HOME_DIR_PATH = getenv("HOME");//std::getenv <-get environment variable. 

    string PERFECT_PATH = string(HOME_DIR_PATH) + "/.github-Aauth.txt";

    FILE *fp = fopen(PERFECT_PATH.c_str() ,"r");
    if(fp == NULL){
        cout<<"Not found:"<<PERFECT_PATH<<endl;
        return 1;
    }

    char trushable[72];
    char uname[72];
    char pass[72];

    fscanf(fp,"%s",trushable);
    fscanf(fp,"%s %s",trushable,uname);
    fscanf(fp,"%s %s",trushable,pass);

    fclose(fp);

    //set environment variable
    setenv("GITHUB_USER", uname, 1);
    setenv("GITHUB_TOKEN", pass, 1);

    cout<<uname<<endl;
    cout<<pass<<endl;

    return 0;
}
