#include <iostream>
#include <iomanip>      // Set Precision
using namespace std;

char* letterGrades(int*, int);
double* studentsAverage(int*, int);

int main()
{
	const int SIZE = 25;
	
	int scores[SIZE];
	int *scoresPtr = nullptr;
	char* scoresLetterPtr = nullptr;

	int score;

	cout << "Input 25 students' scores: \n";

	scoresPtr = scores;

	for(int i = 0; i < SIZE; i++)
	{
		cout << "Student " << i + 1 << ": ";
		cin >> score;

		if (score >= 0 && score <= 100)
		{
			scores[i] = score;
			scoresLetterPtr = letterGrades(scoresPtr, SIZE);
			cout << "The student letter score is: " << *scoresLetterPtr << "\n\n";
		}

		else
		{
			cout << "Invalid input! (0-100)\n";
			i--;
		}
	}

	double* averageScorePtr = studentsAverage(scoresPtr, SIZE);
	cout << "The students average score is: " << fixed << setprecision(2) << *averageScorePtr << endl;

	delete[] scoresPtr;
	delete[] averageScorePtr;
	delete[] scoresLetterPtr;
	
	scoresPtr = nullptr;
	averageScorePtr = nullptr;
	scoresLetterPtr = nullptr;
	
	return 0;
}

char *letterGrades(int *scores, int SIZE)
{
	char* letterGradesptr = nullptr;

	letterGradesptr = new char[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		if (scores[i] >= 90 && scores[i] <= 100)
			*letterGradesptr = 'A';

		else if (scores[i] >= 80 && scores[i] < 90)
			*letterGradesptr = 'B';

		else if (scores[i] >= 70 && scores[i] < 80)
			*letterGradesptr = 'C';

		else if (scores[i] >= 60 && scores[i] < 70)
			*letterGradesptr = 'D';
		
		else if (scores[i] >= 0 && scores[i] < 60)
			*letterGradesptr = 'F';
	}

	return letterGradesptr;
}

double* studentsAverage(int* scores, int SIZE)
{
	double total = 0;
	int belowAverage = 0;
	double* average = nullptr;
	
	average = new double;

	for (int i = 0; i < SIZE; i++)
	{
		if (scores[i] < 60)
		{
			total += scores[i];
			belowAverage++;
		}
	}
		
	*average = total / belowAverage;
	
	return average;
}
