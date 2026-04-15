#include <stdio.h>

// 全局变量：统计符合条件的棋局数量（用long long防止数值太大溢出）
long long valid_count = 0;

// 函数：检查当前棋盘是否有五子连珠（返回1=有连珠，0=无连珠）
// board[5][5]：棋盘，1=白棋，2=黑棋
int check_win(int board[5][5]) {
    // 1. 检查所有行（5行）
    for (int i = 0; i < 5; i++) { // i=行号
        // 检查第i行是否全是白棋（1）或全是黑棋（2）
        int all_white = 1, all_black = 1;
        for (int j = 0; j < 5; j++) { // j=列号
            if (board[i][j] != 1) all_white = 0;
            if (board[i][j] != 2) all_black = 0;
        }
        if (all_white || all_black) return 1; // 有连珠
    }

    // 2. 检查所有列（5列）
    for (int j = 0; j < 5; j++) { // j=列号
        int all_white = 1, all_black = 1;
        for (int i = 0; i < 5; i++) { // i=行号
            if (board[i][j] != 1) all_white = 0;
            if (board[i][j] != 2) all_black = 0;
        }
        if (all_white || all_black) return 1; // 有连珠
    }

    // 3. 检查两条对角线
    // 对角线1：左上→右下（(0,0),(1,1),(2,2),(3,3),(4,4)）
    int all_white = 1, all_black = 1;
    for (int i = 0; i < 5; i++) {
        if (board[i][i] != 1) all_white = 0;
        if (board[i][i] != 2) all_black = 0;
    }
    if (all_white || all_black) return 1;

    // 对角线2：右上→左下（(0,4),(1,3),(2,2),(3,1),(4,0)）
    all_white = 1; all_black = 1;
    for (int i = 0; i < 5; i++) {
        if (board[i][4 - i] != 1) all_white = 0;
        if (board[i][4 - i] != 2) all_black = 0;
    }
    if (all_white || all_black) return 1;

    // 4. 所有情况都检查完，无连珠
    return 0;
}

// 递归函数：枚举所有棋盘布局
// row/col：当前要填的格子位置（行/列）
// white_num：已经放了多少个白棋
// board[5][5]：当前棋盘状态（1=白，2=黑，0=未填）
void dfs(int row, int col, int white_num, int board[5][5]) {
    // 终止条件1：所有格子都填完了（5行5列）
    if (row == 5) {
        // 只有白棋刚好13个，且无连珠 → 计数+1
        if (white_num == 13 && check_win(board) == 0) {
            valid_count++;
        }
        return;
    }

    // 计算下一个要填的格子位置（列满了就换行）
    int next_row = row;
    int next_col = col + 1;
    if (next_col == 5) { // 列到4之后，下一列是0，行+1
        next_row = row + 1;
        next_col = 0;
    }

    // 分支1：当前格子放白棋（1）
    board[row][col] = 1;
    dfs(next_row, next_col, white_num + 1, board);
    board[row][col] = 0; // 回溯：恢复为未填状态

    // 分支2：当前格子放黑棋（2）
    board[row][col] = 2;
    dfs(next_row, next_col, white_num, board);
    board[row][col] = 0; // 回溯：恢复为未填状态
}

int main() {
    // 初始化空棋盘：所有格子都是0（未填）
    int board[5][5] = {0};

    // 启动递归：从(0,0)开始填，已放0个白棋，空棋盘
    dfs(0, 0, 0, board);

    // 输出结果（本题标准答案：2270208）
    printf("满足条件的棋局数量：%lld\n", valid_count);

    return 0;
}