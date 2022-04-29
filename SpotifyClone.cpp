#include <iostream>
#include <string>
#include "LinkedList.h"
#include "CQueue.h"

using namespace std;

class Person{
	
	private:
	
		string name;
		Queue<string> songList;
	
	public:
		
		Person(string name = "", string song = ""){
			
			this->name = name;
			
			if(song != "")
				songList.add(song);
		}
		
		bool operator == (const Person &other){
			
			return (name == other.name);
		}
		
		string getName(){	return name;	}
		
		friend ostream& operator << (ostream &out, const Person &p){
			
			out << p.name << endl;
			
			return out;
		}
		
		void addSong(string song){
			
			songList.add(song);
		}
		
		void deleteSong(string song){
			
			int size = songList.size();
			
			for(int i = 0; i < size; i++){
				
				string temp = songList.remove();
				
				if(temp == song)
					break;
				
				songList.add(temp);
			}
			
		}
		
		void listAllSongs(){
			
			int size = songList.size();
			
			for(int i = 0; i < size; i++){
				
				string temp = songList.remove();
				cout << temp << " ";
				songList.add(temp);
			}
		}
};
	

class Spotify{
	
	private:
		
		LinkedList<Person> l;
		LinkedList<string> allLikedSongList;
		LinkedList<string> commonLikedSongList;
		
	public:
		
		void addPerson(string name){
			
			Person p(name);
			LLNode<Person> *temp = l.search(p);
			
			if(temp == NULL)
				l.insertLast(p);
			
			else{
				cout << "This person is already created !!!" << endl;
			}
			
		}
	
		void deleteSong(string name, string song){
			
			Person p(name);
			LLNode<Person> *temp = l.search(p);
			
			if(temp == NULL)
				cout << "This person is not created before" << endl;
			
			else{
				
				Person p = temp->data;
				p.deleteSong(song);
				updatePerson(p);
			}
			
			deleteCommonLikedSongList(song);
			
		}
		
		void addSong(string name, string song){
			
			LLNode<Person> *temp = l.search(name);
			
			if(temp == NULL){
				
				Person p(name, song);
				l.insertLast(p);
			}
			
			else{
			
				Person p = temp->data;
				p.addSong(song);
				updatePerson(p);
			}
			
			addCommonLikedSongList(song);
		
		}
		
		void listPersonSongList(string name){
			
			Person tempPerson(name);
			LLNode<Person> *temp = l.search(tempPerson); 
			
			if(temp == NULL)
				cout << "There is no person with this name" << endl;
			
			else{
				
				tempPerson = temp->data;
				cout << tempPerson.getName() << ": ";
				tempPerson.listAllSongs();
				cout<<endl;
			}
			
		}
		
		void listAllPerson(){
			
			cout << "All person of have a song list: " << endl << l << endl;
			
		}
		
		void addCommonLikedSongList(string song){
			
			LLNode<string> *tempSong = allLikedSongList.search(song);
			
			if(tempSong == NULL)
				allLikedSongList.insertLast(song);
				
			else{
				LLNode<string> *tempSong = commonLikedSongList.search(song);
				
				if(tempSong == NULL)
					commonLikedSongList.insertLast(song);
			}
			
		}
		
		void deleteCommonLikedSongList(string song){
			
			LLNode<string> *temp = allLikedSongList.search(song);
			allLikedSongList.deleteNode(song);
			
			temp = commonLikedSongList.search(temp->data);
			
			if(temp != NULL){
				commonLikedSongList.deleteNode(song);
			}
		}
		
		void listCommonLikedSongList(){
			
			if(commonLikedSongList.isEmpty())
				cout << endl << "There are no common favorite songs in the list." << endl << endl;
			
			else
				cout << endl << "List all the songs that are liked by anyone: " << commonLikedSongList << endl << endl;
			
		}
				
		//When i changed info of person, update person's info with this funciton.
		void updatePerson(Person p){
			
			l.deleteNode(p);
			l.insertLast(p);
		}
};

int main()
{
	
	
	Spotify s;
	
	s.addPerson("Ahmet");
	s.addPerson("Mehmet");
	s.addPerson("Veli");
	s.addPerson("Zeki");
	
	s.addSong("Ahmet", "x1");
	s.addSong("Ahmet", "x2");
	s.addSong("Ahmet", "x3");
	s.addSong("Ahmet", "CommonSong");
	
	s.addSong("Mehmet", "y1");
	s.addSong("Mehmet", "y2");
	s.addSong("Mehmet", "y3");
	s.addSong("Mehmet", "CommonSong");
	
	
	s.addSong("Veli", "z1");
	s.addSong("Veli", "z2");
	s.addSong("Veli", "z3");
	s.addSong("Veli", "CommonSong");
	
	s.addSong("Zeki", "q1");
	s.addSong("Zeki", "q2");
	s.addSong("Zeki", "q3");
	s.addSong("Zeki", "CommonSong");
	
	
	s.listAllPerson();
	s.listPersonSongList("Ahmet");
	s.listPersonSongList("Mehmet");
	s.listPersonSongList("Veli");
	s.listPersonSongList("Zeki");
	
	s.listCommonLikedSongList();
	
	s.deleteSong("Ahmet", "x1");
	s.deleteSong("Mehmet", "y1");
	s.deleteSong("Veli", "z1");
	s.deleteSong("Zeki", "q1");
	s.deleteSong("Zeki", "CommonSong");
	
	s.listPersonSongList("Ahmet");
	s.listPersonSongList("Mehmet");
	s.listPersonSongList("Veli");
	s.listPersonSongList("Zeki");
	
	s.listCommonLikedSongList();
	
	return 0;
}
