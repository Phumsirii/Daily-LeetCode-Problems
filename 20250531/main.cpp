#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class state
{
public:
    int pos;
    int step;

    state() : pos(0), step(0) {}
    state(int p, int s) : pos(p), step(s) {}

    bool operator<(const state &other) const
    {
        if (step == other.step)
            return pos < other.pos;
        return step > other.step;
    }
};

class Solution
{
public:
    int n;
    vector<bool> visited;
    priority_queue<state> pq;

    int getRow(int pos)
    {
        return n - 1 - (pos - 1) / n;
    }

    int getCol(int pos)
    {
        int row = getRow(pos);
        if ((n - 1 - row) % 2 == 0)
            return (pos - 1) % n;
        else
            return n - 1 - (pos - 1) % n;
    }

    int snakesAndLadders(vector<vector<int>> &board)
    {
        n = board.size();
        visited.resize(n * n + 1, false);
        pq.push(state(1, 0));
        visited[1] = true;
        while (!pq.empty())
        {
            state current = pq.top();
            pq.pop();

            if (current.pos == n * n)
                return current.step;

            for (int i = 1; i <= 6; ++i)
            {
                int nextPos = current.pos + i;
                if (nextPos > n * n)
                    continue;

                int row = getRow(nextPos);
                int col = getCol(nextPos);
                if (board[row][col] != -1)
                    nextPos = board[row][col];

                if (!visited[nextPos])
                {
                    visited[nextPos] = true;
                    pq.push(state(nextPos, current.step + 1));
                }
            }
        }
        return -1;
    }
};