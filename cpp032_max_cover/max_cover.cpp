/*
 * @description 线段重合
 * @link https://www.nowcoder.com/practice/1ae8d0b6bb4e4bcdbf64ec491f63fc37
 * @date   2024/5/17 16:58
 * @author zhc
 */
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef struct Line
{
    int start;
    int end;
} Line;

bool compare(const Line &a, const Line &b)
{
    return a.start < b.start;
}

int max_cover_lines(vector<Line> &lines)
{
    int ans = 0;
    sort(lines.begin(), lines.end(), compare);
    // 默认大根堆
    // 小根堆，使用greater<int>
    priority_queue<int, vector<int>, greater<int> > pq;

    for(size_t i = 0; i < lines.size(); ++i)
    {
        // 当前线段的开始位置 >= 之前线段的结束位置
        while(!pq.empty() && lines[i].start >= pq.top())
        {
            // 弹出不符合条件的线段
            pq.pop();
        }
        // 加入当前线段的结束位置
        pq.push(lines[i].end);
        ans = max(ans, static_cast<int>(pq.size()));
    }

    return ans;
}


int main()
{
    int n = 0;
    cin >> n;
    vector<Line> lines;
    while(n--)
    {
        int start, end;
        cin >> start >> end;
        Line line = {start, end};
        lines.push_back(line);
    }

    cout << max_cover_lines(lines) << endl;
    return 0;
}