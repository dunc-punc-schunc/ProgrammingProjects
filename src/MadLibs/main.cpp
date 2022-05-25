#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  int stories;
  int wordnum;
  int counter = 0;
  string words[wordnum];
  ifstream file;
  file.open("stories.txt");
  string story;
  string line;
  
  cout << " ____    ____               __  _____      _   __\n";
  cout << "|_   \\  /   _|             |  ]|_   _|    (_) [  |\n";
  cout << "  |   \\/   |   ,--.    .--.| |   | |      __   | |.--.   .--.\n";
  cout << "  | |\\  /| |  `'_\\ : / /'`\\' |   | |   _ [  |  | '/'`\\ \\( (`\\]\n";
  cout << " _| |_\\/_| |_ // | |,| \\__/  |  _| |__/ | | |  |  \\__/ | `'.'.\n";
  cout << "|_____||_____|\\'-;__/ '.__.;__]|________|[___][__;.__.' [\\__) )\n";
  cout << "Welcome to Mad Libs! Choose a story to begin!" << endl << "Type 1 for \"Food Day\"" << endl << "Type 2 for \"Summer Love Story\"" << endl << "Type 3 for \"STORY3\"" << endl << "(Type 4 to skip to end screen)" << endl;
  
  bool play = 1;
  while(play){
    
    if(counter > 0){
      cout << "Choose another story!" << endl << "Type 1 for \"Food Day\"" << endl << "Type 2 for \"Summer Love Story\"" << endl << "Type 3 for \"STORY3\"" << endl << "(Type 4 to skip to end screen)" << endl;
    }
    cin >> stories;
    
    switch (stories) {
      case 1:
        for(int i = 1; getline(file, line) && i < 4; i++){
          if(i == 1){
            story = line;
          }
        }
      case 2:
        for(int i = 1; getline(file, line) && i < 4; i++){
          if(i == 2){
            story = line;
          }
        }
      case 3:
        for(int i = 1; getline(file, line) && i < 4; i++){
          if(i == 3){
            story = line;
          }
        }
    }

    counter++;
    if(stories == 1){ 
      cout << "As the prompts come up, fill each with a random word to fill the blanks and allow hilarity to ensue.\n(When inputing multiple words, put a hyphen between them or else it will only show the first word)\n" << endl;
      wordnum = 8;
      
      cout << "Enter a food: ";
      cin >> words[0];
      while (story.find("<FOOD>") != string::npos){
        story.replace(story.find("<FOOD>"), 6, words[0]);
      }
      
      cout << "Enter a name: ";
      cin >> words[1];
      while (story.find("<NAME>") != string::npos){
        story.replace(story.find("<NAME>"), 6, words[1]);
      }
      
      cout << "Enter an emotion: ";
      cin >> words[2];
      story.replace(story.find("<EMOTION>"), 9, words[2]);
      
      cout << "Enter a noun: ";
      cin >> words[3];
      while (story.find("<NOUN1>") != string::npos){
        story.replace(story.find("<NOUN1>"), 7, words[3]);
      }
      
      cout << "Enter another noun: ";
      cin >> words[7];
      story.replace(story.find("<NOUN2>"), 7, words[7]);
      
      cout << "Enter a verb (past-tense): ";
      cin >> words[4];
      story.replace(story.find("<VERB1>"), 7, words[4]);
      
      cout << "Enter another verb (past-tense): ";
      cin >> words[5];
      story.replace(story.find("<VERB2>"), 7, words[5]);
      
      cout << "Enter another verb (past-tense): ";
      cin >> words[6];
      story.replace(story.find("<VERB3>"), 7, words[6]);
      
      cout << endl << story << endl;
      
    }else if(stories == 2){
      cout << "As the prompts come up, fill each with a random word to fill the blanks and allow hilarity to ensue.\n(When inputing multiple words, put a hyphen between them or else it will only show the first word)\n" << endl;
      wordnum = 20;
      cout << "Enter a guy's name: ";
      cin >> words[0];
      while (story.find("<NAME1>") != string::npos){
        story.replace(story.find("<NAME1>"), 7, words[0]);
      }
      
      cout << "Enter a girl's name: ";
      cin >> words[1];
      story.replace(story.find("<NAME2>"), 7, words[1]);
      
      cout << "Enter a noun: ";
      cin >> words[2];
      story.replace(story.find("<NOUN1>"), 7, words[2]);
      
      cout << "Enter another noun: ";
      cin >> words[4];
      story.replace(story.find("<NOUN2>"), 7, words[4]);
      
      cout << "Enter a proper noun: ";
      cin >> words[11];
      story.replace(story.find("<NOUN3>"), 7, words[11]);

      cout << "Enter a body part: ";
      cin >> words[3];
      story.replace(story.find("<BODY1>"), 7, words[3]);

      cout << "Enter another body part: ";
      cin >> words[13];
      story.replace(story.find("<BODY2>"), 7, words[13]);

      cout << "Enter a verb (past-tense): ";
      cin >> words[6];
      story.replace(story.find("<VERB1>"), 7, words[6]);

      cout << "Enter another verb (past-tense): ";
      cin >> words[10];
      story.replace(story.find("<VERB2>"), 7, words[10]);

      cout << "Enter another verb (past-tense): ";
      cin >> words[12];
      story.replace(story.find("<VERB3>"), 7, words[12]);

      cout << "Enter an animal: ";
      cin >> words[5];
      story.replace(story.find("<ANIMAL>"), 8, words[5]);

      cout << "Enter an adjective: ";
      cin >> words[9];
      story.replace(story.find("<ADJ1>"), 6, words[9]);

      cout << "Enter another adjective: ";
      cin >> words[15];
      story.replace(story.find("<ADJ2>"), 6, words[15]);

      cout << "Enter another adjective: ";
      cin >> words[19];
      story.replace(story.find("<ADJ3>"), 6, words[19]);

      cout << "Enter a place: ";
      cin >> words[13];
      story.replace(story.find("<PLACE>"), 7, words[13]);

      cout << "Enter an adverb: ";
      cin >> words[17];
      story.replace(story.find("<ADV>"), 5, words[17]);

      cout << "Enter a catchphrase: ";
      cin >> words[7];
      story.replace(story.find("<PHRASE>"), 8, words[7]);

      cout << "Enter an emotion: ";
      cin >> words[8];
      story.replace(story.find("<EMOTION1>"), 10, words[8]);

      cout << "Enter another emotion: ";
      cin >> words[16];
      story.replace(story.find("<EMOTION2>"), 10, words[16]);

      cout << "Enter a song title: ";
      cin >> words[18];
      story.replace(story.find("<SONG>"), 6, words[18]);
      
      cout << endl << story << endl;
      
    }else if(stories == 3){
      // cout << "As the prompts come up, fill each with a random word to fill the blanks and allow hilarity to ensue. (When inputing multiple words, put a hyphen between them or else it will only show the first word)" << endl;
      cout << "Under construction!" << endl;
    }else if(stories == 4){
      cout << "Skipped!\n";
    }else{
      cout << "Invalid response, try again!\n";
    }

    if(counter > 0){
      cout << endl << "Would you like to try another story? (Y/N)\n";
      char yn;
      cin >> yn;
      if(yn == 'Y'||yn == 'y'){
        cout << endl;
        counter++;
      }else if(yn == 'N'||yn == 'n'){
        play = 0;
      }else{
        cout << "Invalid response, try again!\n";
      }
    }
  }
  cout << " ____    ____               __  _____      _   __\n";
  cout << "|_   \\  /   _|             |  ]|_   _|    (_) [  |\n";
  cout << "  |   \\/   |   ,--.    .--.| |   | |      __   | |.--.   .--.\n";
  cout << "  | |\\  /| |  `'_\\ : / /'`\\' |   | |   _ [  |  | '/'`\\ \\( (`\\]\n";
  cout << " _| |_\\/_| |_ // | |,| \\__/  |  _| |__/ | | |  |  \\__/ | `'.'.\n";
  cout << "|_____||_____|\\'-;__/ '.__.;__]|________|[___][__;.__.' [\\__) )\n";
  cout << "Thanks for playing!\nCreated by Duncan Kyle 2022. Mad Libs stories found online, all rights reserved.";
  return 0;
}