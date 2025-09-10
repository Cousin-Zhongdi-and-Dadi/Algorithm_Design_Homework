#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

class Student{
public:
    string id;
    string name;
    int score;
};

int main(){
    int n,m;
    cin>>n>>m;
    int counter=0;
    while(n!=0 && m!=0){
        cout<<"Case "<<++counter<<":"<<endl;
        vector<Student> students(n);
        for(int i=0; i<n; i++){
            cin>>students[i].id>>students[i].name>>students[i].score;
        }
        if(m==1){
            sort(students.begin(), students.end(), [](const Student &a, const Student &b){
                return a.id<b.id;
            });
        }else if(m==2){
            sort(students.begin(), students.end(), [](const Student &a, const Student &b){
                if(a.name==b.name) return a.id<b.id;
                return a.name<b.name;
            });
        }else{
            sort(students.begin(), students.end(), [](const Student &a, const Student &b){
                if(a.score==b.score) return a.id<b.id;
                return a.score<b.score;
            });
        }
        for(int i=0; i<n; i++){
            cout<<students[i].id<<" "<<students[i].name<<" "<<students[i].score<<endl;
        }
        cin>>n>>m;
    }
    return 0;
}