#include <vector>
#include <iostream>

/*
 Взаперти.

Есть комнаты, помеченные от 0 до n - 1, и все комнаты заперты, за исключением комнаты 0. Ваша цель - посетить все комнаты. Однако вы не можете войти в запертую комнату, не имея ключа от нее.

Когда вы посещаете комнату, вы можете найти в ней набор отдельных ключей. На каждом ключе есть номер, обозначающий, какую комнату он открывает, и вы можете взять их все с собой, чтобы открыть другие комнаты.

Учитывая массив rooms, где rooms[i] - это набор ключей, которые вы можете получить, если вы посетили комнату i, верните true, если вы можете посетить все комнаты, или false в противном случае.

class Solution {
public:
bool canOpenAllDoors(vector<vector<int»& rooms) {

}
};

Пример 1:
Input: rooms = [[1],[2],[3],[]]
Output: true

Пример 2:
Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false

Ограничения:
n == rooms.length
2 <= n <= 1000
0 <= rooms[i].length <= 1000
1 <= sum(rooms[i].length) <= 3000
0 <= rooms[i][j] < n
Все значения в rooms[i] уникальны
*/

using std::vector;

class Solution {
public:
    bool canOpenAllDoors(vector<vector<int>>& rooms) {
        bool* openDoors = new bool[rooms.size()];
        for (int i = 0; i < rooms.size(); ++i)
            openDoors[i] = false;
        goToRoom(rooms, 0, openDoors);
        for (int i = 0; i < rooms.size(); ++i)
            if (!openDoors[i]) return false;
        return true;
    }
private:
    void goToRoom(vector<vector<int>>& rooms, int room, bool* openDoors) {
        openDoors[room] = true;
        for (int i = 0; i < rooms[room].size(); ++i) {
            if (!openDoors[rooms[room][i]])
                goToRoom(rooms, rooms[room][i], openDoors);
        }
    }
};


int main() {
    vector<vector<int>> rooms = {vector<int>{1, 3}, vector<int>{3, 0, 1}, vector<int>{2}, vector<int>{0}};
    std::cout << Solution().canOpenAllDoors(rooms);
}

