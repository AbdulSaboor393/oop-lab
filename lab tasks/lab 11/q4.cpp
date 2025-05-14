#include <iostream>
#include <exception>
#include <string>
using namespace std;

class DatabaseError : public exception {
public:
    const char* what() const noexcept override {
        return "Database error encountered.";
    }
};

class ConnectionFailure : public DatabaseError {};
class TimeoutOccurred : public DatabaseError {};

template <typename T>
class DataSource {
    T dbLabel;

public:
    DataSource(T label) : dbLabel(label) {}

    void initiate() {
        if (dbLabel == "broken_db") {
            throw ConnectionFailure();
        }
        cout << "Connected to: " << dbLabel << endl;
    }

    void execute(const string& query) {
        if (dbLabel == "slow_db") {
            throw TimeoutOccurred();
        }
        cout << "Running: " << query << endl;
    }
};

int main() {
    try {
        cout << "Connecting to a bad database..." << endl;
        DataSource<string> d1("broken_db");
        d1.initiate();
    } catch (ConnectionFailure& ex) {
        cout << "Connection failed." << endl;
        cout << "Cause: " << ex.what() << endl;
    }

    try {
        cout << "Connecting to a laggy database..." << endl;
        DataSource<string> d2("slow_db");
        d2.initiate();
        d2.execute("SELECT * FROM table;");
    } catch (TimeoutOccurred& ex) {
        cout << "Query timeout." << endl;
        cout << "Cause: " << ex.what() << endl;
    }

    return 0;
}
