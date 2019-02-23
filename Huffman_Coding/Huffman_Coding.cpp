#include <iostream>
#include <utility>          //For pair<>
#include <vector>
#include <algorithm>        //For Sorting
#include <string>
#include <map>

struct TreeNode{
  char c;                                          //character
  int freq;                                        //frequency
  int val;                                         //Value: either 0 or 1 according to the node is left or right child
  bool leaf;                                       //True if node is leaf node
  struct TreeNode* parent;                         //Pointer to parent node
  struct TreeNode* right;                          //Pointer to right child
  struct TreeNode* left;                           //Pointer to left child
};

bool MyFunction(TreeNode* t1,TreeNode* t2){       //User-Defined Function to sort TreeNodes in descending order...
  return t1->freq > t2->freq ;                    //...according to it's Frequency
}

int main() {

  std::cout << "Enter Sentence to encode : ";
  std::string s;
  std::getline(std::cin,s);

  std::map<char, int> Frequency;                  //Map<> to count Frequency of Characters in String
  std::vector<char> Characters;                   //To store unique Characters in String

  for(int i=0;i<s.length();i++){
      if(Frequency[s[i]]==0){                     //If Frequency is zero => New Character hence we will add it to
        Characters.push_back(s[i]);               //"Character vector" which stores unique Characters
      }
      ++Frequency[s[i]];
  }

  std::vector<TreeNode*> Cnf;                     //Vector to store TreeNode pointers

  for(int i=0;i<Characters.size();i++){
    struct TreeNode* temp = new TreeNode;
    temp->c = Characters[i];
    temp->freq = Frequency[Characters[i]];
    temp->leaf = true;
    Cnf.push_back(temp);
  }

  sort(Cnf.begin(),Cnf.end(),MyFunction);         //Sorting according to frequency of characters

  std::vector<TreeNode*> ref;                     //Vector to store all leaf nodes, so we can generate codes for them at last

  while(Cnf.size()!=1){

    struct TreeNode* t1 = Cnf.back();             //Extracting two nodes with less frequency
    Cnf.pop_back();
    struct TreeNode* t2 = Cnf.back();
    Cnf.pop_back();

    struct TreeNode* nw = new TreeNode;

    if(t1->freq < t2->freq){                      //Assign value=0 to minimum frequency node and make it left child of
      nw->right = t2;                             //newly created node
      t2->val = 1;                                //Assign value=1 to other node and make it right child of newly created node
      nw->left = t1;
      t1->val = 0;
    }
    else{
      nw->right = t1;
      t1->val = 1;
      nw->left = t2;
      t2->val = 0;
    }

    nw->leaf = false;
    nw->freq = t1->freq + t2->freq;
    nw->parent = NULL;

    t1->parent = t2->parent = nw;

    if(t1->leaf){                                 //Store leaf nodes in "Ref Vector"
      ref.push_back(t1);
    }
    if(t2->leaf){
      ref.push_back(t2);
    }

    Cnf.push_back(nw);
    sort(Cnf.begin(),Cnf.end(),MyFunction);
  }

  std::cout << "Huffman Codes : " << '\n';       //Display Codes of all leaf nodes
  while(ref.size()){
    struct TreeNode* temp = ref.back();
    ref.pop_back();
    std::cout << "\nChar : " << temp->c << "\nFrequency : "<< temp->freq << "\nCode : ";
    std::string s = "";
    while(temp->parent!=NULL){
      s += temp->val + '0';
      temp = temp->parent;
    }
    reverse(s.begin(),s.end());
    std::cout << s << '\n';
    std::cout<<"\n";
  }
  return 0;
}
