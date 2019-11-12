
//------------------------------------------------------------
  Authors: Priyanka Patel and Parvathi Krishnan
  Lab: Tues 1pm
  System: Codio
//------------------------------------------------------------



#include <iostream>
#include <string>
#include <fstream>      // For file input
#include <vector>		// For dictionary vector
#include <iomanip>		// For setw()
#include <cctype>       // For tolower()
#include <algorithm>
using namespace std;

void printLines(int input1, int input2, vector<string> &dictionary)                   //This function will correspond to case 2, where
{                                                                                       // it will display some dictionary words
    
    for (int i = input1; i <= input2; i++)
    { 
        
        cout << setw(5) <<  i<< " " << dictionary[i] << endl;  
        
    }
     cout << endl;     
}

int numWords ( vector<string> &dictionary, int &lengthOfWordsToUse)                      //This function will count how many words
                                                                                         //are of each length in the dictionary
{                                                                                  
    int counter = 0;                                                                     //this will keep track of the number of a specific length
    
    for (int i=0; i < dictionary.size(); i++)
    {
        if (dictionary[i].length() == lengthOfWordsToUse)
        {
            counter++;
        }
    }
    return counter;
    
}
//----------------------------------------------------------------------------------------
void displayIdInfo()                                                                  //This function will display ID information
{ 
    cout<< "Program #3: Work Play\n"
         << "Author: Dale Reed\n"
         << "Lab: Tues 8am\n"
         << "System:  Codio\n";
         
}
//-----------------------------------------------------------------------------------------

void readInWordsFromFile(int &lengthOfWordsToUse, vector<string> &dictionary)          //This function will read in the words in                                                                                     //the dictionary txt file and store it 
{                                                                                      // in a vector
    ifstream inputFileStream;
    string fileName = "dictionary.txt";                                               // C string (array of char) to store filename
    string inputWord;				                                                  // stores each word as it is read
    inputFileStream.open(fileName.c_str());                                           // Open input file
	    
    if( !inputFileStream.is_open())                                                   // Verify that the open worked
    {                                                 
        cout << "Could not find input file " << fileName << "  Exiting..." << endl;
        exit( -1);
    }
    
    while(inputFileStream >> inputWord) 	                                        // Read all the words from the file, and display them
    {  
        for(int i=0; i < inputWord.length(); i++)
        {
            inputWord[i] = tolower(inputWord[i]);
        }
        
        if (inputWord.size() == lengthOfWordsToUse)
        {
            dictionary.push_back(inputWord);
        }
    }    
   
    inputFileStream.close();                                                        // Close the input file.
}
//--------------------------------------------------------------------------------------
                                                                                 // this function will search through using binary searchWord
                                                                                 // and check if the word is in the dictionary vector

