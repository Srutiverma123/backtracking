/*
Crossword Problem

CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Sample Test Cases:
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/


#include<bits/stdc++.h>
using namespace std;
void resetHorizontal(string crossword[],int n,string list,bool* visited,int current,int i,int j){
    int k=current;
    for(j;j<n && list[k]!=';';j++){
        if(visited[k]){
            crossword[i][j]='-';
            visited[k]=false;
        }
        k++;
    }
}
int setHorizontal(string crossword[],int n,string list,bool* visited,int current,int i,int j){
    int k=current;
    for(j;j<n && list[k]!=';';j++){
        if(crossword[i][j]=='-'){
            crossword[i][j]=list[k];
            visited[k]=true;
        }
        k++;
    }
    return k+1;
}
bool horizontal(string crossword[],int n,string list,int current,int i,int j){
    int k=current;
    for(j;j<n && list[k]!=';';j++){
        if(crossword[i][j]!='-' && crossword[i][j]!=list[k])
            return false;
        k++;
    }
    if(list[k]==';')
        return true;
    return false;
}
void resetVertical(string crossword[],int n,string list,bool* visited,int current,int i,int j){
    int k=current;
    for(i;i<n && list[k]!=';';i++){
        if(visited[k]){
            crossword[i][j]='-';
            visited[k]=false;
        }
        k++;
    }
}
int setVertical(string crossword[],int n,string list,bool* visited,int current,int i,int j){
    int k=current;
    for(i;i<n && list[k]!=';';i++){
        if(crossword[i][j]=='-'){
            crossword[i][j]=list[k];
            visited[k]=true;
        }
        k++;
    }
    return k+1;
}
bool vertical(string crossword[],int n,string list,int current,int i,int j){
    int k=current;
    for(i;i<n && list[k]!=';';i++){
        if(crossword[i][j]!='-' && crossword[i][j]!=list[k])
            return false;
        k++;
    }
    if(list[k]==';')
        return true;
    return false;
}
bool isPossible(string crossword[],int n,string list,bool* visited,int current){
    if(list.substr(current).size()==0)
        return true;
    // cout<<list.substr(current)<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             if(crossword[i][j]=='-' || crossword[i][j]==list[current]){
                 if(vertical(crossword,n,list,current,i,j)){
                 int nextCurrent=setVertical(crossword,n,list,visited,current,i,j);
                 if(isPossible(crossword,n,list,visited,nextCurrent))
                     return true;
                 else
                     resetVertical(crossword,n,list,visited,current,i,j);
                 }
                 if(horizontal(crossword,n,list,current,i,j)){         
                 int nextCurrent=setHorizontal(crossword,n,list,visited,current,i,j);
                 if(isPossible(crossword,n,list,visited,nextCurrent))
                     return true;
                 else
                     resetHorizontal(crossword,n,list,visited,current,i,j);
                 }
             }
        }  
    }
   
    return false;
}
int main() {
    string crossword[10];
    for(int i=0;i<10;i++)
        cin>>crossword[i];
    string list;
    cin>>list;
    list+=';';
    bool* visited=new bool[list.size()];
    for(int i=0;i<list.size();i++)
        visited[i]=false;
    if(isPossible(crossword,10,list,visited,0))
        for(int i=0;i<10;i++)
            cout<<crossword[i]<<endl;
    delete[] visited;
    return 0;
}
