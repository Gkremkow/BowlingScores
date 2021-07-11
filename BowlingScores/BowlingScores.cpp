#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>


using namespace std;

//The number of players and scores per player that we are keeping track of in our text document. Must be changed if the number of players goes up, or the number of scores per player goes up.
const int NUMPLAYERS = 10;
const int NUMSCORES = 5;

struct Bowler {
    string strBowlerName;
    int arrBowlerScore[NUMSCORES];
    double iAvgScore;
};

Bowler arrBowler[NUMPLAYERS]{

};

/*//Takes the input of our filename, the array of names, and the 2d array of scores and collects the info, returning true if successful, false if file failure.
bool GetBowlingData(const string FILENAME, string names[], int scores[][NUMSCORES]) {
    //Establishes I for a later loop
    int i = 0;

    //sets up our ifstream variable. An ifstream is only needed over an fstream since we are only inputing information from a text file.
    ifstream inFile;

    //opens our file and verifies it opens properly. If not returns false.
    inFile.open(FILENAME);
    if (!inFile)
    {
        cout << "Error with file name..." << endl;
        return false;
    }

    //Itterates the program through the file all the way to the end.
    while (!inFile.eof()) {

        //Stores the word at the beginning of each line as the current position (i) value in the names array.
        inFile >> names[i];

        //A for loop to handle the scores, itterating through to set up each value of the array for the cooresponding column (j) and row (i)
        for (int j = 0; j < NUMSCORES; j++)
        {
            inFile >> scores[i][j];
        }
        //Progresses our i variable each line of the document to update the name as well as the row assignment for the score 2d array
        i++;
    }

    //Closes our input file for cleanup
    inFile.close();

    //returns true of completes
    return true;
}

//A double pointer function to allow for the return of an array
double* GetAverageScore(int scores[][NUMSCORES]) {
    //Forms the local variable avgScore as a static due to returning arrays sometimes able to have strange results, however by making it static, independent of any part of the object, it prevents this.
    static double avgScore[NUMPLAYERS];
    double numberOfScores = NUMSCORES;

    //A nested for loop to itterate through all the scores for all of the players. Sum gets reset to 0 each time to ensure players scores don't get added into one another by mistake.
    for (int i = 0; i < NUMPLAYERS; i++) {
        int sum = 0;
        for (int j = 0; j < NUMSCORES; j++) {
            sum = sum + scores[i][j];
        }
        avgScore[i] = (sum / numberOfScores);
    }

    //returns the values of the entire array
    return avgScore;

}

//Void function to print out the player name, their scores, and average when called in a formated fashion.
void PrettyPrintResults(string names[], int scores[][NUMSCORES], double avgScore[]) {
    for (int i = 0; i < NUMPLAYERS; i++) {
        cout << left << setw(12) << names[i] << "";
        for (int j = 0; j < NUMSCORES; j++) {
            cout << right << setw(3) <<scores[i][j] << setw(3) << " ";
        }
        cout << "With an avg score of: " << avgScore[i] << "\n";
    }
}



int main()
{
    //sets our local variable constant incase document is desired to be changed.
    const string FILENAME = "BowlingScores.txt";

    //Our array bank for names, scores, and pointer variable for avgScore to allow us to return an array instead of a single value.
    string names[NUMPLAYERS];
    int scores[NUMPLAYERS][NUMSCORES];
    double *avgScore[NUMPLAYERS];

    //Calls out GetBowlingData function to store all names, and scores within our program.
    GetBowlingData(FILENAME, names, scores);

    //Sets the contents of our pointer array avgScore to the results of our GetAverageScore function when called.
    *avgScore = GetAverageScore(scores);
    
    //Calls our PrettyPrintResults function to output all desired data.
    PrettyPrintResults(names, scores, *avgScore);
}
*/

//Takes the input of our filename, and the empty structured array that we created as input to fill our structured array with the initial data needed for calculations
bool GetBowlingData(const string FILENAME, Bowler arrBowler[]) {
    //Establishes I for a later loop
    int i = 0;

    //sets up our ifstream variable. An ifstream is only needed over an fstream since we are only inputing information from a text file.
    ifstream inFile;

    //opens our file and verifies it opens properly. If not returns false.
    inFile.open(FILENAME);
    if (!inFile)
    {
        cout << "Error with file name..." << endl;
        return false;
    }

    //Itterates the program through the file all the way to the end.
    while (!inFile.eof()) {

        //Stores the word at the beginning of each line as the current position (i) value in the names array.
        inFile >> arrBowler[i].strBowlerName;

        //A for loop to handle the scores, itterating through to set up each value of the array for the cooresponding column (j) and row (i)
        for (int j = 0; j < NUMSCORES; j++)
        {
            inFile >> arrBowler[i].arrBowlerScore[j];
        }
        //Progresses our i variable each line of the document to update the name as well as the row assignment for the score 2d array
        i++;
    }

    //Closes our input file for cleanup
    inFile.close();

    //returns true of completes
    return true;
}

//A double pointer function to allow for the return of an array
void GetAverageScore(Bowler arrBowler[]) {
    //Sets our NUMSCORES global constant to a local variable in the form of a double to get the desired avg result. Due to sctructuring, the pointers needed before were no longer needed.
    double numberOfScores = NUMSCORES;

    //A nested for loop to itterate through all the scores for all of the players. Sum gets reset to 0 each time to ensure players scores don't get added into one another by mistake.
    for (int i = 0; i < NUMPLAYERS; i++) {
        int sum = 0;
        for (int j = 0; j < NUMSCORES; j++) {
            sum = sum + arrBowler[i].arrBowlerScore[j];
        }
        arrBowler[i].iAvgScore = (sum / numberOfScores);
    }


}

//Void function to print out the player name, their scores, and average when called in a formated fashion.
void PrettyPrintResults(Bowler arrBowler[]) {
    for (int i = 0; i < NUMPLAYERS; i++) {
        cout << left << setw(12) << arrBowler[i].strBowlerName << "";
        for (int j = 0; j < NUMSCORES; j++) {
            cout << right << setw(3) << arrBowler[i].arrBowlerScore[j] << setw(3) << " ";
        }
        cout << "With an avg score of: " << arrBowler[i].iAvgScore << "\n";
    }
}



int main()
{
    //sets our local variable constant incase document is desired to be changed.
    const string FILENAME = "BowlingScores.txt";

    //Calls out GetBowlingData function to store all names, and scores within our program.
    GetBowlingData(FILENAME, arrBowler);

    //Calls the GetAverageScore function to fill up the average score part of our structure array, taking our established structured array as input.
    GetAverageScore(arrBowler);

    //Calls our PrettyPrintResults function to output all desired data.
    PrettyPrintResults(arrBowler);
}