long binarySearch(
            string searchWord,                                                   // word to be looked up
            vector< string> dictionary)                                          // the dictionary of words
{
    long low, mid, high;                                                         // array indices for binary search
    long searchResult = -1;                                                      // Stores index of word if search succeeded, else -1
    
                                                                                  // Binary search for word
    low = 0;
    high = dictionary.size() - 1;
    while ( low <= high)  {
        mid = (low + high) / 2;
                                                                                   // SearchResult negative value means word is to the left,
                                                                                  //  positive value means
                                                                                  // word is to the right, value of 0 means word was found
        searchResult = searchWord.compare( dictionary[ mid] );
        if ( searchResult == 0)  {
                                                                                  // Word IS in dictionary, so return the index where the word was found
            return mid;
        }
        else if (searchResult < 0)  {
            high = mid - 1;                                                       // word should be located before the mid location
        }
        else  {
            low = mid + 1;                                                        // word should be located after the mid location
        }
    }
                                                                                   // Word was not found
    return -1;
}                                                                                 //end binarySearch()
//--------------------------------------------------------------------------------------
void countWords(vector <string> &dictionary, vector <int> &nums)                   //function countWords() will count the number of words of each
                                                                                   //letter and add it to a vector, which will then display them
{
   int counter=0;                                                                   // this will keep track of the number of words for each length
   int totalCounter=0;                                                              //this will keep track of the total num of words in the dictionary
     
   for(int j = 0; j <=50; j++)                                                      //loop to see if each length is equal to the index that it's searching
   {      
        for(int i = 0; i < dictionary.size(); i++)
        {
            if (dictionary[i].size() == j) 
            {
                counter++;              
            }     
        }                                                                            //cout << counter;
       nums.push_back(counter);
       counter = 0;
   }
    for(int i = 0; i < dictionary.size(); i++)                                       //This will count the total number of words
    {
        totalCounter++;
    }
    
    cout << "Total number of words in dictionary file: " << totalCounter << endl << endl;
    cout << "Word lengths where there are more than 1400 words:" << endl
            << "Length"<< "  " << "How Many" << endl << "------"<< "  "<<"--------" << endl;
   
    for(int i =3; i < 18; i++)
   {       
       cout << setw(5) << i << "   " << setw(7) << nums[i] << endl;
   }  
    cout << endl;  
}
//--------------------------------------------------------------------------------------
int wordDifference(string currentWord, string &userWordInput, int lengthOfWordsToUse)         //This will take two words and return 
                                                                                              //the number of characters different
{
    int wordCount = 0;                                                                        //variable to keep track of the characters different
    for(int i = 0; i < lengthOfWordsToUse; i++)
    {
        if(currentWord[i] != userWordInput[i])
        {
            wordCount++;
        }
    }
    return wordCount;
}
//--------------------------------------------------------------------------------------
void wordChangeGame (string &startWord, string &endWord, vector<string> &dictionary, int lengthOfWordsToUse)       //function corresponds to case 4-- word change game
{
    cout << endl;
    string userWordInput;                                                                                       //this will be the user input for the next word
    string currentWord = startWord;
    int i=1; 
    cout <<endl <<" " << i << ". Previous word is " << "\'" << startWord <<"\'." << "\t" << "Next word: " ;  
    cin >> userWordInput;
    int checkForWord = binarySearch(userWordInput, dictionary);                                                 //this will check if the word is in the dictionary
    
    while(userWordInput != endWord)
    {
        if (userWordInput == "exit")                                                                            //this will break if "exit" is the user input
        {
            break;
        }
        else if(userWordInput.size() == lengthOfWordsToUse)
        {
                
            cout << setw(1) <<" " << ++i << ". Previous word is " << "\'" << userWordInput << "\'."  << "Next word: " ;
                
            currentWord = userWordInput;
                
            cin >> userWordInput; 
            if (userWordInput == "exit")                                                                         //this will break if "exit" is the user input
            {
                break;
            }
            
            cout << endl;
        }
        else if(userWordInput.size() != lengthOfWordsToUse)
        {
           //This checks to see if the word is not the same length as the variable lengthOfWordsToUse     
            cout << "   *** " << "'" << userWordInput << "'" << " is not of length " << lengthOfWordsToUse << ". Please retry." << endl;  
            
            cin >> userWordInput; 
            cout  <<" " << i << ". Previous word is " << "\'" << startWord << "\'."  << "Next word: " ;
            if (userWordInput == "exit")
            {                                                                                                    //this will exit if "exit" is the user input
                break;
            }     
            cout << endl;
        }
            
        if (checkForWord != -1)                                                                                    //this checks to see if word is in dictionary
        {  
            if (wordDifference(currentWord, userWordInput, lengthOfWordsToUse) == 1)
            {
                cout << "  " << ++i << ". Previous word is " << "\'" << userWordInput << "\'."  << "Next word: " ;      //moves to the next step if it is 
                currentWord = userWordInput;                                                                            // in the dictionary
                cin >> userWordInput; 
                cout << endl;
            }      
            else
            {
                cout << "   *** " << "'" << userWordInput << "'" << " must be exactly 1 character different.  Please retry.";
                cout << " " << i << ". Previous word is " << "\'" << startWord << "\'. " << "\t" << "Next word: " ;
                cin  >> userWordInput;
                
                if (userWordInput == "exit")                                                                           //this will exit if "exit" is the user input
                {
                    break;
                }               
            } 
        }
        
        else if (checkForWord == -1)                                                                                  //this will prompt user to print another
         {                                                                                                            //word if it's not in dictionary
            cout << "Not in dictionary, print out another word: ";
            cin >> userWordInput;
         }            
     }    
 
     if (userWordInput == endWord)
     {
         cout << "Congratulations, you did it!" << endl;                                                             //winning sequence was found
     }        
}   

