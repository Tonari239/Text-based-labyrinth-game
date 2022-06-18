using namespace std;
#include "engine.h"


int main()
{
	cout << "Choose your hero's race!" << endl;
	cout << "0 - human, 1 - mage, 2 -warrior" << endl;
	int race;
	do
	{
		cin >> race;
	} while (race < 0 && race >2);
	Hero hero((Race)race);
	system("CLS");
	cout << "Loading map..."<<endl;
	GameEngine gameEngine(hero);

	Engine engine(gameEngine);

	try
	{
		engine.run();
	}
	catch (const std::exception&)
	{
		cout << "Exiting program...";
		return -1;
	}
	

	
}