#include <iostream>

using namespace std;

int funcLetter(double av) //Return number to select ScoreLetter
{
    if(av >= 80 && av <= 100)
        return 0;
    if(av >= 70 && av <= 89.99)
        return 1;
    if(av >= 60 && av <= 79.99)
        return 2;
    if(av >= 50 && av <= 59.99)
        return 3;
    else
        return 4;
}
void displayResults(string name[], int nameSize, double passMarks[],int markSize,double average[],int avSize)
{
    char scoreLetter[5] = {'A','B','C','D','F'};

    for(int j=0;j<nameSize;j++)
    {
        cout << "#" << (j+1) << ": " << name[j] << "\t";
        cout << average[j] << " = " << scoreLetter[funcLetter(average[j])] << endl;
    }
}

int main()
{
    const int NAME_LENGTH = 2; //Number of student
    const int MARKS_LENGTH = 4; //Number of Marks required

    string name[NAME_LENGTH];
    double marks[MARKS_LENGTH], averageDb[NAME_LENGTH], average = 0.0, total = 0;

    for(int j=0;j<NAME_LENGTH;j++)
    {
        string validateName;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Enter name: #" << (j+1) << ": ";
        while (cin >> validateName)
        {
            if (isdigit(validateName[j]) == false)
                {
                    name[j] = validateName;
                    break;
                } else {
                    cout << "ERROR_INVALID_NAME! Please enter valid Name: ";
                    cin.clear();
                }
        }

        for(int i=0;i<MARKS_LENGTH;i++)
        {
            cout << "Enter mark score: ";
            while (!(cin >> marks[i]) || marks[i]<0 || marks[i]>100)
            {
                cout << "ERROR_INVALID_INPUT: Please enter valid mark between [0-100]: ";
                cin.clear();
                cin.ignore(132, '\n');
            }
            total += marks[i];
        }

        average = total/MARKS_LENGTH;
        total = 0; //Reset total
        averageDb[j] = average;
    }
    cout << endl;
    //Print out results
    //call result function
    displayResults(name,NAME_LENGTH,marks,MARKS_LENGTH,averageDb,NAME_LENGTH);

    return 0;
}
