#include "iostream"
using namespace std;

struct books{
    string title;
    string author;
    int year;   
};
void displayBooksAfterYear(books* b, int n, int year_after){
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (b[i].year > year_after)
        {
            cout<<"Title: "<< b[i].title <<"\nAuthor: \n"<<b[i].author << 
            "\nyear: \n" << b[i].year <<endl;  
            found = true;
        }
        
    }
    if(!found){
        cout<<"no books published after the year "<<year_after<<endl;
    }

}
int main(){
    int n;
    cout<<"Enter the number of books: "<<endl;
    cin>>n;
    books* b = new books[n];
    for ( int i = 0; i < n; i++)
    {
    
    cin.ignore();
    cout<<"Enter the details of the book "<< i+1 << endl;
    cout<<"title: "<<endl; 
    getline(cin, b[i].title);
    cout<<"Author: "<<endl;
    getline(cin, b[i].author);
    cout<<"Year: "<<endl;
    cin>>b[i].year;
    }
    int year_after;
    cout<<"Enter a year to filter books publish after: "<<endl;
    cin>>year_after;
    displayBooksAfterYear(b, n, year_after);
    delete[] b;
    
   
    return 0;

}