//--------------------------------------------------------------------------------------
void expandWords(string &startWord, string &endWord, vector <string> &dictionary, vector<string> &successionWords, vector<int> &successionIndex, bool &z, int &mode, vector <string> &temp, int &lengthOfWordsToUse, vector <int> &start, vector <int> &end, vector <int> &finalVec)
{    
    int temp2=0;                
    for(int i=0; i < lengthOfWordsToUse; i++)
    {  
        string newWord = startWord;
        for (char x = 'a'; x <= 'z'; x++)                               //go through each letter of the alphabet and check if its a word
        {  
            newWord[i] = x;
            
            if ((binarySearch(newWord, dictionary) != -1) && (!(find(successionWords.begin(), successionWords.end(),newWord) != successionWords.end())) )             //checks if the word is in the dictionary and if the index is not the last of successionWords
            {
                temp.push_back(newWord);                                //this will add the word to the temp array, which will 
                temp2++;
                successionWords.push_back(newWord);                     //adds a part of the "winning sequence" to successionWords
                successionIndex.push_back(distance(successionWords.begin(), find(successionWords.begin(), successionWords.end(), newWord)));   //adds it to the successionIndex of newWord in successionWords  
            }      
                
            if(newWord == endWord)
            {
                z=true; /***** Identifier not meaningful enough: z - Clark *****/
                if(mode == 0)
                {
                    for(int i = 0; i < temp.size(); i++)                                                                             //this will print the column of words that changed by one letter 
                    {
                        cout << distance(successionWords.begin(), find(successionWords.begin(), successionWords.end(), temp[i])) << ":" << temp [i] << " ";
                    }
                }
                
                
                successionWords.push_back(newWord);
                successionIndex.push_back(distance(successionWords.begin(), find(successionWords.begin(), successionWords.end(), newWord))); 
                end.push_back(successionIndex[successionIndex.size()-1]);
                if(temp2 != 0)
                {
                    start.push_back(successionIndex[successionIndex.size()- temp2]);                               //adds the word in successionWords if its a word 
                }                                                                                                  // in the dictionary, with its corresponding vector
                else
                {
                    start.push_back(successionIndex[successionIndex.size()-1]);
                }
                return;
            }      
             
        }
        if (mode == 0)
        { 
            
            for(int i = 0; i < temp.size(); i++)
                {
                    cout << distance(successionWords.begin(), find(successionWords.begin(), successionWords.end(), temp[i])) << ":" << temp [i] << " ";

                }       
                temp.clear();
        }
    }
    end.push_back(successionIndex[successionIndex.size()-1]);
    if(temp2 != 0)
    {
        start.push_back(successionIndex[successionIndex.size()- temp2]);
    }
    else
    {
        start.push_back(successionIndex[successionIndex.size()-1]);
    }     
}


