#include "Menu.h"
void menu()
{
	int choose[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	string username_1 = "";
	string username_2 = "";

	while (true)
	{
		system("cls");
		cout << "\n _______  _______  __   __  _______    ______   _______  __   __    _______  __   __  _______  __    _  _______ ";
		cout << "\n|       ||   _   ||  |_|  ||       |  |      | |   _   ||  | |  |  |       ||  | |  ||       ||  |  | ||       |";
		cout << "\n|    ___||  |_|  ||       ||    ___|  |  _    ||  |_|  ||  | |  |  |_     _||  | |  ||   _   ||   |_| ||    ___|";
		cout << "\n|   | __ |       ||       ||   |___   | | |   ||       ||  |_|  |    |   |  |  |_|  ||  | |  ||       ||   | __ ";
		cout << "\n|   ||  ||       ||       ||    ___|  | |_|   ||       ||       |    |   |  |       ||  |_|  ||  _    ||   ||  |";
		cout << "\n|   |_| ||   _   || ||_|| ||   |___   |       ||   _   ||       |    |   |  |       ||       || | |   ||   |_| |";
		cout << "\n|_______||__| |__||_|   |_||_______|  |______| |__| |__||_______|    |___|  |_______||_______||_|  |__||_______|";

		cout << "\n";
		cout << "\nMAIN MENU";
		cout << "\n		1. (PLAYER vs PC) or (PLAYER vs PLAYER)";
		cout << "\n		2. LOG VIEW";
		cout << "\n		3. INPUT HERO";
		cout << "\n		4. EXIT";
		cout << "\n		INPUT OPTION: ";
		cin >> choose[1];
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		if (choose[1] == 1)
		{
			choose[2] = 0;
			while (choose[2] != 3)
			{

				system("cls");
				cout << "\nSUB MENU";
				cout << "\n		1. (PLAYER vs PC)";
				cout << "\n		2. (PLAYER vs PLAYER)";
				cout << "\n		3. BACK TO MAIN MENU";
				cout << "\n		INPUT OPTION: ";
				cin >> choose[2];
				cin.clear();
				cin.ignore(INT_MAX, '\n');

				if (choose[2] == 1)
				{
					system("cls");

					GAME game;
					cout << "\nINPUT USERNAME-1 ....... ";
					getline(cin, username_1);

					system("cls");

					game.setMode(1);
					game.setNameForUser1(username_1);
					game.setNameForUser2("PC");
					game.selectChampion();
					game.commonProcessing();

					system("cls");

					game.showMatch();
					game.fighting();

					system("cls");

					game.print();
					game.saveLog();

					system("pause");
					system("cls");

					cout << "\nSUB MENU";
					cout << "\n		1. EXIT";
					cout << "\n		2. PLAY AGAIN";
					cout << "\n		INPUT OPTION: ";
					cin >> choose[3];
					cin.clear();
					cin.ignore(INT_MAX, '\n');

					if (choose[3] == 1)
					{
						exit(0);
					}
				}
				if (choose[2] == 2)
				{
					system("cls");

					cout << "\nINPUT USERNAME-1 ....... ";
					getline(cin, username_1);
					cout << "\nINPUT USERNAME-2 ....... ";
					getline(cin, username_2);

					system("cls");

					GAME game;
					game.setMode(2);
					game.setNameForUser1(username_1);
					game.setNameForUser2(username_2);
					game.selectChampion();

					system("cls");

					game.commonProcessing();

					system("cls");

					game.showMatch();
					game.fighting();

					system("cls");

					game.print();
					game.saveLog();

					system("pause");
					system("cls");

					cout << "\nSUB MENU";
					cout << "\n		1. EXIT";
					cout << "\n		2. PLAY AGAIN";
					cout << "\n		INPUT OPTION: ";
					cin >> choose[4];
					cin.clear();
					cin.ignore(INT_MAX, '\n');

					if (choose[4] == 1)
					{
						exit(0);
					}
				}
			}
		}
		if (choose[1] == 2)
		{
			choose[5] = 0;
			while (choose[5] != 1)
			{
				system("cls");

				cout << "\nSUB MENU";
				cout << "\n		1. EXIT";
				cout << "\n		2. LOG VIEW";
				cout << "\n		INPUT OPTION: ";
				cin >> choose[5];
				cin.clear();
				cin.ignore(INT_MAX, '\n');

				if (choose[5] == 2)
				{
					system("cls");
					LOG x;
					x.readLog();
					x.showLogDetailed();
					system("pause");
				}
			}
			system("cls");

			cout << "\nSUB MENU";
			cout << "\n		1. EXIT";
			cout << "\n		2. BACK TO MAIN MENU";
			cout << "\n		INPUT OPTION: ";
			cin >> choose[6];
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			if (choose[6] == 1)
			{
				exit(0);
			}
		}
		if (choose[1] == 3)
		{
			choose[7] = 0;
			while (choose[7] != 1)
			{
				system("cls");

				cout << "\nSUB MENU";
				cout << "\n		1. EXIT";
				cout << "\n		2. INPUT HERO";
				cout << "\n		3. DELETE HERO";
				cout << "\n		INPUT OPTION: ";
				cin >> choose[7];
				cin.clear();
				cin.ignore(INT_MAX, '\n');

				if (choose[7] == 2)
				{
					system("cls");
					GAME game;
					game.addChampion();
					system("pause");
				}
				if (choose[7] == 3)
				{
					system("cls");
					GAME game;
					game.deleteChampion();
					system("pause");
				}
			}
			system("cls");

			cout << "\nSUB MENU";
			cout << "\n		1. EXIT";
			cout << "\n		2. BACK TO MAIN MENU";
			cout << "\n		INPUT OPTION: ";
			cin >> choose[8];
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			if (choose[8] == 1)
			{
				exit(0);
			}
		}

		if (choose[1] == 4)
		{
			exit(0);
		}
	}
}
