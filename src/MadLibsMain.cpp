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
  cout << "Welcome to Mad Libs! Choose a story to begin!" << endl << "Type 1 for \"Food Day\"" << endl << "Type 2 for \"STORY2\"" << endl << "Type 3 for \"STORY3\"" << endl << "(Type 4 to skip to end screen)" << endl;
  
  bool play = 1;
  while(play){
    
    if(counter > 0){
      cout << "Choose another story!" << endl << "Type 1 for \"Food Day\"" << endl << "Type 2 for \"STORY2\"" << endl << "Type 3 for \"STORY3\"" << endl << "(Type 4 to skip to end screen)" << endl;
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
      cout << "As the prompts come up, fill each with a random word to fill the blanks and allow hilarity to ensue." << endl;
      wordnum = 8;
      cout << "Choose a food: ";
      cin >> words[0];
      while (story.find("<<FOOD>>") != string::npos){
        story.replace(story.find("<<FOOD>>"), 8, words[0]);
      }
      cout << "Choose a name: ";
      cin >> words[1];
      while (story.find("<<NAME>>") != string::npos){
        story.replace(story.find("<<NAME>>"), 8, words[1]);
      }
      cout << "Choose an emotion: ";
      cin >> words[2];
      while (story.find("<<EMOTION>>") != string::npos){
        story.replace(story.find("<<EMOTION>>"), 11, words[2 ]);
      }
      cout << "Choose a noun: ";
      cin >> words[3];
      while (story.find("<<NOUN1>>") != string::npos){
        story.replace(story.find("<<NOUN1>>"), 9, words[3]);
      }
      cout << "Choose another noun: ";
      cin >> words[7];
      while (story.find("<<NOUN2>>") != string::npos){
        story.replace(story.find("<<NOUN2>>"), 9, words[7]);
      }
      cout << "Choose a past-tense verb: ";
      cin >> words[4];
      while (story.find("<<VERB1>>") != string::npos){
        story.replace(story.find("<<VERB1>>"), 9, words[4]);
      }
      cout << "Choose another past-tense verb: ";
      cin >> words[5];
      while (story.find("<<VERB2>>") != string::npos){
        story.replace(story.find("<<VERB2>>"), 9, words[5]);
      }
      cout << "Choose one last past-tense verb: ";
      cin >> words[6];
      while (story.find("<<VERB3>>") != string::npos){
        story.replace(story.find("<<VERB3>>"), 9, words[6]);
      }
      
      cout << endl << story << endl;
      
    }else if(stories == 2){
      // cout << "As the prompts come up, fill each with a random word to fill the blanks and allow hilarity to ensue." << endl;
      cout << "Under construction!" << endl;
    }else if(stories == 3){
      // cout << "As the prompts come up, fill each with a random word to fill the blanks and allow hilarity to ensue." << endl;
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