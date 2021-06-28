//
// Created by Kylian Lee on 2021/06/28.
//

#include <iostream>
#include <stack>

using namespace std;

stack<char> orig, temp;

void push(char ch);
void left();
void right();
void back();

int main() {
  string s;
  cin >> s;
  int len = s.length();
  for (int i = 0; i < len; ++i)
    orig.push(s[i]);
  int num;
  cin >> num;
  for (int i = 0; i < num; ++i) {
    char ch1, ch2;
    cin >> ch1;
    if(ch1 == 'P'){
      cin >> ch2;
      push(ch2);
    }
    else if(ch1 == 'L')
      left();
    else if(ch1 == 'D')
      right();
    else
      back();
  }
  while(!orig.empty()){
    temp.push(orig.top());
    orig.pop();
  }
  while(!temp.empty()){
    cout << temp.top();
    temp.pop();
  }

  return 0;
}

void push(char ch){
  orig.push(ch);
}

void left(){
  if(!orig.empty()) {
    temp.push(orig.top());
    orig.pop();
  }
}

void right(){
  if(!temp.empty()) {
    orig.push(temp.top());
    temp.pop();
  }
}

void back(){
  if(!orig.empty())
    orig.pop();
}