void findEndWord (string &startWord, string &endWord, vector <string> &dictionary, vector<string> &successionWords, vector<int> &successionIndex, bool z, int mode , vector<string> temp, int &lengthOfWordsToUse, vector <int> &start, vector <int> &end, vector <int> &finalVec)
{
        int i=0;/***** Need more comment in the function - Clark *****/
        string currentWord;
        int currentIndex=0;
        successionWords.push_back(startWord);
        successionIndex.push_back(-1);
        
        cout << endl;
        while(i < successionWords.size())
        {
            currentWord = successionWords[i];
            if(mode == 0)                                                      //mode 0 is for case 5 only, and will print the debug
            {   
                cout << currentIndex << ". " << currentWord << ": " << setw(5);
            }
            
            expandWords(currentWord , endWord, dictionary, successionWords, successionIndex, z, mode, temp, lengthOfWordsToUse, start, end, finalVec);  //calling this function to go through all possibilities
            if(mode == 0)
            {
                cout << endl;
            }
            
            i++;
            currentIndex++;
            
            if(z==true)
            {
                 if( mode == 0 || mode == 1)                                //only prints for cases 5 and 6
                 {   
                    cout << "Winning sequence was found!" << endl;        //winning sequence was found   
                    
                 }
                break;
            }               
        }
    
        int index = end[end.size()-1];
        finalVec.push_back(index);                                       //finds the winning sequence elements and adds it to finalVec
        int x = 0;
        
        while(index != 0)
        {
            if((start[x] <= index) && (index <= end[x]))                  //checks the parallel vectors to see if the element is b/w the the range of start and end
            {
                index = x;
                finalVec.push_back(index);
                x = 0;
                continue;
            }
            x++;
        }   
}
//--------------------------------------------------------------------------------------
void case7 (vector <int> &finalVec, vector<string> &successionWords)                       //this function correpsonds to case 7
{
    cout << "Winning sequence in reverse order is:" << endl;
    for(int i = 0; i <= finalVec.size()-1; i++)                                              //printing the winning sequence that was stored in finalVec
    {
        cout << setw(5) << finalVec[i] << ". " << successionWords[finalVec[i]] << endl;
    }
}
//--------------------------------------------------------------------------------------

