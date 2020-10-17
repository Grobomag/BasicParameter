#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	//nesessary variables
	int baseParam = 1;
	int seqLength = 0;
	//int* data = new int[seqLength];


	//reading sequence
	ifstream file("400.txt");
	ifstream in("400.txt");
	char a[10000];
	while (!in.eof())
	{
		in >> a;
		seqLength++;
	}

	cout << "size = " << seqLength << "\n";
	int* data = new int[seqLength];
	for (int i = 0; file.good() && i<seqLength; i++)
	{
		file >> data[i];
		cout << data[i] << "  ";
		cout << endl;
	}

	file.close();

	//search algorythm
	for (baseParam; baseParam < seqLength - 1; baseParam++) {
		bool wordEq = false;
		cout << "test base parameter: " << baseParam;
		for (int currentPosition = baseParam; currentPosition <= seqLength - baseParam; currentPosition++) {
			bool localUnEqual = false;
			for (int search = 0; search < currentPosition; search++) {
				localUnEqual = false;
				//cout << endl;
				for (int equalPoint = 0; equalPoint < baseParam; equalPoint++) {
					//cout << data[search + equalPoint];
					if (data[currentPosition + equalPoint] != data[search + equalPoint]) {
						localUnEqual = true;
						break;
					}
					//else a[equalPoint] = data[search + equalPoint];
				}
				if (!localUnEqual) {
					wordEq = true;
					break;
				}
			}
		}
		cout << endl;
		if (!wordEq) break;
		else cout << "not that"  << endl;
	}
	cout << baseParam;

	//wait for action
	cin.get();

	return 0;
}