#include <iostream>
#include<fstream>
#include<string>

using namespace std;

/*
*Struct holds the node
*/
struct Node{
  string  data;
  Node *Prev;
  Node *Next;
  
  Node(){
    data = " ";
    Prev = NULL;
    Next = NULL;
  }
  Node(string x){
    data = x;
    Prev = NULL;
    Next = NULL;
  }
};

class LuckyOnes{
  private:
    Node *Head;
    Node *Tail;
    Node *Current;
    string word;
    ifstream fin;
    ofstream fout;
    
  public:
    LuckyOnes();
    void header();
    void readFile();
    void Load(Node* &);
    void Load(string);
    void print(int);
    int countItems();
    int getLeng(int,int);
    void cull(int,int);
    void moveRight(int,int);
    void moveLeft(int,int);
    void aniRem(string,int);
    string aniRemP();
};