#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
struct node{ /*node htkon mtkwna mn 4 7agat 
character,value bt3tha , pointer left , right by4waer 3la node 
*/
	char c; //da shayel al character bta3e
	int vl; //da shayel al value bt3te
	node* lft; //da by4awer 3la 4male
	node* rght; // da by4awer 3la yemene
};
class compare{ 
public:
	bool operator () (node* n,node* f){ //al Huffman by3tmd 3la sort belnsba ll value
		return (*n).vl > (*f).vl; //bt3mel sort 3la node
	}
};
priority_queue<node*,vector<node*>,compare> pq; //ana 2st5dmt priority queue 34an by3mel sort lw7to
//bs lazem nla7ez 2no me4 bysort value da bysort node 34an kda pass parameter 3 compare bt3mel sort belnsba
// llvalue 2le mdhalo 2le mawgoda fe kol node
vector<pair<char,string>> res; // de 3bara 2no 4ayel al result bt3te zy list kda
node* AddNode(char c,int vl){//function add node
	node* nod=new node();//bdef new node
	nod->lft=nod->rght=NULL; // bt5le left , right bta3hom null
	nod->vl=vl; //bt5le al value bt3tha bel value al gdeda
	nod->c=c; //bt5le al character bta3ha bel character 2le da5el
	return nod;// btrg3 al node al-gdeda
}
node* AddNode(int vl,node* f,node* s){//add node left , Right b7es        12
	node* myNode=new node();    /*                                       /  \   */
	myNode->lft=f; myNode->rght=s;//                                    7    5
	myNode->vl=vl;//                                                    f    s
	return myNode;
	//nfs 2l7war ana b3mel add node say le node 12 left bta3ha hykon node 7 we right node 5 laken
	//function addnode 2le fo2 bt3mel add node 7
}
void printCoding(node* head,string data=""){
	if(head==NULL) return;//check 2ne fe node by4awe 3leha
	if(head->lft==NULL&&head->rght==NULL) {//check left , right node be null yeb2a kda ana weslt node t7t 5als
		res.push_back(make_pair(head->c,data));  // bydfha fe list
		return; 
	}
	if(head->lft!=NULL) printCoding(head->lft,data+"0"); //lw fe node 3la 4mal bydef 0
	if(head->rght!=NULL) printCoding(head->rght,data+"1"); // lw fe node 3la yemen bydef 1
	return;
}
void Hufman(){
	/*fe al-algorithm kol 2le b3melo 
	1) sort ll nodes 2le 3nde
	2) bgm3 minmum 2 nodes we 23mlhom remove we adef node gdeda 4yla magmo3 al 2 nodes dol
	*/
	node* first,*second,*head;
	while(pq.size()>1){//lazem yekon feh root node lya 34an kda check list > 1
		first=pq.top(); pq.pop();//gbt first node we 4eltha mn list
		second=pq.top(); pq.pop();//gbt second node we 4eltha mn list
		node* newNode=AddNode(first->vl+second->vl,first,second);//3mlt node gdeda refer lehom
		pq.push(newNode);//add new node de list bt3te
	}
	head=pq.top(); pq.pop();//head refer 3la node 2le mawgoda we mafe4 3'erha fe list
	printCoding(head);//b3mel al al-algorithm bta3e 
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	char c;  int n,vl;
	while(cin>>n){ //byd5el number of nodes
		res.clear(); //by clear data before 
		for (int i = 0; i < n; i++){ 
			cin>>c>>vl; //byd5el al character , value
			node* nf=AddNode(c,vl); //by3mel node gdeda left=right=null
			pq.push(nf);//bydef node fe list
		}
		Hufman();//call algorithm
		for (int i = 0; i < res.size(); i++)
			cout<<res[i].first<<" "<<res[i].second<<"\n"; //print data
	}
}