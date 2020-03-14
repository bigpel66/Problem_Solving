#include <iostream>
#define MAX 500
#define endl "\n"

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int answer = 0;
int numberOfRows;
int numberOfColumns;
bool isVisited[MAX][MAX];
int tetromino[MAX][MAX];



void initArrays() {
    for(int i = 0; i< numberOfRows; i++) {
        for(int j = 0; j < numberOfColumns; j++) {
            int inputValue = 0;
            std::cin >> inputValue;
            
            isVisited[i][j] = false;
            tetromino[i][j] = inputValue;
        }
    }
}

void depthSearch(int x, int y, int depthCount, int accValue) {
    if(depthCount == 4) {
        if(answer < accValue - tetromino[x][y]) {
            answer = accValue - tetromino[x][y];
        }
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        int nX = x + dx[i];
        int nY = y + dy[i];
        
        if(nX < 0 ||
           nY < 0 ||
           nX > numberOfRows ||
           nY > numberOfColumns ||
           isVisited[nX][nY] == true) {
            continue;
        }
        
        isVisited[nX][nY] = true;
        depthSearch(nX, nY, depthCount + 1, accValue + tetromino[nX][nY]);
        isVisited[nX][nY] = false;
    }
}

//ㅜ
void middleFinger1(int x, int y) {
    int sumOfMiddleFinger1 = tetromino[x - 1][y] + tetromino[x - 1][y + 1] + tetromino[x - 1][y - 1] + tetromino[x][y];
    if(answer < sumOfMiddleFinger1){
        answer = sumOfMiddleFinger1;
    }
}

//ㅗ
void middleFinger2(int x, int y) {
    int sumOfMiddleFinger2 = tetromino[x + 1][y] + tetromino[x + 1][y + 1] + tetromino[x + 1][y - 1] + tetromino[x][y];
    if(answer < sumOfMiddleFinger2){
        answer = sumOfMiddleFinger2;
    }
}

//ㅏ
void middleFinger3(int x, int y) {
    int sumOfMiddleFinger3 = tetromino[x][y - 1] + tetromino[x - 1][y - 1] + tetromino[x + 1][y - 1] + tetromino[x][y];
    if(answer < sumOfMiddleFinger3){
        answer= sumOfMiddleFinger3;
    }
}

//ㅓ
void middleFinger4(int x, int y) {
    int sumOfMiddleFinger4 = tetromino[x][y + 1] + tetromino[x - 1][y + 1] + tetromino[x + 1][y + 1] + tetromino[x][y];
    if(answer < sumOfMiddleFinger4){
        answer= sumOfMiddleFinger4;
    }
}

void exceptionSearch(int x, int y) {
    if(x - 1 >= 0 && y - 1 >= 0 && y + 1 < numberOfColumns)
        middleFinger1(x, y);
    if(x + 1 < numberOfRows && y - 1 >= 0 && y + 1 < numberOfColumns)
        middleFinger2(x, y);
    if(y - 1 >= 0 && x - 1 >= 0 && x + 1 < numberOfRows)
        middleFinger3(x, y);
    if(y + 1 < numberOfColumns && x - 1 >= 0 && x + 1 < numberOfRows)
        middleFinger4(x, y);
}

void solution() {
    
    
    for(int i = 0; i <numberOfRows; i++) {
        for(int j = 0; j < numberOfColumns; j++) {
            int accValue = tetromino[i][j];
            
            isVisited[i][j] = true;
            depthSearch(i,j,0, accValue);
            exceptionSearch(i, j);
            isVisited[i][j] = false;
        }
    }
}

int main() {
    
    std::cin >> numberOfRows >> numberOfColumns;
    
    initArrays();
    solution();
    
    std::cout << answer;
    
    return 0;
}
