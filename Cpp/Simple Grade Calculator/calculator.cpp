#include<iostream>
using namespace std;

int main(){
    float eng,math,sci,average,total;
    char grade;
    cout<<"Enter your English mark :";
    cin>>eng;
    cout<<"Enter your Math mark :";
    cin>>math;
    cout<<"Enter your Science mark :";
    cin>>sci;
    total=eng+math+sci;
    average=total/3;
    
    grade=average>=90?'A':average>=80?'B':average>=70?'C':average>=60?'D':average>=50?'E':'F';
    cout<<"Your grade is "<<grade<<endl;
    if(average<=100){
        switch (grade){
            case 'A':
            cout<<"Excellent work"<<endl;
            break;

            case 'B':
            cout<<"Well done"<<endl;
            break;

            case 'C':
            cout<<"Good job"<<endl;
            break;

            case 'D':
            case 'E':
            cout<<"You passed,but you could do better."<<endl;
            break;

            case 'F':
            cout<<"Sorry,you failed"<<endl;
            break;
        }
    }

    if(grade>='A' && grade<='E'){
        cout<<"Congratulations! You are eligible for the next level";
    }
    else{
        cout<<"Please try again next time";
    }
}