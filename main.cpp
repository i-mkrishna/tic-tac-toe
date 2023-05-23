#include<iostream>
using namespace std;

char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

char player = 'X';

void Draw(){

    system("cls");
    
    std::cout << " Tic Tac Toe" << endl;

    /*
    // Drawing the matrix form tik tak toe

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */

    for (int i = 0; i < 3; i++) {
        std::cout << matrix[i][0] << " | " << matrix[i][1] << " | " << matrix[i][2] << std::endl;
        if (i != 2) {
            std::cout << "--+---+--" << std::endl;
        }
    }
}

void Input(){

    // Taking iput from users
    /*
    int a;
    std::cout  << "it's " << player << " turn. " << "Press the number of the field : ";
    std::cin >> a;
    if(a == 1){
        if (matrix[0][0] == '1'){
            matrix[0][0] = player;
        }
        else{
            std::cout << "field is already use try different no. " << std::endl;
        }
    }
    else if (a == 2){
        if (matrix[0][1] == '2'){
            matrix[0][1] = player;
        }
        else{
            std::cout << "field is already use try different no. " << std::endl;
            Input();
        } 
    }else if (a == 3){
        if (matrix[0][2] == '3'){
            matrix[0][2] = player;
        }
        else{
            std::cout << "field is already use try different no. " << std::endl;
            Input();
        }
    }
    else if (a == 4){
        if (matrix[1][0] == '4'){
            matrix[1][0] = player;
        }
        else{
            std::cout << "field is already use try different no. " << std::endl;
            Input();
        }
    }
    else if (a == 5){
        if (matrix[1][1] == '5'){
            matrix[1][1] = player;
        }
        else{
            std::cout << "field is already use try different no. " << std::endl;
            Input();
        }
    }
    else if (a == 6){
        if (matrix[1][2] == '6'){
            matrix[1][6] = player;
        }
        else{
            std::cout << "field is already use try different no. " << std::endl;
            Input();
        }
    }
    else if(a == 7){
        if (matrix[2][0] == '7'){
            matrix[2][0] = player;
        }
        else{
            std::cout << "field is already use try different no. " << std::endl;
            Input();
        }
    }
    else if (a == 8){
        if (matrix[2][1] == '8'){
            matrix[2][1] = player;
        }
        else{
            std::cout << "field is already use try different no. " << std::endl;
            Input();
        }
    }
    else if (a == 9){
        if (matrix[2][2] == '9'){
            matrix[2][2] = player;
        }
        else{
            std::cout << "field is already use try different no. " << std::endl;
            Input();
        }
    }
    */
    
    int a;
    std::cout << "It's " << player << " turn. " <<  "Press the number of the field: ";
    std::cin >> a;
    if (a < 1 || a > 9) {
        std::cout << "Invalid input. Please enter a number between 1 and 9." << std::endl;
        Input();
        return;
    }
    int row = (a - 1) / 3;
    int col = (a - 1) % 3;
    if (matrix[row][col] == '0' + a) {
        matrix[row][col] = player;
    } else {
        std::cout << "Field is already in use. Press a different number." << std::endl;
        Input();
    }
    
}

void TogglePlayer(){

    // changing player after 1 entery

    // if (player == 'X'){
    //     player = 'O';
    // }
    // else{
    //     player = 'X';
    // }

    player = (player == 'X') ? 'O' : 'X';
}

char Win(){
    
    /*
    // first player

    // Checking for Row
    if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X'){
        return 'X';
    }
    if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X'){
        return 'X';
    }
    if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X'){
        return 'X';
    }

    // Checking for Column
    if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X'){
        return 'X';
    }
    if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X'){
        return 'X';
    }
    if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X'){
        return 'X';
    }

    // Checking fo diagonals
    if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X'){
        return 'X';
    }
    if (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X'){
        return 'X';
    }

    //Second player

    // Checking for Row
    if (matrix[0][0] == 'O' && matrix[0][1] == 'O'&& matrix[0][2] == 'X'){
        return 'X';
    }
    if (matrix[1][0] == 'O' && matrix[1][1] == 'O'&& matrix[1][2] == 'X'){
        return 'X';
    }
    if (matrix[2][0] == 'O' && matrix[2][1] == 'O'&& matrix[2][2] == 'X'){
        return 'X';
    }

    // Checking for Column
    if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'X'){
        return 'X';
    }
    if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'X'){
        return 'X';
    }
    if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'X'){
        return 'X';
    }

    // Checking for diagonals
    if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'X'){
        return 'X';
    }
    if (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'X'){
        return 'X';
    }
    
    */
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]) {
            return matrix[i][0];
        }
        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]) {
            return matrix[0][i];
        }
    }
    // Check diagonals
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) {
        return matrix[0][0];
    }
    if (matrix[2][0] == matrix[1][1] && matrix[1][1] == matrix[0][2]) {
        return matrix[2][0];
    }

    return '/';
}

int main(){

    int n = 0;
    Draw();
    while (1){

        n++;
        Input();
        Draw();
        if(Win() == 'X'){
            std::cout << "X Wins !!!";
            break;
        }
        else if (Win() == 'O'){
            std::cout << "O Wins !!!";
            break;
        }
        else if (Win() == '/' && n == 9){
            std::cout << "it's a Draw !!!";
            break;
        }
        TogglePlayer();
    }
    
    system("pause");

    return 0;
}