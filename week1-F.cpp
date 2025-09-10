#include<iostream>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

int main(){
    char c;
    set<string>words;
    string word;
    while(cin.get(c)){
        if(isalpha(c)){
            word+=tolower(c);
        }else{
            if(!word.empty()){
                words.insert(word);
                word.clear();
            }
        }
    }
    if(!word.empty()){
        words.insert(word);
    }
    for(const string &w:words){
        cout<<w<<endl;
    }
    return 0;
}