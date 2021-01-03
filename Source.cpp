#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
int menuMain();
int menuClient();

template <class T>
class Document {
	T data;
public:
	Document() {}
	Document(T dat) {
		data = dat;
	}
	void Show() {
		cout << data << endl;
	}
	void Change(T dat) {
		data = dat;
	}
	void Add(T dat) {
		data += dat;
	}
	~Document()
	{
		//cout << "Объект удален" << endl;
	}
};

template <class T1>
struct Status {
	T1* RealPtr;
	int Count;
};

template<class T1>
class SmartDocument {
	Status<T1>* StatPtr;
public:
	T1* operator->()const {
		if (StatPtr) return StatPtr->RealPtr;
		else return NULL;
	}
	SmartDocument(T1* ptr = 0) {
		if (!ptr) StatPtr = NULL;
		else {
			StatPtr = new Status<T1>;
			StatPtr->RealPtr = ptr;
			StatPtr->Count = 1;
		}
	}
	SmartDocument(const SmartDocument<T1>& p) :StatPtr(p.StatPtr) {
		if (StatPtr) StatPtr->Count++;
	}
	SmartDocument<T1>& operator=(const SmartDocument<T1>& p) {
		if (StatPtr) {
			StatPtr->Count--;
			if (StatPtr->Count <= 0) {
				delete StatPtr->RealPtr;
				delete StatPtr;
			}
		}
		StatPtr = p.StatPtr;
		if (StatPtr) StatPtr->Count++;
		return *this;
	}
	~SmartDocument() {
		if (StatPtr) {
			StatPtr->Count--;
			if (StatPtr->Count <= 0) {
				delete StatPtr->RealPtr;
				delete StatPtr;
			}
		}
		cout << "Указатель удален" << endl;
	}
};

int main() {
	setlocale(0, " ");
	SmartDocument<Document<string>> pt1(new Document<string>);
	SmartDocument<Document<string>> pt2 = pt1;
	SmartDocument<Document<string>> pt3(new Document<string>);
	SmartDocument<Document<string>> pt4 = pt3;
	string str;
	bool exit;
	while (true) {
		switch (menuClient()) {
		case 0:
			exit = true;
			while (exit) {
				switch (menuMain())
				{
				case 0:
					cout << "Введите информацию, которую хотите добавить:";
					cin >> str;
					pt1->Add(str);
					break;
				case 1:
					cout << "Введите информацию, которую хотите добавить:";
					cin >> str;
					pt3->Add(str);
					break;
				case 2:
					cout << "Введите информацию:";
					cin >> str;
					pt1->Change(str);
					break;
				case 3:
					cout << "Введите информацию:";
					cin >> str;
					pt3->Change(str);
					break;
				case 4:
					cout << "\tДокумент №1" << endl;
					pt1->Show();
					cout << "\tДокумент №2" << endl;
					pt3->Show();
					system("pause");
					break;
				case 5:
					exit = false;
					break;
				}
			}
			break;
		case 1:
			exit = true;
			while (exit) {
				switch (menuMain())
				{
				case 0:
					cout << "Введите информацию, которую хотите добавить:";
					cin >> str;
					pt2->Add(str);
					break;
				case 1:
					cout << "Введите информацию, которую хотите добавить:";
					cin >> str;
					pt4->Add(str);
					break;
				case 2:
					cout << "Введите информацию:";
					cin >> str;
					pt2->Change(str);
					break;
				case 3:
					cout << "Введите информацию:";
					cin >> str;
					pt4->Change(str);
					break;
				case 4:
					cout << "\tДокумент №1" << endl;
					pt2->Show();
					cout << "\tДокумент №2" << endl;
					pt4->Show();
					system("pause");
					break;
				case 5:
					exit = false;
					break;
				}
			}
			break;
		case 2:
			cout << "Документы сформированы" << endl;
			/*cout << "\tДокументация 1" << endl;
			pt1->Show();
			cout << "\tДокументация 2" << endl;
			pt3->Show();*/
			return 0;
		}
	}
}


int menuMain()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 6) % 6;

     if (choiceButton == 0) cout << "->Добавление информации к первому документу" << endl;
     else cout << "Добавление информации к первой документации" << endl;

	if (choiceButton == 1) cout << "->Добавление информации ко второму документу" << endl;
	else cout << "Добавление информации ко второй документации" << endl;

	if (choiceButton == 2) cout << "->Изменение первого документа" << endl;
	else cout << "Изменение первой документации" << endl;
	
	if (choiceButton == 3) cout << "->Изменение второго документа" << endl;
	else cout << "Изменение второй документации" << endl;

	if (choiceButton == 4) cout << "->Просмотр всех документов" << endl;
	else cout << "Просмотр всех документов" << endl;

	if (choiceButton == 5) cout << "->Выход" << endl;
	else cout << "Выход" << endl;

button = _getch();
if (button == 224)
{
	button = _getch();
	if (button == 72) choiceButton--;
	if (button == 80) choiceButton++;
}
if (button == 13) {
	system("cls");
	return choiceButton;
}
system("cls");
  }
}

int menuClient()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 3) % 3;

		if (choiceButton == 0) cout << "->Сотрудник №1" << endl;
		else cout << "Сотрудник №1" << endl;

		if (choiceButton == 1) cout << "->Сотрудник №2" << endl;
		else cout << "Сотрудник №2" << endl;

		if (choiceButton == 2) cout << "->Прекратить работу с документами" << endl;
		else cout << "Прекратить работу с документами" << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) {
			system("cls");
			return choiceButton;
		}
		system("cls");
	}
}