int main()
{
    vector< string> dictionary;    		                                              // Vector of dictionary words read in from file
    vector< string> dict;                                                        
    int lengthOfWordsToUse=3;                                                        //supposed to store words with size 'lengthOfWordsToUse'
    string startWord = "dog";                                                        // The start word for transformation
    string endWord = "cat";                                                          // The end word for transformation
    int menuOption = -1;                                                             // User menu option selection
    int input1;                                                                      //this is the start index for printing words
    int input2;                                                                      //this is the end index for printing words
    vector <string> temp;                                                            //temp vector to add to when finding winning sequence using parallel vectors
    vector<string> successionWords;                                                  //vector containing words with one letter change
    vector<int> successionIndex;                                                      //vector containing indeces corresponding to the successionWords
    readInWordsFromFile(lengthOfWordsToUse, dictionary);                             //prompt the txt file to read words from the file
    vector<int> start;                                                               //parallel vectors "start"
    vector <int> end;                                                                 //parallel vectors "end"
    vector <int> finalVec;                                                             //this will store the winning sequence
    
    int count = 0;
    string line;
    vector <int> nums;
    int numberOfCalls = 0;
    string starting = "starting";
    string ending = "ending";
    displayIdInfo();
    
    for(int i = 1; i <=50; i++)                    //add the words from the file into a vector called dict 
    {
        readInWordsFromFile(i, dict);
    }
    
    bool z=false;                                 //boolean to see if endword is found
    int mode=0;                                   //for cases 5-7 where it uses the same function but outputs different things
        countWords(dict, nums);                       //this will present the chart of each letter with the amount of words
                                                      //with that specific length
    // Seed the random number generator
    srand( 1);  // Change 1 to time(0) for non-predictable results, but leave as 1 for testing

    // Menu display and handling infinite loop
    do {
        cout << "Currently we have " << nums[lengthOfWordsToUse] << " words of length "
             << lengthOfWordsToUse << " in the dictionary.\n"
             << "Changing from '" << startWord << "' to '" << endWord << "'" << endl
             << endl;
        
        cout << "Choose from the following options:\n"
             << "   1. Change the word length\n"
             << "   2. Display some dictionary words\n"
             << "   3. Get start and end words\n"
             << "   4. Play the word change game\n"
             << "   5. Find the end word with debug\n"
             << "   6. Find the end word\n"
             << "   7. Display an answer sequence\n"
             << "   8. Exit the program\n"
             << "Your choice -> ";
        cin >> menuOption;
   
        switch (menuOption)                                                                   //options for menuOption
        {
            case 1: //change the word length      
                
                cout << "What length words do you want to use? ";
                cin >> lengthOfWordsToUse;
                
                if (lengthOfWordsToUse != 3)
                {
                    startWord = "";
                    endWord = "";
                    
                }
                
                readInWordsFromFile(lengthOfWordsToUse, dictionary);
                break;
                
            case 2:  //display some dictionary words
                
                cout << "Enter the start and end index values of words to display: ";
                cin >> input1 >> input2;    
                cout << "About to display dictionary words from 1 to 10" << endl;
                
                printLines(input1, input2, dictionary);            
                break;
                
            case 3:    //this will change the starting and ending word            
                
                cout <<"Enter starting word, or \'r\' for a random word: " ;
                cin >> startWord;
                
                if(startWord == "exit" )
                {                                                         
                    cout << "Exiting program." << endl;
                    exit(-1);
                }
                else if(startWord == "r")
                {                                                       //creates a random number from 0 to size of dictionary and
                    int startIndex;                                     // finds the word at that index
                    startIndex = rand() % dictionary.size();
                    startWord = dictionary[startIndex];
                    
                }
                else if (binarySearch(startWord, dictionary) != -1)            //this checks if the word is in the dictionary
                {                                                              //prompts user to enter another word if its not the right length
                    
                    if(lengthOfWordsToUse != startWord.size())
                    {
                        cout << "  ***" << "'" << startWord << "'" << " is not of length " << lengthOfWordsToUse<< ". Please retry.";
                        cout <<"Enter starting word, or \'r\' for a random word: " ;
                        cin >> startWord;
                    }
                    
                }
                 
                cout <<"Enter ending word, or \'r\' for a random word: " ;
                cin >> endWord;
                
                if(endWord == "exit" )
                {
                    cout << "Exiting program." << endl;
                    exit(-1);
                } 
                
                else if(endWord == "r")
                {                                                                            //creates a random number from 0 to size of dictionary for endWord
                    int endIndex;
                    endIndex = rand() % dictionary.size();                                   //finds the word at the index in the dictionary
                    endWord = dictionary[endIndex];
                    
                }
                
                else if (binarySearch(endWord, dictionary) != 1)          
                {
                    if (lengthOfWordsToUse != endWord.size())                               //checks to see if it's the right length
                    {
                        cout << "  ***" << "'" << endWord << "'" << " is not of length " << lengthOfWordsToUse<< ". Please retry.";
                        cout <<"Enter ending word, or \'r\' for a random word: " ;
                        cin >> endWord;
                    }   
                }
                break;

            case 4: //Word change game
                
                wordChangeGame(startWord, endWord, dictionary, lengthOfWordsToUse);     //call function for the game
                break;
                
            case 5:  //Find end word with debug
                mode = 0;    //mode is zero so it prints the debug
                findEndWord(startWord, endWord, dictionary, successionWords , successionIndex, z, mode, temp, lengthOfWordsToUse, start, end, finalVec);    //call the function to print the words
                cout << endl;
                break;
                
            case 6: //find the end word
                mode = 1;   //does not print the debug but finds the end word
                findEndWord(startWord, endWord, dictionary, successionWords , successionIndex, z, mode, temp, lengthOfWordsToUse, start, end, finalVec);
                cout << endl;
                break;
                
            case 7: //display an answer sequence
                mode = 2;   //this will only print the winning sequence
                case7(finalVec, successionWords);      //call the function to print the vector containing the winning sequence
                break;
                
           case 8:  //exits the program
                cout << endl;
                cout <<"Exiting the program"<< endl;
                exit(-1);
                break;
        }
        
    } while( true);
	
    return 0;
}

