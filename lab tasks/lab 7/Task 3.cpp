#include <iostream>
using namespace std;

class Ticket {
    protected:
    int TicketID;
    string passengerName;
    double price;
    string date;
    string destination;
    public:
    Ticket(int ID,string N,double p,string d,string dest):TicketID(ID),passengerName(N),price(p),date(d),destination(dest){}
   virtual void reserve() {
        cout << "Ticket reserved for " << passengerName << " to " << destination << " on " << date << ""<<endl;
    }

   virtual void cancel(){
    cout<<"Ticket : "<<TicketID<<" Has been cancelled"<<endl;
   }

   virtual void displayTicketinfo(){
    cout<<"Ticket ID : "<<TicketID<<endl;
    cout<<"Passenger Name :"<<passengerName<<endl;
    cout<<"Price : "<<price<<endl;
    cout<<"DATE : "<< date <<endl;
    cout<<"Destination : "<<destination<<endl;
   }
};
class FlightTicket:public Ticket{
    protected:
    string AirlineName;
    string flightNumber;
    string seatclass;
    public:
    FlightTicket(int ID,string N,double p,string d,string dest,string airline,string flight,string sc):Ticket(ID,N,p,d,dest),AirlineName(airline),flightNumber(flight),seatclass(sc){}
    void displayTicketinfo()override{
        Ticket::displayTicketinfo();
        cout<<"Airline Name :"<<AirlineName<<endl;
        cout<<"Flight Number : "<<flightNumber<<endl;
        cout<<"Seat Class : "<<seatclass<<endl;
    }
};
class TrainTicket : public Ticket{
    protected:
    string TrainNumber;
    string CoachType;
    string DepartureTime;
    public:
    TrainTicket(int ID,string N,double p,string d,string dest,string train,string ct,string dt):Ticket(ID,N,p,d,dest),TrainNumber(train),CoachType(ct),DepartureTime(dt){}
    void reserve ()override{
        cout<<"Seats Assigned in " <<CoachType<<" of Train "<<TrainNumber<<" Departing at "<<DepartureTime<<endl;
    }
};
class Busticket : public Ticket{
    protected:
    string BusCompany;
    string SeatNumber;
    public:
    Busticket(int ID,string N,double p,string d,string dest,string bus,string sn):Ticket(ID,N,p,d,dest),BusCompany(bus),SeatNumber(sn){}
    void cancel()override{
        cout<<"Bus Ticket :"<<TicketID<<"\nCancelled  "<< SeatNumber <<endl;
    }
};
class Concert : public Ticket{
  protected:
  string artistName;
  string venue;
  string seatType;
  public:
  Concert(int ID,string N,double p,string d,string dest,string artist,string venue,string st):Ticket(ID,N,p,d,dest),artistName(artist),venue(venue),seatType(st){}
  void displayTicketinfo() override{
    Ticket::displayTicketinfo();
    cout<<"Artist Name :"<<artistName<<endl;
    cout<<"Venue : "<<venue<<endl;
    cout<<"Seat Type : "<<seatType<<endl;
  }  

};

int main(){
    FlightTicket F1(1,"Ali",4500,"15-6-25","Dubai","Emirates","EK-215","Business");
    TrainTicket T1(2,"Sara",350,"10-8-25","London","T-56","First Class","3:00 PM");
    Busticket B1(3,"Hassan",1200,"30-10-25","New York","Greyhound","B-21");
    Concert C1(4,"Zara",5000,"05-12-25","Los Angeles","Taylor Swift","Hollywood Bowl","Platinum");
     cout << "\nFlight Ticket:\n";
    F1.displayTicketinfo();
    
    cout << "\nTrain Ticket:\n";
    T1.reserve();
    T1.displayTicketinfo();
    
    cout << "\nBus Ticket:\n";
    B1.cancel();
    B1.displayTicketinfo();
    
    cout << "\nConcert Ticket:\n";
    C1.displayTicketinfo();
}

