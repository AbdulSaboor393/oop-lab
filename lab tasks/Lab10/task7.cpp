#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file("quotes_archive.txt");

    if (!file.is_open())
    {
        cout << "Error opening quotes archive file!" << endl;
        return 1;
    }

    file << "The science of today is the technology of tomorrow.\n";
    file << "Innovation distinguishes between a leader and a follower.\n";

    size_t pos = file.tellp();
    cout << "Current write position in file: " << pos << endl;

    file << "Any sufficiently advanced technology is indistinguishable from magic.\n";
    pos = file.tellp();
    cout << "Current write position in file: " << pos << endl;

    file << "Technology is best when it brings people together.\n";
    pos = file.tellp();
    cout << "Current write position in file: " << pos << endl;

    file.close();

    return 0;
}
