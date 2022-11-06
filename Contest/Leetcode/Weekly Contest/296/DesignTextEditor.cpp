// https://leetcode.com/contest/weekly-contest-296/problems/design-a-text-editor/

#include<bits/stdc++.h>
using namespace std;

class TextEditor {
public:
    stack<char> left;
    stack<char> right; 
    
    TextEditor() {
    }
    
    void addText(string text) {
        for(int i=0;i<text.size();i++){
            left.push(text[i]);
        }
    }
    
    int deleteText(int k) {
        int cnt = 0;
        while(!left.empty() && k--){
            left.pop();
            cnt++;
        }

        return cnt;
    }
    
    string cursorLeft(int k) {
        while(!left.empty() && k--){
            char p = left.top();
            left.pop();
            right.push(p);
        }

        return Kleft();
    }
    
    string cursorRight(int k) {
        while(!right.empty() && k--){
            char p = right.top();
            right.pop();
            left.push(p);
        }

        return Kleft();
    }

    string Kleft(){
        int size = left.size();
        int cnt = min(10,size);

        string ans;
        while(cnt-- && !left.empty()){
            ans += left.top();
            left.pop();
        }

        reverse(ans.begin(), ans.end());

        for(int i=0;i<ans.size();i++){
            left.push(ans[i]);
        }

        return ans;
    }
};

int main(){
    TextEditor *obj = new TextEditor();
    obj->addText("leetcode");
    int param_2 = obj->deleteText(4);
    obj->addText("practice");
    string param_3 = obj->cursorRight(3);
    string param_4 = obj->cursorLeft(8);
    int param_5 = obj->deleteText(10);
    string param_6 = obj->cursorLeft(2);
    string param_7 = obj->cursorRight(6);

    return 0; 
}

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */