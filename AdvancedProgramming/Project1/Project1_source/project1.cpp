/* AI융합학부 20160394 임효상 Project1 과제 제출입니다.*/

#include <iostream>

#define SIZE_ARRAY 4
#define MAX_TURNS 20

using namespace std;

int p1_score = 0, p2_score = 0;

int arr_cards[4][4] = 
    {{1,2,3,4},
     {5,6,7,8},
     {8,7,6,5},
     {4,3,2,1}};
    
bool arr_reveal[4][4] =
    {{false,false,false,false},
     {false,false,false,false},
     {false,false,false,false},
     {false,false,false,false}};

bool End_Game() {
    bool ending = false;
    for(int i = 0; i < SIZE_ARRAY * SIZE_ARRAY; i++) {
        if(!(*(*arr_reveal + i))) return false;
    }
    return true;
}

void Show_cards() {
    cout << endl
         << "    1 2 3 4" << endl 
         << "--+--------" << endl;
    
    for(int i = 0; i < SIZE_ARRAY; i++){
        cout << " " << i+1 << "|";

        for(int j = 0; j < SIZE_ARRAY; j++){
            if(arr_reveal[i][j]) 
                cout << " " << arr_cards[i][j];
            else 
                cout << " X";
        }
        cout << endl;
    }
    return;
}

void Match_cards(int row1, int row2, int col1, int col2, int pnum) {

    // when player matches cards
    if(arr_cards[row1][col1] == arr_cards[row2][col2]) {
        if(arr_cards[row1][col1] == 7) {
            if(pnum == 1) p1_score += 2;
            else p2_score += 2;
        }
        else {
            if(pnum == 1) p1_score += 1;
            else p2_score += 1;
        }
        
        arr_reveal[row1][col1] = true;
        arr_reveal[row2][col2] = true;

        Show_cards();
        cout << "P" << pnum << " found a matching pair! P1's score: " << p1_score << " P2's score: " << p2_score << endl;
        return;
    }
    else {
        arr_reveal[row1][col1] = true;
        arr_reveal[row2][col2] = true;
        Show_cards();
        arr_reveal[row1][col1] = false;
        arr_reveal[row2][col2] = false;

        cout << "P" << pnum << " failed to find a matching pair" << endl;
        return;
    }
}

bool Input(int pnum) {
    int s1 = 0, s2 = 0;
    int row1, row2, col1, col2;

    cin >> s1 >> s2;

    if(s1 == s2) {
        cout << "!!!!!!!!!!!!YOU PICKED SAME LOCATION!!!!!!!!!!!!" << endl;
        return false;
    }
    row1 = (s1 / 10) - 1;
    row2 = (s2 / 10) - 1;
    col1 = (s1 % 10) - 1;
    col2 = (s2 % 10) - 1;
    if(row1 < 0 || row1 >=4) {
        cout << "# Invalid row1. Each numbers must be 1 <= N <= 4" << endl;
        return false;
    }
    else if(row2 < 0 || row2 >=4) {
        cout << "# Invalid row2. Each numbers must be 1 <= N <= 4" << endl;
        return false;
    }
    else if(col1 < 0 || col1 >=4) {
        cout << "# Invalid col1. Each numbers must be 1 <= N <= 4" << endl;
        return false;
    }
    else if(col2 < 0 || col2 >=4) {
        cout << "# Invalid col2. Each numbers must be 1 <= N <= 4" << endl;
        return false;
    }

    if(arr_reveal[row1][col1] || arr_reveal[row2][col2]) {
        cout << "!!!!!!!!!!!!YOU PICKED REVEALED CARD!!!!!!!!!!!!" << endl;
        return false;
    }
    Match_cards(row1, row2, col1, col2, pnum);
    return true;
}

int Init_cards() {
    int num_count[8] = {0};

    srand(5);
    
    for(int i = 0; i < SIZE_ARRAY; i++) {
        for(int j = 0; j < SIZE_ARRAY; j++) {
            int tmp = rand()%8;
            if(num_count[tmp] >= 2) {
                j--;
                continue;
            }
            arr_cards[i][j] = tmp + 1;
            num_count[tmp] += 1;
        }
    }

    return 0;
}

int main() {
    bool IS_INPUT_VALID = false;
    int s1 = 0, s2 = 0;
    int mode_selection = 0;
    
    cout << "Choose card generation mode (1: Static, 2: Random): ";
    cin >> mode_selection;
    if(mode_selection == 2) {
        Init_cards();
    }

    Show_cards();

    for(int turnsleft = MAX_TURNS; turnsleft > 0; turnsleft -= 2) {
        IS_INPUT_VALID = false;
        while(!IS_INPUT_VALID) {
            cout << "P1's turn, choose two cards (" << turnsleft << "turns remain): ";
            IS_INPUT_VALID = Input(1);
        }
        if(End_Game()) break;

        IS_INPUT_VALID = false;
        while(!IS_INPUT_VALID) {
            cout << "P2's turn, choose two cards (" << turnsleft - 1 << "turns remain): ";
            IS_INPUT_VALID = Input(2);
        }
        if(End_Game()) break;
    }
    cout << "Game finished. Final scores are P1: " << p1_score << ", P2: " << p2_score << "." << endl;
}