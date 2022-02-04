#include <string>
#include <iostream>

using namespace std;

struct student
{

	char name[25];
	int HWK1;
	int HWK2;
	int HWK3;
	int EXAM1;
	int EXAM2;
	int totalHWK;
	int totalEXAM;
	int classPerc;
	char grade[3];

};

void inputname(struct student s[], int n)
{

	for (int i = 0; i < n; i++)
	{

		cout << "Please enter the students name: ";
		cin.getline(s[i].name, 25);

		cout << "What is the HWK 1 score: ";
		cin >> s[i].HWK1;

		cout << "What is the HWK 2 score: ";
		cin >> s[i].HWK2;

		cout << "What is the HWK 3 score: ";
		cin >> s[i].HWK3;

		cout << "What is the EXAM 1 score: ";
		cin >> s[i].EXAM1;

		cout << "What is the EXAM 2 score: ";
		cin >> s[i].EXAM2;

		cout << "\n\n";
		getchar();

	}

}

void calc(struct student s[], int n)
{
	
	for (int i = 0; i < n; i++)
	{

		s[i].totalHWK = s[i].HWK1 + s[i].HWK2 + s[i].HWK3;
		s[i].totalEXAM = s[i].EXAM1 + s[i].EXAM2;

		s[i].classPerc = (s[i].totalHWK / 1.875) + (s[i].totalEXAM / 3.333);

	}

}

void letterGrade(struct student s[], int n)
{

	for (int i = 0; i < n; i++)
	{

		if (90 <= s[i].classPerc && s[i].classPerc <= 100)
		{

			strcpy_s(s[i].grade, "A");

		}
		else if (80 <= s[i].classPerc && s[i].classPerc < 90)
		{

			strcpy_s(s[i].grade, "B");

		}
		else if (70 <= s[i].classPerc && s[i].classPerc < 80)
		{

			strcpy_s(s[i].grade, "C");

		}
		else if (60 <= s[i].classPerc && s[i].classPerc < 70)
		{

			strcpy_s(s[i].grade, "D");

		}
		else
		{

			strcpy_s(s[i].grade, "F");

		}

	}

}

void print(struct student s[], int n)
{

	for (int i = 0; i < n; i++)
	{

		cout << "Student Name : " << s[i].name << endl;
		cout << "Total Homework Points: " << s[i].totalHWK << endl;
		cout << "Total Exam Points: " << s[i].totalEXAM << endl;
		cout << "Percentage: " << s[i].classPerc << endl;
		cout << "Letter Grade: " << s[i].grade << endl;
		cout << "\n";

	}

}

void average(struct student s[], int n)
{
	int total1 = 0;
	int total2 = 0;
	int averageExam1 = 0;
	int averageExam2 = 0;

	for (int i = 0; i < n; i++)
	{

		total1 += s[i].EXAM1;
		total2 += s[i].EXAM2;

	}

	averageExam1 = total1 / n;
	averageExam2 = total2 / n;

	cout << "\n";
	cout << "The class average for Exam 1 is: " << averageExam1 << endl;
	cout << "The class average for Exam 2 is: " << averageExam2 << endl;

}

void totalLetter(struct student s[], int n)
{

	int a = 0, b = 0, c = 0, d = 0, f = 0;

	for (int i = 0; i < n; i++)
	{

		if (90 <= s[i].classPerc && s[i].classPerc <= 100)
		{

			a++;

		}
		else if (80 <= s[i].classPerc && s[i].classPerc < 90)
		{

			b++;

		}
		else if (70 <= s[i].classPerc && s[i].classPerc < 80)
		{

			c++;

		}
		else if (60 <= s[i].classPerc && s[i].classPerc < 70)
		{

			d++;

		}
		else
		{

			f++;

		}

	}

	cout << "\n\n";
	cout << "Total number of A's in the class: " << a << endl;
	cout << "Total number of B's in the class: " << b << endl;
	cout << "Total number of C's in the class: " << c << endl;
	cout << "Total number of D's in the class: " << d << endl;
	cout << "Total number of F's in the class: " << f << endl;

}

int main()
{

	//5 is the number of students to be inputed

	struct student s[5];
	inputname(s, 5);
	calc(s, 5);
	letterGrade(s, 5);
	print(s, 5);
	average(s, 5);
	totalLetter(s, 5);

}
