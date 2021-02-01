#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node{
    string name;
    Node* left;
    Node* right;
};

bool isOperator(string curr){
    if((curr=="+") || (curr=="-") || (curr=="*") || (curr=="/") ){
        return true;
    }
    return false;
}

Node* create_tree(string exp){
    stack<string> operands;
    stack<string> operators;
    for(int i = 0; i < exp.length(); i++){
        string curr = exp.substr(i,1);
        if(isOperator(curr) || (curr=="(")){
            operators.push(curr);
        } else {
            operands.push(curr);
        }
        if(curr==")"){
            Node parent, child1, child2;
            parent.name = operators.top();
            operators.pop();
            child1.name = operands.top();
            operands.pop();
            child2.name = operands.top();
            operands.pop();
            parent.left = &child1;
            parent.right = &child2;
            if(operators.top()=="("){
                operators.pop();
            } else {
                cout<<"Failure"<<endl;
            }
        }
    }
};


int main(){
    
    ifstream file("input.txt");
    string str;
    getline(file,str);
    int n = stoi(str);
    getline(file,str);
    string orgExp = str;

    Node* root = create_tree(orgExp);
    
    // for(int i = 0; i < n; i++){
    //     getline(file,str);
    //     create_tree(str);
    // }


    return 0;
};